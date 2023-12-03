#ifndef PAUSEMENUSCREEN_H
#define PAUSEMENUSCREEN_H
#include "objects/BasicScreen.h"


class PauseMenuScreen : public BasicScreen {
public:
    PauseMenuScreen(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<sf::Font> font);

    void render(std::shared_ptr<sf::RenderWindow> window) const override;
};


#endif //PAUSEMENUSCREEN_H
