#include "Farm.h"
#include <iostream>

using namespace std;

Farm::Farm(){
    name = "Farm";
    location = "Adelaide";
    balance = 0;
    // bellPeppersHarvastCount = 0;
    // onionHarvastCount = 0;
    // carrotHarvastCount = 0;
    // wheatHarvastCount = 0;
    // cornHarvastCount = 0;
    // cherryHarvastCount = 0;
    // appleHarvastCount = 0;
    numPlots = 0;
    maxNumPlots = 10;
    plots = new Plot*[maxNumPlots];
}

Farm::Farm(string name, string location){
    this->name = name;
    this->location = location; 
    balance = 0;
    // bellPeppersHarvastCount = 0;
    // onionHarvastCount = 0;
    // carrotHarvastCount = 0;
    // wheatHarvastCount = 0;
    // cornHarvastCount = 0;
    // cherryHarvastCount = 0;
    // appleHarvastCount = 0;
    numPlots = 0;
    maxNumPlots = 10;
    plots = new Plot*[maxNumPlots];
}


void Farm::addPlot(Plot* plot){
    if (numPlots < maxNumPlots){
        plots[numPlots] = plot;
        numPlots++;
    }else{
        cout << "The farm is full" << endl;
        return;
    }
}

void Farm::addToBalance(int amount){
    balance += amount;
}