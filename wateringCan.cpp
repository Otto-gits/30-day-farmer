#include <iostream>
#include "wateringCan.h"

using namespace std;

wateringCan::wateringCan() {
    uses = 4;
}

void wateringCan::waterCrop(Plot& plot) {
    Crop* crop = plot.getCrop(); // Create a pointer to a crop that is the crop contained within the plot that is passed through
    if (crop) { // Check if crop is not null
        crop->setWaterLevel(100); // Setting water level to 100
        uses--; // Decrement the uses 
    }
}

void wateringCan::use(Plot& plot) {
    waterCrop(plot); // Call the specific action for the wateringCan
}

