#include <iostream>
#include "Scythe.h"

using namespace std;

Scythe::Scythe(Farm* farm) {
    this->farm = farm;  // Initialize the farm pointer
    uses = 4; 
}

void Scythe::harvestCrop(Plot& plot) {
    if (plot.hasCrop()) { // Check to see if plot has a crop in it 
        Crop* crop = plot.getCrop(); // Create a pointer to the crop in the plot
        if (crop->isMature()) { // Checks to see if the crop is mature
            farm->addToBalance(crop->getSalePrice()); // Sell the crop by adding the sale price to the farms balance 
            plot.removeCrop(); // Remove the crop
            uses--; // Decrement the uses 
        } else { 
            cout << "Crop is not mature yet." << endl;
        }
    } else {
        cout << "No crop in this plot to harvest." << endl;
    }
}

void Scythe::use(Plot& plot) {
    harvestCrop(plot); // Call the specific action for the Scythe
}
