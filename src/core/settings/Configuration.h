#pragma once

#include <fstream>
#include <yaml-cpp/yaml.h>

namespace TerClone::Utils
{
    class Configuration
    {
        YAML::Node m_config;
        std::filesystem::path m_path;

        public:
        explicit Configuration(std::filesystem::path path);
        ~Configuration();

        void Save();
        void Load();

        template<typename T>
        T Get(const std::string& key);

        template<typename T>
        void Set(const std::string& key, T value);

        YAML::Node GetNode();
    };

    /*
     * When templates are defined, their actual instantiation occurs where they are used.
     * If the template definition is not visible in the translator that uses it,
     * the linker won’t know how to generate the code for the specific instantiation.
    */

    template <typename T>
    void Configuration::Set(const std::string& key, T value)
    {
        m_config[key] = value;
    }

    template <typename T>
    T Configuration::Get(const std::string& key)
    {
        return m_config[key].as<T>();
    }
}
