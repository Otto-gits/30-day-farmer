#include <iostream>
#include "Scythe.h"

using namespace std;

Scythe::Scythe(Farm* farm) {
    this->farm = farm;  // Initialize the farm pointer
    uses = 4;
}

void Scythe::harvestCrop(Plot& plot) {
    if (plot.hasCrop()) {
        Crop* crop = plot.getCrop();
        if (crop->isMature()) {
            farm->addToBalance(crop->getSalePrice());
            plot.removeCrop();
            uses--;
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
