#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(const std::weak_ptr<Audio::AudioManager>& audioMgr) {
    if (auto mgr = audioMgr.lock()) {
           music = mgr->getEventInstance("event:/tension");
           music->setVolume(0.3);
           music->start();
    } else {
        std::cout << "Error: AudioManager not loaded?" << std::endl;
        exit(EXIT_FAILURE);
    }

    _buttons.emplace_back(std::make_unique<Button>(120, 200, 200, 80, "PLAY", []() {
        std::cout << "Oui" << std::endl;
    }));

    _buttons.emplace_back(std::make_unique<Button>(120, 300, 200, 80, "EXIT", []() {
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
    sf::Text mainText;
    mainText.setFont(font);
    mainText.setString("RASHNAWA");
    mainText.setFillColor(sf::Color::Black);
    mainText.setStyle(sf::Text::Style::Bold);
    mainText.setCharacterSize(100);

    sf::Vector2 wSize = window->getSize();

    float x = (float) wSize.x / 2.0f -  (mainText.getLocalBounds().width / 2.0f) - (mainText.getLocalBounds().left / 2.0f);
    float y = (float) wSize.y / 7.0f - (mainText.getLocalBounds().height / 2.0f) - (mainText.getLocalBounds().top / 2.0f);

    mainText.setPosition(x, y);


    window->draw(mainText);

    for (const auto &button: _buttons) {
        auto shape = sf::RectangleShape(sf::Vector2f((float) button->getDx(), (float) button->getDy()));
        shape.setPosition((float) button->getX(), (float) button->getY());
        shape.setFillColor((button->isHovered()) ? sf::Color::Blue : sf::Color::Black);

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

