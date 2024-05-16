#include <iostream>
#include "Scythe.h"

using namespace std;

Scythe::Scythe(Farm& farm){
    this->farm = farm;
    uses = 4;
}

void Scythe::harvestCrop(Crop& crop){ // Accepting reference to Crop object
    if (crop.isMature()){
        farm.addToBalance(crop.getSalePrice());
        
        // crop.remove();
        uses--;
    }
}



// Need to fix this
