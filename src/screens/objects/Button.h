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
#include "../../graphics/Animations.h"

struct ButtonAnimationTimelines {
    int normal = 0;
    int hovered = 0;
    int clicked = 0;
};

class Button : public sf::Drawable {
public:
    void onMouseMoved(const sf::Event::MouseMoveEvent &e);

    void onMouseButtonPressed(const sf::Event::MouseButtonEvent &e);

    void updateTextureRect();

    [[nodiscard]] bool isHovered() const;

    [[nodiscard]] sf::Vector2f getPosition() const;

    [[nodiscard]] sf::Vector2f getSize() const;

    void setTransform(const sf::Vector2f &pos, const sf::Vector2f &size);

    void setBackgroundTexture(std::shared_ptr<sf::Texture> texture);

    void setForegroundTexture(std::shared_ptr<sf::Texture> texture);

private:
    friend class ButtonBuilder;

    Button() = default;

    sf::RectangleShape _backgroundShape;
    sf::RectangleShape _foregroundShape;

    std::optional<std::shared_ptr<sf::Texture>> _backgroundTexture;
    std::optional<std::shared_ptr<sf::Texture>> _foregroundTexture;

    std::optional<sf::IntRect> _backgroundNormalStateTexCoords;
    std::optional<sf::IntRect> _backgroundHoverStateTexCoords;
    std::optional<sf::IntRect> _backgroundClickedStateTexCoords;

    std::optional<std::shared_ptr<Animation>> _animation;
    std::optional<ButtonAnimationTimelines> _animationTimelines;

    std::optional<sf::Text> _text;

    std::optional<std::function<void()>> _callback;

    bool _hovered = false;

    std::weak_ptr<Animation> addAnimation(const std::string &name, const ButtonAnimationTimelines &animationTimelines);

    void updateTextTransform();

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_BUTTON_H
