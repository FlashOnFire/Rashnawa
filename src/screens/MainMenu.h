#ifndef RASHNAWA_MAINMENU_H
#define RASHNAWA_MAINMENU_H


#include "BasicScreen.h"
#include "objects/Button.h"

class MainMenu: public BasicScreen {
public:
    MainMenu();
    void update(const sf::Event &e) override;
    void render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const override;
private:
    std::vector<Button> _buttons;
};


#endif //RASHNAWA_MAINMENU_H
