#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H


#include <unordered_map>

#include "Entities.h"
#include "Entity.h"
#include "dexode/EventBus.hpp"
#include "../utils/StringHasher.h"

class EntityBuilder {
public:
    explicit EntityBuilder(std::shared_ptr<dexode::EventBus> event_bus);

    [[nodiscard]] std::unique_ptr<Entity> buildEntity(Entities entity_type);

private:
    std::shared_ptr<dexode::EventBus> event_bus_;
    std::unordered_map<Entities, EntityPrototype> entity_prototypes_map_;
    std::unordered_map<std::string, std::weak_ptr<sf::Texture>, StringHash, std::equal_to<>> textures_map_;

    void populateEntitiesPrototypeMap();

    std::shared_ptr<sf::Texture> getTexture(const std::string &name);
};


#endif //ENTITYBUILDER_H
