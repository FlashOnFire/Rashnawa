#include "MusicManager.h"
#include "../events/Events.h"

namespace Audio {
    MusicManager::MusicManager(std::shared_ptr<dexode::EventBus> event_bus,
                               std::shared_ptr<Audio::AudioManager> audio_manager)
        : event_bus_(std::move(event_bus)),
          audio_manager_(std::move(audio_manager)),
          event_listener_(dexode::EventBus::Listener(event_bus_)) {
        event_listener_.listen<Events::ChangeScreen>([this](const Events::ChangeScreen& e) {
            using enum Screens;

            if (e.from == None && e.to == MainMenu) {
                music_instance_ = audio_manager_->createEventInstance("event:/tension");
                music_instance_->setVolume(0.2f);
                music_instance_->start();
            } else if (e.to == None) {
                music_instance_->stop(FMOD_STUDIO_STOP_MODE::FMOD_STUDIO_STOP_ALLOWFADEOUT);
            }

            if (e.to == OptionsMenu) {
                music_instance_->setParameterByName("midhigh", 0, false);
            } else if (e.to == MainMenu) {
                music_instance_->setParameterByName("midhigh", 1, false);
            }
        });

        std::cout << "Created MusicManager!" << std::endl;
    }
} // Audio
