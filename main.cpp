#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
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
#include "Cherry.h"
#include "Apple.h"
#include "Tree.h" 

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

    wateringCan wCan;
    bool waterMode = false;
    Shovel shove;
    bool shovelMode = false;
    Hoe hoe;
    bool hoeMode = false;
    //Scythe scythe;
    //bool scytheMode = false;


    sf::RenderWindow window(sf::VideoMode(1000, 600), "30 Day Farmer"); // this creates the window in which the game is played
    sf::Font font;
    if (!font.loadFromFile("RobotoSlab-Regular.ttf")) {
        std::cerr << "Failed to load RobotoSlab-Regular.ttf" << std::endl;
        return -1;
    }

    // Create a text object to display the money
    sf::Text moneyText;
    moneyText.setFont(font);
    moneyText.setCharacterSize(38); // Set text size
    moneyText.setFillColor(sf::Color::White); // Set text color
    moneyText.setPosition(635, 93); // Set text position
    sf::Text dayCount;
    dayCount.setFont(font);
    dayCount.setCharacterSize(38); // Set text size
    dayCount.setFillColor(sf::Color::White); // Set text color
    dayCount.setPosition(440, 93); // Set text position


    sf::Texture Background; // Creates the variable for the image in which the crops can be selected
    if (!Background.loadFromFile("30DayFarmerBack.jpg", sf::IntRect(0, 0, 1000, 700))) { //loads the background image from the files
        std::cerr << "Failed to load 30DayFarmerBack.jpg" << std::endl; // sends an error message if the image does not load
        return -1;
    }
    sf::Texture plot1;
    if (!plot1.loadFromFile("Plot1Dry.png",sf::IntRect(0, 0,500,500))) { 
        std::cerr << "Failed to load Plot1 dry.png" << std::endl;
        return -1;
    }
    sf::Texture plot2;
    if (!plot2.loadFromFile("Plot2Dry.png",sf::IntRect(0, 0,500,500))) { 
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
    // this is the area where a user can click to interact with the objects.
    sf::FloatRect wheatPos(280, 137 , 60,55); 
    sf::FloatRect pepperPos(340, 137 , 60,55); 
    sf::FloatRect onionPos(400, 137 , 60,55); 
    sf::FloatRect cornPos(470, 137 , 60,55);
    sf::FloatRect carrotPos(530, 137 , 60,55); 
    sf::FloatRect cherryPos(600, 137 , 60,55); 
    sf::FloatRect applePos(660, 137 , 60,55); 
    sf::FloatRect shovelPos(840,200,70,75);
    sf::FloatRect hoePos(840,275,70,75);
    sf::FloatRect scythePos(840,350,70,75);
    sf::FloatRect wCanPos(840, 425 , 70,75); 
    sf::FloatRect nextDayPos(500,545,160,30);
    sf::FloatRect buyLandPos(330,545,160,30);

    sf::Sprite SPbackground(Background); // creates a sprite from which the background will load into 
    sf::Sprite spPlot1(plot1); 
    spPlot1.setPosition(120, 360); //sets the position of wher the loaded image will sit
    spPlot1.setScale(0.375f, 0.375f); 
    sf::FloatRect plot1Coord(220, 420 , 45,40); 
    sf::Sprite spPlot2(plot2);
    spPlot2.setPosition(250, 345);
    spPlot2.setScale(0.375f, 0.375f); //sets the scale compared to the loaded image of how big the image should be
    sf::FloatRect plot2Coord(300, 410 , 100,45); 
    sf::Sprite spPlot3(plot3);
    spPlot3.setPosition(390, 340);
    spPlot3.setScale(0.375f, 0.375f);
    sf::FloatRect plot3Coord(427, 405 , 110,50); //creates a rectangle of the area in which the user can click to utilize the plot
    sf::Sprite spPlot4(plot4);
    spPlot4.setPosition(525, 345);
    spPlot4.setScale(0.375f, 0.375f);
    sf::FloatRect plot4Coord(570, 400 , 90,50); 
    sf::Sprite spPlot5(plot5);
    spPlot5.setPosition(660, 350);
    spPlot5.setScale(0.375f, 0.375f);
    sf::FloatRect plot5Coord(700, 415 , 70,45); 

    // run the program as long as the window is open
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
                else if (pepperPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    Merchant.buyBellPeppers();
                }
                else if (onionPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    Merchant.buyOnion();
                }
                else if (cornPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    Merchant.buyCorn();
                }
                else if (carrotPos.contains(event.mouseButton.x,event.mouseButton.y)){\
                    Merchant.buyCarrot();
                }
                else if (cherryPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    Merchant.buyCherry();
                }
                else if (applePos.contains(event.mouseButton.x,event.mouseButton.y)){
                    Merchant.buyApple();
                }
                else if (wCanPos.contains(event.mouseButton.x,event.mouseButton.y) ){
                    if (waterMode==false){
                        waterMode = true;
                        hoeMode = false;
                        shovelMode = false;
                        std::cout << "watermode on" <<std::endl;
                    }
                    else{
                        waterMode = false;
                            std::cout << "watermode off" <<std::endl;
                    }
                }
                else if (plot1Coord.contains(event.mouseButton.x,event.mouseButton.y) && waterMode == true && p1->hasCrop() == true){
                    wCan.waterCrop(*p1);
                }
                else if (plot2Coord.contains(event.mouseButton.x,event.mouseButton.y) && waterMode == true && p2->hasCrop() == true){
                    wCan.waterCrop(*p2);
                }
                else if (plot3Coord.contains(event.mouseButton.x,event.mouseButton.y) && waterMode == true && p3->hasCrop() == true){
                    wCan.waterCrop(*p3);
                }
                else if (plot4Coord.contains(event.mouseButton.x,event.mouseButton.y) && waterMode == true && p4->hasCrop() == true){
                    wCan.waterCrop(*p4);
                }
                else if (plot5Coord.contains(event.mouseButton.x,event.mouseButton.y) && waterMode == true && p5->hasCrop() == true){
                    wCan.waterCrop(*p5);
                }
                else if (nextDayPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    farmy.newDay();
                }
                else if (shovelPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    if (shovelMode ==false){
                        shovelMode = true;
                        hoeMode = false;
                        waterMode = false;
                            
                        std::cout << "Shovelmode on" <<std::endl;
                    }
                    else{
                        shovelMode = false;
                            std::cout << "Shovelmode off" <<std::endl;
                    }
                }
                else if (hoePos.contains(event.mouseButton.x,event.mouseButton.y)){
                    if (hoeMode ==false){
                        hoeMode = true;
                        waterMode = false;
                        shovelMode = false;
                        std::cout << "HoeMode on" <<std::endl;
                    }
                    else{
                        hoeMode = false;
                            std::cout << "Hoemode off" <<std::endl;
                    }
                }
                /*else if (scythe.contains(event.mouseButton.x,event.mouseButton.y)){
                    if (scytheMode ==false){
                        scythe = true;
                        std::cout << "ScytheMode on" <<std::endl;
                    }
                    else{
                        scytheMode = false;
                            std::cout << "Scythemode off" <<std::endl;
                    }
                }
                }*/

            }
            
        }

        // clear the window with black color
        std::ostringstream ss;
        ss << farmy.getBalance();
        moneyText.setString(ss.str());

        std::ostringstream dd;
        dd << farmy.getDayNum();
        dayCount.setString(dd.str());

        window.clear(sf::Color(255, 255, 255));
    
        // draw everything here...
        // window.draw(...);
        window.draw(SPbackground);
        window.draw(spPlot1);
        window.draw(spPlot2);      
        window.draw(spPlot3);
        window.draw(spPlot4);
        window.draw(spPlot5); 
        window.draw(moneyText);
        window.draw(dayCount);
        // end the current frame
        window.display();
    }

    return 0;
}
