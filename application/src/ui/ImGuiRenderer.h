#pragma once

#include "SFTemplate.h"
#include "../YamlConfiguration.h"
#include "SFML/Graphics/RenderWindow.hpp"

namespace TowerDefense
{
    class ImGuiRenderer final : public sft::UIRenderer {
        YamlConfiguration m_config;
    public:
        explicit ImGuiRenderer(const YamlConfiguration& config);
        ~ImGuiRenderer() override = default;

        void Render(sf::RenderWindow& window) override;
    };
}
