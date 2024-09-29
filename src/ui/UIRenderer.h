#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

namespace TerClone {

    class UIRenderer {
    public:
        virtual ~UIRenderer() = default;
        virtual void Render(sf::RenderWindow& window) = 0;
    };
}
