#include "Application.h"

#include <imgui-SFML.h>
#include <imgui.h>

#include "../ui/ImGuiRenderer.h"
#include "SFML/Graphics.hpp"

namespace TerClone
{

    Application::Application(const ApplicationWindowSpec &spec) {
        this->m_videoMode.height = spec.height;
        this->m_videoMode.width = spec.width;
        this->m_pWindow = new sf::RenderWindow(this->m_videoMode, spec.title, spec.style);

        this->m_pSettings = new Utils::Configuration("settings.yaml");
        this->m_pSettings->Load();

        if(ImGui::SFML::Init(*this->m_pWindow))
        {
            ImGui::StyleColorsDark();
            this->m_pImGuiRenderer = new ImGuiRenderer(*this->m_pSettings);
        } else
        {
            printf("Failed to initialize ImGui SFML Window\n");
        }


    }

    Application::~Application()
    {
        ImGui::SFML::Shutdown();
        delete this->m_pWindow;
    }

    void Application::Update(const sf::Time deltaTime)
    {
        if(this->m_pImGuiRenderer)
            ImGui::SFML::Update(*this->m_pWindow, deltaTime);

        // Continue
    }

    void Application::Render()
    {
        this->m_pWindow->clear();

        // Last thing to render as we want this on the top layer.
        if(this->m_pImGuiRenderer)
        {
            this->m_pImGuiRenderer->Render(*this->m_pWindow);
            ImGui::SFML::Render(*this->m_pWindow);
        }
        this->m_pWindow->display();
    }

    void Application::PollEvents()
    {
        while(this->m_pWindow->pollEvent(this->m_event))
        {
            ImGui::SFML::ProcessEvent(*this->m_pWindow, this->m_event);
            switch (this->m_event.type)
            {
                case sf::Event::KeyPressed:
                {
                    if (this->m_event.key.code == sf::Keyboard::Escape)
                    {
                        this->m_pWindow->close();
                    }
                    return;
                }

                case sf::Event::Closed:
                {
                    this->m_pWindow->close();
                    return;
                }
                default: ;
            }
        }
    }

    bool Application::IsWindowOpen() const
    {
        return this->m_pWindow->isOpen();
    }
}
