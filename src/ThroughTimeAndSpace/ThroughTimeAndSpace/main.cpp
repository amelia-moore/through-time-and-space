#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include "scene.h"
#include "stage.h"

int main()
{
    sf::Window window(sf::VideoMode({ 1860, 600 }), "Through Time and Space", sf::Style::Default, sf::State::Windowed, sf::ContextSettings(32));
    window.setVerticalSyncEnabled(true);

    window.setActive(true);

    // load resources, init opengl states, etc

    bool run = true;


    while (run)
    {
        // event handling
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>()) {
                run = false;
            }
            else if (const auto* resized = event->getIf<sf::Event::Resized>()) {
                // shift viewport
                glViewport(0, 0, resized->size.x, resized->size.y);
            }
            // else if click, report to generic scene event click handler
        }

        // clear buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // draw
        //create stage
        Stage mainStage(&window);
        //Scene scene(&window);

        // end current frame
        window.display();
        
    }

    window.setActive(false);
}