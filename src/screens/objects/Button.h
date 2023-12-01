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
    void onMouseMoved(const sf::Event::MouseMoveEvent& e);

    void onMouseButtonPressed(const sf::Event::MouseButtonEvent& event);

    void onMouseButtonReleased(const sf::Event::MouseButtonEvent& event);

    void updateTextureRect();

    [[nodiscard]] bool isHovered() const;

    [[nodiscard]] sf::Vector2f getPosition() const;

    [[nodiscard]] sf::Vector2f getSize() const;

    void setTransform(const sf::Vector2f& pos, const sf::Vector2f& size);

    void setBackgroundTexture(std::shared_ptr<sf::Texture> texture);

    void setForegroundTexture(std::shared_ptr<sf::Texture> texture);

private:
    friend class ButtonBuilder;

    Button() = default;

    sf::RectangleShape background_shape_;
    sf::RectangleShape foreground_shape_;

    std::optional<std::shared_ptr<sf::Texture>> background_texture_;
    std::optional<std::shared_ptr<sf::Texture>> foreground_texture_;

    std::optional<sf::IntRect> background_normal_state_tex_coords_;
    std::optional<sf::IntRect> background_hover_state_tex_coords_;
    std::optional<sf::IntRect> background_clicked_state_tex_coords_;

    std::optional<std::shared_ptr<Animation>> animation_;
    std::optional<ButtonAnimationTimelines> animation_timelines_;

    std::optional<sf::Text> text_;

    std::optional<std::function<void()>> callback_;

    bool hovered_ = false;
    bool clicked_ = false;

    std::weak_ptr<Animation> addAnimation(const std::string& name, const ButtonAnimationTimelines& animation_timelines);

    void updateTextTransform();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_BUTTON_H
