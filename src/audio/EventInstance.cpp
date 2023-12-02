#include "EventInstance.h"

#include <iostream>
#include <FMOD/fmod_studio.h>

#include "Utils.hpp"

namespace Audio {
    EventInstance::EventInstance(FMOD_STUDIO_EVENTINSTANCE* instance) : instance_(instance) {
        std::cout << "Created EventInstance!" << std::endl;
    }

    EventInstance::~EventInstance() {
        FMOD_Studio_EventInstance_Stop(instance_, FMOD_STUDIO_STOP_ALLOWFADEOUT);
        FMOD_Studio_EventInstance_Release(instance_);

        std::cout << "Destroyed audio event instance" << std::endl;
    }

    void EventInstance::start() {
        ErrCheck(FMOD_Studio_EventInstance_Start(instance_));
    }

    void EventInstance::stop(const FMOD_STUDIO_STOP_MODE mode) {
        ErrCheck(FMOD_Studio_EventInstance_Stop(instance_, mode));
    }

    FMOD_STUDIO_PLAYBACK_STATE EventInstance::getPlaybackState() const {
        FMOD_STUDIO_PLAYBACK_STATE state;
        ErrCheck(FMOD_Studio_EventInstance_GetPlaybackState(instance_, &state));
        return state;
    }

    bool EventInstance::isPaused() const {
        FMOD_BOOL paused;
        ErrCheck(FMOD_Studio_EventInstance_GetPaused(instance_, &paused));
        return paused;
    }

    void EventInstance::setPaused(const bool paused) {
        ErrCheck(FMOD_Studio_EventInstance_SetPaused(instance_, paused));
    }

    void EventInstance::togglePaused() {
        setPaused(!isPaused());
    }

    void EventInstance::keyOff() const {
        ErrCheck(FMOD_Studio_EventInstance_KeyOff(instance_));
    }

    float EventInstance::getPitch() const {
        float pitch;
        float final_pitch;
        ErrCheck(FMOD_Studio_EventInstance_GetPitch(instance_, &pitch, &final_pitch));
        return pitch;
    }

    void EventInstance::setPitch(float pitch) {
        ErrCheck(FMOD_Studio_EventInstance_SetPitch(instance_, pitch));
    }

    float EventInstance::getProperty(FMOD_STUDIO_EVENT_PROPERTY index) const {
        float val;
        ErrCheck(FMOD_Studio_EventInstance_GetProperty(instance_, index, &val));
        return val;
    }

    void EventInstance::setProperty(FMOD_STUDIO_EVENT_PROPERTY index, float value) {
        ErrCheck(FMOD_Studio_EventInstance_SetProperty(instance_, index, value));
    }

    int EventInstance::getTimelinePosition() const {
        int pos;
        ErrCheck(FMOD_Studio_EventInstance_GetTimelinePosition(instance_, &pos));
        return pos;
    }

    void EventInstance::setTimelinePosition(int pos) {
        ErrCheck(FMOD_Studio_EventInstance_SetTimelinePosition(instance_, pos));
    }

    float EventInstance::getVolume() const {
        float vol;
        float final_volume;
        ErrCheck(FMOD_Studio_EventInstance_GetVolume(instance_, &vol, &final_volume));
        return vol;
    }

    void EventInstance::setVolume(const float vol) {
        ErrCheck(FMOD_Studio_EventInstance_SetVolume(instance_, vol));
    }

    bool EventInstance::isVirtual() const {
        FMOD_BOOL virt;
        ErrCheck(FMOD_Studio_EventInstance_IsVirtual(instance_, &virt));
        return virt;
    }

    float EventInstance::getParameterByName(const std::string& name) const {
        float value;
        float final_value;
        ErrCheck(FMOD_Studio_EventInstance_GetParameterByName(instance_, name.c_str(), &value, &final_value));
        return value;
    }

    void EventInstance::setParameterByName(const std::string& name, float value, bool ignoreSeekSpeed) {
        ErrCheck(FMOD_Studio_EventInstance_SetParameterByName(instance_, name.c_str(), value, ignoreSeekSpeed));
    }

    void EventInstance::setParameterByNameWithLabel(const std::string& name, const std::string& label,
                                                    bool ignoreSeekSpeed) {
        ErrCheck(FMOD_Studio_EventInstance_SetParameterByNameWithLabel(instance_, name.c_str(), label.c_str(),
                                                                       ignoreSeekSpeed));
    }

    std::shared_ptr<FMOD_CHANNELGROUP> EventInstance::getChannelGroup() const {
        FMOD_CHANNELGROUP* group;
        ErrCheck(FMOD_Studio_EventInstance_GetChannelGroup(instance_, &group));

        std::shared_ptr<FMOD_CHANNELGROUP> ptr(group, [](FMOD_CHANNELGROUP* g) {
            FMOD_ChannelGroup_Release(g);
        });

        return ptr;
    }

    float EventInstance::getReverbLevel(int index) const {
        float reverb;
        ErrCheck(FMOD_Studio_EventInstance_GetReverbLevel(instance_, index, &reverb));
        return reverb;
    }

    void EventInstance::setReverbLevel(int index, float level) {
        ErrCheck(FMOD_Studio_EventInstance_SetReverbLevel(instance_, index, level));
    }

    FMOD_STUDIO_MEMORY_USAGE EventInstance::getMemoryUsage() const {
        FMOD_STUDIO_MEMORY_USAGE usage;
        ErrCheck(FMOD_Studio_EventInstance_GetMemoryUsage(instance_, &usage));
        return usage;
    }

    bool EventInstance::isValid() const {
        return FMOD_Studio_EventInstance_IsValid(instance_);
    }
} // Audio
