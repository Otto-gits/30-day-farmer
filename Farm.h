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
        string name; // Name of farm
        string location; // Location of farm
        int balance; // Farm bank account balance
        int dayNum; // Current day the farm is on 
        int maxNumDays; // Maximum number of days for the game (30)
        int numPlots; // Number of plots (5)
        Plot** plots; // Creates an array of pointers to plotss
    public: 
        Farm(); // Default constructor for Farm
        void newDay(); // Increments to dayNum by one and then changes the crop data members accordingly 
        void addToBalance(int amount); // Add an amount of money to the farms balance
        void removeFromBalance(int amount); // Remove an amount of money from the farms balance
        int getDayNum(); // Return the day number you are currently on
        int getNumPlots(); // Return the number of plots there are 
        Plot* getAvailablePlot(); // Find an available plot that does not have a crop in it and return a pointer to that plot
        float getBalance(); // Return the farms account balance 
        Plot* getPlot(int index); // Return a pointer to a specific plot depended on the the index 
};


#endif