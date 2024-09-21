#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
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
        sf::RenderWindow* m_Window = nullptr;
        sf::Event m_Event;
        sf::VideoMode m_VideoMode;

    public:
        explicit Application(const ApplicationWindowSpec& spec);
        virtual ~Application();

        void Update(sf::Time deltaTime);

        void Render();

        void PollEvents();

        bool IsWindowOpen() const;
    };
}


