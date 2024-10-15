#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Sprite.hpp"
#include "SFML/Graphics/Texture.hpp"

namespace sft
{
    class Entity {
    protected:
        sf::Sprite m_sprite;
        sf::Texture m_texture;
        sf::Vector2f m_position;
        sf::Vector2f m_velocity;

    public:
        virtual ~Entity() = default;
        virtual void Update(float deltaTime) = 0;
        virtual void Render(sf::RenderWindow& window)
        {
            m_sprite.setPosition(m_position);
            window.draw(m_sprite);
        }

        void SetPosition(const sf::Vector2f& position)
        {
            m_position = position;
            m_sprite.setPosition(m_position);
        }
        void SetVelocity(const sf::Vector2f& velocity)
        {
            m_velocity = velocity;
        }
        void SetTexture(const sf::Texture& texture)
        {
            m_texture = texture;
            m_sprite.setTexture(m_texture);
        }

        void SetTexturePosition(const sf::Vector2i& position)
        {
            m_sprite.setTextureRect(sf::IntRect({ position.x * 32, position.y * 32}, { 32, 32 }));
        }
    };
}
