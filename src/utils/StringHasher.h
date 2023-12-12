#ifndef RASHNAWA_STRINGHASHER_H
#define RASHNAWA_STRINGHASHER_H

#include <string_view>

struct StringHash {
    using is_transparent = void; // enables heterogeneous lookup

    std::size_t operator()(std::string_view sv) const {
        std::hash<std::string_view> hasher;
        return hasher(sv);
    }
};

#endif //RASHNAWA_STRINGHASHER_H
