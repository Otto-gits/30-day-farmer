#ifndef CROP_H
#define CROP_H

#include <string>

using namespace std;

 class Crop {
    protected:
        int plantAge; // Current age of a crop
        int maxAge; // Maximum age a crop can reach, meaning the maximum day it can get it before dying 
        int plantSize; // Current size of a crop
        int maxSize; // Maximum size a crop can reach, meaning the size it will be harvestable at 
        float waterLevel; // The water level of a crop, initially 0 but then set to 100 using the watering an
        int salePrice; // The profit you receive for harvesting a crop
        string type; // The type of crop you are working with

    public:
        Crop(); // Default consturctor for crop
        int getAge(); // Returns the current age of a crop
        int getMaxAge(); // Returns the maximum age of a crop
        int getPlantSize(); // Returns the current plant size of a crop
        int getMaxSize(); // Returns the maximum plant size for a crop
        float getWaterLevel(); // Returns the current water level of a plant
        void setPlantAge(int plantAge); // Set the plant age of a crop
        void setPlantSize(int plantSize); // Set the plant size of a crop
        void setWaterLevel(float waterLevel); // Set the water level of a crop
        bool isMature(); // Checks to see whether a crop has achieved its maximum plant size
        int getSalePrice(); // Returns the sale price for a crop
        string getType(); // Returns the type of crop a crop object is
 };

#endif

