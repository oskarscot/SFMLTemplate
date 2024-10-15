#include "ImGuiRenderer.h"
#include <imgui.h>

namespace TowerDefense
{
    ImGuiRenderer::ImGuiRenderer(const YamlConfiguration &config): m_config(config)
    {
    }

    void ImGuiRenderer::Render(sf::RenderWindow &window)
    {
        ImGui::Begin("Settings");
        ImGui::Text("Application average %.3f ms/frame (%.0f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                    ImGui::GetIO().Framerate);
        ImGui::End();
    }
}