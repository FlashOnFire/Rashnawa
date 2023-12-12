#include "Room.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>

Room::Room(std::string zone_name, std::string room_name, const std::shared_ptr<EntityBuilder>& builder)
        : zone_name_(std::move(zone_name)), room_name_(std::move(room_name)) {
    std::string folder = "../assets/map/zone_" + zone_name_ + "/room_" + room_name_;
    std::ifstream room_file(folder + "/room.txt");

    if (!room_file.is_open()) {
        std::cerr << "Cannot open Room file" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;

    room_file >> size_.x >> size_.y;

    getline(room_file >> std::ws, line);
    if (!background_texture_->loadFromFile(folder + "/" + line)) {
        std::cerr << "Cannot load room_" + room_name_ + "'s background" << std::endl;
        exit(EXIT_FAILURE);
    }

    room_file >> spawnpoint_.x >> spawnpoint_.y;

    std::ifstream entity_file(folder + "/entities.txt");
    if (!entity_file.is_open()) {
        std::cerr << "Cannot open Entity file" << std::endl;
        exit(EXIT_FAILURE);
    }

    int id;
    std::string entity_name;
    float x = 0;
    float y = 0;

    float scale_x = 0;
    float scale_y = 0;

    while (!entity_file.eof()) {
        entity_file >> id;
        entity_file >> entity_name;
        entity_file >> x;
        entity_file >> y;
        entity_file >> scale_x;
        entity_file >> scale_y;

        std::unique_ptr<Entity> entity = builder->buildEntity(static_cast<Entities>(id));
        entity->setPosition(x, y);
        entity->setScale(scale_x, scale_y);
        entities_->push_back(std::move(entity));
    }

    std::ifstream trigger_file(folder + "/triggers.txt");
    if (!entity_file.is_open()) {
        std::cerr << "Cannot open Trigger file" << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string word;

    std::string name;
    sf::IntRect rect;
    int uses = 0;
    int cooldown = 0;
    TriggerType type;

    Events::Triggers::TriggerAction action{};
    std::vector<std::string> args;

    while (!trigger_file.eof()) {
        while (getline(trigger_file >> std::ws, line)) {
            std::stringstream stream(line);
            stream >> name;
            stream >> rect.left >> rect.top >> rect.width >> rect.height;
            stream >> uses;
            stream >> cooldown;
            stream >> word;
            type = TriggerBox::trigger_type_map_.find(word)->second;
            stream >> word;

            switch (type) {
                using enum TriggerType;

                case SOUND:
                    action.sound = TriggerBox::trigger_sound_action_map_.find(word)->second;
                    break;
                case WORLD:
                    action.world = TriggerBox::trigger_world_action_map_.find(word)->second;
                    break;
                case CUTSCENE:
                    action.cutscene = TriggerBox::trigger_cutscene_action_map_.find(word)->second;
                    break;
            }

            while (!stream.eof()) {
                stream >> word;
                args.push_back(word);
            }
        }
        triggers_->push_back(std::make_unique<TriggerBox>(name, rect, uses, cooldown, type, action, args));

    }
}

std::shared_ptr<std::vector<std::unique_ptr<Entity>>> Room::getEntities() const {
    return entities_;
}

std::shared_ptr<std::vector<std::unique_ptr<TriggerBox>>> Room::getTriggers() const {
    return triggers_;
}

std::shared_ptr<sf::Texture> Room::getBackgroundTexture() const {
    return background_texture_;
}

sf::Vector2i Room::getSize() const {
    return size_;
}