#include "Application.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <unordered_map>

#include "SFML/Graphics.hpp"

namespace TerClone
{

    std::unordered_map<int32_t, sf::RectangleShape> m_Shapes; // Temporary, remove me
    sf::View m_View;
    float color[3] = {1.f, 1.f, 1.f};

    Application::Application(const ApplicationWindowSpec &spec)
        : m_Window(std::make_unique<sf::RenderWindow>(
            sf::VideoMode({spec.width, spec.height}),
            spec.title,
            sf::Style::Close | sf::Style::Titlebar
            ))
    {
        printf("Application created\n");
    }

    void Application::Run() const
    {
        sf::Clock m_Clock;
        Load();
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

            ImGui::SFML::Update(*m_Window, m_Clock.restart());
            ImGui::Begin("Hello, world!");
            ImGui::Text("Hello!");
            // sfml color picker
            ImGui::ColorEdit3("Color", color);
            m_Shapes[0].setFillColor(sf::Color(color[0] * 255, color[1] * 255, color[2] * 255));
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::End();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            {
                m_Window->close();
            }
            const sf::Time deltaTime = m_Clock.restart();
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

        m_View.setSize({static_cast<float>(m_Window->getSize().x), static_cast<float>(m_Window->getSize().y)});
        m_View.setCenter({static_cast<float>(m_Window->getSize().x) / 2, static_cast<float>(m_Window->getSize().y) / 2});

        sf::RectangleShape shape({50, 50});
        shape.setFillColor(sf::Color::Red);
        shape.setPosition({static_cast<float>(m_Window->getSize().x) / 2, static_cast<float>(m_Window->getSize().y) / 2});

        m_Shapes[0] = shape;
    }

    int speed = 150;

    void Application::Update(const sf::Time deltaTime) const
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
            m_Shapes[0].move({-1 * (deltaTime.asSeconds() * speed), 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        {
            m_Shapes[0].move({1 * (deltaTime.asSeconds() * speed), 0});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        {
            m_Shapes[0].move({0, -1 * (deltaTime.asSeconds() * speed)});
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        {
            m_Shapes[0].move({0, 1 * (deltaTime.asSeconds() * speed)});
        }

        m_View.setCenter(m_Shapes[0].getPosition());
        m_Window->setView(m_View);
    }

    void Application::Render() const
    {
        for (const auto &[index, value] : m_Shapes)
        {
            m_Window->draw(value);
        }
        ImGui::SFML::Render(*m_Window);
    }
}