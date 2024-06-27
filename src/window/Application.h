#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/String.hpp"

namespace TerClone
{
    struct ApplicationWindowSpec
    {
        uint32_t width{};
        uint32_t height{};
        sf::String title;
    };

    class Application
    {
    public:
        explicit Application(const ApplicationWindowSpec& spec);
        ~Application() = default;

        void Run();
    protected:
        void Load();
        void Update(sf::Time deltaTime);
        void Render();
        std::unique_ptr<sf::RenderWindow> m_Window;
    };
}


