#ifndef WATERINGCAN_H
#define WATERINGCAN_H

#include "Tool.h"
#include "Plot.h"


class wateringCan : public Tool {
public:
    wateringCan();
    void waterCrop(Plot& plot); // Accepting reference to Crop object
};

#endif
