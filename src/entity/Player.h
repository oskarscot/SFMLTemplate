#pragma once

#include <SFML/Graphics.hpp>

namespace TerClone {

    class Player {
    public:
        Player();
        ~Player() = default;

        void Update(sf::Time deltaTime);

        sf::RectangleShape& GetShape() { return m_Shape; }
        float* GetColour() { return m_Colour; }
    private:
        sf::RectangleShape m_Shape{sf::Vector2f(50, 50)};
        float m_Colour[3]{1.f, 1.f, 1.f};
        float m_Speed{150.f};
    };
}