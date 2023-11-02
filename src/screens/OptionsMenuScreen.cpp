#include "OptionsMenuScreen.h"
#include "../events/Events.h"
#include "SoundOptions.h"

#include <utility>

OptionsMenuScreen::OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::Font> font,
                                     const sf::Vector2<unsigned int> &windowSize) : BasicScreen(std::move(font)),
                                                                                    _eventBus(std::move(eventBus)) {
    if (!_backgroundTexture->loadFromFile("../assets/menu/newfont.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }
    _backgroundTexture->setSmooth(true);

    if (!_titleBackground->loadFromFile("../assets/menu/newfont.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_optionsBackgroundTexture->loadFromFile("../assets/menu/options/background.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_buttonsTexture->loadFromFile("../assets/menu/options/button.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_sliderTexture->loadFromFile("../assets/menu/options/slider.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_sliderKnobTexture->loadFromFile("../assets/menu/options/sliderknob.png")) {
        std::cout << "Can't load menu _background texture from file";
        exit(EXIT_FAILURE);
    }


    _titleText.setString("Options");
    _titleText.setFont(*_font);
    _titleText.setCharacterSize(65);
    _titleText.setFillColor(sf::Color::Black);

    _background = sf::RectangleShape();
    _background.setTexture(_backgroundTexture.get());

    _optionsBackground.setTexture(_optionsBackgroundTexture.get());

    _soundCategoryBackgroundButton = std::make_unique<Button>(_buttonsTexture, []() {
        std::cout << "clicked" << std::endl;
    });

    _currentOptionCategory = std::make_unique<SoundOptions>(_sliderTexture, _sliderKnobTexture);

    updateComponentsTransform(windowSize);

    _eventListener = std::make_unique<dexode::EventBus::Listener>(_eventBus);
    _eventListener->listen<Events::EscapeBtn>([this](const Events::EscapeBtn &e) {
        _eventBus->postpone<Events::ChangeScreen>({.from = Screens::OptionsMenu, .to = Screens::MainMenu});
    });

    std::cout << "Created OptionsMenuScreen!" << std::endl;
}

void OptionsMenuScreen::updateComponentsTransform(const sf::Vector2<unsigned int> &windowSize) {
    _background.setSize(sf::Vector2f(windowSize));

    _titleText.setPosition(
            (float) windowSize.x / 2.0f - _titleText.getLocalBounds().width / 2.0f - _titleText.getLocalBounds().left,
            (float) windowSize.y / 10.0f - _titleText.getLocalBounds().height / 2.0f - _titleText.getLocalBounds().top);


    const auto optionsBackgroundPosX = (float) windowSize.x * (0.1f + 0.1f + 0.05f);
    const auto optionsBackgroundPosY = (float) windowSize.y * 0.2f;

    const auto optionsBackgroundSizeX = (float) windowSize.x * 0.65f;
    const auto optionsBackgroundSizeY = (float) windowSize.y * (1.0f - 0.2f - 0.1f);

    _optionsBackground.setPosition(optionsBackgroundPosX, optionsBackgroundPosY);
    _optionsBackground.setSize(sf::Vector2f(optionsBackgroundSizeX, optionsBackgroundSizeY));

    _currentOptionCategory->setPosition(sf::Vector2f(optionsBackgroundPosX, optionsBackgroundPosY));
    _currentOptionCategory->setSize(sf::Vector2f(optionsBackgroundSizeX, optionsBackgroundSizeY));

    const auto buttonCategoriesPosX = (float) windowSize.x * 0.1f;
    const auto buttonCategoriesPosY = (float) windowSize.y * 0.2f;

    const auto buttonCategoriesSizeX = (float) windowSize.x * 0.1f;
    const auto buttonCategoriesSizeY = (float) windowSize.y * 0.15f;

    _soundCategoryBackgroundButton->setTransform(sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY),
                                                 sf::Vector2f(buttonCategoriesSizeX, buttonCategoriesSizeY));

    _currentOptionCategory->updateComponentsTransform();
}

void OptionsMenuScreen::render(std::shared_ptr<sf::RenderWindow> window) const {
    window->draw(_background);
    window->draw(_titleText);
    window->draw(_optionsBackground);

    window->draw(*_soundCategoryBackgroundButton);

    window->draw(*_currentOptionCategory);
}
