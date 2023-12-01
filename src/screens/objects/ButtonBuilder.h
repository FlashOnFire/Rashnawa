#ifndef RASHNAWA_BUTTONBUILDER_H
#define RASHNAWA_BUTTONBUILDER_H

#include <memory>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <functional>
#include "dexode/EventBus.hpp"

#include "Button.h"

class ButtonBuilder {
private:
    std::unique_ptr<Button> _button = std::unique_ptr<Button>(new Button());

public:
    ButtonBuilder& backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::IntRect& tex_coords);

    ButtonBuilder& backgroundTexture(std::shared_ptr<sf::Texture> texture, const sf::Vector2i& tex_coords_position,
                                     const sf::Vector2i& tex_coords_size);

    ButtonBuilder&
    backgroundTexture(std::shared_ptr<sf::Texture> texture, int x, int y, int dx, int dy);

    ButtonBuilder& foregroundTexture(std::shared_ptr<sf::Texture> texture);

    ButtonBuilder& hoverBackgroundTexCoords(const sf::IntRect& tex_coords);

    ButtonBuilder&
    hoverBackgroundTexCoords(const sf::Vector2i& hover_tex_coords_pos, const sf::Vector2i& hover_tex_coords_size);

    ButtonBuilder& hoverBackgroundTexCoords(int x, int y, int dx, int dy);

    ButtonBuilder& clickedBackgroundTexCoords(const sf::IntRect& tex_coords);

    ButtonBuilder&
    clickedBackgroundTexCoords(const sf::Vector2i& hover_tex_coords_pos, const sf::Vector2i& hover_tex_coords_size);

    ButtonBuilder& clickedTexCoords(int x, int y, int dx, int dy);

    ButtonBuilder& text(const std::string& text, const std::shared_ptr<sf::Font>& font);

    ButtonBuilder& callback(std::function<void()> callback);

    ButtonBuilder& transform(sf::Vector2f position, sf::Vector2f size);

    ButtonBuilder& transform(float x, float y, float dx, float dy);

    ButtonBuilder&
    animation(const std::shared_ptr<dexode::EventBus>& event_bus, const std::string& name, int normal_timeline,
              int hovered_timeline, int clicked_timeline);

    std::unique_ptr<Button> build();
};


#endif //RASHNAWA_BUTTONBUILDER_H
