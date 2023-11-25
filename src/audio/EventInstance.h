#ifndef RASHNAWA_AUDIO_EVENTINSTANCE_H
#define RASHNAWA_AUDIO_EVENTINSTANCE_H

#include "FMOD/fmod_studio.hpp"
#include <string>
#include <memory>
#include "Utils.hpp"

using namespace FMOD;

namespace Audio {

    class EventInstance {
    public:
        explicit EventInstance(std::unique_ptr<Studio::EventInstance, EventInstanceDeleter>);

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

        [[nodiscard]] float getProperty(FMOD_STUDIO_EVENT_PROPERTY index);

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

        float getParameterByName(const std::string &name);

        void setParameterByName(const std::string &name, float value, bool ignoreSeekSpeed);

        void setParameterByNameWithLabel(const std::string &name, const std::string &label, bool ignoreSeekSpeed);

        [[nodiscard]] std::shared_ptr<ChannelGroup> getChannelGroup() const;

        [[nodiscard]] float getReverbLevel(int index) const;

        void setReverbLevel(int index, float level);

        // two values, must create a struct for this : void getCPUUsage(int *exclusive, int *inclusive) const;
        [[nodiscard]] FMOD_STUDIO_MEMORY_USAGE getMemoryUsage() const;

        bool isValid();

    private:
        std::unique_ptr<Studio::EventInstance, EventInstanceDeleter> _instance;
    };

} // Audio

#endif //RASHNAWA_AUDIO_EVENTINSTANCE_H