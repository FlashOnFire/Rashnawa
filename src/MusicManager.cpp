#include "MusicManager.h"
#include "events/Events.h"

namespace Audio {

    MusicManager::MusicManager(std::shared_ptr<dexode::EventBus> eventBus,
                               std::shared_ptr<Audio::AudioManager> audioManager) : _eventBus(std::move(eventBus)),
                                                                                    _audioManager(
                                                                                            std::move(audioManager)),
                                                                                    _eventListener(
                                                                                            dexode::EventBus::Listener(
                                                                                                    {_eventBus})) {

        _eventListener.listen<Events::SwitchToMainMenu>([this](const Events::SwitchToMainMenu &e) {
            _musicInstance = _audioManager->createEventInstance("event:/tension");
            _musicInstance->setVolume(0.2);
            _musicInstance->start();
        });

        std::cout << "Created MusicManager!" << std::endl;
    }

} // Audio