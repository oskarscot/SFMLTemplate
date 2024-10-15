#include "YamlConfiguration.h"

#include <iostream>

namespace TowerDefense
{
    YamlConfiguration::YamlConfiguration(std::filesystem::path  path)
        : m_path(std::move(path))
    {
    }

    void YamlConfiguration::Save()
    {
        std::ofstream fout(m_path);
        if (!fout)
        {
            std::cerr << "Failed to open file for saving: " << m_path << std::endl;
            return;
        }

        fout << m_node;
        std::cout << "Saved configuration to " << m_path << std::endl;
    }

    void YamlConfiguration::Load()
    {
        try
        {
            m_node = YAML::LoadFile(m_path);
        } catch (const YAML::Exception &e)
        {
            std::cerr << "Failed to load configuration from " << m_path << ": " << e.what() << std::endl;
            std::cout << "Writing default configuration..." << std::endl;
            SetDefaults();
            Save();
        }
    }

    bool YamlConfiguration::HasKey(const std::string &key) const
    {
        return m_node[key].IsDefined();
    }

    void YamlConfiguration::SetDefaults()
    {
        Set("version", 1.0);
        Set("vsync", true);
    }

    std::unique_ptr<YamlConfiguration> YamlConfiguration::CreateConfiguration(std::filesystem::path path)
    {
        return std::make_unique<YamlConfiguration>(std::move(path));
    }
}
