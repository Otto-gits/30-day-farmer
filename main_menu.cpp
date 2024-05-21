#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer");

    // Load an image into a texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Main menu.JPG", sf::IntRect(0, 0, 1000, 600)))
    {
        std::cerr << "Failed to load Main menu.JPG" << std::endl;
        return -1;
    }

    // Create a sprite and set its texture
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Define the clickable area
    sf::IntRect clickableArea(300, 175, 400, 100); // (left, top, width, height)

    // Main loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window if the close button is clicked
            if (event.type == sf::Event::Closed)
                window.close();

            // Check for mouse button pressed event
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the mouse click is within the clickable area
                if (clickableArea.contains(event.mouseButton.x, event.mouseButton.y))
                {
                    std::cout << "Clicked within the clickable area!" << std::endl;
                    // Add your code here to execute when clicked within the area
                    // For example, you can add code to change the scene or perform an action
                }

                // Display the coordinates of the mouse click
                std::cout << "Mouse clicked at: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
            }
        }

        // Clear the window
        window.clear();

        // Draw the sprite
        window.draw(backgroundSprite);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
