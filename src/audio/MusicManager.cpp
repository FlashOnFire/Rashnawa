#include "MusicManager.h"

#include "../events/Events.h"

namespace Audio {
    MusicManager::MusicManager(std::shared_ptr<dexode::EventBus> event_bus,
                               std::shared_ptr<Audio::AudioManager> audio_manager,
                               std::shared_ptr<OptionsManager> options_manager)
        : event_bus_(std::move(event_bus)),
          audio_manager_(std::move(audio_manager)),
          options_manager_(std::move(options_manager)),
          event_listener_(dexode::EventBus::Listener(event_bus_)) {
        event_listener_.listen<Events::ChangeScreen>([this](const Events::ChangeScreen& e) {
            using enum Screens;

            if (e.from == None && e.to == MainMenu) {
                music_instance_ = audio_manager_->createEventInstance("event:/tension");
                music_instance_->setVolume(options_manager_->getSoundOption(SoundOptionType::MUSIC_VOLUME)._float);
                music_instance_->start();
            } else if (e.to == None) {
                if (e.from == PauseMenu) {
                    audio_manager_->setParameterByName("midhigh", 1, false);
                } else {
                    music_instance_ = audio_manager_->createEventInstance("event:/unknoawedplez");
                    music_instance_->setVolume(options_manager_->getSoundOption(SoundOptionType::MUSIC_VOLUME)._float);
                    music_instance_->start();

                    audio_manager_->update();

                    while (music_instance_->getPlaybackState() != FMOD_STUDIO_PLAYBACK_PLAYING) {
                    }

                    music_instance_->setTimelinePosition(30000);
                    music_instance_->setParameterByName("drum1", 1.0);
                    music_instance_->setParameterByName("drum2", 1.0);
                    music_instance_->setParameterByName("drum3", 1.0);
                    music_instance_->setParameterByName("drum4", 1.0);
                    music_instance_->setParameterByName("bass", 1.0);
                    music_instance_->setParameterByName("acc", 1.0);
                    music_instance_->setParameterByName("attack", 1.0);
                    music_instance_->setParameterByName("choeur", 1.0);
                }
            } else if (e.to == PauseMenu) {
                audio_manager_->setParameterByName("midhigh", 0, false);
            }
        });

        event_listener_.listen<Events::Options::SoundOptionChangeEvent>(
            [this](const Events::Options::SoundOptionChangeEvent& e) {
                if (e.type == SoundOptionType::MUSIC_VOLUME) {
                    music_instance_->setVolume(e.value._float);
                }
            });

        std::cout << "Created MusicManager!" << std::endl;
    }
} // Audio
