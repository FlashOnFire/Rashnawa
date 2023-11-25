#ifndef RASHNAWA_OPTIONSMENUSCREEN_H
#define RASHNAWA_OPTIONSMENUSCREEN_H


#include "objects/BasicScreen.h"
#include "dexode/EventBus.hpp"
#include "../audio/AudioManager.h"
#include "objects/Slider.h"
#include "objects/OptionsCategory.h"
#include "objects/Button.h"

class OptionsMenuScreen: public BasicScreen {
public:
    explicit OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::Font> font, const sf::Vector2<unsigned int> &windowSize);

    void onMouseMove(const sf::Event::MouseMoveEvent &event) override;
    void onMousePressed(const sf::Event::MouseButtonEvent &event) override;
    void onMouseReleased(const sf::Event::MouseButtonEvent &event) override;

    void render(std::shared_ptr<sf::RenderWindow> window) const override;
private:
    const std::shared_ptr<dexode::EventBus> _eventBus;

    std::unique_ptr<dexode::EventBus::Listener> _eventListener;

    const std::unique_ptr<sf::Texture> _backgroundTexture = std::make_unique<sf::Texture>();

    const std::unique_ptr<sf::Texture> _titleBackground = std::make_unique<sf::Texture>();
    const std::unique_ptr<sf::Texture> _optionsBackgroundTexture = std::make_unique<sf::Texture>();
    const std::shared_ptr<sf::Texture> _buttonsTexture = std::make_shared<sf::Texture>();

    const std::shared_ptr<sf::Texture> _sliderTexture = std::make_shared<sf::Texture>();
    const std::shared_ptr<sf::Texture> _sliderKnobTexture = std::make_shared<sf::Texture>();

    sf::Text _titleText;
    sf::RectangleShape _background;
    sf::RectangleShape _optionsBackground;

    std::unique_ptr<OptionsCategory> _currentOptionCategory;

    std::unique_ptr<Button> _soundCategoryBackgroundButton;
    std::unique_ptr<Button> _graphicsCategoryBackgroundButton;
    std::unique_ptr<Button> _otherCategoryBackgroundButton;

    void updateComponentsTransform(const sf::Vector2<unsigned int> &windowSize);
};


#endif //RASHNAWA_OPTIONSMENUSCREEN_H
