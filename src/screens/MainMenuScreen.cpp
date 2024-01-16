#include <iostream>

#include "../events/Events.h"

#include "MainMenuScreen.h"

#include "../Defines.h"
#include "objects/ButtonBuilder.h"

MainMenuScreen::MainMenuScreen(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<sf::Font> font)
    : BasicScreen(std::move(event_bus), std::move(font)) {
    if (!background_texture_->loadFromFile(ASSETS_DIR + "menu/menu_background2.png")) {
        std::cout << "Can't load menu background texture from file" << std::endl;
        exit(EXIT_FAILURE);
    }
    background_texture_->setSmooth(true);

    if (!button_texture_->loadFromFile(ASSETS_DIR + "menu/button.png")) {
        std::cout << "Can't load menu button backgroundTexture from file" << std::endl;
        exit(EXIT_FAILURE);
    }

    const sf::IntRect normal_button_tex_coords = {
        sf::Vector2i(0, 0),
        sf::Vector2i(static_cast<int>(button_texture_->getSize().x),
                     static_cast<int>(button_texture_->getSize().y) / 2)
    };

    const sf::IntRect hovered_button_tex_coords = {
        sf::Vector2i(0, static_cast<int>(button_texture_->getSize().y) / 2),
        sf::Vector2i(static_cast<int>(button_texture_->getSize().x),
                     static_cast<int>(button_texture_->getSize().y) / 2)
    };

    buttons_.push_back(ButtonBuilder()
        .backgroundTexture(button_texture_, normal_button_tex_coords)
        .hoverBackgroundTexCoords(hovered_button_tex_coords)
        .text("PLAY", font_)
        .transform(120, 300, 200, 80)
        .callback([this] {
            std::cout << "Play" << std::endl;
            event_bus_->postpone(
                Events::ChangeScreen{.from = Screens::MainMenu, .to = Screens::None});
        }).build());

    buttons_.push_back(ButtonBuilder()
        .backgroundTexture(button_texture_, normal_button_tex_coords)
        .hoverBackgroundTexCoords(hovered_button_tex_coords)
        .text("OPTIONS", font_)
        .transform(120, 400, 200, 80)
        .callback([this] {
            std::cout << "Options" << std::endl;
            event_bus_->postpone(
                Events::ChangeScreen{.from = Screens::MainMenu, .to = Screens::OptionsMenu});
        }).build());

    buttons_.push_back(ButtonBuilder()
        .backgroundTexture(button_texture_, normal_button_tex_coords)
        .hoverBackgroundTexCoords(hovered_button_tex_coords)
        .text("EXIT", font_)
        .transform(120, 600, 200, 80)
        .callback([this] {
            std::cout << "Exit" << std::endl;
            event_bus_->postpone(Events::CloseGame{});
        }).build());

    std::cout << "Created MainMenuScreen!" << std::endl;
}

void MainMenuScreen::onMouseMove(const sf::Event::MouseMoveEvent& event) {
    for (const auto& button: buttons_) {
        button->onMouseMoved(event);
    }
}

void MainMenuScreen::onMousePressed(const sf::Event::MouseButtonEvent& event) {
    for (const auto& button: buttons_) {
        button->onMouseButtonPressed(event);
    }
}

void MainMenuScreen::onMouseReleased(const sf::Event::MouseButtonEvent& event) {
    for (const auto& button: buttons_) {
        button->onMouseButtonReleased(event);
    }
}

void MainMenuScreen::render(std::shared_ptr<sf::RenderWindow> window) const {
    sf::Vector2 window_size = window->getSize();

    auto background = sf::RectangleShape(sf::Vector2f(window_size));
    background.setTexture(background_texture_.get());
    window->draw(background);

    sf::Text mainText;
    mainText.setFont(*font_);
    mainText.setString("RASHNAWA");
    mainText.setFillColor(sf::Color::Black);
    mainText.setStyle(sf::Text::Style::Bold);
    mainText.setCharacterSize(100);

    float x =
            static_cast<float>(window_size.x) / 2.0f - mainText.getLocalBounds().width / 2.0f
            - mainText.getLocalBounds().left / 2.0f;
    float y =
            static_cast<float>(window_size.y) / 7.0f - (mainText.getLocalBounds().height / 2.0f)
            - (mainText.getLocalBounds().top / 2.0f);

    mainText.setPosition(x, y);

    window->draw(mainText);

    for (const auto& button: buttons_) {
        window->draw(*button);
    }
}
