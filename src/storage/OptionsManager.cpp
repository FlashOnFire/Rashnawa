#include "OptionsManager.h"

#include <cstdlib>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "../events/Events.h"

OptionsManager::OptionsManager(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    if (!std::filesystem::exists(OPTIONS_FILE_NAME)) {
        saveOptionsSnapshot();
    } else {
        loadOptionsSnapshot();
    }
}

void OptionsManager::loadOptionsSnapshot() {
    std::ifstream stream(OPTIONS_FILE_NAME);

    if (!stream.is_open()) {
        exit(EXIT_FAILURE);
    }

    while (!stream.eof()) {
        std::string line;
        std::getline(stream, line);

        if (line.find('=') != std::string::npos) {
            std::string key = line.substr(0, line.find('='));
            std::string value = line.substr(line.find('=') + 1);

            if (key == "master_volume") {
                options_snapshot_.sound.master_volume = std::stof(value);
            } else if (key == "music_volume") {
                options_snapshot_.sound.music_volume = std::stof(value);
            } else if (key == "effects_volume") {
                options_snapshot_.sound.effects_volume = std::stof(value);
            } else if (key == "fps") {
                options_snapshot_.graphics.fps = std::stoi(value);
            }
        }
    }
}

void OptionsManager::saveOptionsSnapshot() const {
    std::cout << "save" << std::endl;

    std::ofstream stream(OPTIONS_FILE_NAME);

    if (!stream.is_open()) {
        exit(EXIT_FAILURE);
    }

    stream << "[Sound]" << std::endl;

    stream << "master_volume=" << options_snapshot_.sound.master_volume << std::endl;
    stream << "music_volume=" << options_snapshot_.sound.music_volume << std::endl;
    stream << "effects_volume=" << options_snapshot_.sound.effects_volume << std::endl;

    stream << std::endl;

    stream << "[Graphics]" << std::endl;

    stream << "fps=" << options_snapshot_.graphics.fps << std::endl;
}

SoundOptionData OptionsManager::getSoundOptions() const {
    return options_snapshot_.sound;
}

GenericOption OptionsManager::getSoundOption(const SoundOptionType& type) const {
    switch (type) {
        using enum SoundOptionType;

        case MASTER_VOLUME:
            return GenericOption(options_snapshot_.sound.master_volume);
        case MUSIC_VOLUME:
            return GenericOption(options_snapshot_.sound.music_volume);
        case EFFECTS_VOLUME:
            return GenericOption(options_snapshot_.sound.effects_volume);
        default:
            std::cerr << "Not implemented";
            exit(EXIT_FAILURE);
    }
}

void OptionsManager::setSoundOptions(const SoundOptionData& sound_options) {
    this->options_snapshot_.sound = sound_options;
}

void OptionsManager::setSoundOption(const SoundOptionType& type, const GenericOption &value) {
    switch (type) {
        using enum SoundOptionType;

        case MASTER_VOLUME:
            options_snapshot_.sound.master_volume = value._float;
            break;
        case MUSIC_VOLUME:
            options_snapshot_.sound.music_volume = value._float;
            break;
        case EFFECTS_VOLUME:
            options_snapshot_.sound.effects_volume = value._float;
            break;
    }

    event_bus_->postpone<Events::Options::SoundOptionChangeEvent>({type, value});
}

GraphicsOptionsData OptionsManager::getGraphicsOptionsData() const {
    return options_snapshot_.graphics;
}

GenericOption OptionsManager::getGraphicsOption(const GraphicsOptionType& type) const {
    switch (type) {
        using enum GraphicsOptionType;

        case FPS:
            return GenericOption({._int = options_snapshot_.graphics.fps});
        default:
            std::cerr << "Not implemented";
            exit(EXIT_FAILURE);
    }
}

void OptionsManager::setGraphicsOptionsData(const GraphicsOptionsData& graphics_options_data) {
    options_snapshot_.graphics = graphics_options_data;
}

OptionsSnapshot OptionsManager::getOptionsSnapshot() const {
    return options_snapshot_;
}

void OptionsManager::setOptionsSnapshot(const OptionsSnapshot& options_snapshot) {
    options_snapshot_ = options_snapshot;
}
