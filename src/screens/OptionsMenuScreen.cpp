#include "OptionsMenuScreen.h"
#include "../events/Events.h"
#include "SoundOptions.h"
#include "objects/ButtonBuilder.h"
#include "../graphics/Animations.h"

#include <utility>

OptionsMenuScreen::OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::Font> font,
                                     const sf::Vector2<unsigned int>& windowSize) : BasicScreen(std::move(font)),
    event_bus_(std::move(eventBus)) {
    if (!background_texture_->loadFromFile("../assets/menu/new_background.png")) {
        std::cout << "Can't load menu background backgroundTexture from file";
        exit(EXIT_FAILURE);
    }
    background_texture_->setSmooth(true);

    if (!title_background_->loadFromFile("../assets/menu/new_background.png")) {
        std::cout << "Can't load menu background backgroundTexture from file";
        exit(EXIT_FAILURE);
    }

    if (!options_background_texture_->loadFromFile("../assets/menu/options/background.png")) {
        std::cout << "Can't load menu background backgroundTexture from file";
        exit(EXIT_FAILURE);
    }

    if (!buttons_background_texture_->loadFromFile("../assets/menu/options/button_background.png")) {
        std::cout << "Can't load menu button backgroundTexture from file";
        exit(EXIT_FAILURE);
    }

    if (!buttons_foreground_texture_->loadFromFile("../assets/menu/options/button.png")) {
        std::cout << "Can't load menu button backgroundTexture from file";
        exit(EXIT_FAILURE);
    }

    if (!slider_texture_->loadFromFile("../assets/menu/options/slider.png")) {
        std::cout << "Can't load menu slider backgroundTexture from file";
        exit(EXIT_FAILURE);
    }

    if (!slider_knob_texture_->loadFromFile("../assets/menu/options/sliderknob.png")) {
        std::cout << "Can't load menu sliderknob backgroundTexture from file";
        exit(EXIT_FAILURE);
    }

    title_text_.setString("Options");
    title_text_.setFont(*font_);
    title_text_.setCharacterSize(65);
    title_text_.setFillColor(sf::Color::Black);

    background_ = sf::RectangleShape();
    background_.setTexture(background_texture_.get());

    options_background_.setTexture(options_background_texture_.get());

    const auto button_size = sf::Vector2i(static_cast<int>(buttons_background_texture_->getSize().x),
                                          static_cast<int>(buttons_background_texture_->getSize().y) / 3);

    const auto button_normal_coords = sf::Vector2i(0, 0);
    const auto button_hovered_coords = sf::Vector2i(0, static_cast<int>(buttons_background_texture_->getSize().y) / 3);
    const auto button_clicked_coords = sf::Vector2i(
        0, static_cast<int>(buttons_background_texture_->getSize().y) * 2 / 3);

    sound_category_background_button_ = ButtonBuilder()
            .backgroundTexture(buttons_background_texture_, button_normal_coords, button_size)
            .hoverBackgroundTexCoords(button_hovered_coords, button_size)
            .clickedBackgroundTexCoords(button_clicked_coords, button_size)
            .foregroundTexture(buttons_foreground_texture_)
            .animation(event_bus_, "button", 0, 1, 2)
            .callback([]() {
                std::cout << "clicked" << std::endl;
            }).build();

    graphics_category_background_button_ = ButtonBuilder()
            .backgroundTexture(buttons_background_texture_, button_normal_coords, button_size)
            .hoverBackgroundTexCoords(button_hovered_coords, button_size)
            .clickedBackgroundTexCoords(button_clicked_coords, button_size)
            .foregroundTexture(buttons_foreground_texture_)
            .animation(event_bus_, "button", 3, 4, 5)
            .callback([]() {
                std::cout << "clicked" << std::endl;
            }).build();

    other_category_background_button_ = ButtonBuilder()
            .backgroundTexture(buttons_background_texture_, button_normal_coords, button_size)
            .hoverBackgroundTexCoords(button_hovered_coords, button_size)
            .clickedBackgroundTexCoords(button_clicked_coords, button_size)
            .foregroundTexture(buttons_foreground_texture_)
            .animation(event_bus_, "button", 6, 7, 8)
            .callback([]() {
                std::cout << "clicked" << std::endl;
            }).build();

    current_option_category_ = std::make_unique<SoundOptions>(slider_texture_, slider_knob_texture_);

    updateComponentsTransform(windowSize);

    event_listener_ = std::make_unique<dexode::EventBus::Listener>(event_bus_);
    event_listener_->listen<Events::EscapeBtn>([this](const Events::EscapeBtn) {
        event_bus_->postpone<Events::ChangeScreen>({.from = Screens::OptionsMenu, .to = Screens::MainMenu});
    });

    std::cout << "Created OptionsMenuScreen!" << std::endl;
}

