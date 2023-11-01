#ifndef RASHNAWA_OPTIONSMENUSCREEN_H
#define RASHNAWA_OPTIONSMENUSCREEN_H


#include "objects/BasicScreen.h"
#include "dexode/EventBus.hpp"
#include "../audio/AudioManager.h"

class OptionsMenuScreen: public BasicScreen {
public:
    explicit OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus);

    void update(const sf::Event &e) override;

    void render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const override;
private:
    const std::shared_ptr<dexode::EventBus> _eventBus;
    std::unique_ptr<dexode::EventBus::Listener> _eventListener;

    const std::unique_ptr<sf::Texture> backgroundTexture = std::make_unique<sf::Texture>();
};


#endif //RASHNAWA_OPTIONSMENUSCREEN_H
