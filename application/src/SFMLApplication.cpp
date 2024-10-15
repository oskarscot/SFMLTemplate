#include "SFMLApplication.h"

#include <imgui-SFML.h>
#include <imgui.h>
#include <iostream>

#include "SFTemplate.h"
#include "YamlConfiguration.h"
#include "entity/Player.h"
#include "ui/ImGuiRenderer.h"

namespace TowerDefense
{
    SFMLApplication::SFMLApplication(const sft::ApplicationWindowSpec& spec) {
        m_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(spec.width, spec.height), spec.title, spec.style);
        m_settings = YamlConfiguration::CreateConfiguration(std::filesystem::path("resources/setting.yml"));
        m_settings->Load();

        m_spriteSheet.loadFromFile("resources/assets/sheet.png");

        if (m_settings->Get<bool>("vsync")) {
            m_window->setVerticalSyncEnabled(true);
        }

        if (!ImGui::SFML::Init(*this->m_window))
        {
            throw std::runtime_error("Failed to initialize ImGui SFML Window");
        }
        ImGui::StyleColorsDark();
        this->m_imGuiRenderer = std::make_unique<ImGuiRenderer>(*this->m_settings);
        SFMLApplication::AddEntity(std::make_unique<Player>(m_spriteSheet, sf::Vector2i(0, 0)));
    }

    SFMLApplication::~SFMLApplication() {
        ImGui::SFML::Shutdown();
    }

    void SFMLApplication::Update(const sf::Time deltaTime) {
        ImGui::SFML::Update(*this->m_window, deltaTime);

        for (auto& entity : m_entities) {
            if (entity) {
                entity->Update(deltaTime.asSeconds());
            }
        }
    }

    void SFMLApplication::Render() {
        m_window->clear();

        for (auto& entity : m_entities) {
            if (entity) {
                entity->Render(*m_window);
            }
        }

        m_imGuiRenderer->Render(*m_window);
        ImGui::SFML::Render(*m_window);
        m_window->display();
    }

    void SFMLApplication::PollEvents() {
        while (m_window->pollEvent(m_event)) {
            ImGui::SFML::ProcessEvent(*m_window, m_event);
            switch (m_event.type) {
                case sf::Event::KeyPressed:
                    if (m_event.key.code == sf::Keyboard::Escape) {
                        m_window->close();
                    }
                return;
                case sf::Event::Closed:
                    m_window->close();
                return;
                default:
                    break;
            }
        }
    }

    bool SFMLApplication::IsWindowOpen() const {
        return m_window->isOpen();
    }

    void SFMLApplication::AddEntity(std::unique_ptr<sft::Entity> entity) {
        m_entities.emplace_back(std::move(entity));
    }

    std::unique_ptr<sft::IApplication> CreateApplication(const sft::ApplicationWindowSpec& spec) {
        return std::make_unique<SFMLApplication>(spec);
    }
}
