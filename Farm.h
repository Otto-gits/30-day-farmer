#ifndef FARM_H
#define FARM_H

#include <string>
#include <iostream>

#include "Plot.h"
#include "Crop.h"
#include "Tool.h"


using namespace std;

// Farm class that is the basis for the project

class Farm{
    protected:
        string name;
        string location;
        float balance;
        int dayNum;
        int maxNumDays;
        // int bellPeppersHarvastCount;
        // int onionHarvastCount;
        // int carrotHarvastCount;
        // int wheatHarvastCount;
        // int cornHarvastCount;
        // int cherryHarvastCount;
        // int appleHarvastCount;
        int numPlots;
        Plot** plots;
    public: 
        Farm();
        Farm(string name, string location);
        void newDay();
        // void addPlot(Plot* plot);
        void addToBalance(int amount);
        void removeFromBalance(int amount);
        int getDayNum();
        int getNumPlots();
        Plot* getAvailablePlot();
        float getBalance();
        Plot* getPlot(int index);
        
};


#endif