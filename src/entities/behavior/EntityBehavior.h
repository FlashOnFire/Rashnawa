#ifndef ENTITYBEHAVIOR_H
#define ENTITYBEHAVIOR_H


#include <dexode/EventBus.hpp>

class Entity;

class EntityBehavior {
public:
    EntityBehavior() = delete;
    virtual ~EntityBehavior() = default;
protected:
    EntityBehavior(std::shared_ptr<dexode::EventBus> event_bus, std::weak_ptr<Entity> entity);

    virtual void onTick(int deltaTime) = 0;

    std::shared_ptr<dexode::EventBus> event_bus_;
    std::unique_ptr<dexode::EventBus::Listener> listener_;
    std::weak_ptr<Entity> entity_;
};


#endif //ENTITYBEHAVIOR_H
