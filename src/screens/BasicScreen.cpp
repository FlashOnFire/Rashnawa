#include <iostream>
#include "BasicScreen.h"

void BasicScreen::update(const int deltaT) {

}

void BasicScreen::render(std::shared_ptr<sf::RenderWindow>) const {
    std::cout << "main menu update" << std::endl;
}
