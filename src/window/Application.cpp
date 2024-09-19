#include "Application.h"

#include <imgui-SFML.h>
#include <imgui.h>

#include "SFML/Graphics.hpp"
#include "../entity/Player.h"

namespace TerClone
{

    sf::View m_View;
    Player player;

    Application::Application(const ApplicationWindowSpec &spec)
        : m_Window(std::make_unique<sf::RenderWindow>(
            sf::VideoMode({spec.width, spec.height}),
            spec.title,
            sf::Style::Close | sf::Style::Titlebar
            ))
    {
        printf("Application created\n");
        Load();
    }

    void Application::Run() const
    {
        sf::Clock m_Clock;
        while (m_Window->isOpen())
        {
            sf::Event event{};
            while (m_Window->pollEvent(event))
            {
                ImGui::SFML::ProcessEvent(*m_Window, event);
                if (event.type == sf::Event::Closed)
                {
                    m_Window->close();
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                m_Window->close();
            }
            const sf::Time deltaTime = m_Clock.restart();

            ImGui::SFML::Update(*m_Window, deltaTime);
            ImGui::Begin("Hello, world!");
            ImGui::Text("Hello!");
            ImGui::Text("Application average %.3f ms/frame (%.0f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::ColorEdit3("Colour", player.GetColour());
            ImGui::End();

            Update(deltaTime);
            m_Window->clear();
            Render();
            m_Window->display();
        }
        ImGui::SFML::Shutdown();
    }

    void Application::Load() const
    {
        ImGui::SFML::Init(*m_Window);
        ImGui::StyleColorsDark();
        ImGuiIO &io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGuiStyle &style = ImGui::GetStyle();
        style.Colors[ImGuiCol_WindowBg].w = 0.5f;

      //  m_View.setSize({static_cast<float>(m_Window->getSize().x), static_cast<float>(m_Window->getSize().y)});
      //  m_View.setCenter({static_cast<float>(m_Window->getSize().x) / 2, static_cast<float>(m_Window->getSize().y) / 2});

    }

    void Application::Update(const sf::Time deltaTime) const
    {
        player.Update(deltaTime);
       // m_View.setCenter(m_Shapes[0].getPosition());
       // m_Window->setView(m_View);
    }

    void Application::Render() const
    {
        // The first thing we render is the background.
        // This is important because it will be rendered first and will be the bottom layer.
        // Background
        m_Window->draw(player.GetShape());

        ImGui::SFML::Render(*m_Window);
    }
}