#include <SFML/Graphics.hpp>
#include <iostream>
#include "Leaderboard.h"

// Define the states
enum class State
{
    MainMenu,
    Intro1,
    FirstPopup,
    SecondPopup
};

int main()
{

    Leaderboard leaderboard;
    leaderboard.addEntry("BIG FARMER 60", 30);
    leaderboard.addEntry("God Farmer", 497);
    leaderboard.addEntry("Charlie", 2);


    // Create a window
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer");

    // Load the main menu texture
    sf::Texture mainMenuTexture;
    if (!mainMenuTexture.loadFromFile("Main menu.jpeg", sf::IntRect(0, 0, 1000, 600)))
    {
        std::cerr << "Failed to load Main menu.JPG" << std::endl;
        return -1;
    }
    sf::Sprite mainMenuSprite;
    mainMenuSprite.setTexture(mainMenuTexture);

    // Load the Intro 1 texture
    sf::Texture intro1Texture;
    if (!intro1Texture.loadFromFile("Intro 1.JPG", sf::IntRect(0, 0, 1000, 600)))
    {
        std::cerr << "Failed to load Intro 1.JPG" << std::endl;
        return -1;
    }
    sf::Sprite intro1Sprite;
    intro1Sprite.setTexture(intro1Texture);

    // Load the first pop-up texture
    sf::Texture popupTexture1;
    if (!popupTexture1.loadFromFile("Intro 2.JPG")) // Ensure you have an appropriate image file
    {
        std::cerr << "Failed to load Intro 2.JPG" << std::endl;
        return -1;
    }
    sf::Sprite popupSprite1;
    popupSprite1.setTexture(popupTexture1);

    // Load the second pop-up texture
    sf::Texture popupTexture2;
    if (!popupTexture2.loadFromFile("Intro 3.JPG")) // Ensure you have an appropriate image file
    {
        std::cerr << "Failed to load Intro 3.JPG" << std::endl;
        return -1;
    }
    sf::Sprite popupSprite2;
    popupSprite2.setTexture(popupTexture2);

    // Variable to control pop-up visibility
    State currentState = State::MainMenu;

    // Define the clickable areas
    sf::IntRect clickableAreaMainMenu(300, 175, 400, 100); // (left, top, width, height)
    sf::IntRect clickableAreaIntro1(640, 355, 100, 100); // Area for interaction in Intro 1
    sf::IntRect clickableArea1(640, 355, 100, 100); // Area for the first pop-up interaction
    sf::IntRect clickableArea2(640, 355, 100, 100); // Area for second interaction in the first pop-up
    sf::IntRect clickableArea3(230, 150, 120, 100); // Another area for interaction in the first pop-up
    sf::IntRect clickableArea4(640, 355, 100, 100); // Area for interaction in the second pop-up
    sf::IntRect clickableArea5(230, 150, 120, 100); // Another area for interaction in the second pop-up
    sf::IntRect clickableAreaQuit(300, 440, 400, 100); // Area for interaction to quit
    sf::IntRect clickableAreaLeaderBoard(300, 300, 400, 100); // Area for interaction to quit

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
                if (currentState == State::MainMenu)
                {
                    // Check if the mouse click is within the clickable area of the main menu
                    if (clickableAreaMainMenu.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area of the main menu!" << std::endl;
                        // Show Intro 1
                        currentState = State::Intro1;
                    }
                    else if (clickableAreaQuit.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area QUIT!" << std::endl;
                        // Close the window
                        window.close();
                    }
                    else if (clickableAreaLeaderBoard.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area LeaderBoard !" << std::endl;
                        // Close the window
                        leaderboard.display();
                    }
                }
                else if (currentState == State::Intro1)
                {
                    // Check if the mouse click is within the clickable area of Intro 1
                    if (clickableAreaIntro1.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area of Intro 1!" << std::endl;
                        // Show the first pop-up
                        currentState = State::FirstPopup;
                    }
                }
                else if (currentState == State::FirstPopup)
                {
                    // Check if the mouse click is within the clickable areas of the first pop-up
                    if (clickableArea1.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area 1!" << std::endl;
                        // Show the second pop-up
                        currentState = State::SecondPopup;
                    }
                    else if (clickableArea3.contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        std::cout << "Clicked within the clickable area 3!" << std::endl;
                        // Return to Intro 1
                        currentState = State::Intro1;
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

        // Draw the appropriate content based on the current state
        if (currentState == State::MainMenu)
        {
            // Draw the main menu sprite
            window.draw(mainMenuSprite);
        }
        else if (currentState == State::Intro1)
        {
            // Draw the Intro 1 sprite
            window.draw(intro1Sprite);
        }
        else if (currentState == State::FirstPopup)
        {
            // Draw the first pop-up sprite
            popupSprite1.setPosition(0, 0); // Adjust the position as needed
            window.draw(popupSprite1);
        }
        else if (currentState == State::SecondPopup)
        {
            // Draw the second pop-up sprite
            popupSprite2.setPosition(0, 0); // Adjust the position as needed
            window.draw(popupSprite2);
        }

        // Display the contents of the window
        window.display();
    }

    return 0;
}