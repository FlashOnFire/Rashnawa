#ifndef RASHNAWA_SLIDER_H
#define RASHNAWA_SLIDER_H

#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

#include "OptionComponent.h"

class Slider : public OptionComponent {
public:
    Slider() = delete;

    Slider(std::shared_ptr<sf::Texture> sliderTexture, std::shared_ptr<sf::Texture> slider_knob_texture,
           std::function<void(const float value)> callback, float value = 0);

    [[nodiscard]] float getValue() const;

    void setValue(float value);

    void updateComponentTransform() override;

private:
    std::shared_ptr<sf::Texture> slider_texture_;
    std::shared_ptr<sf::Texture> slider_knob_slider_knob_texture_;

    float scale_ = 0;

    float min_knob_x_ = 0;
    float max_knob_x_ = 0;

    float value_;
    bool hovered_ = false;
    bool grabbed_ = false;

    sf::RectangleShape visu_;
    sf::RectangleShape slider_;
    sf::RectangleShape slider_knob_;

    std::function<void(const float value)> callback_;

    void updateKnobPlacement();

    void onMouseMove(const sf::Event::MouseMoveEvent& event) override;

    void onMousePressed(const sf::Event::MouseButtonEvent& event) override;

    void onMouseReleased(const sf::Event::MouseButtonEvent& event) override;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


#endif //RASHNAWA_SLIDER_H
