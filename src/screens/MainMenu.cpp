#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu() {
    _buttons.emplace_back(500, 100, 200, 100, "PLAY", []() {
        std::cout << "Oui" << std::endl;
    });
}

void MainMenu::update(const sf::Event &e) {
    if (e.type != sf::Event::MouseButtonPressed && e.type != sf::Event::MouseMoved)
        return;

    for (auto &button: _buttons) {
        button.update(e);
    }
}

void MainMenu::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
    for (const auto &button: _buttons) {
        auto shape = sf::RectangleShape(sf::Vector2f((float) button.getDx(), (float) button.getDy()));
        shape.setPosition((float) button.getX(), (float) button.getY());
        shape.setFillColor((button.isHovered()) ? sf::Color::Blue : sf::Color::Black);

        window->draw(shape);

        sf::Text text;
        text.setFont(font);
        text.setString(button.getText());
        text.setFillColor(sf::Color::Yellow);
        text.setCharacterSize(65);

        float x = (float) button.getX() + (float) button.getDx() / 2.0f - (text.getLocalBounds().width / 2.0f) - text.getLocalBounds().left;
        float y = (float) button.getY() + (float) button.getDy() / 2.0f - (text.getLocalBounds().height / 2.0f) - text.getLocalBounds().top;

        text.setPosition(x, y);

        window->draw(text);
    }
}

