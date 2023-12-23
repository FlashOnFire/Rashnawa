#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H


#include <iostream>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <functional>

class Animation {
public:
    Animation() = delete;

    explicit Animation(const std::string& file_name, const std::function<void(sf::Vector2i coords,
                                                                              sf::Vector2i size)>& callback,
                       unsigned int timeline = 0,
                       unsigned int offset = 0);

    [[nodiscard]] bool paused() const;

    void setPaused(bool paused);

    [[nodiscard]] unsigned int getTimeline() const;

    void setTimeline(unsigned int new_timeline, bool trigger_callback = true);

    void resetTimeline();

    void update(unsigned int deltaTime);

    void triggerCallback() const;

private:
    bool paused_ = false;
    std::vector<unsigned int> frames_per_timeline_;
    std::vector<int> link_to_another_timeline_;
    sf::Vector2i size_;
    unsigned int frame_time_ = 0;
    unsigned int nb_timeline_ = 0;
    unsigned int current_frame_;
    unsigned int current_time_; //current time in the current animation
    unsigned int current_timeline_; //index of the timeline in FRAME_PER_TIMELINE
    unsigned int total_animation_time_ = 0;
    std::function<void(sf::Vector2i coords, sf::Vector2i size)> callback_;
};


#endif //RASHNAWA_ANIMATIONS_H
