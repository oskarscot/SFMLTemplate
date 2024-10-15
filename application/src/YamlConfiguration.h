#pragma once
#include <yaml-cpp/yaml.h>

#include "core/util/IConfiguration.h"

namespace TowerDefense {

    class YamlConfiguration : public sft::Util::IConfiguration {
        YAML::Node m_node;
        std::filesystem::path m_path;

        void SetDefaults();

    public:
        explicit YamlConfiguration(std::filesystem::path path);
        ~YamlConfiguration() override = default;

        void Save() override;
        void Load() override;

        template<typename T>
        T Get(const std::string &key) const
        {
            return m_node[key].as<T>();
        }
        template<typename T>
        void Set(const std::string &key, T value)
        {
            m_node[key] = value;
        }

        bool HasKey(const std::string& key) const;

        static std::unique_ptr<YamlConfiguration> CreateConfiguration(std::filesystem::path path);
    };


}
