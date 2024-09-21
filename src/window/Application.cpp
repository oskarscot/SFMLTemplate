#include "Application.h"

#include <imgui-SFML.h>
#include <imgui.h>

#include "SFML/Graphics.hpp"

namespace TerClone
{

    Application::Application(const ApplicationWindowSpec &spec) {
        this->m_VideoMode.height = spec.height;
        this->m_VideoMode.width = spec.width;
        this->m_Window = new sf::RenderWindow(this->m_VideoMode, spec.title, spec.style);

        if(ImGui::SFML::Init(*this->m_Window))
        {
            ImGui::StyleColorsDark();
        }
    }

    Application::~Application()
    {
        ImGui::SFML::Shutdown();
        delete this->m_Window;
    }

    void Application::Update(const sf::Time deltaTime)
    {
        ImGui::SFML::Update(*this->m_Window, deltaTime);

        ImGui::Begin("Hello, world!");
        ImGui::Text("Application average %.3f ms/frame (%.0f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }

    void Application::Render()
    {
        this->m_Window->clear();

        ImGui::SFML::Render(*m_Window);
        this->m_Window->display();
    }

    void Application::PollEvents()
    {
        while(this->m_Window->pollEvent(this->m_Event))
        {
            ImGui::SFML::ProcessEvent(*this->m_Window, this->m_Event);
            switch (this->m_Event.type)
            {
                case sf::Event::KeyPressed:
                    if (this->m_Event.key.code == sf::Keyboard::Escape)
                    {
                        this->m_Window->close();
                    }

                case sf::Event::Closed:
                    this->m_Window->close();

                default:
            }
        }
    }

    bool Application::IsWindowOpen() const {
        return this->m_Window->isOpen();
    }
}
