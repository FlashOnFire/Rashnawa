#ifndef RASHNAWA_MUSICMANAGER_H
#define RASHNAWA_MUSICMANAGER_H

#include "dexode/EventBus.hpp"
#include "AudioManager.h"
#include "../storage/OptionsManager.h"

namespace Audio {
    class MusicManager {
    public:
        MusicManager(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<AudioManager> audio_manager,
                     std::shared_ptr<OptionsManager> options_manager);

    private:
        const std::shared_ptr<dexode::EventBus> event_bus_;
        const std::shared_ptr<AudioManager> audio_manager_;
        const std::shared_ptr<OptionsManager> options_manager_;

        dexode::EventBus::Listener event_listener_;

        std::unique_ptr<EventInstance> music_instance_;
    };
} // Audio


#endif //RASHNAWA_MUSICMANAGER_H
