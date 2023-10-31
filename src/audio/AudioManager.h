#ifndef RASHNAWA_AUDIO_AUDIOMANAGER_H
#define RASHNAWA_AUDIO_AUDIOMANAGER_H

#include <memory>
#include "FMOD/fmod_studio.hpp"
#include "EventInstance.h"
#include <vector>
#include <map>

using namespace FMOD;

namespace Audio {

    class AudioManager {
    public:
        AudioManager();
        void initialize();

        void update() const;

        std::weak_ptr<Studio::Bank> loadBank(const std::string &path);

        [[nodiscard]] std::weak_ptr<Studio::System> getSystem() const;

        std::unique_ptr<EventInstance> createEventInstance(const std::string &path);
    private:
        std::shared_ptr<Studio::System> _system = nullptr;
        std::vector<std::shared_ptr<Studio::Bank>> _banks;
        std::map<const std::string, std::shared_ptr<Studio::EventDescription>> eventDescriptions;

        std::weak_ptr<Studio::EventDescription> getEventDescription(const std::string &path);
    };

} // Audio

#endif // RASHNAWA_AUDIO_AUDIOMANAGER_H