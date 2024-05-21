#ifndef SCYTHE_H
#define SCYTHE_H

#include "Tool.h"
#include "Plot.h"
#include "cropMerchant.h"
#include "Farm.h"
#include "Wheat.h"




class Scythe: public Tool{
    private:
        Farm* farm;
    public:
        Scythe(Farm* farm);
        void harvestCrop(Plot& plot);
};

#endif

// Need to fix this