void OptionsMenuScreen::updateComponentsTransform(const sf::Vector2<unsigned int>& windowSize) {
    background_.setSize(sf::Vector2f(windowSize));

    title_text_.setPosition(
        static_cast<float>(windowSize.x) / 2.0f - title_text_.getLocalBounds().width / 2.0f - title_text_.
        getLocalBounds().left,
        static_cast<float>(windowSize.y) / 10.0f - title_text_.getLocalBounds().height / 2.0f - title_text_.
        getLocalBounds().top);


    const auto optionsBackgroundPosX = static_cast<float>(windowSize.x) * (0.1f + 0.1f + 0.05f);
    const auto optionsBackgroundPosY = static_cast<float>(windowSize.y) * 0.2f;

    const auto optionsBackgroundSizeX = static_cast<float>(windowSize.x) * 0.65f;
    const auto optionsBackgroundSizeY = static_cast<float>(windowSize.y) * (1.0f - 0.2f - 0.1f);

    options_background_.setPosition(optionsBackgroundPosX, optionsBackgroundPosY);
    options_background_.setSize(sf::Vector2f(optionsBackgroundSizeX, optionsBackgroundSizeY));

    current_option_category_->setTransform(sf::Vector2f(optionsBackgroundPosX, optionsBackgroundPosY),
                                           sf::Vector2f(optionsBackgroundSizeX, optionsBackgroundSizeY));

    const auto buttonCategoriesPosX = static_cast<float>(windowSize.x) * 0.1f;
    const auto buttonCategoriesPosY = static_cast<float>(windowSize.y) * 0.2f;

    const auto buttonCategoriesSize = static_cast<float>(windowSize.x) * 0.1f;
    const auto betweenCategoryButtonsGap = static_cast<float>(windowSize.x) * 0.02f;

    sound_category_background_button_->setTransform(sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY),
                                                    sf::Vector2f(buttonCategoriesSize, buttonCategoriesSize));

    graphics_category_background_button_->setTransform(
        sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY + buttonCategoriesSize + betweenCategoryButtonsGap),
        sf::Vector2f(buttonCategoriesSize, buttonCategoriesSize));

    other_category_background_button_->setTransform(
        sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY + 2 * (buttonCategoriesSize +
                                                                       betweenCategoryButtonsGap)),
        sf::Vector2f(buttonCategoriesSize, buttonCategoriesSize));
}

void OptionsMenuScreen::render(std::shared_ptr<sf::RenderWindow> window) const {
    window->draw(background_);
    window->draw(title_text_);
    window->draw(options_background_);

    window->draw(*sound_category_background_button_);
    window->draw(*graphics_category_background_button_);
    window->draw(*other_category_background_button_);

    window->draw(*current_option_category_);
}

void OptionsMenuScreen::onMouseMove(const sf::Event::MouseMoveEvent& event) {
    current_option_category_->onMouseMove(event);
    sound_category_background_button_->onMouseMoved(event);
    graphics_category_background_button_->onMouseMoved(event);
    other_category_background_button_->onMouseMoved(event);
}

void OptionsMenuScreen::onMousePressed(const sf::Event::MouseButtonEvent& event) {
    current_option_category_->onMouseButtonPressed(event);
    sound_category_background_button_->onMouseButtonPressed(event);
    graphics_category_background_button_->onMouseButtonPressed(event);
    other_category_background_button_->onMouseButtonPressed(event);
}

void OptionsMenuScreen::onMouseReleased(const sf::Event::MouseButtonEvent& event) {
    current_option_category_->onMouseButtonReleased(event);
    sound_category_background_button_->onMouseButtonReleased(event);
    graphics_category_background_button_->onMouseButtonReleased(event);
    other_category_background_button_->onMouseButtonReleased(event);
}

void OptionsMenuScreen::onWindowResize(const sf::Event::SizeEvent& event) {
    updateComponentsTransform(sf::Vector2<unsigned int>(event.width, event.height));
}
