#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "Tool.h"
#include "Plot.h"

class wateringCan : public Tool {
public:
    wateringCan();
    void waterCrop(Plot& plot); // Returning pointer to Crop object
    void use(Plot& plot)override;
};


#endif
