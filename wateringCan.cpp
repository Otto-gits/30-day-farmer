#include <iostream>
#include "wateringCan.h"

using namespace std;

wateringCan::wateringCan() {
    uses = 4;
}

void wateringCan::waterCrop(Plot& plot) { // Returning pointer to Crop object
    Crop* crop = plot.getCrop(); // Correct method call
    if (crop) { // Check if crop is not null
        crop->setWaterLevel(100); // Setting water level to 100
        uses--;
    }
}

void wateringCan::use(Plot& plot) {
    waterCrop(plot); // Call the specific action for the WateringCan
}

