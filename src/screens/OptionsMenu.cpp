#include "OptionsMenu.h"

#include <utility>

OptionsMenu::OptionsMenu(std::shared_ptr<dexode::EventBus> eventBus) : _eventBus(std::move(eventBus)) {
    if (!backgroundTexture->loadFromFile("../assets/menu/newfont.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }
    backgroundTexture->setSmooth(true);

    std::cout << "Created OptionsMenu!" << std::endl;
}

void OptionsMenu::update(const sf::Event &e) {
}

void OptionsMenu::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
    sf::Vector2 wSize = window->getSize();

    auto background = sf::RectangleShape(sf::Vector2f(wSize));
    background.setTexture(backgroundTexture.get());
    window->draw(background);

    sf::Text txt;
    txt.setString("Options");
    txt.setFont(font);
    txt.setFillColor(sf::Color::Black);
    txt.setPosition(100, 100);

    window->draw(txt);
}
