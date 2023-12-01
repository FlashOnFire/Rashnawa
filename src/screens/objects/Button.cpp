#include "Button.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

void Button::onMouseMoved(const sf::Event::MouseMoveEvent& e) {
    const auto pos = sf::Vector2i(background_shape_.getPosition());

    const bool inside = (e.x > pos.x && e.x < (pos.x + static_cast<int>(background_shape_.getSize().x))
                         && e.y > pos.y && e.y < (pos.y + static_cast<int>(background_shape_.getSize().y)));

    if (!hovered_ && inside) {
        hovered_ = true;

        if (animation_timelines_.has_value()) {
            animation_.value()->setTimeline(clicked_ ? animation_timelines_->clicked : animation_timelines_->hovered);
        }

        updateTextureRect();
    } else if (hovered_ && !inside) {
        hovered_ = false;

        if (animation_timelines_.has_value()) {
            animation_.value()->setTimeline(animation_timelines_->normal);
        }

        updateTextureRect();
    }
}

void Button::onMouseButtonPressed(const sf::Event::MouseButtonEvent& event) {
    if (event.button != sf::Mouse::Button::Left)
        return;

    if (hovered_) {
        clicked_ = true;

        if (animation_timelines_.has_value()) {
            animation_.value()->setTimeline(animation_timelines_->clicked);
        }

        updateTextureRect();

        if (callback_.has_value()) {
            callback_.value()();
        }
    }
}

void Button::onMouseButtonReleased(const sf::Event::MouseButtonEvent&) {
    if (clicked_) {
        clicked_ = false;

        if (animation_timelines_.has_value()) {
            animation_.value()->setTimeline(hovered_ ? animation_timelines_->hovered : animation_timelines_->normal);
        }

        updateTextureRect();
    }
}

void Button::updateTextureRect() {
    if (background_texture_.has_value()) {
        if (clicked_) {
            if (background_clicked_state_tex_coords_.has_value()) {
                background_shape_.setTextureRect(background_clicked_state_tex_coords_.value());
            }
        } else if (hovered_) {
            if (background_hover_state_tex_coords_.has_value()) {
                background_shape_.setTextureRect(background_hover_state_tex_coords_.value());
            }
        } else {
            // no check needed for normalTexCoords.hasValue() because if background texture has a value, normalTexCoords must also have a value
            background_shape_.setTextureRect(background_normal_state_tex_coords_.value());
        }
    }
}

void Button::updateTextTransform() {
    const float font_x = background_shape_.getPosition().x + background_shape_.getSize().x / 2.0f - (
                             text_.value().getLocalBounds().width / 2.0f) - text_.value().getLocalBounds().left;
    const float font_y = background_shape_.getPosition().y + background_shape_.getSize().y / 2.0f - (
                             text_.value().getLocalBounds().height / 2.0f) - text_.value().getLocalBounds().top;

    text_.value().setPosition(sf::Vector2f(font_x, font_y));

    //TODO: set characterSize
}

bool Button::isHovered() const {
    return hovered_;
}

sf::Vector2f Button::getPosition() const {
    return background_shape_.getPosition();
}

sf::Vector2f Button::getSize() const {
    return background_shape_.getSize();
}

void Button::setBackgroundTexture(std::shared_ptr<sf::Texture> texture) {
    background_texture_ = std::move(texture);
    background_shape_.setTexture(background_texture_.value().get());
}

void Button::setForegroundTexture(std::shared_ptr<sf::Texture> texture) {
    foreground_texture_ = std::move(texture);
    foreground_shape_.setTexture(foreground_texture_.value().get());
}

void Button::setTransform(const sf::Vector2f& pos, const sf::Vector2f& size) {
    background_shape_.setPosition(pos);
    background_shape_.setSize(size);

    foreground_shape_.setPosition(pos);
    foreground_shape_.setSize(size);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (background_texture_.has_value())
        target.draw(background_shape_);

    if (foreground_texture_.has_value())
        target.draw(foreground_shape_);

    if (text_.has_value()) {
        target.draw(text_.value());
    }
}

std::weak_ptr<Animation>
Button::addAnimation(const std::string& name, const ButtonAnimationTimelines& animation_timelines) {
    animation_ = std::make_shared<Animation>(name, [this](const sf::Vector2i coords, const sf::Vector2i size) {
        foreground_shape_.setTextureRect(sf::IntRect(coords, size));
    });

    animation_timelines_ = animation_timelines;

    return animation_.value();
}
