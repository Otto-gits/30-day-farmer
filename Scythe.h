#ifndef SCYTHE_H
#define SCYTHE_H

#include "Tool.h"
#include "Plot.h"
#include "cropMerchant.h"
#include "Farm.h"



class Scythe: public Tool{
    public:
        Scythe();
        void harvestCrop(Crop& crop);
};

#endif

// Need to fix this