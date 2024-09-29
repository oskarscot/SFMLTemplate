#pragma once

#include "UIRenderer.h"
#include "../core/settings/Configuration.h"

class ImGuiRenderer final : public TerClone::UIRenderer {
    TerClone::Utils::Configuration m_config;
    public:
    explicit ImGuiRenderer(const TerClone::Utils::Configuration& config);
    ~ImGuiRenderer() override = default;

    void Render(sf::RenderWindow& window) override;
};
