#ifndef PLOT_H
#define PLOT_H

#include "Crop.h"

class Plot{
    protected:
        bool sowed;
        int numCrops;
        int maxCrops;   
        Crop** crops;
    public:
        Plot();
        bool getSowed();
        int getNumCrops();
        void sow();
        void plantCrop(Crop* crop);
        // void removeCrop(int ID);
};

#endif