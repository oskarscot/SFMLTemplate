#pragma once

#include "SFML/Graphics/RenderWindow.hpp"

namespace sft {

    class SFT_API UIRenderer {
    public:
        virtual ~UIRenderer() = default;
        virtual void Render(sf::RenderWindow& window) = 0;
    };
}
