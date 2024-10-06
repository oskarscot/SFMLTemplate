#pragma once
#include "Entity.h"

namespace TerClone {

    class Player: public Entity {
    public:
        Player(const sf::Texture& texture, sf::Vector2i sprite_position);
        ~Player() override = default;

        void Update(float deltaTime) override;
    };

}
