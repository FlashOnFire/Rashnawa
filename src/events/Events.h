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
}
#endif //RASHNAWA_EVENTS_H
