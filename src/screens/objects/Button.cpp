#include "Button.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

void Button::onMouseMoved(const sf::Event::MouseMoveEvent &e) {
    const auto pos = sf::Vector2i(_backgroundShape.getPosition());

    bool inside = (e.x > pos.x && e.x < (pos.x + (int) _backgroundShape.getSize().x)
                   && e.y > pos.y && e.y < (pos.y + (int) _backgroundShape.getSize().y));

    if (!_hovered && inside) {
        _hovered = true;

        if (_animationTimelines.has_value()) {
            _animation.value()->setTimeline(_clicked ? _animationTimelines->clicked : _animationTimelines->hovered);
        }

        updateTextureRect();
    } else if (_hovered && !inside) {
        _hovered = false;

        if (_animationTimelines.has_value()) {
            _animation.value()->setTimeline(_animationTimelines->normal);
        }

        updateTextureRect();
    }
}

void Button::onMouseButtonPressed(const sf::Event::MouseButtonEvent &e) {
    if (e.button != sf::Mouse::Button::Left)
        return;

    if (_hovered) {
        _clicked = true;

        if (_animationTimelines.has_value()) {
            _animation.value()->setTimeline(_animationTimelines->clicked);
        }

        updateTextureRect();

        if (_callback.has_value()) {
            _callback.value()();
        }
    }
}

void Button::onMouseButtonReleased(const sf::Event::MouseButtonEvent &) {
    if (_clicked) {
        _clicked = false;

        if (_animationTimelines.has_value()) {
            _animation.value()->setTimeline(_hovered ? _animationTimelines->hovered : _animationTimelines->normal);
        }

        updateTextureRect();
    }
}

void Button::updateTextureRect() {
    if (_backgroundTexture.has_value()) {
        if (_clicked) {
            if (_backgroundClickedStateTexCoords.has_value()) {
                _backgroundShape.setTextureRect(_backgroundClickedStateTexCoords.value());
            }
        } else if (_hovered) {
            if (_backgroundHoverStateTexCoords.has_value()) {
                _backgroundShape.setTextureRect(_backgroundHoverStateTexCoords.value());
            }
        } else { // no check needed for normalTexCoords.hasValue() because if background texture has a value, normalTexCoords must also have a value
            _backgroundShape.setTextureRect(_backgroundNormalStateTexCoords.value());
        }
    }
}

void Button::updateTextTransform() {
    float fontX = _backgroundShape.getPosition().x + _backgroundShape.getSize().x / 2.0f -
                  (_text.value().getLocalBounds().width / 2.0f) -
                  _text.value().getLocalBounds().left;
    float fontY = _backgroundShape.getPosition().y + _backgroundShape.getSize().y / 2.0f -
                  (_text.value().getLocalBounds().height / 2.0f) -
                  _text.value().getLocalBounds().top;

    _text.value().setPosition(sf::Vector2f(fontX, fontY));

    //TODO: set characterSize
}

bool Button::isHovered() const {
    return _hovered;
}

sf::Vector2f Button::getPosition() const {
    return _backgroundShape.getPosition();
}

sf::Vector2f Button::getSize() const {
    return _backgroundShape.getSize();
}

void Button::setBackgroundTexture(std::shared_ptr<sf::Texture> texture) {
    _backgroundTexture = std::move(texture);
    _backgroundShape.setTexture(_backgroundTexture.value().get());
}

void Button::setForegroundTexture(std::shared_ptr<sf::Texture> texture) {
    _foregroundTexture = std::move(texture);
    _foregroundShape.setTexture(_foregroundTexture.value().get());
}

void Button::setTransform(const sf::Vector2f &pos, const sf::Vector2f &size) {
    _backgroundShape.setPosition(pos);
    _backgroundShape.setSize(size);

    _foregroundShape.setPosition(pos);
    _foregroundShape.setSize(size);
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (_backgroundTexture.has_value())
        target.draw(_backgroundShape);

    if (_foregroundTexture.has_value())
        target.draw(_foregroundShape);

    if (_text.has_value()) {
        target.draw(_text.value());
    }
}

std::weak_ptr<Animation>
Button::addAnimation(const std::string &name, const ButtonAnimationTimelines &animationTimelines) {
    _animation = std::make_shared<Animation>(name, [this](sf::Vector2i coords, sf::Vector2i size) {
        _foregroundShape.setTextureRect(sf::IntRect(coords, size));
    });

    _animationTimelines = animationTimelines;

    return _animation.value();
}
