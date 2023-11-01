#ifndef RASHNAWA_OPTIONSMENU_H
#define RASHNAWA_OPTIONSMENU_H


#include "objects/BasicScreen.h"
#include "dexode/EventBus.hpp"
#include "../audio/AudioManager.h"

class OptionsMenu: public BasicScreen {
public:
    explicit OptionsMenu(std::shared_ptr<dexode::EventBus> eventBus);

    void update(const sf::Event &e) override;

    void render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const override;
private:
    std::shared_ptr<dexode::EventBus> _eventBus;

    const std::unique_ptr<sf::Texture> backgroundTexture = std::make_unique<sf::Texture>();
};


#endif //RASHNAWA_OPTIONSMENU_H
