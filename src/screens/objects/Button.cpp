#include "Button.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Button::Button(const float x, const float y, const float dx, const float dy, std::shared_ptr<sf::Texture> texture,
               const std::function<void()> &callback) : _texture(std::move(texture)),
                                                        _callback(
                                                                callback) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(dx, dy));
    shape.setTexture(_texture.get());

    updateTextureRect();
}

Button::Button(std::shared_ptr<sf::Texture> texture, const std::function<void()> &callback) : _texture(
        std::move(texture)), _callback(callback) {
    shape.setTexture(_texture.get());
    updateTextureRect();
}

void Button::mouseMoved(sf::Event::MouseMoveEvent e) {
    const auto pos = sf::Vector2i(shape.getPosition());
    const auto size = sf::Vector2i(shape.getSize());

    if (_hovered != (e.x > pos.x && e.x < (pos.x + size.x)
        && e.y > pos.y && e.y < (pos.y + size.y))) {
        _hovered = !_hovered;
        updateTextureRect();
    }
}

void Button::mouseButtonPressed(sf::Event::MouseButtonEvent e) {
    if (e.button != sf::Mouse::Button::Left)
        return;

    const auto pos = sf::Vector2i(shape.getPosition());
    const auto size = sf::Vector2i(shape.getSize());

    if (e.x > pos.x && e.x < (pos.x + size.x)
        && e.y > pos.y && e.y < (pos.y + size.y)) {
        _callback();
    }
}

void Button::updateTextureRect() {
    const auto textureSize = _texture->getSize();
    const auto position = sf::Vector2i(0, _hovered ? 0 : (int) textureSize.y / 2);

    const auto size = sf::Vector2i((int) textureSize.x, (int) textureSize.y / 2);

    shape.setTextureRect(sf::IntRect(position, size));
}

bool Button::isHovered() const {
    return _hovered;
}

sf::Vector2f Button::getPosition() const {
    return shape.getPosition();
}

void Button::setPosition(const sf::Vector2f &pos) {
    shape.setPosition(pos);
}

sf::Vector2f Button::getSize() const {
    return shape.getSize();
}

void Button::setSize(const sf::Vector2f &size) {
    shape.setSize(size);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(shape);
}
