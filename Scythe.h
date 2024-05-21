#ifndef SCYTHE_H
#define SCYTHE_H

#include "Tool.h"
#include "Plot.h"
#include "cropMerchant.h"
#include "Farm.h"
#include "Wheat.h"




class Scythe: public Tool{
    private:
        Farm* farm; // Create a pointer to a farm
    public:
        Scythe(Farm* farm); // Default constructor that accepts a farm passed in to it 
        void harvestCrop(Plot& plot); // Harvest a crop that is passsed through by the plot that the crop is contained in 
        void use(Plot& plot) override; // Overidden use function from tool that calls harvestCrop to perform the scythe's specific use
};

#endif

// Need to fix this