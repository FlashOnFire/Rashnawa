#include <cassert>
#include <utility>
#include "ButtonBuilder.h"

ButtonBuilder::ButtonBuilder() {
    _button = std::unique_ptr<Button>(new Button());
}

ButtonBuilder &
ButtonBuilder::texture(std::shared_ptr<sf::Texture> texture, const sf::IntRect &texCoords) {
    assert(_button->_fillMode == FillMode::None);

    _button->_fillMode = FillMode::Texture;
    _button->setTexture(std::move(texture));

    _button->_normalStateTexCoords = texCoords;

    return *this;
}

ButtonBuilder &ButtonBuilder::texture(std::shared_ptr<sf::Texture> texture, const sf::Vector2i &texCoordsPosition,
                                      const sf::Vector2i &texCoordsSize) {
    return ButtonBuilder::texture(std::move(texture), {texCoordsPosition, texCoordsSize});
}

ButtonBuilder &
ButtonBuilder::texture(std::shared_ptr<sf::Texture> texture, const int x, const int y, const int dx, const int dy) {
    return ButtonBuilder::texture(std::move(texture), sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder &ButtonBuilder::hoverTexCoords(const sf::IntRect &texCoords) {
    _button->_hoverStateTexCoords = texCoords;
    return *this;
}

ButtonBuilder &
ButtonBuilder::hoverTexCoords(const sf::Vector2i &hoverTexCoordsPos, const sf::Vector2i &hoverTexCoordsSize) {
    return ButtonBuilder::hoverTexCoords({hoverTexCoordsPos, hoverTexCoordsSize});
}

ButtonBuilder &ButtonBuilder::hoverTexCoords(int x, int y, int dx, int dy) {
    return ButtonBuilder::hoverTexCoords(sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder &ButtonBuilder::text(const std::string &text, const std::shared_ptr<sf::Font> &font) {
    _button->_text = sf::Text(text, *font, 45);
    _button->_text->setFillColor(sf::Color::Black);

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

    if (_button->_text.has_value()) {
        _button->updateTextTransform();
    }

    return std::move(_button);
}
