#ifndef RASHNAWA_AUDIO_AUDIOMANAGER_H
#define RASHNAWA_AUDIO_AUDIOMANAGER_H

#include <memory>
#include "EventInstance.h"
#include <vector>
#include <map>

#include "FMOD/fmod_studio.h"

namespace Audio {
    class AudioManager {
    public:
        AudioManager();

        ~AudioManager();

        void initialize();

        void update() const;

        std::weak_ptr<FMOD_STUDIO_BANK> loadBank(const std::string& path);

        std::unique_ptr<EventInstance> createEventInstance(const std::string& path);

    private:
        FMOD_STUDIO_SYSTEM* system_;
        std::vector<std::shared_ptr<FMOD_STUDIO_BANK>> banks_;
        std::map<const std::string, std::shared_ptr<FMOD_STUDIO_EVENTDESCRIPTION>> event_descriptions_;

        std::weak_ptr<FMOD_STUDIO_EVENTDESCRIPTION> getEventDescription(const std::string& path);
    };
} // Audio

#endif // RASHNAWA_AUDIO_AUDIOMANAGER_H
