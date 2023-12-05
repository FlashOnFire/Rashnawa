#ifndef RASHNAWA_TRIGGERBOX_H
#define RASHNAWA_TRIGGERBOX_H

#include <SFML/Graphics.hpp>

enum class TriggerType {
    MUSIC,
    PLAYER,
    CUTSCENE,
    ROOM
};

static std::unordered_map<std::string,TriggerType> const triggerMap = { {"MUSIC",TriggerType::MUSIC}, {"PLAYER",TriggerType::PLAYER}, {"CUTSCENE",TriggerType::CUTSCENE}, {"ROOM",TriggerType::ROOM} };

class TriggerBox {
public:
    TriggerBox(std::string name, sf::IntRect rect, TriggerType type, std::string action, std::vector<std::string> args);

private:
    std::string name_;
    sf::IntRect rect_;
    TriggerType type_;
    std::string action_;
    std::vector<std::string> args_;

};


#endif //RASHNAWA_TRIGGERBOX_H
