#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H


#include <iostream>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <functional>

class Animation {
public:
    Animation();

    explicit Animation(const std::string& file_name, const std::function<void(sf::Vector2i coords,
                                                                              sf::Vector2i size)>& callback);

    // fileName must be the path without the extension of the file at the end

    [[nodiscard]] bool paused() const;

    void setPaused(bool paused);

    [[nodiscard]] unsigned int getTimeline() const;

    void setTimeline(unsigned int new_timeline);

    void resetTimeline();

    void update(int deltaTime);

    void triggerCallback() const;

private:
    bool paused_ = false;
    std::vector<unsigned int> frames_per_timeline_;
    sf::Vector2i size_;
    unsigned int frame_time_;
    unsigned int nb_frames_;
    unsigned int current_frame_ = 0;
    unsigned int current_time_ = 0; //current time in the current animation
    unsigned int current_timeline_ = 0; //index of the timeline in FRAME_PER_TIMELINE
    unsigned int total_animation_time_ = 0; //FRAME_TIME * FRAME_PER_TIMELINE.at(0);
    std::function<void(sf::Vector2i coords, sf::Vector2i size)> callback_;
};


#endif //RASHNAWA_ANIMATIONS_H
