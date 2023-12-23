#include "Animations.h"
#include <fstream>
#include <cassert>

Animation::Animation(const std::string &file_name,
                     const std::function<void(sf::Vector2i coords, sf::Vector2i size)> &callback, unsigned int timeline,
                     unsigned int offset) {
    std::ifstream file("../assets/animations/" + file_name + ".txt");

    current_timeline_ = timeline;
    current_time_ = offset;

    if (!file.is_open()) {
        std::cerr << "Cannot open file " << file_name << "\n";
        std::exit(EXIT_FAILURE);
    }

    std::string line;

    file >> frame_time_;
    int x, y;
    file >> x >> y;
    file >> nb_frames_;

    current_frame_ = offset / frame_time_;
    size_ = sf::Vector2i(x, y);

    std::getline(file, line);

    int i = 0;
    unsigned int nb_frame;
    int link_to_another_timeline;
    while (!file.eof() && i < nb_frames_) {
        file >> nb_frame;
        file >> link_to_another_timeline;
        frames_per_timeline_.emplace_back(nb_frame);
        link_to_another_timeline_.emplace_back(link_to_another_timeline);
        i++;
    }

    total_animation_time_ = frame_time_ * frames_per_timeline_.at(current_timeline_);

    callback_ = callback;

    triggerCallback(); //To set correctly the first frame
}

void Animation::resetTimeline() {
    current_frame_ = 0;
    current_time_ = 0;
}

bool Animation::paused() const {
    return paused_;
}

void Animation::setPaused(const bool paused) {
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

void Animation::update(const int deltaTime) {
    if (paused_) {
        return;
    }
    if (total_animation_time_ != frame_time_) {
        unsigned int current_time = current_time_ + deltaTime;
        if ((link_to_another_timeline_[current_timeline_] != -1) && (current_time >= total_animation_time_)) {
            setTimeline(link_to_another_timeline_[current_timeline_]);
        } else {
            current_time_ = current_time % total_animation_time_;
            const auto new_frame = current_time / frame_time_;
            if (new_frame != current_frame_) {
                current_frame_ = new_frame;
                triggerCallback();
            }
        }
    }
}

void Animation::triggerCallback() const {
    callback_(sf::Vector2i(static_cast<int>(current_frame_) * size_.x, static_cast<int>(current_timeline_) * size_.y),
              size_);
}

unsigned int Animation::getTimeline() const {
    return current_timeline_;
}
