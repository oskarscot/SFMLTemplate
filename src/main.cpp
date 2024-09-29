#include "core/Application.h"

int main(){
    TerClone::ApplicationWindowSpec spec{1280, 720, "SFML Engine!!", sf::Style::Titlebar | sf::Style::Close};
    TerClone::Application app(spec);

    static sf::Clock clock;
    while (app.IsWindowOpen()) {
        app.PollEvents();
        const sf::Time deltaTime = clock.restart();
        app.Update(deltaTime);
        app.Render();
    }

    return 0;
}
