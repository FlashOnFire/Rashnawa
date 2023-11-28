#include "Animations.h"

Animation::Animation(const std::string& fileName) {
    _lenght_width = sf::Vector2i(0, 0); //pour stocker la taille des frames
    _total_animation_time = 0; // _frame_time * FRAME_PER_TIMELINE.at(0);
}

void Animation::setTimeline(const unsigned int new_timeline) {
    _current_frame = 0;
    _current_timeline = new_timeline;
    _lenght_width = sf::Vector2i(_lenght_width.x, (int) _current_timeline * _lenght_width.y);
}

void Animation::update(unsigned int deltaTime) {
    _current_time = (_current_time + deltaTime) % _total_animation_time;
}