#include "Configuration.h"

#include <iostream>
#include <fstream>

namespace TerClone::Util
{
    Configuration::Configuration(std::filesystem::path path)
        : m_path(std::move(path))
    {
    }

    Configuration::~Configuration() = default;

    void Configuration::Save()
    {
        std::ofstream fout(m_path);
        if (!fout)
        {
            printf("Failed to open file for saving: %s\n", m_path.string().c_str());
            return;
        }

        fout << this->m_config;
        printf("Saved configuration to %s\n", m_path.string().c_str());
    }

    void Configuration::Load()
    {
        std::ifstream file(m_path);
        if (!file)
        {
            printf("File could not be opened: %s\n", m_path.c_str());
            printf("Writing default configuration...\n");

            Set("version", "1.0");
            Set("vsync", "true");
            Save();
            return;
        }

        this->m_config = YAML::LoadFile(m_path);
        if (this->m_config.IsNull())
        {
            printf("Failed to load configuration from %s, writing defaults.\n", m_path.c_str());
            Set("version", "1.0");
            Save();
        }
    }

    YAML::Node Configuration::GetNode()
    {
        return this->m_config;
    }

}