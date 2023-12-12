#ifndef RASHNAWA_MUSICMANAGER_H
#define RASHNAWA_MUSICMANAGER_H

#include "dexode/EventBus.hpp"
#include "AudioManager.h"
#include "../storage/OptionsManager.h"
#include "../events/Events.h"

namespace Audio {
    class MusicManager {
    public:
        MusicManager(std::shared_ptr<dexode::EventBus> event_bus, std::shared_ptr<AudioSystem> audio_system,
                     std::shared_ptr<OptionsManager> options_manager);

    private:
        const std::shared_ptr<dexode::EventBus> event_bus_;
        const std::shared_ptr<AudioSystem> audio_system_;
        const std::shared_ptr<OptionsManager> options_manager_;

        dexode::EventBus::Listener event_listener_;

        std::unique_ptr<EventInstance> music_instance_;

        void onScreenChange(const Events::ChangeScreen &event);

        void onSoundOptionChange(const Events::Options::SoundOptionChangeEvent &event);
    };
} // Audio


#endif //RASHNAWA_MUSICMANAGER_H
