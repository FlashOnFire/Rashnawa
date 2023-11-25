#include "OptionsMenuScreen.h"
#include "../events/Events.h"
#include "SoundOptions.h"
#include "objects/ButtonBuilder.h"

#include <utility>

OptionsMenuScreen::OptionsMenuScreen(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<sf::Font> font,
                                     const sf::Vector2<unsigned int> &windowSize) : BasicScreen(std::move(font)),
                                                                                    _eventBus(std::move(eventBus)) {
    if (!_backgroundTexture->loadFromFile("../assets/menu/new_background.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }
    _backgroundTexture->setSmooth(true);

    if (!_titleBackground->loadFromFile("../assets/menu/new_background.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_optionsBackgroundTexture->loadFromFile("../assets/menu/options/background.png")) {
        std::cout << "Can't load menu background texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_buttonsTexture->loadFromFile("../assets/menu/options/button.png")) {
        std::cout << "Can't load menu button texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_sliderTexture->loadFromFile("../assets/menu/options/slider.png")) {
        std::cout << "Can't load menu slider texture from file";
        exit(EXIT_FAILURE);
    }

    if (!_sliderKnobTexture->loadFromFile("../assets/menu/options/sliderknob.png")) {
        std::cout << "Can't load menu sliderknob texture from file";
        exit(EXIT_FAILURE);
    }

    _titleText.setString("Options");
    _titleText.setFont(*_font);
    _titleText.setCharacterSize(65);
    _titleText.setFillColor(sf::Color::Black);

    _background = sf::RectangleShape();
    _background.setTexture(_backgroundTexture.get());

    _optionsBackground.setTexture(_optionsBackgroundTexture.get());

    sf::Vector2i buttonSize = sf::Vector2i((int) _buttonsTexture->getSize().x, (int) _buttonsTexture->getSize().y / 9);

    _soundCategoryBackgroundButton = ButtonBuilder().texture(_buttonsTexture, sf::Vector2i(0, 0), buttonSize)
            .hoverTexCoords(sf::Vector2i(0, (int) _buttonsTexture->getSize().y / 9), buttonSize)
            .callback([]() {
                std::cout << "clicked" << std::endl;
            }).build();

    _graphicsCategoryBackgroundButton = ButtonBuilder().texture(_buttonsTexture, sf::Vector2i(0,
                                                                                              (int) (_buttonsTexture->getSize().y /
                                                                                                     3)), buttonSize)
            .hoverTexCoords(
                    sf::Vector2i(0, (int) (_buttonsTexture->getSize().y / 3 + _buttonsTexture->getSize().y / 9)),
                    buttonSize)
            .callback([]() {
                std::cout << "clicked" << std::endl;
            }).build();

    _otherCategoryBackgroundButton = ButtonBuilder().texture(_buttonsTexture, sf::Vector2i(0,
                                                                                           (int) ((_buttonsTexture->getSize().y /
                                                                                                   3) * 2)), buttonSize)
            .hoverTexCoords(
                    sf::Vector2i(0, (int) (2 * (_buttonsTexture->getSize().y / 3) + _buttonsTexture->getSize().y / 9)),
                    buttonSize)
            .callback([]() {
                std::cout << "clicked" << std::endl;
            }).build();

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

    _currentOptionCategory->setTransform(sf::Vector2f(optionsBackgroundPosX, optionsBackgroundPosY),
                                         sf::Vector2f(optionsBackgroundSizeX, optionsBackgroundSizeY));

    const auto buttonCategoriesPosX = (float) windowSize.x * 0.1f;
    const auto buttonCategoriesPosY = (float) windowSize.y * 0.2f;

    const auto buttonCategoriesSize = (float) windowSize.x * 0.1f;
    const auto betweenCategoryButtonsGap = (float) windowSize.x * 0.02f;

    _soundCategoryBackgroundButton->setTransform(sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY),
                                                 sf::Vector2f(buttonCategoriesSize, buttonCategoriesSize));

    _graphicsCategoryBackgroundButton->setTransform(
            sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY + buttonCategoriesSize + betweenCategoryButtonsGap),
            sf::Vector2f(buttonCategoriesSize, buttonCategoriesSize));

    _otherCategoryBackgroundButton->setTransform(
            sf::Vector2f(buttonCategoriesPosX, buttonCategoriesPosY + 2 * (buttonCategoriesSize +
                                                                           betweenCategoryButtonsGap)),
            sf::Vector2f(buttonCategoriesSize, buttonCategoriesSize));
}

void OptionsMenuScreen::render(std::shared_ptr<sf::RenderWindow> window) const {
    window->draw(_background);
    window->draw(_titleText);
    window->draw(_optionsBackground);

    window->draw(*_soundCategoryBackgroundButton);
    window->draw(*_graphicsCategoryBackgroundButton);
    window->draw(*_otherCategoryBackgroundButton);

    window->draw(*_currentOptionCategory);
}

void OptionsMenuScreen::onMouseMove(const sf::Event::MouseMoveEvent &e) {
    _currentOptionCategory->onMouseMove(e);
    _soundCategoryBackgroundButton->onMouseMoved(e);
    _graphicsCategoryBackgroundButton->onMouseMoved(e);
    _otherCategoryBackgroundButton->onMouseMoved(e);
}

void OptionsMenuScreen::onMousePressed(const sf::Event::MouseButtonEvent &e) {
    _currentOptionCategory->onMouseButtonPressed(e);
    _soundCategoryBackgroundButton->onMouseButtonPressed(e);
    _graphicsCategoryBackgroundButton->onMouseButtonPressed(e);
    _otherCategoryBackgroundButton->onMouseButtonPressed(e);
}

void OptionsMenuScreen::onMouseReleased(const sf::Event::MouseButtonEvent &event) {
    _currentOptionCategory->onMouseButtonReleased(event);
}
