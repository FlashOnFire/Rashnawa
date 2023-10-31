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

void Button::update(const sf::Event e) {
    switch (e.type) {
        case sf::Event::EventType::MouseMoved:
            _hovered = e.mouseMove.x > _x && e.mouseMove.x < (_x + _dx)
                       && e.mouseMove.y > _y && e.mouseMove.y < (_y + _dy);
            break;
        case sf::Event::EventType::MouseButtonPressed:
            if (e.mouseButton.button != sf::Mouse::Button::Left)
                return;

            if (e.mouseButton.x > _x && e.mouseButton.x < (_x + _dx)
                       && e.mouseButton.y > _y && e.mouseButton.y < (_y + _dy)) {
                _callback();
            }
            break;
        default:
            break;
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
