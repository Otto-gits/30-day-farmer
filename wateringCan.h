#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "Tool.h"
#include "Crop.h"

class wateringCan : public Tool {
public:
    wateringCan();
    void waterCrop(Crop& crop); // Accepting reference to Crop object
};

#endif
