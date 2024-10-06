#pragma once

#include "UIRenderer.h"
#include "../core/util/Configuration.h"

class ImGuiRenderer final : public TerClone::UIRenderer {
    TerClone::Util::Configuration m_config;
    public:
    explicit ImGuiRenderer(const TerClone::Util::Configuration& config);
    ~ImGuiRenderer() override = default;

    void Render(sf::RenderWindow& window) override;
};
