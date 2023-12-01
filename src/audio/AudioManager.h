#ifndef RASHNAWA_AUDIO_AUDIOMANAGER_H
#define RASHNAWA_AUDIO_AUDIOMANAGER_H

#include <memory>
#include "FMOD/fmod_studio.hpp"
#include "EventInstance.h"
#include <vector>
#include <map>

namespace Audio {

    class AudioManager {
    public:
        AudioManager();

        void initialize();

        void update() const;

        std::weak_ptr<FMOD::Studio::Bank> loadBank(const std::string &path);

        [[nodiscard]] std::weak_ptr<FMOD::Studio::System> getSystem() const;

        std::unique_ptr<EventInstance> createEventInstance(const std::string &path);

    private:
        std::shared_ptr<FMOD::Studio::System> system_;
        std::vector<std::shared_ptr<FMOD::Studio::Bank>> banks_;
        std::map<const std::string, std::shared_ptr<FMOD::Studio::EventDescription>> event_descriptions_;

        std::weak_ptr<FMOD::Studio::EventDescription> getEventDescription(const std::string &path);
    };

} // Audio

#endif // RASHNAWA_AUDIO_AUDIOMANAGER_H