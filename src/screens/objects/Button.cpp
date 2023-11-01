#include "Button.h"

#include <utility>

Button::Button(const int x, const int y, const int dx, const int dy, std::string text,
               const std::function<void()> &callback) : _x(x), _y(y),
                                                        _dx(dx),
                                                        _dy(dy),
                                                        _text(std::move(text)),
                                                        _callback(
                                                                callback) {
}

void Button::mouseMoved(sf::Event::MouseMoveEvent e) {
    _hovered = e.x > _x && e.x < (_x + _dx)
               && e.y > _y && e.y < (_y + _dy);
}

void Button::mouseButtonPressed(sf::Event::MouseButtonEvent e) {
    _hovered = e.x > _x && e.x < (_x + _dx)
               && e.y > _y && e.y < (_y + _dy);

    if (e.button != sf::Mouse::Button::Left)
        return;

    if (e.x > _x && e.x < (_x + _dx)
        && e.y > _y && e.y < (_y + _dy)) {
        _callback();
    }
}

bool Button::isHovered() const {
    return _hovered;
}

int Button::getX() const {
    return _x;
}

int Button::getY() const {
    return _y;
}

int Button::getDx() const {
    return _dx;
}

int Button::getDy() const {
    return _dy;
}

const std::string &Button::getText() const {
    return _text;
}
