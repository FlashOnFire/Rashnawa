#include "Game.h"

#include <memory>
#include "screens/MainMenuScreen.h"
#include "screens/OptionsMenuScreen.h"
#include "events/Events.h"

Game::Game() {
    event_bus_ = std::make_shared<dexode::EventBus>();

    window_ = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Rashnawa");
    window_->setFramerateLimit(240);

    options_manager_ = std::make_shared<OptionsManager>(event_bus_);

    audio_manager_ = std::make_shared<Audio::AudioManager>();
    music_manager_ = std::make_unique<Audio::MusicManager>(event_bus_, audio_manager_, options_manager_);

    renderer_ = std::make_unique<Graphics::Renderer>(window_);

    keybind_handler_ = std::make_unique<KeybindHandler>(event_bus_);

    audio_manager_->initialize();
    audio_manager_->loadBank("../assets/audio/Master.bank");
    audio_manager_->loadBank("../assets/audio/Master.strings.bank");

    event_bus_->postpone<Events::ChangeScreen>({.from = Screens::None, .to = Screens::MainMenu});

    if (!font_->loadFromFile("../assets/fonts/Unitblock.ttf")) {
        std::cout << "Error: can't load font!" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void Game::run() {
    dexode::EventBus::Listener end_game_listener{event_bus_};
    end_game_listener.listen<Events::CloseGame>([this](const Events::CloseGame) {
        running_ = false;
    });

    dexode::EventBus::Listener change_screen_listener{event_bus_};
    change_screen_listener.listen<Events::ChangeScreen>([this](const Events::ChangeScreen& e) {
        switch (e.to) {
                using
                        enum Screens;

            case None:
                current_screen_.reset();
                break;
            case MainMenu:
                current_screen_ = std::make_unique<MainMenuScreen>(event_bus_, font_);
                break;
            case OptionsMenu:
                current_screen_ = std::make_unique<OptionsMenuScreen>(event_bus_, options_manager_, font_,
                                                                      window_->getSize());
                break;
        }
    });

    dexode::EventBus::Listener animation_created_listener{event_bus_};
    animation_created_listener.listen<Events::AnimationCreated>([this](const Events::AnimationCreated& event) {
        animations_.push_back(event.animation);
    });

    sf::Clock clock;

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
        audio_manager_->update();

        handleEvents();

        window_->clear(sf::Color::White);

        if (current_screen_.has_value()) {
            current_screen_.value()->render(window_);
        } else {
            renderer_->render();
        }

        window_->display();
    }
}

void Game::handleEvents() {
    sf::Event event{};
    while (window_->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                event_bus_->postpone(Events::CloseGame{});
                break;
            case sf::Event::Resized:
                window_->setView(sf::View(sf::FloatRect(0, 0, static_cast<float>(event.size.width),
                                                        static_cast<float>(event.size.height))));

                if (current_screen_.has_value()) {
                    current_screen_.value()->onWindowResize(event.size);
                }
                break;
            case sf::Event::KeyPressed:
                keybind_handler_->handleEvent(event.key);
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        event_bus_->postpone(Events::EscapeBtn{});
                        break;
                    default:
                        break;
                }
                break;
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
