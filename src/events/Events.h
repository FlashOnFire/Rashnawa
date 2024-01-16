#ifndef RASHNAWA_EVENTS_H
#define RASHNAWA_EVENTS_H


#include <memory>

#include "../screens/Screens.h"
#include "Keybinds.h"
#include "../graphics/Animations.h"
#include "../storage/options/OptionDataStructs.h"

namespace Events {
    struct CloseGame {
    };

    struct EscapeBtn {
    };

    struct ChangeScreen {
        Screens from;
        Screens to;
    };

    struct PlayerAction {
        Keybinds keybinds;
        bool pressed;
    };

    struct AnimationCreated {
        std::weak_ptr<Animation> animation;
    };

    namespace Options {
        struct SoundOptionChangeEvent {
            SoundOptionType type;
            GenericOption value;
        };

        struct GraphicsOptionChangeEvent {
            GraphicsOptionType type;
            GenericOption value;
        };
    }

    namespace Triggers {
        namespace Sound {
            struct TriggerMusicStartEvent {
                std::string name;
            };

            struct TriggerMusicStopEvent {
            };

            struct TriggerMusicParameterSetEvent {
                std::string parameter_name;
                float value;
            };

            struct TriggerMusicGlobalParameterSetEvent {
                std::string parameter_name;
                float value;
            };
        }

        namespace World {
            struct TriggerRoomChangeEvent {
                std::string room;
            };

            struct TriggerZoneChangeEvent {
                std::string zone;
                std::string room;
            };
        }

        namespace Cutscene {
            struct TriggerCutsceneStartEvent {
                std::string cutscene_name;
            };

            struct TriggerCutsceneSkipEvent {
            };
        }

        enum class TriggerSoundAction {
            START,
            STOP,
            PARAMETER_SET,
            GLOBAL_PARAMETER_SET
        };

        enum class TriggerWorldAction {
            ZONE_CHANGE,
            ROOM_CHANGE
        };

        enum class TriggerCutsceneAction {
            START,
            SKIP
        };

        union TriggerAction {
            TriggerSoundAction sound;
            TriggerWorldAction world;
            TriggerCutsceneAction cutscene;
        };
    }
}


#endif //RASHNAWA_EVENTS_H
