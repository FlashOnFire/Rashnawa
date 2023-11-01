#ifndef RASHNAWA_MUSICMANAGER_H
#define RASHNAWA_MUSICMANAGER_H

#include <functional>

#include "dexode/EventBus.hpp"
#include "AudioManager.h"

namespace Audio {

    class MusicManager {
    public:
        MusicManager(std::shared_ptr<dexode::EventBus> eventBus, std::shared_ptr<Audio::AudioManager> audioManager);

    private:
        std::shared_ptr<dexode::EventBus> _eventBus;
        std::shared_ptr<Audio::AudioManager> _audioManager;

        dexode::EventBus::Listener _eventListener;

        std::unique_ptr<Audio::EventInstance> _musicInstance;
    };

} // Audio


#endif //RASHNAWA_MUSICMANAGER_H
