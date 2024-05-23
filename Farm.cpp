#include "Farm.h"
#include <iostream>

using namespace std;

Farm::Farm(){
    name = "Farm";
    location = "Adelaide";
    balance = 1000;
    dayNum = 0;
    numPlots = 5;
    maxNumDays = 30;
    plots = new Plot*[numPlots]; 
    for (int i = 0; i < numPlots; i++){
        plots[i] = new Plot(); // Dynamically allocate space for all the plots 
    }
}


void Farm::newDay(){
    if (dayNum < maxNumDays){
        dayNum++;
        for (int i = 0; i < numPlots; i++) {
            Plot* plot = plots[i];
            if (plot->hasCrop()) {
                Crop* crop = plot->getCrop();
                crop->setPlantAge((crop->getAge())+1); // Age all crops by one day 
                if (crop->getWaterLevel() == 100 && crop->getSize() < crop->getMaxSize()){
                    crop->setPlantSize(crop->getPlantSize() + 1); // If watered and not surpassed max size, age plant by one
                    crop->setWaterLevel(0);
                }
            }
        }
    }
    else{
        cout << "Game over" << endl;
    }
}

void Farm::addToBalance(int amount){
    balance += amount;
}

void Farm::removeFromBalance(int amount){
    balance -= amount;
}

Plot* Farm::getAvailablePlot(){
    for (int i = 0; i < numPlots; i++){
        if (!plots[i]->hasCrop()){
            return plots[i];
        }
    }
    return nullptr;
}

Plot* Farm::getPlot(int index){
    if (index >= 0 && index < numPlots) {
        return plots[index];
    } else {
        return nullptr; 
    }
}



float Farm::getBalance(){
    return balance;
}

int Farm::getDayNum(){
    return dayNum;
}

int Farm::getNumPlots(){
    return numPlots;
}

Farm::~Farm(){
    for (int i = 0; i < numPlots; i++) {
        delete plots[i]; // Delete each individual Plot object, freeing up any dynamically allocated space 
    }
    delete[] plots; // Delete the array of pointers, freeing up any dynamically allocated space z
}

