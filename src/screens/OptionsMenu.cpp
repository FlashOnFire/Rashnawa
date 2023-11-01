#include "OptionsMenu.h"

#include <utility>

OptionsMenu::OptionsMenu(std::shared_ptr<dexode::EventBus> eventBus) : _eventBus(std::move(eventBus)) {
}

void OptionsMenu::update(const sf::Event &e) {
}

void OptionsMenu::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
    sf::Text txt;
    txt.setString("Options");
    txt.setFont(font);
    txt.setFillColor(sf::Color::Black);
    txt.setPosition(100, 100);

    window->draw(txt);
}
