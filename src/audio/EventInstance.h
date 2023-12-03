#ifndef RASHNAWA_AUDIO_EVENTINSTANCE_H
#define RASHNAWA_AUDIO_EVENTINSTANCE_H

#include <string>
#include <memory>
#include <FMOD/fmod_studio_common.h>

namespace Audio {
    class EventInstance {
    public:
        explicit EventInstance(FMOD_STUDIO_EVENTINSTANCE* instance);

        ~EventInstance();

        void start();

        void stop(FMOD_STUDIO_STOP_MODE mode);

        [[nodiscard]] FMOD_STUDIO_PLAYBACK_STATE getPlaybackState() const;

        // Pause
        [[nodiscard]] bool isPaused() const;

        void setPaused(bool paused);

        void togglePaused();

        void keyOff() const;

        [[nodiscard]] float getPitch() const;

        void setPitch(float pitch);

        [[nodiscard]] float getProperty(FMOD_STUDIO_EVENT_PROPERTY index) const;

        void setProperty(FMOD_STUDIO_EVENT_PROPERTY index, float value);

        [[nodiscard]] int getTimelinePosition() const;

        void setTimelinePosition(int pos);

        // Volume
        [[nodiscard]] float getVolume() const;

        void setVolume(float vol);

        [[nodiscard]] bool isVirtual() const;

        /********************************************************************/
        /** Skipped 3D attributes and functions since we are in a 2D game  **/
        /********************************************************************/

        [[nodiscard]] float getParameterByName(const std::string& name) const;

        void setParameterByName(const std::string& name, float value, bool ignoreSeekSpeed = false);

        void setParameterByNameWithLabel(const std::string& name, const std::string& label, bool ignoreSeekSpeed);

        [[nodiscard]] std::shared_ptr<FMOD_CHANNELGROUP> getChannelGroup() const;

        [[nodiscard]] float getReverbLevel(int index) const;

        void setReverbLevel(int index, float level);

        // two values, must create a struct for this : void getCPUUsage(int *exclusive, int *inclusive) const;
        [[nodiscard]] FMOD_STUDIO_MEMORY_USAGE getMemoryUsage() const;

        [[nodiscard]] bool isValid() const;

    private:
        FMOD_STUDIO_EVENTINSTANCE* instance_;
    };
} // Audio

#endif //RASHNAWA_AUDIO_EVENTINSTANCE_H
