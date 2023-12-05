#include "AudioManager.h"
#include <iostream>

#include "Utils.hpp"

namespace Audio {
    AudioManager::AudioManager() {
        FMOD_Studio_System_Create(&system_, FMOD_VERSION);

        std::cout << "Created AudioManager!" << std::endl;
    }

    AudioManager::~AudioManager() {
        FMOD_Studio_System_Release(system_);
    }

    void AudioManager::initialize() const {
        ErrCheck(FMOD_Studio_System_Initialize(system_, 512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr));
    }

    void AudioManager::update() const {
        FMOD_Studio_System_Update(system_);
    }

    std::weak_ptr<FMOD_STUDIO_BANK> AudioManager::loadBank(const std::string& path) {
        FMOD_STUDIO_BANK* bank;
        ErrCheck(FMOD_Studio_System_LoadBankFile(system_, path.c_str(), FMOD_STUDIO_LOAD_BANK_NORMAL, &bank));

        std::shared_ptr<FMOD_STUDIO_BANK> bankPtr(bank, [](FMOD_STUDIO_BANK* b) {
            FMOD_Studio_Bank_Unload(b);
        });

        banks_.push_back(bankPtr);
        return bankPtr;
    }

    std::unique_ptr<EventInstance>
    AudioManager::createEventInstance(const std::string& path) {
        FMOD_STUDIO_EVENTINSTANCE* instance;
        FMOD_Studio_EventDescription_CreateInstance(getEventDescription(path).lock().get(), &instance);

        return std::make_unique<EventInstance>(instance);
    }

    void AudioManager::setParameterByName(const std::string& name, const float value,
                                          const bool ignoreSeekSpeed) const {
        ErrCheck(FMOD_Studio_System_SetParameterByName(system_, name.c_str(), value, ignoreSeekSpeed));
    }

    std::weak_ptr<FMOD_STUDIO_EVENTDESCRIPTION> AudioManager::getEventDescription(const std::string& path) {
        if (!event_descriptions_.contains(path)) {
            FMOD_STUDIO_EVENTDESCRIPTION* event;

            ErrCheck(FMOD_Studio_System_GetEvent(system_, path.c_str(), &event));

            if (!FMOD_Studio_EventDescription_IsValid(event)) {
                std::cout << "AudioManager Error! (Invalid EventDescription for event " << path << ")" << std::endl;
                exit(EXIT_FAILURE);
            }

            auto event_ptr = std::shared_ptr<FMOD_STUDIO_EVENTDESCRIPTION>(event,
                                                                           [](FMOD_STUDIO_EVENTDESCRIPTION* evt) {
                                                                               FMOD_Studio_EventDescription_ReleaseAllInstances(
                                                                                   evt);
                                                                           });

            event_descriptions_.insert(std::pair(path, event_ptr));

            return event_ptr;
        }

        return event_descriptions_.at(path);
    }
} // Audio
