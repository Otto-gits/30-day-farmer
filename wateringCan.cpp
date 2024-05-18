#include <iostream>
#include "wateringCan.h"

using namespace std;

wateringCan::wateringCan() {
    uses = 4;
}

void wateringCan::waterCrop(Plot& plot) { // Accepting reference to Crop object
    Crop* crop = plot.getCrop();
    crop->setWaterLevel(100); // Setting water level to 100
    uses--;
}

