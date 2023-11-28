#ifndef RASHNAWA_ANIMATIONS_H
#define RASHNAWA_ANIMATIONS_H


#include <iostream>
#include <vector>
#include <SFML/Graphics/Rect.hpp>

class Animation {
public:
    explicit Animation(const std::string &fileName); // fileName must be the path without the extension of the file at the end

    std::vector<unsigned int> FRAME_PER_TIMELINE;
    sf::Vector2i TAILLE;
    unsigned int FRAME_TIME;
    unsigned int _current_frame = 0;
    unsigned int _current_time = 0; //current time in the current animation
    unsigned int _current_timeline = 0; //index of the timeline in FRAME_PER_TIMELINE
    unsigned int _total_animation_time = 0; //FRAME_TIME * FRAME_PER_TIMELINE.at(0);
    sf::Vector2i _length_width = sf::Vector2i(0, 0); //to stock the length of the frame


    void setTimeline(unsigned int new_timeline);

    void update(unsigned int deltaTime);
};


#endif //RASHNAWA_ANIMATIONS_H
