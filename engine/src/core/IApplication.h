#pragma once

#include <memory>

#include <SFML/Config.hpp>

#include "entity/Entity.h"
#include "SFML/System/String.hpp"
#include "SFML/System/Time.hpp"
#include "Core.h"

namespace sft {

    struct ApplicationWindowSpec {
        uint32_t width{};
        uint32_t height{};
        sf::String title;
        sf::Uint32 style{};
    };

    class IApplication {
    public:
        virtual ~IApplication() = default;

        virtual void Update(sf::Time deltaTime) = 0;
        virtual void Render() = 0;
        virtual void PollEvents() = 0;
        virtual bool IsWindowOpen() const = 0;
        virtual void AddEntity(std::unique_ptr<Entity> entity) = 0;
    };
}
