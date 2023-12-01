#include "SoundOptions.h"

float SoundOptions::getMasterVolume() const {
    return master_volume;
}

void SoundOptions::setMasterVolume(const float master_volume) {
    this->master_volume = master_volume;
}

float SoundOptions::getMusicVolume() const {
    return music_volume;
}

void SoundOptions::setMusicVolume(const float music_volume) {
    this->music_volume = music_volume;
}

float SoundOptions::getEffectsVolume() const {
    return effects_volume;
}

void SoundOptions::setEffectsVolume(const float effects_volume) {
    this->effects_volume = effects_volume;
}
