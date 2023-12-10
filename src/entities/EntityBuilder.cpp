#include "EntityBuilder.h"
#include "../events/Events.h"
#include "SFML/Graphics/Texture.hpp"

EntityBuilder::EntityBuilder(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    populateEntitiesPrototypeMap();
}

void EntityBuilder::populateEntitiesPrototypeMap() {
    entity_prototypes_map_.emplace(Entities::GROUND, EntityPrototype{.name = "ground", .has_animation = false});
    entity_prototypes_map_.emplace(Entities::PLAYER, EntityPrototype{.name = "halteroman", .has_animation = true});
}

std::unique_ptr<Entity> EntityBuilder::buildEntity(Entities entity_type) {
    const auto prototype = entity_prototypes_map_.find(entity_type)->second;
    auto texture = getTexture(prototype.name);

    if (prototype.has_animation) {
        auto entity = std::make_unique<Entity>(std::move(texture), prototype.name);
        event_bus_->postpone<Events::AnimationCreated>({entity->getAnimation().value()});

        return entity;
    }

    return std::make_unique<Entity>(std::move(texture));
}

std::shared_ptr<sf::Texture> EntityBuilder::getTexture(const std::string &name) {
    if (textures_map_.contains(name) && !textures_map_.at(name).expired()) {
        return textures_map_.at(name).lock();
    } else {
        std::shared_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();

        if (!texture->loadFromFile("../assets/sprites/" + name + ".png")) {
            std::cerr << "Can't load " << name << ".png, You are so disappointed  :(" << std::endl;
            texture->loadFromFile("../assets/sprites/default.png");
        }
        textures_map_.emplace(name, texture);

        return texture;
    }
}
