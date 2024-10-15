#include "Player.h"

#include "SFML/Window/Keyboard.hpp"

namespace TowerDefense {
    Player::Player(const sf::Texture &texture, sf::Vector2i sprite_position)
    {
        SetTexture(texture);
        SetTexturePosition(sprite_position);
    }

    void Player::Update(float deltaTime)
    {
        sf::Vector2f direction(0.f, 0.f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            direction.y -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            direction.y += 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            direction.x -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            direction.x += 1.f;
        }

        if (direction.x != 0.f && direction.y != 0.f)
        {
            direction /= std::sqrt(2.f);
        }

        const sf::Vector2f movement = direction * (125 * deltaTime);
        m_position += movement;

        SetPosition(m_position);
    }
}
