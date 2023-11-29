#include "Animations.h"
#include <fstream>

Animation::Animation(const std::string &fileName,
                     const std::function<void(sf::Vector2i coords, sf::Vector2i size)> &callback) {
    std::ifstream file("../assets/animations/" + fileName + ".txt");

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
    while (!file.eof()) {
        std::getline(file, line);
        FRAME_PER_TIMELINE.insert(FRAME_PER_TIMELINE.end(), std::stoi(line));
    }
    _total_animation_time = FRAME_TIME * FRAME_PER_TIMELINE.at(_current_timeline);
    _callback = callback;
}

void Animation::setTimeline(const unsigned int new_timeline) {
    _current_frame = 0;
    _current_time = 0;
    _current_timeline = new_timeline;
    _total_animation_time = FRAME_TIME * FRAME_PER_TIMELINE.at(_current_timeline);

    triggerCallback();
}

void Animation::update(int deltaTime) {
    if (_total_animation_time != FRAME_TIME) {
        _current_time = (_current_time + deltaTime) % _total_animation_time;
        unsigned int new_frame = _current_time / FRAME_TIME;
        if (new_frame != _current_frame) {
            _current_frame = new_frame;
            triggerCallback();
        }
    }
}

void Animation::triggerCallback() {
    _callback(sf::Vector2i((int) _current_frame * TAILLE.x, (int) _current_timeline * TAILLE.y), TAILLE);
}
