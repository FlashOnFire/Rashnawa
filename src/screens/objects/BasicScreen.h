#ifndef RASHNAWA_BASICSCREEN_H
#define RASHNAWA_BASICSCREEN_H

#include <memory>

#include <SFML/Graphics.hpp>

class BasicScreen {
public:
    virtual ~BasicScreen();

    virtual void onMouseMove(const sf::Event::MouseMoveEvent &event);

    virtual void onMousePressed(const sf::Event::MouseButtonEvent &event);

    virtual void onMouseReleased(const sf::Event::MouseButtonEvent &event);

    virtual void render(std::shared_ptr<sf::RenderWindow> window) const = 0;

protected:
    std::shared_ptr<sf::Font> _font;

    explicit BasicScreen(std::shared_ptr<sf::Font> font);
};


#endif //RASHNAWA_BASICSCREEN_H
