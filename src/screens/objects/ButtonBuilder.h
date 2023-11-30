#ifndef RASHNAWA_BUTTONBUILDER_H
#define RASHNAWA_BUTTONBUILDER_H

#include <memory>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <functional>
#include "dexode/EventBus.hpp"

#include "Button.h"

class ButtonBuilder {
private:
    std::unique_ptr<Button> _button = std::unique_ptr<Button>(new Button());
public:
    ButtonBuilder &backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::IntRect &texCoords);

    ButtonBuilder &backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::Vector2i &texCoordsPosition,
                                     const sf::Vector2i &texCoordsSize);

    ButtonBuilder &
    backgroundTexture(std::shared_ptr<sf::Texture> texture, const int x, const int y, const int dx, const int dy);

    ButtonBuilder &foregroundTexture(std::shared_ptr<sf::Texture> texture);

    ButtonBuilder &hoverBackgroundTexCoords(const sf::IntRect &texCoords);

    ButtonBuilder &
    hoverBackgroundTexCoords(const sf::Vector2i &hoverTexCoordsPos, const sf::Vector2i &hoverTexCoordsSize);

    ButtonBuilder &hoverBackgroundTexCoords(int x, int y, int dx, int dy);

    ButtonBuilder &clickedBackgroundTexCoords(const sf::IntRect &texCoords);

    ButtonBuilder &
    clickedBackgroundTexCoords(const sf::Vector2i &hoverTexCoordsPos, const sf::Vector2i &hoverTexCoordsSize);

    ButtonBuilder &clickedTexCoords(int x, int y, int dx, int dy);

    ButtonBuilder &text(const std::string &text, const std::shared_ptr<sf::Font> &font);

    ButtonBuilder &callback(std::function<void()> callback);

    ButtonBuilder &transform(sf::Vector2f position, sf::Vector2f size);

    ButtonBuilder &transform(float x, float y, float dx, float dy);

    ButtonBuilder &
    animation(const std::shared_ptr<dexode::EventBus> &eventBus, const std::string &name, int normalTimeline,
              int hoveredTimeline, int clickedTimeline);

    std::unique_ptr<Button> build();
};


#endif //RASHNAWA_BUTTONBUILDER_H
