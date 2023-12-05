#ifndef RASHNAWA_GAME_H
#define RASHNAWA_GAME_H

#include <optional>

#include "dexode/EventBus.hpp"

#include "audio/AudioManager.h"
#include "graphics/Renderer.h"
#include "screens/objects/BasicScreen.h"
#include "audio/MusicManager.h"
#include "events/KeybindHandler.h"
#include "graphics/Animations.h"
#include "storage/OptionsManager.h"

class Game {
public:
    Game();

    void run();

private:
    bool running_ = true;

    std::shared_ptr<dexode::EventBus> event_bus_;

    std::unique_ptr<dexode::EventBus::Listener> gamePausedListener_;

    std::shared_ptr<sf::RenderWindow> window_;

    std::shared_ptr<OptionsManager> options_manager_;

    std::shared_ptr<Audio::AudioManager> audio_manager_;
    std::unique_ptr<Audio::MusicManager> music_manager_;

    std::unique_ptr<Graphics::Renderer> renderer_;

    std::optional<std::unique_ptr<BasicScreen>> current_screen_;

    std::shared_ptr<sf::Font> font_ = std::make_shared<sf::Font>();

    std::shared_ptr<KeybindHandler> keybind_handler_;

    std::vector<std::weak_ptr<Animation>> animations_;

    void handleEvents() const;
};


#endif //RASHNAWA_GAME_H
