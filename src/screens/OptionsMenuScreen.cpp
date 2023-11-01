#include "OptionsMenuScreen.h"
#include "../events/Events.h"

#include <utility>

OptionsMenuScreen::OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus) : _eventBus(std::move(eventBus)) {
    if (!backgroundTexture->loadFromFile("../assets/menu/newfont.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }
    backgroundTexture->setSmooth(true);

    std::cout << "Created OptionsMenuScreen!" << std::endl;

    _eventListener = std::make_unique<dexode::EventBus::Listener>(_eventBus);
    _eventListener->listen<Events::EscapeBtn>([this](const Events::EscapeBtn &e) {
        _eventBus->postpone<Events::ChangeScreen>({.from = Screens::OptionsMenu, .to = Screens::MainMenu});
    });
}

void OptionsMenuScreen::update(const sf::Event &e) {
}

void OptionsMenuScreen::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
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
