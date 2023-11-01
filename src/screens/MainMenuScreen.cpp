#include <iostream>

#include "../events/Events.h"

#include "MainMenuScreen.h"

MainMenuScreen::MainMenuScreen(std::shared_ptr<dexode::EventBus> eventBus) : _eventBus(std::move(eventBus)) {
    if (!backgroundTexture->loadFromFile("../assets/menu/menufond2.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }
    backgroundTexture->setSmooth(true);

    if (!buttonTexture->loadFromFile("../assets/menu/button.png")) {
        std::cout << "Can't load menu button texture from file";
        exit(EXIT_FAILURE);
    }

    _buttons.emplace_back(std::make_unique<Button>(120, 300, 200, 80, "PLAY", [this]() {
        std::cout << "Play" << std::endl;
        _eventBus->postpone(Events::ChangeScreen{.from = Screens::MainMenu, .to = Screens::None});
    }));

    _buttons.emplace_back(std::make_unique<Button>(120, 400, 200, 80, "OPTIONS", [this]() {
        std::cout << "Options" << std::endl;
        _eventBus->postpone(Events::ChangeScreen{.from = Screens::MainMenu, .to = Screens::OptionsMenu});
    }));

    _buttons.emplace_back(std::make_unique<Button>(120, 600, 200, 80, "EXIT", [this]() {
        std::cout << "Exit" << std::endl;
        _eventBus->postpone(Events::CloseGame{});
    }));

    _eventListener = std::make_unique<dexode::EventBus::Listener>(_eventBus);
    _eventListener->listen<sf::Event::MouseMoveEvent>([this](const sf::Event::MouseMoveEvent &e) {
        for (const auto &button: _buttons) {
            button->mouseMoved(e);
        }
    });

    _eventListener->listen<Events::MouseButtonPressed>([this](const Events::MouseButtonPressed &e) {
        for (const auto &button: _buttons) {
            button->mouseButtonPressed(e.event);
        }
    });

    std::cout << "Created MainMenuScreen!" << std::endl;
}

void MainMenuScreen::update(const sf::Event &e) {
}

void MainMenuScreen::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
    sf::Vector2 wSize = window->getSize();

    auto background = sf::RectangleShape(sf::Vector2f(wSize));
    background.setTexture(backgroundTexture.get());
    window->draw(background);

    sf::Text mainText;
    mainText.setFont(font);
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
        auto shape = sf::RectangleShape(sf::Vector2f((float) button->getDx(), (float) button->getDy()));
        shape.setPosition((float) button->getX(), (float) button->getY());
        shape.setTexture(buttonTexture.get());

        const auto textureSize = buttonTexture->getSize();
        const auto position = sf::Vector2i(button->isHovered() ? 0 : (int) textureSize.x / 2, 0);

        const auto size = sf::Vector2i((int) textureSize.x / 2, (int) textureSize.y);

        shape.setTextureRect(sf::IntRect(position, size));


        window->draw(shape);

        sf::Text text;
        text.setFont(font);
        text.setString(button->getText());
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(45);

        float fontX = (float) button->getX() + (float) button->getDx() / 2.0f - (text.getLocalBounds().width / 2.0f) -
                      text.getLocalBounds().left;
        float fontY = (float) button->getY() + (float) button->getDy() / 2.0f - (text.getLocalBounds().height / 2.0f) -
                      text.getLocalBounds().top;

        text.setPosition(fontX, fontY);

        window->draw(text);
    }
}

