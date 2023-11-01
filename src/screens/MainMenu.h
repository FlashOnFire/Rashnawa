#ifndef RASHNAWA_MAINMENU_H
#define RASHNAWA_MAINMENU_H

#include "objects/BasicScreen.h"
#include "objects/Button.h"
#include "../audio/AudioManager.h"
#include "dexode/EventBus.hpp"

class MainMenu : public BasicScreen {
public:
    explicit MainMenu(std::shared_ptr<dexode::EventBus> eventBus, const std::shared_ptr<Audio::AudioManager>& audioMgr);

    void update(const sf::Event &e) override;

    void render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const override;

private:
    std::shared_ptr<dexode::EventBus> _eventBus;

    std::vector<std::unique_ptr<Button>> _buttons;
    std::unique_ptr<Audio::EventInstance> music;

    const std::unique_ptr<sf::Texture> backgroundTexture = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> buttonTexture = std::make_unique<sf::Texture>();
};


#endif //RASHNAWA_MAINMENU_H
