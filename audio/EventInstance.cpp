#include "EventInstance.h"

namespace Audio {

    EventInstance::EventInstance(std::unique_ptr<Studio::EventInstance, EventInstanceDeleter> instance) {
        _instance = std::move(instance);
    }

    void EventInstance::start() {
        ErrCheck(_instance->start());
    }

    void EventInstance::stop(const FMOD_STUDIO_STOP_MODE mode) {
        ErrCheck(_instance->stop(mode));
    }

    FMOD_STUDIO_PLAYBACK_STATE EventInstance::getPlaybackState() const {
        FMOD_STUDIO_PLAYBACK_STATE state;
        ErrCheck(_instance->getPlaybackState(&state));
        return state;
    }

    bool EventInstance::isPaused() const {
        bool paused;
        ErrCheck(_instance->getPaused(&paused));
        return paused;
    }

    void EventInstance::setPaused(const bool paused) {
        ErrCheck(_instance->setPaused(paused));
    }

    void EventInstance::togglePaused() {
        setPaused(!isPaused());
    }

    void EventInstance::keyOff() const {
        ErrCheck(_instance->keyOff());
    }

    float EventInstance::getPitch() const {
        float pitch;
        ErrCheck(_instance->getPitch(&pitch));
        return pitch;
    }

    void EventInstance::setPitch(float pitch) {
        ErrCheck(_instance->setPitch(pitch));
    }

    float EventInstance::getProperty(FMOD_STUDIO_EVENT_PROPERTY index) {
        float val;
        ErrCheck(_instance->getProperty(index, &val));
        return val;
    }

    void EventInstance::setProperty(FMOD_STUDIO_EVENT_PROPERTY index, float value) {
        ErrCheck(_instance->setProperty(index, value));
    }

    int EventInstance::getTimelinePosition() const {
        int pos;
        ErrCheck(_instance->getTimelinePosition(&pos));
        return pos;
    }

    void EventInstance::setTimelinePosition(int pos) {
        ErrCheck(_instance->setTimelinePosition(pos));
    }

    float EventInstance::getVolume() const {
        float vol;
        ErrCheck(_instance->getVolume(&vol));
        return vol;
    }

    void EventInstance::setVolume(const float vol) {
        ErrCheck(_instance->setVolume(vol));
    }

    bool EventInstance::isVirtual() const {
        bool virt;
        ErrCheck(_instance->isVirtual(&virt));
        return virt;
    }

    float EventInstance::getParameterByName(const std::string &name) {
        float value;
        ErrCheck(_instance->getParameterByName(name.c_str(), &value));
        return value;
    }

    void EventInstance::setParameterByName(const std::string &name, float value, bool ignoreSeekSpeed) {
        ErrCheck(_instance->setParameterByName(name.c_str(), value, ignoreSeekSpeed));
    }

    void EventInstance::setParameterByNameWithLabel(const std::string &name, const std::string &label,
                                                    bool ignoreSeekSpeed) {
        ErrCheck(_instance->setParameterByNameWithLabel(name.c_str(), label.c_str(), ignoreSeekSpeed));
    }

    std::shared_ptr<ChannelGroup> EventInstance::getChannelGroup() const {
        ChannelGroup *grp;
        ErrCheck(_instance->getChannelGroup(&grp));

        std::shared_ptr<ChannelGroup> ptr(grp, [](ChannelGroup *grp) {
            grp->release();
        });

        return ptr;
    }

    float EventInstance::getReverbLevel(int index) const {
        float reverb;
        ErrCheck(_instance->getReverbLevel(index, &reverb));
        return reverb;
    }

    void EventInstance::setReverbLevel(int index, float level) {
        ErrCheck(_instance->setReverbLevel(index, level));
    }

    FMOD_STUDIO_MEMORY_USAGE EventInstance::getMemoryUsage() const {
        FMOD_STUDIO_MEMORY_USAGE usage;
        ErrCheck(_instance->getMemoryUsage(&usage));
        return usage;
    }

    bool EventInstance::isValid() {
        return _instance->isValid();
    }
}