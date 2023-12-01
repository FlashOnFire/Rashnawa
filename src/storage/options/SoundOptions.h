#ifndef SOUNDOPTIONS_H
#define SOUNDOPTIONS_H


class SoundOptions {
public:
    SoundOptions() = delete;

private:
    float master_volume = 1;
    float music_volume = 1;
    float effects_volume = 1;

public:
    [[nodiscard]] float getMasterVolume() const;

    void setMasterVolume(float master_volume);

    [[nodiscard]] float getMusicVolume() const;

    void setMusicVolume(float music_volume);

    [[nodiscard]] float getEffectsVolume() const;

    void setEffectsVolume(float effects_volume);
};


#endif //SOUNDOPTIONS_H
