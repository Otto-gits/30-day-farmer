#include <SFML/Graphics.hpp>
#include <iostream>
#include "Wheat.h"
#include "Plot.h"
#include "Crop.h"
#include "Farm.h"
#include "bellPeppers.h"
#include "Onion.h"
#include "Carrot.h"
#include "Corn.h"
#include "Scythe.h"
#include "Hoe.h"
#include "Shovel.h"
#include "wateringCan.h"
#include "Tool.h"
#include "cropMerchant.h"


int main(){
    Farm farmy("Farmy", "Adelaide");
    cropMerchant Merchant(farmy);
    for (int i = 0; i < 5; ++i) {
        Plot* newPlot = new Plot(); // Assuming default constructor for Plot
        farmy.addPlot(newPlot);
    }
    Plot* p1 = farmy.getPlot(0);
    Plot* p2 = farmy.getPlot(1);
    Plot* p3 = farmy.getPlot(2);
    Plot* p4 = farmy.getPlot(3);
    Plot* p5 = farmy.getPlot(4);

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
    sf::Sprite SPbackground(Background); // creates a sprite from which the image will load into
    SPbackground.setPosition(0, 0); // sets the position for where the crops image will be 
    sf::FloatRect wheatPos(280, 137 , 60,55); // the area in which the wheat is selected to be planted
    sf::FloatRect pepperPos(340, 137 , 60,55); // the area in which the wheat is selected to be planted
    sf::FloatRect onionPos(400, 137 , 60,55); // the area in which the wheat is selected to be planted
    sf::FloatRect cornPos(470, 137 , 60,55); // the area in which the wheat is selected to be planted
    sf::FloatRect carrotPos(530, 137 , 60,55); // the area in which the wheat is selected to be planted
    sf::FloatRect cherryPos(600, 137 , 60,55); // the area in which the wheat is selected to be planted
    sf::FloatRect applePos(660, 137 , 60,55); // the area in which the wheat is selected to be planted

    sf::Sprite spPlot1(plot1);
    spPlot1.setPosition(120, 360);
    spPlot1.setScale(0.375f, 0.375f);
    sf::FloatRect plot1Coord(220, 420 , 45,40); 

    sf::Sprite spPlot2(plot2);
    spPlot2.setPosition(250, 345);
    spPlot2.setScale(0.375f, 0.375f);
    sf::FloatRect plot2Coord(300, 410 , 100,45); 

    sf::Sprite spPlot3(plot3);
    spPlot3.setPosition(390, 340);
    spPlot3.setScale(0.375f, 0.375f);
    sf::FloatRect plot3Coord(427, 405 , 110,50); 

    sf::Sprite spPlot4(plot4);
    spPlot4.setPosition(525, 345);
    spPlot4.setScale(0.375f, 0.375f);
    sf::FloatRect plot4Coord(570, 400 , 90,50); 

    sf::Sprite spPlot5(plot5);
    spPlot5.setPosition(660, 350);
    spPlot5.setScale(0.375f, 0.375f);
    sf::FloatRect plot5Coord(700, 415 , 70,45); 

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
                    Merchant.buyWheat();
                }
                if (wheatPos.contains(event.mouseButton.x,event.mouseButton.y)){

                }
                
                if (wheatPos.contains(event.mouseButton.x,event.mouseButton.y)){

                }

                if (wheatPos.contains(event.mouseButton.x,event.mouseButton.y)){

                }

                if (wheatPos.contains(event.mouseButton.x,event.mouseButton.y)){\

                }
                if (wheatPos.contains(event.mouseButton.x,event.mouseButton.y)){

                }
            }
            
        }

        // clear the window with black color
        window.clear(sf::Color(255, 255, 255));
    
        // draw everything here...
        // window.draw(...);
        window.draw(SPbackground);
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
