#ifndef RASHNAWA_BUTTONBUILDER_H
#define RASHNAWA_BUTTONBUILDER_H

#include <memory>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <functional>
#include "Button.h"

class ButtonBuilder {
private:
    std::unique_ptr<Button> _button = std::unique_ptr<Button>(new Button());
public:
    ButtonBuilder &texture(std::shared_ptr<sf::Texture> texture, const sf::IntRect &texCoords);

    ButtonBuilder &texture(std::shared_ptr<sf::Texture> texture, const sf::Vector2i &texCoordsPosition,
                           const sf::Vector2i &texCoordsSize);

    ButtonBuilder &texture(std::shared_ptr<sf::Texture> texture, int x, int y, int dx, int dy);

    ButtonBuilder &hoverTexCoords(const sf::IntRect &texCoords);

    ButtonBuilder &hoverTexCoords(const sf::Vector2i &hoverTexCoordsPos, const sf::Vector2i &hoverTexCoordsSize);

    ButtonBuilder &hoverTexCoords(int x, int y, int dx, int dy);

    ButtonBuilder &text(const std::string &text, const std::shared_ptr<sf::Font> &font);

    ButtonBuilder &callback(std::function<void()> callback);

    ButtonBuilder &transform(sf::Vector2f position, sf::Vector2f size);

    ButtonBuilder &transform(float x, float y, float dx, float dy);

    std::unique_ptr<Button> build();

};


#endif //RASHNAWA_BUTTONBUILDER_H
