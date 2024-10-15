#pragma once
#include "core/entity/Entity.h"

namespace TowerDefense {

    class Player: public sft::Entity {
    public:
        Player(const sf::Texture& texture, sf::Vector2i sprite_position);
        ~Player() override = default;

        void Update(float deltaTime) override;
    };

}
