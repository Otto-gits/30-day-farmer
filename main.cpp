#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
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
    Farm farmy;
    cropMerchant Merchant(farmy);
    
    Plot* p1 = farmy.getPlot(0);
    Plot* p2 = farmy.getPlot(1);
    Plot* p3 = farmy.getPlot(2);
    Plot* p4 = farmy.getPlot(3);
    Plot* p5 = farmy.getPlot(4);
    
    Wheat wheatCrop;

    wateringCan wCan;
    bool waterMode = false;
    Shovel shovel;
    bool shovelMode = false;
    Hoe hoe;
    bool hoeMode = false;
    Scythe scythe(&farmy);
    bool scytheMode = false;


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
    sf::Text plot1Text;
    plot1Text.setFont(font);
    plot1Text.setCharacterSize(19); // Set text size
    plot1Text.setFillColor(sf::Color::Red); // Set text color
    plot1Text.setPosition(180, 480); // Set text position
    sf::Text plot2Text;
    plot2Text.setFont(font);
    plot2Text.setCharacterSize(19); // Set text size
    plot2Text.setFillColor(sf::Color::Red); // Set text color
    plot2Text.setPosition(310, 475); // Set text position
    sf::Text plot3Text;
    plot3Text.setFont(font);
    plot3Text.setCharacterSize(19); // Set text size
    plot3Text.setFillColor(sf::Color::Red); // Set text color
    plot3Text.setPosition(455, 470); // Set text position
    sf::Text plot4Text;
    plot4Text.setFont(font);
    plot4Text.setCharacterSize(19); // Set text size
    plot4Text.setFillColor(sf::Color::Red); // Set text color
    plot4Text.setPosition(600, 475); // Set text position
    sf::Text plot5Text;
    plot5Text.setFont(font);
    plot5Text.setCharacterSize(19); // Set text size
    plot5Text.setFillColor(sf::Color::Red); // Set text color
    plot5Text.setPosition(740, 480); // Set text position


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

    sf::Texture plant;
    plant.loadFromFile("Planted.png",sf::IntRect(0,0,1000,1000));
    sf::Sprite spPlant1(plant);
    spPlant1.setPosition(223,425);
    spPlant1.scale(2,2);
    sf::Sprite spPlant2(plant);
    spPlant2.setPosition(350,425);
    spPlant2.scale(2,2);
    sf::Sprite spPlant3(plant);
    spPlant3.setPosition(480,425);
    spPlant3.scale(2,2);
    sf::Sprite spPlant4(plant);
    spPlant4.setPosition(610,425);
    spPlant4.scale(2,2);
    sf::Sprite spPlant5(plant);
    spPlant5.setPosition(750,425);
    spPlant5.scale(2,2);

    sf::Texture wheatGrown;
    wheatGrown.loadFromFile("Wheat.png",sf::IntRect(0,0,250,250));
    sf::Sprite spWheat1(wheatGrown);
    spWheat1.scale(2.3f,2.3f);
    sf::Sprite spWheat2(wheatGrown);
    spWheat2.scale(2.6f,2.6f);
    sf::Sprite spWheat3(wheatGrown);
    spWheat3.scale(2.9f,2.9f);
    sf::Sprite spWheat4(wheatGrown);
    spWheat4.scale(2.6f,2.6f);
    sf::Sprite spWheat5(wheatGrown);
    spWheat5.scale(2.3f,2.3f);

    sf::Texture pepperGrown;
    pepperGrown.loadFromFile("BellPepper.png",sf::IntRect(0,0,250,250));
    sf::Sprite spPepper1(pepperGrown);
    sf::Sprite spPepper2(pepperGrown);
    sf::Sprite spPepper3(pepperGrown);
    sf::Sprite spPepper4(pepperGrown);
    sf::Sprite spPepper5(pepperGrown);

    sf::Texture onionGrown;
    onionGrown.loadFromFile("Onion.png",sf::IntRect(0,0,250,250));
    sf::Sprite spOnion1(onionGrown);
    sf::Sprite spOnion2(onionGrown);
    sf::Sprite spOnion3(onionGrown);
    sf::Sprite spOnion4(onionGrown);
    sf::Sprite spOnion5(onionGrown);

    sf::Texture cornGrown;
    cornGrown.loadFromFile("Corn.png", sf::IntRect(0, 0, 250, 250));
    sf::Sprite spCorn1(cornGrown);
    sf::Sprite spCorn2(cornGrown);
    sf::Sprite spCorn3(cornGrown);
    sf::Sprite spCorn4(cornGrown);
    sf::Sprite spCorn5(cornGrown);

    sf::Texture carrotGrown;
    carrotGrown.loadFromFile("Carrot.png", sf::IntRect(0, 0, 250, 250));
    sf::Sprite spCarrot1(carrotGrown);
    sf::Sprite spCarrot2(carrotGrown);
    sf::Sprite spCarrot3(carrotGrown);
    sf::Sprite spCarrot4(carrotGrown);
    sf::Sprite spCarrot5(carrotGrown);

    sf::Texture cherryGrown;
    cherryGrown.loadFromFile("Cherry.png", sf::IntRect(0, 0, 250, 250));
    sf::Sprite spCherry1(cherryGrown);
    sf::Sprite spCherry2(cherryGrown);
    sf::Sprite spCherry3(cherryGrown);
    sf::Sprite spCherry4(cherryGrown);
    sf::Sprite spCherry5(cherryGrown);
    spCherry1.setScale(0.8f, 0.8f);
    spCherry2.setScale(0.8f, 0.8f);
    spCherry3.setScale(0.8f, 0.8f);
    spCherry4.setScale(0.8f, 0.8f);
    spCherry5.setScale(0.8f, 0.8f);
    
    sf::Texture appleGrown;
    appleGrown.loadFromFile("Apple.png", sf::IntRect(0, 0, 250, 250));
    sf::Sprite spApple1(appleGrown);
    sf::Sprite spApple2(appleGrown);
    sf::Sprite spApple3(appleGrown);
    sf::Sprite spApple4(appleGrown);
    sf::Sprite spApple5(appleGrown);
    spApple1.setScale(0.8f, 0.8f);
    spApple2.setScale(0.8f, 0.8f);
    spApple3.setScale(0.8f, 0.8f);
    spApple4.setScale(0.8f, 0.8f);
    spApple5.setScale(0.8f, 0.8f);


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

    sf::Sprite SPbackground(Background); // creates a sprite from which the background will load into 
    std::vector<sf::Sprite> plotSprites;

    // Create and configure each sprite, then add it to the vector
    sf::Sprite spPlot1(plot1);
    spPlot1.setPosition(120, 360); //sets the position of where the loaded image will sit
    spPlot1.setScale(0.375f, 0.375f); 
    plotSprites.push_back(spPlot1); // Add sprite to vector
    sf::FloatRect plot1Coord(220, 420, 45, 40);

    sf::Sprite spPlot2(plot2);
    spPlot2.setPosition(250, 345);
    spPlot2.setScale(0.375f, 0.375f); //sets the scale compared to the loaded image of how big the image should be
    plotSprites.push_back(spPlot2); // Add sprite to vector
    sf::FloatRect plot2Coord(300, 410, 100, 45);

    sf::Sprite spPlot3(plot3);
    spPlot3.setPosition(390, 340);
    spPlot3.setScale(0.375f, 0.375f);
    plotSprites.push_back(spPlot3); // Add sprite to vector
    sf::FloatRect plot3Coord(427, 405, 110, 50); //creates a rectangle of the area in which the user can click to utilize the plot

    sf::Sprite spPlot4(plot4);
    spPlot4.setPosition(525, 345);
    spPlot4.setScale(0.375f, 0.375f);
    plotSprites.push_back(spPlot4); // Add sprite to vector
    sf::FloatRect plot4Coord(570, 400, 90, 50);

    sf::Sprite spPlot5(plot5);
    spPlot5.setPosition(660, 350);
    spPlot5.setScale(0.375f, 0.375f);
    plotSprites.push_back(spPlot5); // Add sprite to vector
    sf::FloatRect plot5Coord(700, 415, 70, 45);


    
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
                        scytheMode = false;

                        std::cout << "watermode on" <<std::endl;
                    }
                    else{
                        waterMode = false;
                            std::cout << "watermode off" <<std::endl;
                    }
                }
                else if (plot1Coord.contains(event.mouseButton.x,event.mouseButton.y)){
                    if(p1->hasCrop() == true){
                        if (waterMode == true){
                            wCan.waterCrop(*p1);                            
                        }
                        else if (scytheMode == true){
                            scythe.harvestCrop(*p1);
                        }
                        else if(shovelMode == true){
                            shovel.digupCrop(*p1);
                        }
                    }
                    else{
                        if (hoeMode == true){
                            hoe.sowPlot(*p1);
                            std::cout << hoe.getUses() << std::endl;

                        }
                    }
                }
                else if (plot2Coord.contains(event.mouseButton.x,event.mouseButton.y)){
                    if(p2->hasCrop() == true){
                        if (waterMode == true){
                            wCan.waterCrop(*p2);
                        }
                        else if (scytheMode == true){
                            scythe.harvestCrop(*p2);
                        }
                        else if(shovelMode == true){
                            shovel.digupCrop(*p2);
                        }
                    }
                    else{
                        if (hoeMode == true){
                            hoe.sowPlot(*p2);
                            std::cout << hoe.getUses() << std::endl;
                        }
                    }
                }
                else if (plot3Coord.contains(event.mouseButton.x,event.mouseButton.y)){
                    if(p3->hasCrop() == true){
                        if (waterMode == true){
                            wCan.waterCrop(*p3);
                        }
                        else if (scytheMode == true){
                            scythe.harvestCrop(*p3);
                        }
                        else if(shovelMode == true){
                            shovel.digupCrop(*p3);
                        }
                    }
                    else{
                        if (hoeMode == true){
                            hoe.sowPlot(*p3);
                        }
                    }
                }
                else if (plot4Coord.contains(event.mouseButton.x,event.mouseButton.y)){
                    if(p4->hasCrop() == true){
                        if (waterMode == true){
                            wCan.waterCrop(*p4);
                            plotSprites[3].setColor(sf::Color(150, 150, 150));
                        }
                        else if (scytheMode == true){
                            scythe.harvestCrop(*p4);
                        }
                        else if(shovelMode == true){
                            shovel.digupCrop(*p4);
                        }
                    }
                    else{
                        if (hoeMode == true){
                            hoe.sowPlot(*p4);
                        }
                    }
                }
                else if (plot5Coord.contains(event.mouseButton.x,event.mouseButton.y)){
                    if(p5->hasCrop() == true){
                        if (waterMode == true){
                            wCan.waterCrop(*p5);
                            spPlot5.setColor(sf::Color(150, 150, 150));
                        }
                        else if (scytheMode == true){
                            scythe.harvestCrop(*p5);
                        }
                        else if(shovelMode == true){
                            shovel.digupCrop(*p5);
                        }
                    }
                    else{
                        if (hoeMode == true){
                            hoe.sowPlot(*p5);
                        }
                    }
                }
                else if (nextDayPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    farmy.newDay();
                    std::cout << "tuesday" << std::endl;
                }
                else if (shovelPos.contains(event.mouseButton.x,event.mouseButton.y)){
                    if (shovelMode ==false){
                        shovelMode = true;
                        hoeMode = false;
                        scytheMode = false;
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
                        scytheMode = false;
                        std::cout << "HoeMode on" <<std::endl;
                    }
                    else{
                        hoeMode = false;
                            std::cout << "Hoemode off" <<std::endl;
                    }
                }
                else if (scythePos.contains(event.mouseButton.x,event.mouseButton.y)){
                    if (scytheMode ==false){
                        scytheMode = true;
                        waterMode = false;
                        shovelMode = false;
                        hoeMode = false;
                        std::cout << "ScytheMode on" <<std::endl;
                    }
                    else{
                        scytheMode = false;
                            std::cout << "Scythemode off" <<std::endl;
                    }
                }
            
            }
        }

        // clear the window with black color
        std::ostringstream ss;
        ss << farmy.getBalance();
        moneyText.setString(ss.str());

        std::ostringstream dd;
        dd << farmy.getDayNum();
        dayCount.setString(dd.str());

        // For p1
        std::ostringstream p1Stream;
        if (p1 != nullptr && p1->getCrop() != nullptr && p1->getCrop()->getAge() < p1->getCrop()->getMaxAge() ) {
            p1Stream << p1->getPlotCropType() << "\n";
            p1Stream << " " << p1-> getCrop()->getPlantSize() <<  "/" << p1->getCrop()->getMaxSize();
        } else if(p1 != nullptr && p1->getCrop() != nullptr && p1->getCrop()->getAge() >= p1->getCrop()->getMaxAge()) {
            p1Stream << "Dead Crop";
        } else{
            p1Stream << "Empty";
        }

        plot1Text.setString(p1Stream.str());

        // For p2
        std::ostringstream p2Stream;
        if (p2 != nullptr && p2->getCrop() != nullptr && p2->getCrop()->getAge() < p2->getCrop()->getMaxAge() ) {
            p2Stream << p2->getPlotCropType() << "\n";
            p2Stream << " " << p2-> getCrop()->getPlantSize() <<  "/" << p2->getCrop()->getMaxSize();
        } else if(p2 != nullptr && p2->getCrop() != nullptr && p2->getCrop()->getAge() >= p2->getCrop()->getMaxAge()) {
            p2Stream << "Dead Crop";
        } else{
            p2Stream << "Empty";
        }
        plot2Text.setString(p2Stream.str());

        // For p3
        std::ostringstream p3Stream;
        if (p3 != nullptr && p3->getCrop() != nullptr && p3->getCrop()->getAge() < p3->getCrop()->getMaxAge() ) {
            p3Stream << p3->getPlotCropType() << "\n";
            p3Stream << " " << p3-> getCrop()->getPlantSize() <<  "/" << p3->getCrop()->getMaxSize();
        } else if(p3 != nullptr && p3->getCrop() != nullptr && p3->getCrop()->getAge() >= p3->getCrop()->getMaxAge()) {
            p3Stream << "Dead Crop";
        } else{
            p3Stream << "Empty";
        }
        plot3Text.setString(p3Stream.str());

        // For p4
        std::ostringstream p4Stream;
        if (p4 != nullptr && p4->getCrop() != nullptr && p4->getCrop()->getAge() < p4->getCrop()->getMaxAge() ) {
            p4Stream << p4->getPlotCropType() << "\n";
            p4Stream << " " << p4-> getCrop()->getPlantSize() <<  "/" << p4->getCrop()->getMaxSize();
        } else if(p4 != nullptr && p4->getCrop() != nullptr && p4->getCrop()->getAge() >= p4->getCrop()->getMaxAge()) {
            p4Stream << "Dead Crop";
        } else{
            p4Stream << "Empty";
        }
        
        plot4Text.setString(p4Stream.str());

        // For p5
        std::ostringstream p5Stream;
        if (p5 != nullptr && p5->getCrop() != nullptr && p5->getCrop()->getAge() < p5->getCrop()->getMaxAge() ) {
            p5Stream << p5->getPlotCropType() << "\n";
            p5Stream << " " << p5-> getCrop()->getPlantSize() <<  "/" << p5->getCrop()->getMaxSize();
        } else if(p5 != nullptr && p5->getCrop() != nullptr && p5->getCrop()->getAge() >= p5->getCrop()->getMaxAge()) {
            p5Stream << "Dead Crop";
        } else{
            p5Stream << "Empty";
        }
        plot5Text.setString(p5Stream.str());

        for (int i = 0; i < farmy.getNumPlots(); ++i) {
            Crop *crop = farmy.getPlot(i)->getCrop();
            if (crop != nullptr) {
                if (farmy.getPlot(i)->getCrop()->getWaterLevel() > 1) {
                    plotSprites[i].setColor(sf::Color(150, 150, 150)); // Darker color
                }
                else if(farmy.getPlot(i)->getCrop()->getWaterLevel() == 0) {
                    plotSprites[i].setColor(sf::Color(sf::Color::White)); // Original color
                }
            }
        }
        window.clear(sf::Color(255, 255, 255));
    
        // draw everything here...
        // window.draw(...);
        window.draw(SPbackground);
        for (int i=0;i<5;i++){
            window.draw(plotSprites[i]);
        }
        
        window.draw(moneyText);
        window.draw(dayCount);
        window.draw(plot1Text);
        window.draw(plot2Text);        
        window.draw(plot3Text);
        window.draw(plot4Text);        
        window.draw(plot5Text);
        
        for (int i=0;i<5;i++){
            if (farmy.getPlot(i) != nullptr){
                if (farmy.getPlot(i)->hasCrop() == true){
                    if (i==0 && p1 != nullptr && p1->getCrop() != nullptr && p1->getCrop()->getPlantSize() != p1->getCrop()->getMaxSize() ){
                        window.draw(spPlant1);
                    }
                    else if (i==0 && p1 != nullptr && p1->getCrop() != nullptr && p1->getCrop()->getPlantSize() == p1->getCrop()->getMaxSize()){
                        if(p1->getPlotCropType() == "Wheat"){
                            spWheat1.setPosition(185,390);
                            window.draw(spWheat1);
                        }
                        else if(p1->getPlotCropType() == "bellPeppers"){
                            spPepper1.setPosition(185,400);
                            window.draw(spPepper1);
                        }
                        else if(p1->getPlotCropType() == "Onion"){
                            spOnion1.setPosition(200, 335);
                            window.draw(spOnion1);
                        }
                        else if(p1->getPlotCropType() == "Corn"){
                            spCorn1.setPosition(180,290);
                            window.draw(spCorn1);
                        }
                        else if(p1->getPlotCropType() == "Carrot"){
                            spCarrot1.setPosition(200, 370);
                            window.draw(spCarrot1);
                        }
                        else if(p1->getPlotCropType() == "Cherry"){
                            spCherry1.setPosition(155, 295);
                            window.draw(spCherry1);
                        }
                        else if(p1->getPlotCropType() == "Apple"){
                            spApple1.setPosition(155, 280);
                            window.draw(spApple1);
                        }
                    }
                    if (i==1 && p2 != nullptr && p2->getCrop() != nullptr && p2->getCrop()->getPlantSize() != p2->getCrop()->getMaxSize() ){
                        window.draw(spPlant2);
                    }
                    else if (i==1 && p2 != nullptr && p2->getCrop() != nullptr && p2->getCrop()->getPlantSize() == p2->getCrop()->getMaxSize()){
                        if(p2->getPlotCropType() == "Wheat"){
                            spWheat2.setPosition(290,370);
                            window.draw(spWheat2);
                        }
                        else if(p2->getPlotCropType() == "bellPeppers"){
                            spPepper2.setPosition(295,390);
                            window.draw(spPepper2);
                        }
                        else if(p2->getPlotCropType() == "Onion"){
                            spOnion2.setPosition(315, 325);
                            window.draw(spOnion2);
                        }
                        else if(p2->getPlotCropType() == "Corn"){
                            spCorn2.setPosition(295,280);
                            window.draw(spCorn2);
                        }
                        else if(p2->getPlotCropType() == "Carrot"){
                            spCarrot2.setPosition(315, 360);
                            window.draw(spCarrot2);
                        }
                        else if(p2->getPlotCropType() == "Cherry"){
                            spCherry2.setPosition(270, 285);
                            window.draw(spCherry2);
                        }
                        else if(p2->getPlotCropType() == "Apple"){
                            spApple2.setPosition(270, 270);
                            window.draw(spApple2);
                        }
                    }
                    if (i==2 && p3 != nullptr && p3->getCrop() != nullptr && p3->getCrop()->getPlantSize() != p3->getCrop()->getMaxSize() ){
                        window.draw(spPlant3);
                    }
                    else if (i==2 && p3 != nullptr && p3->getCrop() != nullptr && p3->getCrop()->getPlantSize() == p3->getCrop()->getMaxSize()){
                        if(p3->getPlotCropType() == "Wheat"){
                            spWheat3.setPosition(425,355);
                            window.draw(spWheat3);
                        }
                        else if(p3->getPlotCropType() == "bellPeppers"){
                            spPepper3.setPosition(430,390);
                            window.draw(spPepper3);
                        }
                        else if(p3->getPlotCropType() == "Onion"){
                            spOnion3.setPosition(450, 325);
                            window.draw(spOnion3);
                        }
                        else if(p3->getPlotCropType() == "Corn"){
                            spCorn3.setPosition(430,280);
                            window.draw(spCorn3); 
                        }
                        else if(p3->getPlotCropType() == "Carrot"){
                            spCarrot3.setPosition(450, 360);
                            window.draw(spCarrot3);
                        }
                        else if(p3->getPlotCropType() == "Cherry"){
                            spCherry3.setPosition(405, 285);
                            window.draw(spCherry3);
                        }
                        else if(p3->getPlotCropType() == "Apple"){
                            spApple3.setPosition(405, 270);
                            window.draw(spApple3);
                        }
                    }
                    if (i==3 && p4 != nullptr && p4->getCrop() != nullptr && p4->getCrop()->getPlantSize() != p4->getCrop()->getMaxSize() ){
                        window.draw(spPlant4);
                    }
                    else if (i==3 && p4 != nullptr && p4->getCrop() != nullptr && p4->getCrop()->getPlantSize() == p4->getCrop()->getMaxSize()){
                        if(p4->getPlotCropType() == "Wheat"){
                            spWheat4.setPosition(565,370);
                            window.draw(spWheat4);
                        }
                        else if(p4->getPlotCropType() == "bellPeppers"){
                            spPepper4.setPosition(565,390);
                            window.draw(spPepper4);
                        }
                        else if(p4->getPlotCropType() == "Onion"){
                            spOnion4.setPosition(585, 325);
                            window.draw(spOnion4);
                        }
                        else if(p4->getPlotCropType() == "Corn"){
                            spCorn4.setPosition(565,280);
                            window.draw(spCorn4);
                        }
                        else if(p4->getPlotCropType() == "Carrot"){
                            spCarrot4.setPosition(585, 360);
                            window.draw(spCarrot4);
                        }
                        else if(p4->getPlotCropType() == "Cherry"){
                            spCherry4.setPosition(540, 285);
                            window.draw(spCherry4);
                        }
                        else if(p4->getPlotCropType() == "Apple"){
                            spApple4.setPosition(540, 270);
                            window.draw(spApple4);
                        }
                    }
                    if (i==4 && p5 != nullptr && p5->getCrop() != nullptr && p5->getCrop()->getPlantSize() != p5->getCrop()->getMaxSize() ){
                        window.draw(spPlant5);
                    }
                    else if (i==4 && p5 != nullptr && p5->getCrop() != nullptr && p5->getCrop()->getPlantSize() == p5->getCrop()->getMaxSize()){
                        if(p5->getPlotCropType() == "Wheat"){
                            spWheat5.setPosition(695,380);
                            window.draw(spWheat5);
                        }
                        else if(p5->getPlotCropType() == "bellPeppers"){
                            spPepper5.setPosition(695,390);
                            window.draw(spPepper5);     
                        }
                        else if(p5->getPlotCropType() == "Onion"){
                            spOnion5.setPosition(705, 325);
                            window.draw(spOnion5);      
                        }   
                        else if(p5->getPlotCropType() == "Corn"){
                            spCorn5.setPosition(685,280);
                            window.draw(spCorn5);
                        }
                        else if(p5->getPlotCropType() == "Carrot"){
                            spCarrot5.setPosition(705, 360);
                            window.draw(spCarrot5);
                        }   
                        else if(p5->getPlotCropType() == "Cherry"){
                            spCherry5.setPosition(660, 285);
                            window.draw(spCherry5);
                        }
                        else if(p5->getPlotCropType() == "Apple"){
                            spApple5.setPosition(660, 270);
                            window.draw(spApple5);
                        }
                    }
            }
            }
        }
        // end the current frame
        window.display();
    }
    return 0;
    }