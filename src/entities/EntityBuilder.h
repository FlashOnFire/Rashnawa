#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H


#include <unordered_map>

#include "Entities.h"
#include "Entity.h"
#include "dexode/EventBus.hpp"

class EntityBuilder {
public:
    explicit EntityBuilder(std::shared_ptr<dexode::EventBus> event_bus);

    std::unique_ptr<Entity> buildEntity(Entities entity_type);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;
    std::unordered_map<Entities, EntityPrototype> entity_prototypes_map_;
    std::map<std::string, std::weak_ptr<sf::Texture>> textures_map_;

    void populateEntitiesPrototypeMap();

    std::shared_ptr<sf::Texture> getTexture(const std::string& name);
};


#endif //ENTITYBUILDER_H
