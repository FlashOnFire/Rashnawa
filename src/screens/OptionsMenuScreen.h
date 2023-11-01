#ifndef RASHNAWA_OPTIONSMENUSCREEN_H
#define RASHNAWA_OPTIONSMENUSCREEN_H


#include "objects/BasicScreen.h"
#include "dexode/EventBus.hpp"
#include "../audio/AudioManager.h"

class OptionsMenuScreen: public BasicScreen {
public:
    explicit OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, const sf::Font &font, const sf::Vector2<unsigned int> &windowSize);

    void render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const override;
private:
    const std::shared_ptr<dexode::EventBus> _eventBus;
    const sf::Font _font;

    std::unique_ptr<dexode::EventBus::Listener> _eventListener;

    const std::unique_ptr<sf::Texture> backgroundTexture = std::make_unique<sf::Texture>();

    const std::unique_ptr<sf::Texture> titleBackground = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> optionsBackgroundTexture = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> buttonsTexture = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> sliderTexture = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> sliderKnobTexture = std::make_unique<sf::Texture>();

    sf::Text titleText;
    sf::RectangleShape background;
    sf::RectangleShape optionsBackground;

    void positionComponents(const sf::Vector2<unsigned int> &windowSize);
};


#endif //RASHNAWA_OPTIONSMENUSCREEN_H
