#include "Game.h"

#include <memory>

#include "Defines.h"
#include "screens/MainMenuScreen.h"
#include "screens/OptionsMenuScreen.h"
#include "events/Events.h"
#include "screens/PauseMenuScreen.h"

Game::Game() {
    event_bus_ = std::make_shared<dexode::EventBus>();

    gamePausedListener_ = std::make_unique<dexode::EventBus::Listener>(event_bus_);

    window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Rashnawa");
    window_->setFramerateLimit(240);

    options_manager_ = std::make_shared<OptionsManager>(event_bus_);

    audio_system_ = std::make_shared<Audio::AudioSystem>();
    music_manager_ = std::make_unique<Audio::MusicManager>(event_bus_, audio_system_, options_manager_);

    renderer_ = std::make_unique<Graphics::Renderer>(window_);

    keybind_handler_ = std::make_unique<KeybindHandler>(event_bus_);

    world_ = std::make_shared<World>(event_bus_);

    audio_system_->initialize();
    audio_system_->loadBank(ASSETS_DIR + "audio/Master.bank");
    audio_system_->loadBank(ASSETS_DIR + "audio/Master.strings.bank");

    event_bus_->postpone<Events::ChangeScreen>({.from = Screens::None, .to = Screens::MainMenu});

    if (!font_->loadFromFile(ASSETS_DIR + "fonts/Unitblock.ttf")) {
        std::cout << "Error: can't load font!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Game::run() {
    dexode::EventBus::Listener end_game_listener{event_bus_};
    end_game_listener.listen<Events::CloseGame>([this](const Events::CloseGame) {
        running_ = false;
    });

    dexode::EventBus::Listener change_screen_listener(event_bus_);
    change_screen_listener.listen<Events::ChangeScreen>([this](const Events::ChangeScreen &e) {
        switch (e.to) {
            using
            enum Screens;

            case None:
                current_screen_.reset();
                gamePausedListener_->listen<Events::EscapeBtn>([this](const Events::EscapeBtn &) {
                    event_bus_->postpone<Events::ChangeScreen>({.from = None, .to = PauseMenu});
                });

                break;
            case MainMenu:
                current_screen_ = std::make_unique<MainMenuScreen>(event_bus_, font_);
                break;
            case OptionsMenu:
                current_screen_ = std::make_unique<OptionsMenuScreen>(event_bus_, font_, options_manager_,
                                                                      window_->getSize());
                break;
            case PauseMenu:
                current_screen_ = std::make_unique<PauseMenuScreen>(event_bus_, font_);
                gamePausedListener_->unlistenAll();
        }
    });

    dexode::EventBus::Listener animation_created_listener(event_bus_);
    animation_created_listener.listen<Events::AnimationCreated>([this](const Events::AnimationCreated &event) {
        animations_.push_back(event.animation);
    });

    sf::Clock clock;
    //temporary tests (sorry guigui)
    world_->load("0", "tmp");

    while (running_) {
        const int delta_time = clock.restart().asMilliseconds();

        for (int i = 0; i < animations_.size(); i++) {
            if (const auto animation = animations_.at(i).lock()) {
                animation->update(delta_time);
            } else {
                animations_.erase(animations_.begin() + i);
                std::cout << "Animation deleted" << std::endl;
            }
        }
        event_bus_->process();
        audio_system_->update();

        handleEvents();

        window_->clear(sf::Color::White);

        if (current_screen_.has_value()) {
            current_screen_.value()->render(window_);
        } else {
            renderer_->render_game(world_);
        }

        window_->display();
    }
}

void Game::handleEvents() const {
    sf::Event event{};
    while (window_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                event_bus_->postpone(Events::CloseGame{});
                break;
            case sf::Event::Resized:
                //window_->setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(event.size.width),
                //                                        static_cast<float>(event.size.height))));

                if (current_screen_.has_value()) {
                    current_screen_.value()->onWindowResize(event.size);
                }
                break;
            case sf::Event::KeyPressed:
                keybind_handler_->handleEvent(event.key, true);
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        event_bus_->postpone(Events::EscapeBtn{});
                        break;
                    default:
                        break;
                }
                break;
            case sf::Event::KeyReleased:
                keybind_handler_->handleEvent(event.key, false);
            case sf::Event::MouseMoved:
                if (current_screen_.has_value()) {
                    current_screen_.value()->onMouseMove(event.mouseMove);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button != sf::Mouse::Button::Left)
                    continue;

                if (current_screen_.has_value()) {
                    current_screen_.value()->onMousePressed(event.mouseButton);
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button != sf::Mouse::Button::Left)
                    continue;

                if (current_screen_.has_value()) {
                    current_screen_.value()->onMouseReleased(event.mouseButton);
                }
                break;
            default:
                break;
        }
    }
}
