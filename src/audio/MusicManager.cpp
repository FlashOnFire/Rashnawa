#include "MusicManager.h"

#include <thread>

#include "../events/Events.h"

namespace Audio {
    MusicManager::MusicManager(std::shared_ptr<dexode::EventBus> event_bus,
                               std::shared_ptr<AudioSystem> audio_system,
                               std::shared_ptr<OptionsManager> options_manager)
        : event_bus_(std::move(event_bus)),
          audio_system_(std::move(audio_system)),
          options_manager_(std::move(options_manager)),
          event_listener_(dexode::EventBus::Listener(event_bus_)) {
        event_listener_.listen<Events::ChangeScreen>([this](const Events::ChangeScreen& event) {
            onScreenChange(event);
        });

        event_listener_.listen<Events::Options::SoundOptionChangeEvent>(
            [this](const Events::Options::SoundOptionChangeEvent& event) {
                onSoundOptionChange(event);
            });

        std::cout << "Created MusicManager!" << std::endl;
    }

    void MusicManager::onScreenChange(const Events::ChangeScreen& event) {
        using
                enum Screens;

        if (event.from == None && event.to == MainMenu) {
            music_instance_ = audio_system_->createEventInstance("event:/tension");
            music_instance_->setVolume(
                std::get<float>(options_manager_->getSoundOption(SoundOptionType::MUSIC_VOLUME)));
            music_instance_->start();
        } else if (event.to == None) {
            if (event.from == PauseMenu) {
                audio_system_->setParameterByName("midhigh", 1, false);
            } else {
                music_instance_ = audio_system_->createEventInstance("event:/unknoawedplez");
                music_instance_->setVolume(
                    std::get<float>(options_manager_->getSoundOption(SoundOptionType::MUSIC_VOLUME)));
                music_instance_->start();

                audio_system_->update();

                while (music_instance_->getPlaybackState() != FMOD_STUDIO_PLAYBACK_PLAYING) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(15));
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
        } else if (event.to == PauseMenu) {
            audio_system_->setParameterByName("midhigh", 0, false);
        }
    }

    void MusicManager::onSoundOptionChange(const Events::Options::SoundOptionChangeEvent& event) const {
        if (event.type == SoundOptionType::MUSIC_VOLUME) {
            music_instance_->setVolume(std::get<float>(event.value));
        }
    }
} // Audio
