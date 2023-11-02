#include "TextButton.h"

#include <utility>

#include <SFML/Graphics/RenderTarget.hpp>

TextButton::TextButton(float x, float y, float dx, float dy, const std::string& string, std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> texture,
                       const std::function<void()> &callback) : Button(x, y, dx, dy, std::move(texture), callback) {
    text.setString(string);

    text.setCharacterSize(45);
    text.setFont(*font);

    updateTextTransform();
}

TextButton::TextButton(const std::string& string, const sf::Font& font, std::shared_ptr<sf::Texture> texture,
                       const std::function<void()> &callback) : Button(std::move(texture), callback) {
    text.setString(string);

    text.setCharacterSize(45);
    text.setFont(font);
}

void TextButton::updateTextTransform() {
    float fontX = (float) shape.getPosition().x + (float) shape.getSize().x / 2.0f - (text.getLocalBounds().width / 2.0f) -
                  text.getLocalBounds().left;
    float fontY = (float) shape.getPosition().y+ (float) shape.getSize().y / 2.0f - (text.getLocalBounds().height / 2.0f) -
                  text.getLocalBounds().top;

    text.setPosition(sf::Vector2f(fontX, fontY));
}

void TextButton::setColor(const sf::Color &color) {
    text.setFillColor(color);
}

std::string TextButton::getText() const {
    return text.getString();
}

void TextButton::setTransform(const sf::Vector2f &pos, const sf::Vector2f &size) {
    Button::setTransform(pos, size);

    updateTextTransform();
}

void TextButton::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    Button::draw(target, states);

    target.draw(text);
}
