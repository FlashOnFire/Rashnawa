#include "AudioManager.h"
#include <iostream>

namespace Audio {
    AudioManager::AudioManager() {
        FMOD::Studio::System* sys;
        FMOD::Studio::System::create(&sys);

        system_.reset(sys, [](FMOD::Studio::System* system) {
            system->release();
        });

        std::cout << "Created AudioManager!" << std::endl;
    }

    void AudioManager::initialize() {
        ErrCheck(system_->initialize(512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr));
    }

    void AudioManager::update() const {
        system_->update();
    }

    std::weak_ptr<FMOD::Studio::Bank> AudioManager::loadBank(const std::string& path) {
        FMOD::Studio::Bank* bank;
        ErrCheck(system_->loadBankFile(path.c_str(), FMOD_STUDIO_LOAD_BANK_NORMAL, &bank));

        std::shared_ptr<FMOD::Studio::Bank> bankPtr(bank, [](FMOD::Studio::Bank* b) {
            b->unload();
        });

        banks_.push_back(bankPtr);
        return bankPtr;
    }

    std::weak_ptr<FMOD::Studio::System> AudioManager::getSystem() const {
        return system_;
    }

    std::unique_ptr<EventInstance>
    AudioManager::createEventInstance(const std::string& path) {
        FMOD::Studio::EventInstance* instance;
        getEventDescription(path).lock()->createInstance(&instance);
        std::unique_ptr<FMOD::Studio::EventInstance, EventInstanceDeleter> ptr_instance(
            instance, EventInstanceDeleter());

        return std::make_unique<Audio::EventInstance>(std::move(ptr_instance));
    }

    std::weak_ptr<FMOD::Studio::EventDescription> AudioManager::getEventDescription(const std::string& path) {
        if (!event_descriptions_.contains(path)) {
            FMOD::Studio::EventDescription* event;

            ErrCheck(system_->getEvent(path.c_str(), &event));

            if (!event->isValid()) {
                std::cout << "AudioManager Error! (Invalid EventDescription for event " << path << ")" << std::endl;
                exit(EXIT_FAILURE);
            }

            auto event_ptr = std::shared_ptr<FMOD::Studio::EventDescription>(event,
                                                                             [](FMOD::Studio::EventDescription* evt) {
                                                                                 evt->releaseAllInstances();
                                                                             });

            event_descriptions_.insert(std::pair(path, event_ptr));

            return event_ptr;
        } else {
            return event_descriptions_.at(path);
        }
    }
} // Audio
