#include "Application.h"

#include "SFML/Graphics.hpp"

namespace TerClone
{
    Application::Application(const ApplicationWindowSpec &spec)
        : m_Window(std::make_unique<sf::RenderWindow>(sf::VideoMode({spec.width, spec.height}), spec.title))
    {
        printf("Created Base window!\n");
    }

    void Application::Run()
    {
        sf::Clock m_Clock;
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

    void Application::Update(sf::Time deltaTime)
    {
    }

    void Application::Render()
    {
    }
}
