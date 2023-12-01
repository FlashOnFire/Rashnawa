#include "OptionsManager.h"

#include <cstdlib>
#include <iostream>

#include "../events/Events.h"

OptionsManager::OptionsManager(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
}

SoundOptionData OptionsManager::getSoundOptions() const {
    return sound_options_;
}

GenericOption OptionsManager::getSoundOption(const SoundOptionType& type) const {
    switch (type) {
        case SoundOptionType::MASTER_VOLUME:
            return GenericOption(sound_options_.master_volume);
        case SoundOptionType::MUSIC_VOLUME:
            return GenericOption(sound_options_.music_volume);
        case SoundOptionType::EFFECTS_VOLUME:
            return GenericOption(sound_options_.effects_volume);
        default:
            std::cerr << "Not implemented";
            exit(EXIT_FAILURE);
    }
}

void OptionsManager::setSoundOptions(const SoundOptionData& sound_options) {
    this->sound_options_ = sound_options;
}

void OptionsManager::setSoundOption(const SoundOptionType& type, GenericOption value) {
    switch (type) {
        case SoundOptionType::MASTER_VOLUME:
            sound_options_.master_volume = value._float;
            break;
        case SoundOptionType::MUSIC_VOLUME:
            sound_options_.music_volume = value._float;
            break;
        case SoundOptionType::EFFECTS_VOLUME:
            sound_options_.effects_volume = value._float;
            break;
    }

    event_bus_->postpone<Events::Options::SoundOptionChangeEvent>({type, value});
}

GraphicsOptionsData OptionsManager::getGraphicsOptionsData() const {
    return graphics_options_;
}

GenericOption OptionsManager::getGraphicsOption(const GraphicsOptionType& type) const {
    switch (type) {
        case GraphicsOptionType::FPS:
            return GenericOption({._int = graphics_options_.fps});
        default:
            std::cerr << "Not implemented";
            exit(EXIT_FAILURE);
    }
}

void OptionsManager::setGraphicsOptionsData(const GraphicsOptionsData& graphics_options_data) {
    graphics_options_ = graphics_options_data;
}
