#ifndef RASHNAWA_GAME_H
#define RASHNAWA_GAME_H


#include "audio/AudioManager.h"
#include "world/World.h"
#include "graphics/Renderer.h"

class Game {
public:
    Game();
    void run();
private:
    std::shared_ptr<sf::RenderWindow> _window;

    Audio::AudioManager _audioMgr;
    World _world;
    std::unique_ptr<Graphics::Renderer> _renderer;
};


#endif //RASHNAWA_GAME_H
