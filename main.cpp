#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wheat.h"
#include "Plot.h"
#include "Crop.h"
#include "Farm.h"




int main()
{
    Farm farmy("Farmy", "Adelaide");
    for (int i = 0; i < 5; ++i) {
        Plot* newPlot = new Plot(); // Assuming default constructor for Plot
        farmy.addPlot(newPlot);
    }
    Plot* p1 = farmy.getPlot(0);

    Wheat wheatCrop;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer"); // this creates the window in which the game is played
    sf::Texture TXcrops; // Creates the variable for the image in which the crops can be selected
    if (!TXcrops.loadFromFile("crops.png", sf::IntRect(0, 0, 550, 75))) { //loads crops.png from the github
        std::cerr << "Failed to load crops.png" << std::endl;
        return -1;
    }
    // run the program as long as the window is open

    //sf::

    sf::RectangleShape rectangle(sf::Vector2f(100, 100));
    rectangle.setFillColor(sf::Color(139, 69, 19)); // Color of the rectangle
    rectangle.setPosition(200, 250);
    sf::FloatRect dirtPos(200, 250 , 100,100); 

    sf::Sprite SPcrops(TXcrops); // creates a sprite from which the image will load into
    SPcrops.setPosition(50, 10); // sets the position for where the crops image will be 
    sf::FloatRect wheatPos(55, 15, 50, 50); // the area in which the wheat is selected to be planted
    bool wheatMode = false; // A boolean variable in which the game knows which crop is being planted
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)){
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                std::cout << "Mouse click at: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << std::endl;
                if (wheatPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    if (!wheatMode){
                        std::cout << "Wheat ready to plant" << std::endl;
                        wheatMode = true;
                    }
                    else{
                        std::cout << "Wheatmode turned off" << std::endl;
                        wheatMode = false;
                    }
                }
            }
                else if (dirtPos.contains(event.mouseButton.x,event.mouseButton.y) && wheatMode == true){
                    rectangle.setFillColor(sf::Color(20, 20, 0));
                    p1.plantCrop(&wheatCrop);
                    if (p1.hasCrop()) {
                        std::cout << "Wheat successfully planted in the plot." << std::endl;
                    } else {
                        std::cout << "Failed to plant wheat in the plot." << std::endl;
                    }

                }
            
        }

        // clear the window with black color
        window.clear(sf::Color(255, 255, 255));
    
        // draw everything here...
        // window.draw(...);
        window.draw(SPcrops);
        window.draw(rectangle);
        // end the current frame
        window.display();
    }

    return 0;
}