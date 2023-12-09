#ifndef RASHNAWA_AUDIO_AUDIOMANAGER_H
#define RASHNAWA_AUDIO_AUDIOMANAGER_H

#include <memory>
#include "EventInstance.h"
#include <vector>
#include <map>

#include "FMOD/fmod_studio.h"

namespace Audio {
    class AudioSystem {
    public:
        AudioSystem();

        ~AudioSystem();

        void initialize() const;

        void update() const;

        std::weak_ptr<FMOD_STUDIO_BANK> loadBank(const std::string& path);

        std::unique_ptr<EventInstance> createEventInstance(const std::string& path);

        void setParameterByName(const std::string& name, float value, bool ignore_seek_speed = false) const;

    private:
        FMOD_STUDIO_SYSTEM* system_ = nullptr;
        std::vector<std::shared_ptr<FMOD_STUDIO_BANK>> banks_;
        std::map<const std::string, std::shared_ptr<FMOD_STUDIO_EVENTDESCRIPTION>> event_descriptions_;

        std::weak_ptr<FMOD_STUDIO_EVENTDESCRIPTION> getEventDescription(const std::string& path);
    };
} // Audio

#endif // RASHNAWA_AUDIO_AUDIOMANAGER_H
