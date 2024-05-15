#ifndef FARM_H
#define FARM_H

#include <string>
#include <iostream>
#include "Plot.h"

using namespace std;

// Farm class that is the basis for the project

class Farm{
    protected:
        string name;
        string location;
        float balance;
        int bellPeppersHarvastCount;
        int onionHarvastCount;
        int carrotHarvastCount;
        int wheatHarvastCount;
        int cornHarvastCount;
        int cherryHarvastCount;
        int appleHarvastCount;
        int numPlots;
        int maxNumPlots;
        Plot** plots;
    public: 
        Farm();
        Farm(string name, string location);
        void addPlot(Plot* plot);
};


#endif