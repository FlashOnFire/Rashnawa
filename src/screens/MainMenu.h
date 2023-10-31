#ifndef RASHNAWA_MAINMENU_H
#define RASHNAWA_MAINMENU_H


#include "BasicScreen.h"
#include "objects/Button.h"
#include "../audio/AudioManager.h"

class MainMenu : public BasicScreen {
public:
    explicit MainMenu(const std::weak_ptr<Audio::AudioManager>& audioMgr);

    void update(const sf::Event &e) override;

    void render(std::shared_ptr<sf::RenderWindow> window, const sf::Font &font) const override;

private:
    std::vector<std::unique_ptr<Button>> _buttons;
    std::unique_ptr<Audio::EventInstance> music;
};


#endif //RASHNAWA_MAINMENU_H
