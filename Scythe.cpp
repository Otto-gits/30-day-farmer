#include <iostream>
#include "Scythe.h"

using namespace std;

Scythe::Scythe(){
    uses = 4;
}

void Scythe::harvestCrop(Crop& crop) { // Accepting reference to Crop object
    
    uses--;
}

// Need to fix this
