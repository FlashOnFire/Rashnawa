#ifndef RASHNAWA_GAME_H
#define RASHNAWA_GAME_H

#include <optional>

#include "dexode/EventBus.hpp"

#include "audio/AudioManager.h"
#include "world/World.h"
#include "graphics/Renderer.h"
#include "screens/objects/BasicScreen.h"
#include "MusicManager.h"
#include "events/EventManager.h"

class Game {
public:
    Game();
    void run();
private:
    bool _running = true;

    std::shared_ptr<dexode::EventBus> _eventBus;

    std::shared_ptr<sf::RenderWindow> _window;
    std::shared_ptr<EventManager> _eventManager;

    std::shared_ptr<Audio::AudioManager> _audioMgr;
    std::unique_ptr<Audio::MusicManager> _musicManager;

    World _world;
    std::unique_ptr<Graphics::Renderer> _renderer;

    std::optional<std::unique_ptr<BasicScreen>> _currentScreen;

    sf::Font font;
};


#endif //RASHNAWA_GAME_H
