#ifndef RASHNAWA_BASICSCREEN_H
#define RASHNAWA_BASICSCREEN_H

#include <memory>
#include <dexode/EventBus.hpp>

#include <SFML/Graphics.hpp>

class BasicScreen {
public:
    virtual ~BasicScreen();

    virtual void onMouseMove(const sf::Event::MouseMoveEvent& event);

    virtual void onMousePressed(const sf::Event::MouseButtonEvent& event);

    virtual void onMouseReleased(const sf::Event::MouseButtonEvent& event);

    virtual void onWindowResize(const sf::Event::SizeEvent& event);

    virtual void render(std::shared_ptr<sf::RenderWindow> window) const = 0;

protected:
    const std::shared_ptr<dexode::EventBus> event_bus_;
    const std::unique_ptr<dexode::EventBus::Listener> event_listener_;

    const std::shared_ptr<sf::Font> font_;

    explicit BasicScreen(std::shared_ptr<dexode::EventBus>, std::shared_ptr<sf::Font> font);
};


#endif //RASHNAWA_BASICSCREEN_H
