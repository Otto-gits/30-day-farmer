#ifndef SCYTHE_H
#define SCYTHE_H

#include "Tool.h"
#include "Plot.h"
#include "cropMerchant.h"
#include "Farm.h"



class Scythe: public Tool{
    private:
        Farm farm;
    public:
        Scythe(Farm& farm);
        void harvestCrop(Crop& crop);
};

#endif

// Need to fix this