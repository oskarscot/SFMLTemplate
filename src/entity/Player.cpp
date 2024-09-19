#include "Player.h"

namespace TerClone {

    Player::Player()
    {
        m_Shape.setFillColor(sf::Color::Green);
        m_Shape.setPosition({100, 100});
    }

    void Player::Update(const sf::Time deltaTime)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            m_Shape.move({-1 * (deltaTime.asSeconds() * m_Speed), 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            m_Shape.move({1 * (deltaTime.asSeconds() * m_Speed), 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            m_Shape.move({0, -1 * (deltaTime.asSeconds() * m_Speed)});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            m_Shape.move({0, 1 * (deltaTime.asSeconds() * m_Speed)});
        }
    }
}