#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "Tool.h"
#include "Plot.h"

class wateringCan : public Tool {
public:
    wateringCan(); // Default constructor for watering can 
    void waterCrop(Plot& plot); // Waters a crop that is passed in through the plot that that crop is contained in 
    void use(Plot& plot)override; // Overidden use function from tool that calls waterCrop to perform the watering can's specific use 
};


#endif
