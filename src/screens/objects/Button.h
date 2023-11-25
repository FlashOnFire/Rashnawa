#ifndef RASHNAWA_BUTTON_H
#define RASHNAWA_BUTTON_H

#include <functional>
#include <string>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <optional>
#include "FillMode.h"

class Button : public sf::Drawable {
public:
    void onMouseMoved(const sf::Event::MouseMoveEvent &e);

    void onMouseButtonPressed(const sf::Event::MouseButtonEvent &e);

    void updateTextureRect();

    [[nodiscard]] bool isHovered() const;

    [[nodiscard]] sf::Vector2f getPosition() const;

    [[nodiscard]] sf::Vector2f getSize() const;

    void setTransform(const sf::Vector2f &pos, const sf::Vector2f &size);

    void setTexture(std::shared_ptr<sf::Texture> texture);

private:
    friend class ButtonBuilder;

    Button() = default;

    FillMode _fillMode = FillMode::None;
    std::shared_ptr<sf::Texture> _texture;

    sf::IntRect _normalStateTexCoords;
    std::optional<sf::IntRect> _hoverStateTexCoords;

    std::optional<sf::Text> _text;

    std::optional<std::function<void()>> _callback;

    bool _hovered = false;

    void updateTextTransform();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    sf::RectangleShape _shape;
};


#endif //RASHNAWA_BUTTON_H
