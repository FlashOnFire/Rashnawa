#ifndef RASHNAWA_EVENTS_H
#define RASHNAWA_EVENTS_H

#include <SFML/Window/Event.hpp>

#include "../screens/Screens.h"

namespace Events {

    struct CloseGame {
    };

    struct EscapeBtn {
    };

    struct ChangeScreen {
        Screens from;
        Screens to;
    };

    struct SwitchToOptionsScreen {
    };

    struct GoInGame {
    };

    struct MouseButtonPressed {
        sf::Event::MouseButtonEvent event;
    };

    struct MouseButtonReleased {
        sf::Event::MouseButtonEvent event;
    };
}
#endif //RASHNAWA_EVENTS_H
