#ifndef PLOT_H
#define PLOT_H

#include "Crop.h"

class Plot{
    protected:
        bool sowed;
        Crop* crop;
    public:
        Plot();
        bool getSowed();
        void sow();
        void plantCrop(Crop* newCrop);
        void removeCrop();  
        bool hasCrop();
        Crop* getCrop();
};

#endif