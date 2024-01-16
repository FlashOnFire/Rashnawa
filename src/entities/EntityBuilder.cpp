#include "EntityBuilder.h"

#include "../events/Events.h"
#include "SFML/Graphics/Texture.hpp"

EntityBuilder::EntityBuilder(std::shared_ptr<dexode::EventBus> event_bus) : event_bus_(std::move(event_bus)) {
    populateEntitiesPrototypeMap();
}

void EntityBuilder::populateEntitiesPrototypeMap() {
    using enum Entities;

    entity_prototypes_map_.try_emplace(GROUND, EntityPrototype{.name = "ground"});
    entity_prototypes_map_.try_emplace(PLAYER,
                                       EntityPrototype{
                                               .name = "halteroman", .has_animation = true, .hitbox = Hitbox(
                                                       1.0f, 1.0f, 1.0f, 1.0f)
                                       });
    entity_prototypes_map_.try_emplace(BEDS1, EntityPrototype{.name = "beds1"});
    entity_prototypes_map_.try_emplace(BEDS2, EntityPrototype{.name = "beds2"});
    entity_prototypes_map_.try_emplace(HUBLOT, EntityPrototype{.name = "hublot", .has_animation = true});
    entity_prototypes_map_.try_emplace(AFFICHE1, EntityPrototype{.name = "affiche1"});
    entity_prototypes_map_.try_emplace(AFFICHE2, EntityPrototype{.name = "affiche2"});
    entity_prototypes_map_.try_emplace(PLINTH, EntityPrototype{.name = "plinth"});
    entity_prototypes_map_.try_emplace(STUFF1, EntityPrototype{.name = "stuff1"});
    entity_prototypes_map_.try_emplace(STUFF2, EntityPrototype{.name = "stuff2"});
    entity_prototypes_map_.try_emplace(STUFF3, EntityPrototype{.name = "stuff3"});
    entity_prototypes_map_.try_emplace(STUFF4, EntityPrototype{.name = "stuff4"});
    entity_prototypes_map_.try_emplace(LIGHTS, EntityPrototype{.name = "lights", .has_animation = true});
    entity_prototypes_map_.try_emplace(REFLECT, EntityPrototype{.name = "reflect"});
    entity_prototypes_map_.try_emplace(ROBIM, EntityPrototype{.name = "robim"});
}

std::unique_ptr<Entity> EntityBuilder::buildEntity(Entities entity_type) {
    const auto prototype = entity_prototypes_map_.find(entity_type)->second;
    auto texture = getTexture(prototype.name);
    std::unique_ptr<Entity> entity;

    if (prototype.has_animation) {
        entity = std::make_unique<Entity>(std::move(texture), prototype.name);
        event_bus_->postpone<Events::AnimationCreated>({entity->getAnimation().value()});
    } else {
        entity = std::make_unique<Entity>(std::move(texture));
    }

    if (prototype.hitbox.has_value()) {
        entity->setHitbox(prototype.hitbox.value());
    }

    if (!prototype.patterns.empty()) {
        entity->setPatterns(prototype.patterns);
    }

    return entity;
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

        textures_map_.try_emplace(name, texture);

        return texture;
    }
}
