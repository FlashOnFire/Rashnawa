#include <cassert>
#include "ButtonBuilder.h"

ButtonBuilder::ButtonBuilder() {
    _button = std::unique_ptr<Button>(new Button());
}

ButtonBuilder &ButtonBuilder::texture(std::shared_ptr<sf::Texture> texture) {
    assert(_button->_fillMode == FillMode::None);

    _button->_fillMode = FillMode::Texture;
    _button->setTexture(std::move(texture));
    return *this;
}

ButtonBuilder &ButtonBuilder::text(const std::string& text, std::shared_ptr<sf::Font> font) {
    _button->_text = sf::Text(text, *font, 45);

    return *this;
}

ButtonBuilder &ButtonBuilder::callback(std::function<void()> callback) {
    _button->_callback = std::move(callback);

    return *this;
}

ButtonBuilder &ButtonBuilder::transform(const sf::Vector2f position, const sf::Vector2f size) {
    _button->setTransform(position, size);
    return *this;
}

ButtonBuilder &ButtonBuilder::transform(const float x, const float y, const float dx, const float dy) {
    _button->setTransform(sf::Vector2f(x, y), sf::Vector2f(dx, dy));
    return *this;
}

std::unique_ptr<Button> ButtonBuilder::build() {
    assert(_button->fillColor != FillMode::None);

    if (_button->_fillMode == FillMode::Texture) {
        _button->updateTextureRect();
    }

    // hack
    if (_button->_text.has_value()) {
        _button->updateTextTransform();
    }

    return std::move(_button);
}

