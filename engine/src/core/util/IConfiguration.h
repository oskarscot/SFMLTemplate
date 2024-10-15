#pragma once

#include <any>
#include <fstream>

namespace sft::Util
{
    class IConfiguration {
    public:
        virtual ~IConfiguration() = default;

        virtual void Save() = 0;
        virtual void Load() = 0;
    };

    // Factory function
    std::unique_ptr<IConfiguration> CreateConfiguration(const std::filesystem::path& path);
}
