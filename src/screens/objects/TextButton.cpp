#include "TextButton.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>

TextButton::TextButton(float x, float y, float dx, float dy, const std::string& string, std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> texture,
                       const std::function<void()> &callback) : Button(x, y, dx, dy, std::move(texture), callback) {
    text.setString(string);
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(45);
    text.setFont(*font);


    // TODO : call this when updating size and/or position to update Text transform as well
    updateComponentsTransform();
}

TextButton::TextButton(const std::string& string, const sf::Font& font, std::shared_ptr<sf::Texture> texture,
                       const std::function<void()> &callback) : Button(std::move(texture), callback) {
    text.setString(string);
    text.setFillColor(sf::Color::Yellow);
    text.setCharacterSize(45);
    text.setFont(font);
}

void TextButton::updateComponentsTransform() {
    float fontX = (float) shape.getPosition().x + (float) shape.getSize().x / 2.0f - (text.getLocalBounds().width / 2.0f) -
                  text.getLocalBounds().left;
    float fontY = (float) shape.getPosition().y+ (float) shape.getSize().y / 2.0f - (text.getLocalBounds().height / 2.0f) -
                  text.getLocalBounds().top;

    text.setPosition(sf::Vector2f(fontX, fontY));
}

std::string TextButton::getText() const {
    return text.getString();
}

void TextButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    Button::draw(target, states);

    target.draw(text);
}
