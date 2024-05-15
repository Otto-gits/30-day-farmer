#include "Shovel.h"

Shovel::Shovel(){
    uses = 4;
}

void Shovel::plant(Plot& plot){
    // Create a new Crop object to plant
    Crop* newCrop = new Crop(/* optionally pass ID */);

    // Plant the crop in the plot
    plot.plantCrop(newCrop);
    uses--;
}
