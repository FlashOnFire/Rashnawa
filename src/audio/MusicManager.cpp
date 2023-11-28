#include "MusicManager.h"
#include "../events/Events.h"

namespace Audio {
    MusicManager::MusicManager(std::shared_ptr<dexode::EventBus> eventBus,
                               std::shared_ptr<Audio::AudioManager> audioManager) : _eventBus(std::move(eventBus)),
                                                                                    _audioManager(
                                                                                            std::move(audioManager)),
                                                                                    _eventListener(
                                                                                            dexode::EventBus::Listener(
                                                                                                    _eventBus)) {

        _eventListener.listen<Events::ChangeScreen>([this](const Events::ChangeScreen &e) {
            using enum Screens;

            if (e.from == None && e.to == MainMenu) {
                _musicInstance = _audioManager->createEventInstance("event:/tension");
                _musicInstance->setVolume(0.2f);
                _musicInstance->start();
            } else if (e.to == None) {
                _musicInstance->stop(FMOD_STUDIO_STOP_MODE::FMOD_STUDIO_STOP_ALLOWFADEOUT);
            }

            if (e.to == OptionsMenu) {
                _musicInstance->setParameterByName("midhigh", 0, false);
            } else if (e.to == MainMenu) {
                _musicInstance->setParameterByName("midhigh", 1, false);
            }
        });

        std::cout << "Created MusicManager!" << std::endl;
    }

} // Audio