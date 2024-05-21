#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer");

    // Load an image into a texture
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Intro 1.JPG", sf::IntRect(0, 0, 1000, 600)))
    {
        std::cerr << "Failed to load Intro 1.JPG" << std::endl;
        return -1;
    }

    // Create a sprite and set its texture
    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    // Load the pop-up texture
    sf::Texture popupTexture;
    if (!popupTexture.loadFromFile("Intro 2.JPG")) // Ensure you have an appropriate image file
    {
        std::cerr << "Failed to load Intro 2.JPG" << std::endl;
        return -1;
    }

    // Create a sprite for the pop-up and set its texture
    sf::Sprite popupSprite;
    popupSprite.setTexture(popupTexture);

    // Variable to control pop-up visibility
    bool showPopup = false;

    // Define the clickable area
    sf::IntRect clickableArea(640, 355, 100, 100); // (left, top, width, height)

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
                    // Toggle pop-up visibility
                    showPopup = !showPopup;
                }

                // Display the coordinates of the mouse click
                std::cout << "Mouse clicked at: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
            }
        }

        // Clear the window
        window.clear();

        // Draw the background sprite
        window.draw(backgroundSprite);

        // Draw the pop-up sprite if it is visible
        if (showPopup)
        {
            // Position the pop-up sprite at the desired location
            popupSprite.setPosition(0, 0); // Adjust the position as needed
            window.draw(popupSprite);
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
