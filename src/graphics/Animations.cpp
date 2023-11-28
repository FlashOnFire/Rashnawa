#include "Animations.h"
#include <fstream>

Animation::Animation(const std::string &fileName) {
    _length_width = sf::Vector2i(0, 0); //to stock length of the frame
    std::ifstream file(fileName + ".txt");

    if (!file.is_open()) {
        std::cout << "cannot open file " << fileName << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    FRAME_TIME = std::stoi(line);
    std::getline(file, line);
    int x = std::stoi(line);
    std::getline(file, line);
    int y = std::stoi(line);
    TAILLE = sf::Vector2i(x, y);
    std::getline(file, line); //to obtain the number of the frame of the first timeline
    while (!file.eof()) {
        FRAME_PER_TIMELINE.insert(FRAME_PER_TIMELINE.end(), std::stoi(line));
        std::getline(file, line);
    }
    _total_animation_time = FRAME_TIME * FRAME_PER_TIMELINE.at(0);
}

void Animation::setTimeline(const unsigned int new_timeline) {
    _current_frame = 0;
    _current_time = 0;
    _current_timeline = new_timeline;
    _total_animation_time = FRAME_TIME * FRAME_PER_TIMELINE.at(_current_timeline);
    _length_width = sf::Vector2i(_length_width.x, _current_timeline * TAILLE.y);
}

void Animation::update(unsigned int deltaTime) {
    if (_total_animation_time != FRAME_TIME) {
        _current_time = (_current_time + deltaTime) % _total_animation_time;
        int new_frame = _current_time / FRAME_TIME;
        if (new_frame != _current_frame) {
            _current_frame = new_frame;
            _length_width = sf::Vector2i(_current_frame * TAILLE.x, _length_width.y);
        }
    }
}