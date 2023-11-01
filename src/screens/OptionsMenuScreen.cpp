#include "OptionsMenuScreen.h"
#include "../events/Events.h"

#include <utility>

OptionsMenuScreen::OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, const sf::Font &font,
                                     const sf::Vector2<unsigned int> &windowSize) : _eventBus(std::move(eventBus)), _font(font) {
    if (!backgroundTexture->loadFromFile("../assets/menu/newfont.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }
    backgroundTexture->setSmooth(true);

    if (!titleBackground->loadFromFile("../assets/menu/newfont.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!optionsBackgroundTexture->loadFromFile("../assets/menu/options/background.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!sliderTexture->loadFromFile("../assets/menu/options/slider.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!sliderKnobTexture->loadFromFile("../assets/menu/options/sliderknob.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }


    titleText.setString("Options");
    titleText.setFont(font);
    titleText.setCharacterSize(65);
    titleText.setFillColor(sf::Color::Black);

    background = sf::RectangleShape();
    background.setTexture(backgroundTexture.get());

    optionsBackground.setTexture(optionsBackgroundTexture.get());

    positionComponents(windowSize);

    _eventListener = std::make_unique<dexode::EventBus::Listener>(_eventBus);
    _eventListener->listen<Events::EscapeBtn>([this](const Events::EscapeBtn &e) {
        _eventBus->postpone<Events::ChangeScreen>({.from = Screens::OptionsMenu, .to = Screens::MainMenu});
    });

    std::cout << "Created OptionsMenuScreen!" << std::endl;
}

void OptionsMenuScreen::positionComponents(const sf::Vector2<unsigned int> &windowSize) {
    background.setSize(sf::Vector2f(windowSize));

    titleText.setPosition(
            (float) windowSize.x / 2.0f - titleText.getLocalBounds().width / 2.0f - titleText.getLocalBounds().left,
            (float) windowSize.y / 10.0f - titleText.getLocalBounds().height / 2.0f - titleText.getLocalBounds().top);

    optionsBackground.setPosition(windowSize.x /2.0f, 200);
    optionsBackground.setSize(sf::Vector2f(200, 200));
}

void OptionsMenuScreen::render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const {
    window->draw(background);
    window->draw(titleText);
    window->draw(optionsBackground);

}
