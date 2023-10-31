#ifndef RASHNAWA_GAME_H
#define RASHNAWA_GAME_H

#include <optional>

#include "audio/AudioManager.h"
#include "world/World.h"
#include "graphics/Renderer.h"
#include "screens/BasicScreen.h"

class Game {
public:
    Game();
    void run();
private:
    std::shared_ptr<sf::RenderWindow> _window;

    std::shared_ptr<Audio::AudioManager> _audioMgr;
    World _world;
    std::unique_ptr<Graphics::Renderer> _renderer;

    std::optional<std::unique_ptr<BasicScreen>> _currentScreen;

    sf::Font font;

    void handleEvents(bool &running);
};


#endif //RASHNAWA_GAME_H
