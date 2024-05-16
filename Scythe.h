#ifndef SCYTHE_H
#define SCYTHE_H

#include "Tool.h"
#include "Plot.h"
#include "cropMerchant.h"
#include "Farm.h"



class Scythe: public Tool{
    private:
        Farm farm;
        Plot plot;
    public:
        Scythe(Farm& farm, Plot& plot);
        void harvestCrop(Crop& crop);
};

#endif

// Need to fix this