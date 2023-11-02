#ifndef RASHNAWA_TEXTBUTTON_H
#define RASHNAWA_TEXTBUTTON_H

#include <string>

#include "Button.h"

class TextButton : public Button {
public:
    TextButton(float x, float y, float dx, float dy, const std::string& string, std::shared_ptr<sf::Font> font, std::shared_ptr<sf::Texture> texture,
               const std::function<void()> &callback);

    TextButton(const std::string& string, const sf::Font &font, std::shared_ptr<sf::Texture> texture, const std::function<void()> &callback);

    void updateComponentsTransform();

    [[nodiscard]] std::string getText() const;
private:
    sf::Text text;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_TEXTBUTTON_H
