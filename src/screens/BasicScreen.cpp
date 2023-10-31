#include <iostream>
#include "BasicScreen.h"

BasicScreen::~BasicScreen() {
}

void BasicScreen::update(const sf::Event &e) {
    std::cout << "basic screen update" << std::endl;
}

void BasicScreen::render(std::shared_ptr<sf::RenderWindow>, const sf::Font &font) const {
    std::cout << "basic screen render" << std::endl;
}
