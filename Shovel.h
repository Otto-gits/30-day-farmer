#ifndef SHOVEL_H
#define SHOVEL_H

#include "Tool.h"
#include "Plot.h"

class Shovel: public Tool{
    public:
        Shovel(); // Default constructor for a shovel
        void digupCrop(Plot& plot); // Digs up a crop that is passed through the plot that the crop is contained in. 
        void use (Plot& plot)override; // Overidden use function from tool that calls digupCrop to perform the shovel's specific use

};


#endif