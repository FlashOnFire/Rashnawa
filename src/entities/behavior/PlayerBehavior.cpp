#include "PlayerBehavior.h"
#include "../data/EntityData.h"

#include "../Entity.h"

PlayerBehavior::PlayerBehavior(std::shared_ptr<dexode::EventBus> event_bus,
                               std::weak_ptr<Entity> entity) : EntityBehavior(std::move(event_bus), std::move(entity)) {
    listener_ = std::make_unique<dexode::EventBus::Listener>(event_bus_);

    listener_->listen([this](const Events::PlayerAction& event) {
        onPlayerAction(event);
    });
}

void PlayerBehavior::onPlayerAction(const Events::PlayerAction& event) {
    if (entity_.expired()) {
        // shouldn't happen
        std::cerr << "[PlayerBehavior] Entity pointer null ???" << std::endl;
    } else {
        const std::shared_ptr<Entity> entity_ptr = entity_.lock();
        const std::shared_ptr<EntityData> data = entity_ptr->getEntityData();

        if (event.pressed) {
            switch (event.keybinds) {
                case Keybinds::LEFT:
                    data->player.facing_left = true;
                    data->player.move_left = true;
                break;
                case Keybinds::RIGHT:
                    data->player.facing_left = false;
                    data->player.move_right = true;
                break;
                case Keybinds::JUMP:
                    data->player.jumping = true;
                    data->player.on_ground = false;
                break;
                case Keybinds::DASH:
                    if (!data->player.has_dashed)
                        data->player.dashing = true;
                break;
                case Keybinds::ATTACK:
                    data->player.using_weapon = true;
                break;
                default:
                    break;
            }
        } else {
            switch (event.keybinds) {
                case Keybinds::LEFT:
                    data->player.move_left = false;
                    data->player.facing_left = !data->player.move_right;
                break;
                case Keybinds::RIGHT:
                    data->player.move_right = false;
                    data->player.facing_left = data->player.move_left;
                break;
                default:
                    break;
            }
        }
    }
}

void PlayerBehavior::onTick(int deltaTime) {
    if (entity_.expired()) {
        // shouldn't happen
        std::cerr << "[PlayerBehavior] Entity pointer null ???" << std::endl;
    } else {
        const std::shared_ptr<Entity> entity_ptr = entity_.lock();
        const std::shared_ptr<EntityData> data = entity_ptr->getEntityData();

        const sf::Vector2f pos = entity_ptr->getPosition();
        if (!(data->player.move_left && data->player.move_right)) {
            entity_ptr->setPosition(pos.x + static_cast<float>((data->player.move_left ? -1 : 1) * 200.0 * deltaTime), pos.y);
        }
    }
}
