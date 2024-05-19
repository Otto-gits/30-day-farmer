#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "Tool.h"
#include "Plot.h"

class wateringCan : public Tool {
public:
    wateringCan();
    Crop* waterCrop(Plot& plot); // Returning pointer to Crop object
};

#endif
