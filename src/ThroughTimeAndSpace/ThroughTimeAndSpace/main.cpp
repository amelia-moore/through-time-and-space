#include <SFML/Graphics.hpp>
#include "scene.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1860, 600 }), "Through Time and Space");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        Scene scene(&window);
        window.display();
        
    }
}