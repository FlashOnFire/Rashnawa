#include <cassert>
#include <utility>
#include "ButtonBuilder.h"
#include "../../events/Events.h"

ButtonBuilder &
ButtonBuilder::backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::IntRect &texCoords) {
    _button->setBackgroundTexture(std::move(texture));

    _button->_backgroundNormalStateTexCoords = texCoords;

    return *this;
}

ButtonBuilder &
ButtonBuilder::backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::Vector2i &texCoordsPosition,
                                 const sf::Vector2i &texCoordsSize) {
    return ButtonBuilder::backgroundTexture(std::move(texture), {texCoordsPosition, texCoordsSize});
}

ButtonBuilder &
ButtonBuilder::backgroundTexture(std::shared_ptr<sf::Texture> texture, const int x, const int y, const int dx,
                                 const int dy) {
    return ButtonBuilder::backgroundTexture(std::move(texture), sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder &
ButtonBuilder::foregroundTexture(std::shared_ptr<sf::Texture> texture) {
    _button->setForegroundTexture(std::move(texture));
    return *this;
}


ButtonBuilder &ButtonBuilder::hoverBackgroundTexCoords(const sf::IntRect &texCoords) {
    _button->_backgroundHoverStateTexCoords = texCoords;
    return *this;
}

ButtonBuilder &
ButtonBuilder::hoverBackgroundTexCoords(const sf::Vector2i &hoverTexCoordsPos, const sf::Vector2i &hoverTexCoordsSize) {
    return ButtonBuilder::hoverBackgroundTexCoords({hoverTexCoordsPos, hoverTexCoordsSize});
}

ButtonBuilder &ButtonBuilder::hoverBackgroundTexCoords(int x, int y, int dx, int dy) {
    return ButtonBuilder::hoverBackgroundTexCoords(sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder &ButtonBuilder::clickedBackgroundTexCoords(const sf::IntRect &texCoords) {
    _button->_backgroundHoverStateTexCoords = texCoords;
    return *this;
}

ButtonBuilder &
ButtonBuilder::clickedBackgroundTexCoords(const sf::Vector2i &hoverTexCoordsPos,
                                          const sf::Vector2i &hoverTexCoordsSize) {
    return ButtonBuilder::hoverBackgroundTexCoords({hoverTexCoordsPos, hoverTexCoordsSize});
}

ButtonBuilder &ButtonBuilder::clickedTexCoords(int x, int y, int dx, int dy) {
    return ButtonBuilder::hoverBackgroundTexCoords(sf::Vector2i(x, y), sf::Vector2i(dx, dy));
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

ButtonBuilder &
ButtonBuilder::animation(std::shared_ptr<dexode::EventBus> eventBus, const std::string &name, const int normalTimeline,
                         const int hoveredTimeline,
                         const int clickedTimeline) {

    std::weak_ptr<Animation> animation = _button->addAnimation(name, ButtonAnimationTimelines{.normal = normalTimeline, .hovered = hoveredTimeline, .clicked = clickedTimeline});
    eventBus->postpone<Events::AnimationCreated>({.animation = animation});

    return *this;
}

std::unique_ptr<Button> ButtonBuilder::build() {
    assert((_button->_animation.has_value() && _button->_foregroundTexture.has_value()) ||
           !_button->_animation.has_value());

    if (_button->_backgroundTexture.has_value()) {
        _button->updateTextureRect();
    }

    if (_button->_text.has_value()) {
        _button->updateTextTransform();
    }

    return std::move(_button);
}
