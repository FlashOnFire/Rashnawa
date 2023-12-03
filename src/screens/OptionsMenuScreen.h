#ifndef RASHNAWA_OPTIONSMENUSCREEN_H
#define RASHNAWA_OPTIONSMENUSCREEN_H


#include "objects/BasicScreen.h"
#include "dexode/EventBus.hpp"
#include "objects/Slider.h"
#include "objects/OptionsCategory.h"
#include "objects/Button.h"
#include "../storage/OptionsManager.h"

class OptionsMenuScreen : public BasicScreen {
public:
    explicit OptionsMenuScreen(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<sf::Font> font,
                               std::shared_ptr<OptionsManager> options_manager,
                               const sf::Vector2<unsigned int>& window_size);

    void onMouseMove(const sf::Event::MouseMoveEvent& event) override;

    void onMousePressed(const sf::Event::MouseButtonEvent& event) override;

    void onMouseReleased(const sf::Event::MouseButtonEvent& event) override;

    void onWindowResize(const sf::Event::SizeEvent& event) override;

    void render(std::shared_ptr<sf::RenderWindow> window) const override;

private:
    const std::shared_ptr<OptionsManager> options_manager_;

    const std::unique_ptr<sf::Texture> background_texture_ = std::make_unique<sf::Texture>();

    const std::unique_ptr<sf::Texture> title_background_ = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> options_background_texture_ = std::make_unique<sf::Texture>();
    const std::shared_ptr<sf::Texture> buttons_background_texture_ = std::make_shared<sf::Texture>();
    const std::shared_ptr<sf::Texture> buttons_foreground_texture_ = std::make_shared<sf::Texture>();

    const std::shared_ptr<sf::Texture> slider_texture_ = std::make_shared<sf::Texture>();
    const std::shared_ptr<sf::Texture> slider_knob_texture_ = std::make_shared<sf::Texture>();

    sf::Text title_text_;
    sf::RectangleShape background_;
    sf::RectangleShape options_background_;

    std::unique_ptr<OptionsCategory> current_option_category_;

    std::unique_ptr<Button> sound_category_background_button_;
    std::unique_ptr<Button> graphics_category_background_button_;
    std::unique_ptr<Button> other_category_background_button_;

    void updateComponentsTransform(const sf::Vector2<unsigned int>& windowSize);
};


#endif //RASHNAWA_OPTIONSMENUSCREEN_H
