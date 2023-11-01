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
            if (e.from == Screens::None && e.to == Screens::MainMenu) {
                _musicInstance = _audioManager->createEventInstance("event:/tension");
                _musicInstance->setVolume(0.2);
                _musicInstance->start();
            } else if (e.to == Screens::None) {
                _musicInstance->stop(FMOD_STUDIO_STOP_MODE::FMOD_STUDIO_STOP_ALLOWFADEOUT);
            }

            if (e.to == Screens::OptionsMenu) {
                _musicInstance->setParameterByName("midhigh", 0, false);
            } else if (e.from == Screens::OptionsMenu) {
                _musicInstance->setParameterByName("midhigh", 1, false);
            }
        });

        std::cout << "Created MusicManager!" << std::endl;
    }

} // Audio