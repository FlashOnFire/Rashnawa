#ifndef RASHNAWA_MAINMENUSCREEN_H
#define RASHNAWA_MAINMENUSCREEN_H

#include "objects/BasicScreen.h"
#include "objects/Button.h"
#include "../audio/AudioManager.h"
#include "dexode/EventBus.hpp"

class MainMenuScreen : public BasicScreen {
public:
    explicit MainMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::Font> font);

    void onMouseMove(const sf::Event::MouseMoveEvent &event) override;
    void onMousePressed(const sf::Event::MouseButtonEvent &event) override;

    void render(std::shared_ptr<sf::RenderWindow> window) const override;
private:
    const std::shared_ptr<dexode::EventBus> _eventBus;
    std::unique_ptr<dexode::EventBus::Listener> _eventListener;

    std::vector<std::unique_ptr<Button>> _buttons;

    const std::unique_ptr<sf::Texture> backgroundTexture = std::make_unique<sf::Texture>();
    const std::shared_ptr<sf::Texture> buttonTexture = std::make_shared<sf::Texture>();
};


#endif //RASHNAWA_MAINMENUSCREEN_H
