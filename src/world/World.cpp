#include "World.h"
#include "../Defines.h"
#include <filesystem>
#include <utility>

World::World(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    entity_builder_ = std::make_shared<EntityBuilder>(event_bus_);
    std::cout << "Created World!" << std::endl;
}

std::shared_ptr<Room> World::getCurrentRoom() const {
    return current_room_;
}

void World::load(const std::string &zone_name, const std::string &room_name) {
    if (current_zone_name_ != zone_name) {
        current_zone_name_ = zone_name;
        loaded_rooms_.clear();

        std::string zone_folder = ASSETS_DIR + "map/" + zone_name;
        for (const auto &room_folder: std::filesystem::directory_iterator(zone_folder)) {
            std::string temp_room_name = room_folder.path().filename().string();
            loaded_rooms_.emplace_back(std::make_shared<Room>(zone_name, temp_room_name, entity_builder_));
        }

        std::cout << "Zone loaded!" << std::endl;
    }
    for (const auto &room: loaded_rooms_) {
        if (room->getRoomName() == room_name) {
            current_room_ = room;
        }
    }

    std::cout << "Room loaded!" << std::endl;
}