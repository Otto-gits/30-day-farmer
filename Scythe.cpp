#include <iostream>
#include "Scythe.h"

using namespace std;

Scythe::Scythe(Farm& farm) {
    this->farm = &farm;  // Initialize the farm pointer
    uses = 4;
}

void Scythe::harvestCrop(int plotIndex) {
    if (plotIndex >= 0 && plotIndex < farm->getNumPlots()) {
        Plot* plot = farm->getPlot(plotIndex);
        if (plot->hasCrop()) {
            Crop* crop = plot->getCrop();
            if (crop->isMature()) {
                farm->addToBalance(crop->getSalePrice());
                plot->removeCrop();
                uses--;
            } else {
                cout << "Crop is not mature yet." << endl;
            }
        } else {
            cout << "No crop in this plot to harvest." << endl;
        }
    } else {
        cout << "Invalid plot index." << endl;
    }
}


