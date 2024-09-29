#include "ImGuiRenderer.h"
#include <imgui.h>
#include "../core/settings/Configuration.h"

ImGuiRenderer::ImGuiRenderer(const TerClone::Utils::Configuration &config): m_config(config)
{
}

static std::string key_to_add(24, '\0');
static std::string value_to_add(24, '\0');
static std::string key_to_remove(24, '\0');

void ImGuiRenderer::Render(sf::RenderWindow &window)
{
    ImGui::Begin("Settings");
    ImGui::Text("Application average %.3f ms/frame (%.0f FPS)", 1000.0f / ImGui::GetIO().Framerate,
                ImGui::GetIO().Framerate);

    if (ImGui::BeginTabBar("ConfigTabBar"))
    {
        if (ImGui::BeginTabItem("Configuration Editor"))
        {
            ImGui::Text("Current Configuration");
            ImGui::Separator();

            for (YAML::const_iterator it = m_config.GetNode().begin(); it != m_config.GetNode().end(); ++it)
            {
                auto key = it->first.as<std::string>();
                auto value = it->second.as<std::string>();
                ImGui::Text("%s: %s", key.c_str(), value.c_str());
            }

            ImGui::Separator();

            // Add new config value
            ImGui::Text("Add/Update Configuration Value");
            ImGui::InputText("Key", key_to_add.data(), key_to_add.size());
            ImGui::InputText("Value", value_to_add.data(), value_to_add.size());

            if (ImGui::Button("Add/Update"))
            {
                if (!key_to_add.empty() && !value_to_add.empty())
                {
                    m_config.Set(key_to_add, value_to_add);
                    key_to_add.clear();
                    value_to_add.clear();
                }
            }

            ImGui::Separator();

            // Remove config value
            ImGui::Text("Remove Configuration Value");
            ImGui::InputText("Key to Remove", key_to_remove.data(), key_to_remove.size());

            if (ImGui::Button("Remove"))
            {
                if (!key_to_remove.empty())
                {
                    m_config.GetNode().remove(key_to_remove);
                    key_to_remove.clear();
                }
            }

            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();
        ImGui::End();
    }
}