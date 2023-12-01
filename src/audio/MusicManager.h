#ifndef RASHNAWA_MUSICMANAGER_H
#define RASHNAWA_MUSICMANAGER_H

#include "dexode/EventBus.hpp"
#include "AudioManager.h"

namespace Audio {

    class MusicManager {
    public:
        MusicManager(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<Audio::AudioManager> audio_manager);

    private:
        const std::shared_ptr<dexode::EventBus> event_bus_;
        const std::shared_ptr<Audio::AudioManager> audio_manager_;

        dexode::EventBus::Listener event_listener_;

        std::unique_ptr<Audio::EventInstance> music_instance_;
    };

} // Audio


#endif //RASHNAWA_MUSICMANAGER_H
