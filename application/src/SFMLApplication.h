#pragma once

#include "SFTemplate.h"
#include "YamlConfiguration.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/Window/Event.hpp"

namespace TowerDefense {

    class SFMLApplication : public sft::IApplication {
        std::unique_ptr<sf::RenderWindow> m_window;
        sf::Event m_event{};
        sf::VideoMode m_videoMode;
        sf::Texture m_spriteSheet;
        std::unique_ptr<YamlConfiguration> m_settings;
        std::unique_ptr<sft::UIRenderer> m_imGuiRenderer;
        std::vector<std::unique_ptr<sft::Entity>> m_entities;

    public:
        explicit SFMLApplication(const sft::ApplicationWindowSpec& spec);
        ~SFMLApplication() override;

        void Update(sf::Time deltaTime) override;
        void Render() override;
        void PollEvents() override;
        bool IsWindowOpen() const override;
        void AddEntity(std::unique_ptr<sft::Entity> entity) override;
    };

}
