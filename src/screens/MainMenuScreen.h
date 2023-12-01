#ifndef RASHNAWA_MAINMENUSCREEN_H
#define RASHNAWA_MAINMENUSCREEN_H

#include "objects/BasicScreen.h"
#include "objects/Button.h"
#include "../audio/AudioManager.h"
#include "dexode/EventBus.hpp"

class MainMenuScreen : public BasicScreen {
public:
    explicit MainMenuScreen(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<sf::Font> font);

    void onMouseMove(const sf::Event::MouseMoveEvent& event) override;

    void onMousePressed(const sf::Event::MouseButtonEvent& event) override;

    void onMouseReleased(const sf::Event::MouseButtonEvent& event) override;

    void render(std::shared_ptr<sf::RenderWindow> window) const override;

private:
    const std::shared_ptr<dexode::EventBus> event_bus_;
    std::unique_ptr<dexode::EventBus::Listener> event_listener_;

    std::vector<std::unique_ptr<Button>> buttons_;

    const std::unique_ptr<sf::Texture> background_texture_ = std::make_unique<sf::Texture>();
    const std::shared_ptr<sf::Texture> button_texture_ = std::make_shared<sf::Texture>();
};


#endif //RASHNAWA_MAINMENUSCREEN_H
