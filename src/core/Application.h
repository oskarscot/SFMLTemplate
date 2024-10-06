#pragma once

#include "../ui/UIRenderer.h"
#include "entity/Player.h"
#include "util/Configuration.h"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Texture.hpp"
#include "SFML/System/String.hpp"
#include "SFML/Window/Event.hpp"

namespace TerClone
{
    struct ApplicationWindowSpec
    {
        uint32_t width{};
        uint32_t height{};
        sf::String title;
        sf::Uint32 style{};
    };

    class Application {
        sf::RenderWindow* m_pWindow = nullptr;
        sf::Event m_event{};
        sf::VideoMode m_videoMode;
        sf::Texture m_spriteSheet;
        UIRenderer* m_pImGuiRenderer = nullptr;
        Util::Configuration* m_pSettings = nullptr;
        std::vector<std::unique_ptr<Entity>> m_entities;

    public:
        explicit Application(const ApplicationWindowSpec& spec);
        virtual ~Application();

        void Update(sf::Time deltaTime);

        void Render();

        void PollEvents();

        bool IsWindowOpen() const;

        void AddEntity(std::unique_ptr<Entity> entity) {
            m_entities.emplace_back(std::move(entity));
        }
    };
}


