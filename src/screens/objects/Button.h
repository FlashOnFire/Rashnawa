#ifndef RASHNAWA_BUTTON_H
#define RASHNAWA_BUTTON_H

#include <functional>
#include <string>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <memory>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Button : public sf::Drawable {
public:
    Button(float x, float y, float dx, float dy, std::shared_ptr<sf::Texture> texture,
           const std::function<void()> &callback);

    Button(std::shared_ptr<sf::Texture> texture, const std::function<void()> &callback);

    void mouseMoved(sf::Event::MouseMoveEvent e);

    void mouseButtonPressed(sf::Event::MouseButtonEvent e);

    void updateTextureRect();

    [[nodiscard]] bool isHovered() const;

    [[nodiscard]] sf::Vector2f getPosition() const;

    void setPosition(const sf::Vector2f &pos);

    [[nodiscard]] sf::Vector2f getSize() const;

    void setSize(const sf::Vector2f &size);

private:
    std::shared_ptr<sf::Texture> _texture;
    std::function<void()> _callback;

    bool _hovered = false;

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape shape;
};


#endif //RASHNAWA_BUTTON_H
