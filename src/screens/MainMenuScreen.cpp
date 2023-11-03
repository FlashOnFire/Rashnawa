#include <iostream>

#include "../events/Events.h"

#include "MainMenuScreen.h"
#include "objects/TextButton.h"

MainMenuScreen::MainMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::Font> font) : BasicScreen(std::move(font)), _eventBus(std::move(eventBus)), _eventListener(std::make_unique<dexode::EventBus::Listener>(_eventBus)) {
    if (!backgroundTexture->loadFromFile("../assets/menu/menufond2.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }
    backgroundTexture->setSmooth(true);

    if (!buttonTexture->loadFromFile("../assets/menu/button.png")) {
        std::cout << "Can't load menu button texture from file";
        exit(EXIT_FAILURE);
    }

    _buttons.emplace_back(std::make_unique<TextButton>(120, 300, 200, 80, "PLAY", _font, buttonTexture, [this]() {
        std::cout << "Play" << std::endl;
        _eventBus->postpone(Events::ChangeScreen{.from = Screens::MainMenu, .to = Screens::None});
    }));

    _buttons.emplace_back(std::make_unique<TextButton>(120, 400, 200, 80, "OPTIONS", _font, buttonTexture, [this]() {
        std::cout << "Options" << std::endl;
        _eventBus->postpone(Events::ChangeScreen{.from = Screens::MainMenu, .to = Screens::OptionsMenu});
    }));

    _buttons.emplace_back(std::make_unique<TextButton>(120, 600, 200, 80, "EXIT", _font, buttonTexture, [this]() {
        std::cout << "Exit" << std::endl;
        _eventBus->postpone(Events::CloseGame{});
    }));

    std::cout << "Created MainMenuScreen!" << std::endl;
}

void MainMenuScreen::onMouseMove(const sf::Event::MouseMoveEvent &event) {
    for (const auto &button: _buttons) {
        button->mouseMoved(event);
    }
}

void MainMenuScreen::onMousePressed(const sf::Event::MouseButtonEvent &event) {
    for (const auto &button: _buttons) {
        button->mouseButtonPressed(event);
    }
}

void MainMenuScreen::render(std::shared_ptr<sf::RenderWindow> window) const {
    sf::Vector2 wSize = window->getSize();

    auto background = sf::RectangleShape(sf::Vector2f(wSize));
    background.setTexture(backgroundTexture.get());
    window->draw(background);

    sf::Text mainText;
    mainText.setFont(*_font);
    mainText.setString("RASHNAWA");
    mainText.setFillColor(sf::Color::Black);
    mainText.setStyle(sf::Text::Style::Bold);
    mainText.setCharacterSize(100);

    float x =
            (float) wSize.x / 2.0f - (mainText.getLocalBounds().width / 2.0f) - (mainText.getLocalBounds().left / 2.0f);
    float y =
            (float) wSize.y / 7.0f - (mainText.getLocalBounds().height / 2.0f) - (mainText.getLocalBounds().top / 2.0f);

    mainText.setPosition(x, y);

    window->draw(mainText);

    for (const auto &button: _buttons) {
        window->draw(*button);
    }
}
