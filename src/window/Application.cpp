#include "Application.h"
#include <unordered_map>

#include "SFML/Graphics.hpp"

namespace TerClone
{
    Application::Application(const ApplicationWindowSpec &spec)
        : m_Window(std::make_unique<sf::RenderWindow>(sf::VideoMode({spec.width, spec.height}), spec.title))
    {
        printf("Created Base window!\n");
    }

    std::unordered_map<int32_t, sf::RectangleShape> m_Shapes; // Temporary, remove me

    void Application::Run()
    {
        sf::Clock m_Clock;
        Load();
        while (m_Window->isOpen())
        {
            while (const std::optional<sf::Event> event = m_Window->pollEvent())
            {
                if (event->is<sf::Event::Closed>()){
                    m_Window->close();
                }
            }

            if (isKeyPressed(sf::Keyboard::Key::Escape)){
                m_Window->close();
            }
            const sf::Time deltaTime = m_Clock.restart();
            Update(deltaTime);
            m_Window->clear();
            Render();
            m_Window->display();
        }
    }

    void Application::Load()
    {
        sf::RectangleShape shape({50, 50});
        shape.setFillColor(sf::Color::Red);
        shape.setPosition({static_cast<float>(m_Window->getSize().x) / 2, static_cast<float>(m_Window->getSize().y) / 2});

        m_Shapes[0] = shape;
    }

    int speed = 150;

    void Application::Update(const sf::Time deltaTime)
    {

        if (isKeyPressed(sf::Keyboard::Key::A))
        {
            m_Shapes[0].move({-1 * (deltaTime.asSeconds() * speed), 0 });
        }

        if (isKeyPressed(sf::Keyboard::Key::D))
        {
            m_Shapes[0].move({1 * (deltaTime.asSeconds() * speed), 0 });
        }

        if (isKeyPressed(sf::Keyboard::Key::W))
        {
            m_Shapes[0].move({0, -1 * (deltaTime.asSeconds() * speed) });
        }

        if (isKeyPressed(sf::Keyboard::Key::S))
        {
            m_Shapes[0].move({0, 1 * (deltaTime.asSeconds() * speed) });
        }


    }

    void Application::Render()
    {
        for (const auto &[index, value] : m_Shapes)
        {
            m_Window->draw(value);
        }
    }
}
