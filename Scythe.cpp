#include <iostream>
#include "Scythe.h"

using namespace std;

Scythe::Scythe(Farm& farm, Plot& plot){
    this->farm = farm;
    this->plot = plot;
    uses = 4;
}

void Scythe::harvestCrop(Crop& crop){ // Accepting reference to Crop object
    if (crop.isMature()){
        farm.addToBalance(crop.getSalePrice());
        plot.removeCrop();
        
        uses--;
    }
}



// Need to fix this
