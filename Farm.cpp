#include "Farm.h"
#include <iostream>

using namespace std;

Farm::Farm(){
    name = "Farm";
    location = "Adelaide";
    balance = 1000;
    dayNum = 0;
    numPlots = 5;
    plots = new Plot*[numPlots];
    for (int i = 0; i < numPlots; i++){
        plots[i] = new Plot();
    }
}


void Farm::newDay(){
    if (dayNum < maxNumDays){
        dayNum += 1;
        for (int i = 0; i < numPlots; i++) {
            Plot* plot = plots[i];
            if (plot->hasCrop()) {
                Crop* crop = plot->getCrop();
                crop->ageOneDay();
                if (crop->getWaterLevel() == 100) {
                    crop->setPlantSize(crop->getPlantSize() + 1);
                    crop->setWaterLevel(0);
                }
            }
        }
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