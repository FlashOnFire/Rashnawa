#include "EventInstance.h"

namespace Audio {
    EventInstance::EventInstance(
        std::unique_ptr<FMOD::Studio::EventInstance, EventInstanceDeleter> instance) : instance_(std::move(instance)) {
        std::cout << "Created EventInstance!" << std::endl;
    }

    void EventInstance::start() {
        ErrCheck(instance_->start());
    }

    void EventInstance::stop(const FMOD_STUDIO_STOP_MODE mode) {
        ErrCheck(instance_->stop(mode));
    }

    FMOD_STUDIO_PLAYBACK_STATE EventInstance::getPlaybackState() const {
        FMOD_STUDIO_PLAYBACK_STATE state;
        ErrCheck(instance_->getPlaybackState(&state));
        return state;
    }

    bool EventInstance::isPaused() const {
        bool paused;
        ErrCheck(instance_->getPaused(&paused));
        return paused;
    }

    void EventInstance::setPaused(const bool paused) {
        ErrCheck(instance_->setPaused(paused));
    }

    void EventInstance::togglePaused() {
        setPaused(!isPaused());
    }

    void EventInstance::keyOff() const {
        ErrCheck(instance_->keyOff());
    }

    float EventInstance::getPitch() const {
        float pitch;
        ErrCheck(instance_->getPitch(&pitch));
        return pitch;
    }

    void EventInstance::setPitch(float pitch) {
        ErrCheck(instance_->setPitch(pitch));
    }

    float EventInstance::getProperty(FMOD_STUDIO_EVENT_PROPERTY index) const {
        float val;
        ErrCheck(instance_->getProperty(index, &val));
        return val;
    }

    void EventInstance::setProperty(FMOD_STUDIO_EVENT_PROPERTY index, float value) {
        ErrCheck(instance_->setProperty(index, value));
    }

    int EventInstance::getTimelinePosition() const {
        int pos;
        ErrCheck(instance_->getTimelinePosition(&pos));
        return pos;
    }

    void EventInstance::setTimelinePosition(int pos) {
        ErrCheck(instance_->setTimelinePosition(pos));
    }

    float EventInstance::getVolume() const {
        float vol;
        ErrCheck(instance_->getVolume(&vol));
        return vol;
    }

    void EventInstance::setVolume(const float vol) {
        ErrCheck(instance_->setVolume(vol));
    }

    bool EventInstance::isVirtual() const {
        bool virt;
        ErrCheck(instance_->isVirtual(&virt));
        return virt;
    }

    float EventInstance::getParameterByName(const std::string& name) const {
        float value;
        ErrCheck(instance_->getParameterByName(name.c_str(), &value));
        return value;
    }

    void EventInstance::setParameterByName(const std::string& name, float value, bool ignoreSeekSpeed) {
        ErrCheck(instance_->setParameterByName(name.c_str(), value, ignoreSeekSpeed));
    }

    void EventInstance::setParameterByNameWithLabel(const std::string& name, const std::string& label,
                                                    bool ignoreSeekSpeed) {
        ErrCheck(instance_->setParameterByNameWithLabel(name.c_str(), label.c_str(), ignoreSeekSpeed));
    }

    std::shared_ptr<FMOD::ChannelGroup> EventInstance::getChannelGroup() const {
        FMOD::ChannelGroup* group;
        ErrCheck(instance_->getChannelGroup(&group));

        std::shared_ptr<FMOD::ChannelGroup> ptr(group, [](FMOD::ChannelGroup* g) {
            g->release();
        });

        return ptr;
    }

    float EventInstance::getReverbLevel(int index) const {
        float reverb;
        ErrCheck(instance_->getReverbLevel(index, &reverb));
        return reverb;
    }

    void EventInstance::setReverbLevel(int index, float level) {
        ErrCheck(instance_->setReverbLevel(index, level));
    }

    FMOD_STUDIO_MEMORY_USAGE EventInstance::getMemoryUsage() const {
        FMOD_STUDIO_MEMORY_USAGE usage;
        ErrCheck(instance_->getMemoryUsage(&usage));
        return usage;
    }

    bool EventInstance::isValid() const {
        return instance_->isValid();
    }
} // Audio
