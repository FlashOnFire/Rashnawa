#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(const std::weak_ptr<Audio::AudioManager>& audioMgr) {
    if (auto mgr = audioMgr.lock()) {
           music = mgr->createEventInstance("event:/tension");
           music->setVolume(0.3);
           music->start();
    } else {
        std::cout << "Error: AudioManager not loaded?" << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!backgroundTexture->loadFromFile("../assets/menu/menufond1.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!buttonTexture->loadFromFile("../assets/menu/button.png")) {
        std::cout << "Can't load menu button texture from file";
        exit(EXIT_FAILURE);
    }

    _buttons.emplace_back(std::make_unique<Button>(120, 300, 200, 80, "PLAY", []() {
        std::cout << "Oui" << std::endl;
    }));

    _buttons.emplace_back(std::make_unique<Button>(120, 400, 200, 80, "EXIT", []() {
        std::cout << "Exit" << std::endl;
    }));
}

void MainMenu::update(const sf::Event &e) {
    if (e.type != sf::Event::MouseButtonPressed && e.type != sf::Event::MouseMoved)
        return;

    for (const auto &button: _buttons) {
        button->update(e);
    }
}

void MainMenu::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
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

    float x = (float) wSize.x / 2.0f -  (mainText.getLocalBounds().width / 2.0f) - (mainText.getLocalBounds().left / 2.0f);
    float y = (float) wSize.y / 7.0f - (mainText.getLocalBounds().height / 2.0f) - (mainText.getLocalBounds().top / 2.0f);

    mainText.setPosition(x, y);


    window->draw(mainText);

    for (const auto &button: _buttons) {
        auto shape = sf::RectangleShape(sf::Vector2f((float) button->getDx(), (float) button->getDy()));
        shape.setPosition((float) button->getX(), (float) button->getY());
        shape.setTexture(buttonTexture.get());

        const auto textureSize = buttonTexture->getSize();
        const auto position = sf::Vector2i(textureSize.x * ((button->isHovered()) ? 0 : 0.5), 0);
        const auto size = sf::Vector2i(textureSize.x / 2, textureSize.y);

        shape.setTextureRect(sf::IntRect(position, size));


        window->draw(shape);

        sf::Text text;
        text.setFont(font);
        text.setString(button->getText());
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(45);

        float x = (float) button->getX() + (float) button->getDx() / 2.0f - (text.getLocalBounds().width / 2.0f) - text.getLocalBounds().left;
        float y = (float) button->getY() + (float) button->getDy() / 2.0f - (text.getLocalBounds().height / 2.0f) - text.getLocalBounds().top;

        text.setPosition(x, y);

        window->draw(text);
    }
}

