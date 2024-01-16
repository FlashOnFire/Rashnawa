#ifndef PLAYERBEHAVIOR_H
#define PLAYERBEHAVIOR_H
#include "EntityBehavior.h"
#include "../../events/Events.h"


class PlayerBehavior : public EntityBehavior {
public:
    PlayerBehavior(std::shared_ptr<dexode::EventBus> event_bus, std::weak_ptr<Entity> entity);
private:
    void onPlayerAction(const Events::PlayerAction& event);

    void onTick(int deltaTime) override;
};



#endif //PLAYERBEHAVIOR_H
