#pragma once

#include <memory>
#include "fmod_studio.hpp"
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

        EventInstance getEventInstance(const std::string &path);
    private:
        std::shared_ptr<Studio::System> _system = nullptr;
        std::vector<std::shared_ptr<Studio::Bank>> _banks;
        std::map<const std::string, std::shared_ptr<Studio::EventDescription>> eventDescriptions;

        std::weak_ptr<Studio::EventDescription> getEventDescription(const std::string &path);
    };

} // Audio