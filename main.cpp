#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wheat.h"
#include "Plot.h"
#include "Crop.h"
#include "Farm.h"

int main(){
    Farm farmy("Farmy", "Adelaide");
    for (int i = 0; i < 5; ++i) {
        Plot* newPlot = new Plot(); // Assuming default constructor for Plot
        farmy.addPlot(newPlot);
    }
    Plot* p1 = farmy.getPlot(0);

    Wheat wheatCrop;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer"); // this creates the window in which the game is played
    sf::Texture Background; // Creates the variable for the image in which the crops can be selected
    if (!Background.loadFromFile("30DayFarmerBack.jpg", sf::IntRect(0, 0, 1000, 700))) { //loads crops.png from the github
        std::cerr << "Failed to load 30DayFarmerBack.jpg" << std::endl;
        return -1;
    }
    sf::Texture plot1;
    if (!plot1.loadFromFile("Plot1Dry.png",sf::IntRect(0, 0,500,500))) { //loads crops.png from the github
        std::cerr << "Failed to load Plot1 dry.png" << std::endl;
        return -1;
    }
    sf::Texture plot2;
    if (!plot2.loadFromFile("Plot2Dry.png",sf::IntRect(0, 0,500,500))) { //loads crops.png from the github
        std::cerr << "Failed to load Plot2dry.png" << std::endl;
        return -1;
    }

    sf::Texture plot3;
    if (!plot3.loadFromFile("Plot3Dry.png", sf::IntRect(0, 0, 500, 500))) {
        std::cerr << "Failed to load Plot3Dry.png" << std::endl;
        return -1;
    }

    sf::Texture plot4;
    if (!plot4.loadFromFile("Plot4Dry.png", sf::IntRect(0, 0, 500, 500))) {
        std::cerr << "Failed to load Plot4Dry.png" << std::endl;
        return -1;
    }

    sf::Texture plot5;
    if (!plot5.loadFromFile("Plot5Dry.png", sf::IntRect(0, 0, 500, 500))) {
        std::cerr << "Failed to load Plot5Dry.png" << std::endl;
        return -1;
    }
    // run the program as long as the window is open

    sf::RectangleShape rectangle(sf::Vector2f(60, 60));
    rectangle.setFillColor(sf::Color(139, 69, 19)); // Color of the rectangle
    rectangle.setPosition(280, 135);
    sf::FloatRect dirtPos(280, 135 , 60,60); 

    sf::Sprite SPbackground(Background); // creates a sprite from which the image will load into
    SPbackground.setPosition(0, 0); // sets the position for where the crops image will be 
    sf::FloatRect wheatPos(280, 135 , 60,60); // the area in which the wheat is selected to be planted
    bool wheatMode = false; // A boolean variable in which the game knows which crop is being planted

    sf::Sprite spPlot1(plot1);
    spPlot1.setPosition(145, 360);
    spPlot1.setScale(0.35f, 0.35f);

    sf::Sprite spPlot2(plot2);
    spPlot2.setPosition(275, 350);
    spPlot2.setScale(0.35f, 0.35f);

    sf::Sprite spPlot3(plot3);
    spPlot3.setPosition(410, 350);
    spPlot3.setScale(0.35f, 0.35f);

    sf::Sprite spPlot4(plot4);
    spPlot4.setPosition(550, 350);
    spPlot4.setScale(0.35f, 0.35f);

    sf::Sprite spPlot5(plot5);
    spPlot5.setPosition(675, 350);
    spPlot5.setScale(0.35f, 0.35f);




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
                    p1->plantCrop(&wheatCrop);
                    if (p1->hasCrop()) {
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
        window.draw(SPbackground);
        window.draw(rectangle);
        window.draw(spPlot1);
        window.draw(spPlot2);      
        window.draw(spPlot3);
        window.draw(spPlot4);
        window.draw(spPlot5); 
 
        // end the current frame
        window.display();
    }

    return 0;
}
