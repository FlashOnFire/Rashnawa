#include "Animations.h"
#include <fstream>
#include <cassert>

Animation::Animation(const std::string& fileName,
                     const std::function<void(sf::Vector2i coords, sf::Vector2i size)>& callback) {
    std::ifstream file("../assets/animations/" + fileName + ".txt");

    if (!file.is_open()) {
        std::cout << "cannot open file " << fileName << std::endl;
        return;
    }

    std::string line;

    std::getline(file, line);
    frame_time_ = std::stoi(line);

    std::getline(file, line);
    int x = std::stoi(line);

    std::getline(file, line);
    int y = std::stoi(line);

    size_ = sf::Vector2i(x, y);

    std::getline(file, line);
    nb_frames_ = std::stoi(line);

    int i = 0;
    while (!file.eof() && (i < nb_frames_)) {
        std::getline(file, line);
        frames_per_timeline_.insert(frames_per_timeline_.end(), std::stoi(line));
        i++;
    }

    total_animation_time_ = frame_time_ * frames_per_timeline_.at(current_timeline_);

    _callback = callback;

    triggerCallback(); //To set correctly the first frame
}

void Animation::resetTimeline() {
    current_frame_ = 0;
    current_time_ = 0;
}

void Animation::setPaused(bool paused) {
    paused_ = paused;
}

void Animation::setTimeline(const unsigned int new_timeline) {
    assert(new_timeline < nb_frames_); //button.txt hasn't the true number of frame

    if (new_timeline != current_timeline_) {
        resetTimeline();
        current_timeline_ = new_timeline;
        total_animation_time_ = frame_time_ * frames_per_timeline_.at(current_timeline_);

        triggerCallback();
    }
}

void Animation::update(int deltaTime) {
    if (paused_) {
        return;
    }
    if (total_animation_time_ != frame_time_) {
        current_time_ = (current_time_ + deltaTime) % total_animation_time_;
        unsigned int new_frame = current_time_ / frame_time_;
        if (new_frame != current_frame_) {
            current_frame_ = new_frame;
            triggerCallback();
        }
    }
}

void Animation::triggerCallback() const {
    _callback(sf::Vector2i(static_cast<int>(current_frame_) * size_.x, static_cast<int>(current_timeline_) * size_.y),
              size_);
}

unsigned int Animation::getTimeline() const {
    return current_timeline_;
}

bool Animation::paused() const {
    return paused_;
}
