#include <cassert>
#include <utility>
#include "ButtonBuilder.h"
#include "../../events/Events.h"

ButtonBuilder&
ButtonBuilder::backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::IntRect& tex_coords) {
    _button->setBackgroundTexture(std::move(texture));
    _button->background_normal_state_tex_coords_ = tex_coords;

    return *this;
}

ButtonBuilder&
ButtonBuilder::backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::Vector2i& tex_coords_position,
                                 const sf::Vector2i& tex_coords_size) {
    return ButtonBuilder::backgroundTexture(std::move(texture), {tex_coords_position, tex_coords_size});
}

ButtonBuilder&
ButtonBuilder::backgroundTexture(std::shared_ptr<sf::Texture> texture, const int x, const int y, const int dx,
                                 const int dy) {
    return ButtonBuilder::backgroundTexture(std::move(texture), sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder&
ButtonBuilder::foregroundTexture(std::shared_ptr<sf::Texture> texture) {
    _button->setForegroundTexture(std::move(texture));
    return *this;
}


ButtonBuilder& ButtonBuilder::hoverBackgroundTexCoords(const sf::IntRect& tex_coords) {
    _button->background_hover_state_tex_coords_ = tex_coords;
    return *this;
}

ButtonBuilder&
ButtonBuilder::hoverBackgroundTexCoords(const sf::Vector2i& hover_tex_coords_pos,
                                        const sf::Vector2i& hover_tex_coords_size) {
    return ButtonBuilder::hoverBackgroundTexCoords({hover_tex_coords_pos, hover_tex_coords_size});
}

ButtonBuilder& ButtonBuilder::hoverBackgroundTexCoords(const int x, const int y, const int dx, const int dy) {
    return ButtonBuilder::hoverBackgroundTexCoords(sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder& ButtonBuilder::clickedBackgroundTexCoords(const sf::IntRect& tex_coords) {
    _button->background_clicked_state_tex_coords_ = tex_coords;
    return *this;
}

ButtonBuilder&
ButtonBuilder::clickedBackgroundTexCoords(const sf::Vector2i& hover_tex_coords_pos,
                                          const sf::Vector2i& hover_tex_coords_size) {
    return ButtonBuilder::clickedBackgroundTexCoords({hover_tex_coords_pos, hover_tex_coords_size});
}

ButtonBuilder& ButtonBuilder::clickedTexCoords(const int x, const int y, const int dx, const int dy) {
    return ButtonBuilder::clickedBackgroundTexCoords(sf::Vector2i(x, y), sf::Vector2i(dx, dy));
}

ButtonBuilder& ButtonBuilder::text(const std::string& text, const std::shared_ptr<sf::Font>& font) {
    _button->text_ = sf::Text(text, *font, 45);
    _button->text_->setFillColor(sf::Color::Black);

    return *this;
}

ButtonBuilder& ButtonBuilder::callback(std::function<void()> callback) {
    _button->callback_ = std::move(callback);

    return *this;
}

ButtonBuilder& ButtonBuilder::transform(const sf::Vector2f position, const sf::Vector2f size) {
    _button->setTransform(position, size);
    return *this;
}

ButtonBuilder& ButtonBuilder::transform(const float x, const float y, const float dx, const float dy) {
    _button->setTransform(sf::Vector2f(x, y), sf::Vector2f(dx, dy));
    return *this;
}

ButtonBuilder&
ButtonBuilder::animation(const std::shared_ptr<dexode::EventBus>& event_bus, const std::string& name,
                         const int normal_timeline,
                         const int hovered_timeline,
                         const int clicked_timeline) {
    const std::weak_ptr<Animation> animation = _button->addAnimation(name,
                                                                     ButtonAnimationTimelines{
                                                                         .normal = normal_timeline,
                                                                         .hovered = hovered_timeline,
                                                                         .clicked = clicked_timeline
                                                                     });
    event_bus->postpone<Events::AnimationCreated>({.animation = animation});

    return *this;
}

std::unique_ptr<Button> ButtonBuilder::build() {
    assert((_button->animation_.has_value() && _button->foreground_texture_.has_value()) ||
        !_button->animation_.has_value());

    if (_button->background_texture_.has_value()) {
        _button->updateTextureRect();
    }

    if (_button->text_.has_value()) {
        _button->updateTextTransform();
    }

    if (_button->animation_timelines_.has_value()) {
        _button->animation_.value()->setTimeline(_button->animation_timelines_->normal);
    }

    return std::move(_button);
}
