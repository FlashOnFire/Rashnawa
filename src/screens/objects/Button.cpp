#include "Button.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

void Button::onMouseMoved(const sf::Event::MouseMoveEvent &e) {
    const auto pos = sf::Vector2i(_shape.getPosition());
    const auto size = sf::Vector2i(_shape.getSize());

    if (_hovered != (e.x > pos.x && e.x < (pos.x + size.x)
        && e.y > pos.y && e.y < (pos.y + size.y))) {
        _hovered = !_hovered;
        updateTextureRect();
    }
}

void Button::onMouseButtonPressed(const sf::Event::MouseButtonEvent &e) {
    if (e.button != sf::Mouse::Button::Left)
        return;

    const auto pos = sf::Vector2i(_shape.getPosition());
    const auto size = sf::Vector2i(_shape.getSize());

    if (_callback.has_value()) {
        if (e.x > pos.x && e.x < (pos.x + size.x)
            && e.y > pos.y && e.y < (pos.y + size.y)) {

            _callback.value()();
        }
    }
}

void Button::updateTextureRect() {
    const auto textureSize = _texture->getSize();
    const auto position = sf::Vector2i(0, _hovered ? 0 : (int) textureSize.y / 2);

    const auto size = sf::Vector2i((int) textureSize.x, (int) textureSize.y / 2);

    _shape.setTextureRect(sf::IntRect(position, size));
}

void Button::updateTextTransform() {
    float fontX = (float) _shape.getPosition().x + (float) _shape.getSize().x / 2.0f - (_text.value().getLocalBounds().width / 2.0f) -
                  _text.value().getLocalBounds().left;
    float fontY = (float) _shape.getPosition().y + (float) _shape.getSize().y / 2.0f - (_text.value().getLocalBounds().height / 2.0f) -
                  _text.value().getLocalBounds().top;

    _text.value().setPosition(sf::Vector2f(fontX, fontY));

    //TODO: set characterSize
}

bool Button::isHovered() const {
    return _hovered;
}

sf::Vector2f Button::getPosition() const {
    return _shape.getPosition();
}

sf::Vector2f Button::getSize() const {
    return _shape.getSize();
}

void Button::setTransform(const sf::Vector2f &pos, const sf::Vector2f &size) {
    _shape.setPosition(pos);
    _shape.setSize(size);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(_shape);

    if (_text.has_value()) {
        target.draw(_text.value());
    }
}

void Button::setTexture(std::shared_ptr<sf::Texture> texture) {
    _texture = std::move(texture);
    _shape.setTexture(_texture.get());
}
