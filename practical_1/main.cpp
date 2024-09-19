#include <SFML/Graphics.hpp>

sf::CircleShape shape(25.f);
double speed = 150.0;

void Update(double dt, sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        shape.move(0, dt * speed * -1);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        shape.move(0, 1 * dt * speed);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        shape.move(-1 * dt * speed, 0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        shape.move(1 * speed * dt, 0);
    }
}

void Render(sf::RenderWindow &window)
{
    window.draw(shape);
}

int main(){
    sf::RenderWindow window(sf::VideoMode({1280, 720}), "SFML works!");
    shape.setFillColor(sf::Color::Green);
    static sf::Clock clock;

    while (window.isOpen()){
        sf::Event event{};
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        double dt = clock.restart().asSeconds();
        Update(dt, window);
        window.clear();
        Render(window);
        window.display();
    }
    return 0;
}