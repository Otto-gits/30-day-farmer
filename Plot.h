#ifndef PLOT_H
#define PLOT_H

#include "Crop.h"

class Plot{
    protected:
        bool sowed;
        // int numCrops;
        // int maxCrops;   
        // Crop** crops;
        Crop* crop;
    public:
        Plot();
        bool getSowed();
        // int getNumCrops();
        void sow();
        void plantCrop(Crop* newCrop);
        void removeCrop();  
        bool hasCrop();
        Crop* getCrop();
};

#endif