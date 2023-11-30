#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H


#include <iostream>
#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <functional>

class Animation {
public:
    explicit Animation(const std::string &fileName, const std::function<void(sf::Vector2i coords,
                                                                             sf::Vector2i size)> &callback); // fileName must be the path without the extension of the file at the end

    [[nodiscard]] bool getPaused() const;

    void setPaused(bool isPaused);

    [[nodiscard]] unsigned int getTimeline() const;

    void setTimeline(unsigned int new_timeline);

    void resetTimeline();

    void update(int deltaTime);

    void triggerCallback();

private:
    bool _isPaused = false;
    std::vector<unsigned int> FRAME_PER_TIMELINE;
    sf::Vector2i TAILLE;
    unsigned int FRAME_TIME;
    unsigned int _current_frame = 0;
    unsigned int _current_time = 0; //current time in the current animation
    unsigned int _current_timeline = 0; //index of the timeline in FRAME_PER_TIMELINE
    unsigned int _total_animation_time = 0; //FRAME_TIME * FRAME_PER_TIMELINE.at(0);
    std::function<void(sf::Vector2i coords, sf::Vector2i size)> _callback;
};


#endif //RASHNAWA_ANIMATIONS_H
