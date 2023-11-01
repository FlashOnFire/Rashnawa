#ifndef RASHNAWA_BUTTON_H
#define RASHNAWA_BUTTON_H

#include <functional>
#include <string>

#include <SFML/Window/Event.hpp>

class Button {
public:
    Button(int x, int y, int dx, int dy, std::string text,
           const std::function<void()> &callback);

    void mouseMoved(sf::Event::MouseMoveEvent e);

    void mouseButtonPressed(sf::Event::MouseButtonEvent e);

    [[nodiscard]] int getX() const;

    [[nodiscard]] int getY() const;

    [[nodiscard]] int getDx() const;

    [[nodiscard]] int getDy() const;

    [[nodiscard]] const std::string &getText() const;

    [[nodiscard]] bool isHovered() const;

private:
    const int _x, _y, _dx, _dy;
    const std::string _text;
    const std::function<void()> _callback;

    bool _hovered = false;
};


#endif //RASHNAWA_BUTTON_H
