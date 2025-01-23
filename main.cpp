#include <iostream>
#include <stdint.h>
#include <vector>

#include <SFML/Graphics.hpp>

#define DATA_RANGE_FROM 1
#define DATA_RANGE_TO 255

int main()
{
    // Creating a window for a visualization.
    const int WIDTH = 960, 
             HEIGHT = 540;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode({WIDTH, HEIGHT}), "SFML Testing Grounds", sf::Style::Default);
    window->setFramerateLimit(30);

    // --------------------------- RANDOM DATA GEN -------------------------------------------

    std::srand(std::time(nullptr)); // Setting the seed of random number generator.

    std::vector<uint8_t> data; // Vector that is holding all of the random values. Input for a sorting algorithm.
    uint8_t n = 100; // Size of the vector.
    data.reserve(n); // Knowing the size of the vector, instantly reserving some memory.

    // Generating random values to the vector's elements.
    for (size_t i = 0; i < n; i++)
    {
        uint8_t randomValue = static_cast<uint8_t>(DATA_RANGE_FROM + std::rand() % DATA_RANGE_TO);
        data.push_back(randomValue);
    }

    while (window->isOpen())
    {
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
        // --- Update logic here:

#pragma endregion

#pragma region Drawing/Rendering
        window->clear();

        // --- Drawing logic here:

        window->display();
#pragma endregion

    }

    delete window;
    return 0;
}

/*
                    To-Do

                  MANDATORY:

- Generate some data into a vector. (DONE)
- Create all of the sorting algorithms.
- Visualize the sorting with rectangles:
        - * Height is the vector's element's size;
        - * Red rectangles are the currently used rectangles by the algorithm.

             OTHER COOL FEATURES:

- User input in cmd for choosing the algorithm.
- Make readable and understandable documentation.
- Graphics auto-scaling to vector length and screen size.
*/