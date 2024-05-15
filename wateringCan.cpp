#include <iostream>
#include "wateringCan.h"

using namespace std;

wateringCan::wateringCan() {
    uses = 4;
}

void wateringCan::waterCrop(Crop& crop) { // Accepting reference to Crop object
    crop.setWaterLevel(100); // Setting water level to 100
    uses--;
}

