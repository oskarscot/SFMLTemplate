
#include "SFMLApplication.h"
#include "SFTemplate.h"
#include "SFML/System/Clock.hpp"
#include "SFML/Window/WindowStyle.hpp"

int main() {
    sft::ApplicationWindowSpec spec{1280, 720, "My Game", sf::Style::Close | sf::Style::Titlebar};
    auto app = std::make_unique<TowerDefense::SFMLApplication>(spec);

    sf::Clock clock;
    while (app->IsWindowOpen()) {
        sf::Time deltaTime = clock.restart();
        app->PollEvents();
        app->Update(deltaTime);
        app->Render();
    }

    return 0;
}
