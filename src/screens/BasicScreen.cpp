#include <iostream>
#include "BasicScreen.h"

void BasicScreen::update(const sf::Event &e) {
}

void BasicScreen::render(std::shared_ptr<sf::RenderWindow>, const sf::Font &font) const {
    std::cout << "main menu update" << std::endl;
}
