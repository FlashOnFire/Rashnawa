#include "AudioManager.h"
#include <iostream>

namespace Audio {
    AudioManager::AudioManager() {
        Studio::System *sys;
        Studio::System::create(&sys);

        _system.reset(sys, [](Studio::System *system) {
            system->release();
        });

        ErrCheck(_system->initialize(512, FMOD_STUDIO_INIT_NORMAL, FMOD_INIT_NORMAL, nullptr));
    }

    void AudioManager::update() const {
        _system->update();
    }

    std::weak_ptr<Studio::Bank> AudioManager::loadBank(const std::string &path) {
        Studio::Bank *bank;
        ErrCheck(_system->loadBankFile(path.c_str(), FMOD_STUDIO_LOAD_BANK_NORMAL, &bank));

        std::shared_ptr<Studio::Bank> bankPtr(bank, [](Studio::Bank *bank) {
            bank->unload();
        });

        _banks.push_back(bankPtr);
        return (bankPtr);
    }

    std::weak_ptr<Studio::System> AudioManager::getSystem() const {
        return _system;
    }

    EventInstance
    AudioManager::getEventInstance(const std::string &path) {
        Studio::EventInstance *instance;
        getEventDescription(path).lock()->createInstance(&instance);
        std::unique_ptr<Studio::EventInstance, EventInstanceDeleter> ptrInstance(instance, EventInstanceDeleter());

        EventInstance a = Audio::EventInstance(std::move(ptrInstance));

        return std::move(a);
    }

    std::weak_ptr<Studio::EventDescription> AudioManager::getEventDescription(const std::string &path) {
        if (eventDescriptions.count(path) == 0) {
            Studio::EventDescription *event;

            ErrCheck(_system->getEvent(path.c_str(), &event));

            if (!event->isValid()) {
                std::cout << "AudioManager Error! (Invalid EventDescription for event " << path << ")" << std::endl;
                exit(EXIT_FAILURE);
            }

            std::shared_ptr<Studio::EventDescription> eventPtr = std::shared_ptr<Studio::EventDescription>(event,
                                                                                                           [](Studio::EventDescription *evt) {
                                                                                                               evt->releaseAllInstances();
                                                                                                           });

            eventDescriptions.insert(std::pair(path, eventPtr));

            return eventPtr;
        } else {
            return eventDescriptions.at(path);
        }
    }
}