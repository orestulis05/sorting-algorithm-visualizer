#include <iostream>
#include <vector>

// SFML Libs
#include <SFML/Graphics.hpp>

// Custom Libs
#include "rMath.h"

int main()
{
    // ----------------- INIT -------------------
    unsigned int width = 960, height = 540;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({width, height}), "SFML Testing Grounds", sf::Style::Default);
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    window->setFramerateLimit(60);
    sf::Clock clock;
    float deltaTime = clock.restart().asSeconds();

    while (window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window->close();
                }
            }
        }

#pragma region Update

#pragma endregion

#pragma region Drawing/Rendering

        window->clear();

        window->display();

#pragma endregion

    }

    delete window;
    return 0;
}