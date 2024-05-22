#include <SFML/Graphics.hpp>
#include <iostream>

enum class State
{
    None,
    FirstPopup,
    SecondPopup
};

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

    // Load the first pop-up texture
    sf::Texture popupTexture1;
    if (!popupTexture1.loadFromFile("Intro 2.JPG")) // Ensure you have an appropriate image file
    {
        std::cerr << "Failed to load Intro 2.JPG" << std::endl;
        return -1;
    }

    // Create a sprite for the first pop-up and set its texture
    sf::Sprite popupSprite1;
    popupSprite1.setTexture(popupTexture1);

    // Load the second pop-up texture
    sf::Texture popupTexture2;
    if (!popupTexture2.loadFromFile("Intro 3.JPG")) // Ensure you have an appropriate image file
    {
        std::cerr << "Failed to load Intro 3.JPG" << std::endl;
        return -1;
    }

    // Create a sprite for the second pop-up and set its texture
    sf::Sprite popupSprite2;
    popupSprite2.setTexture(popupTexture2);

    // Variable to control pop-up visibility
    State currentState = State::None;

    // Define the clickable areas
    sf::IntRect clickableArea1(640, 355, 100, 100); // (left, top, width, height)
    sf::IntRect clickableArea2(640, 355, 100, 100); // Area for second interaction in the first pop-up
    sf::IntRect clickableArea3(230, 150, 120, 100); // Another area for interaction in the first pop-up
    sf::IntRect clickableArea4(640, 355, 100, 100); // Area for interaction in the second pop-up
    sf::IntRect clickableArea5(230, 150, 120, 100); // Another area for interaction in the second pop-up
    sf::IntRect clickableAreaClose(500, 250, 100, 100); // Area to close the window in the final pop-up

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
                if (currentState == State::None)
                {
                    // Check if the mouse click is within the clickable area of the background
                    if (clickableArea1.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area 1!" << std::endl;
                        // Show the first pop-up
                        currentState = State::FirstPopup;
                    }
                }
                else if (currentState == State::FirstPopup)
                {
                    // Check if the mouse click is within the clickable areas of the first pop-up
                    if (clickableArea2.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area 2!" << std::endl;
                        // Show the second pop-up
                        currentState = State::SecondPopup;
                    }
                    else if (clickableArea3.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area 3!" << std::endl;
                        // Return to the main page
                        currentState = State::None;
                    }
                }
                else if (currentState == State::SecondPopup)
                {
                    // Check if the mouse click is within the clickable areas of the second pop-up
                    if (clickableArea4.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area to close the window!" << std::endl;
                        // Close the window
                        window.close();
                    }
                    else if (clickableArea5.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area 5!" << std::endl;
                        // Return to the first pop-up
                        currentState = State::FirstPopup;
                    }
                
                }

                // Display the coordinates of the mouse click
                std::cout << "Mouse clicked at: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
            }
        }

        // Clear the window
        window.clear();

        // Draw the background sprite
        window.draw(backgroundSprite);

        // Draw the first pop-up sprite if it is visible
        if (currentState == State::FirstPopup)
        {
            // Position the first pop-up sprite at the desired location
            popupSprite1.setPosition(0, 0); // Adjust the position as needed
            window.draw(popupSprite1);
        }

        // Draw the second pop-up sprite if it is visible
        if (currentState == State::SecondPopup)
        {
            // Position the second pop-up sprite at the desired location
            popupSprite2.setPosition(0, 0); // Adjust the position as needed
            window.draw(popupSprite2);
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}
