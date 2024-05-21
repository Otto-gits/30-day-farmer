#include "Shovel.h"
#include <iostream>

using namespace std;

Shovel::Shovel(){
    uses = 4;
}


void Shovel::digupCrop(Plot& plot){
    if(plot.hasCrop()){ // Check to see if the plot has a crop
        plot.removeCrop(); // Call removeCrop from Plot
        cout << "Crop dug up succesfully" << endl;
        uses--; // decrement uses 
    }else{
        cout <<"Crop could not be dug up" << endl;
    }
}


void Shovel::use(Plot& plot) {
    digupCrop(plot); // Call the specific action for the Shovel
}
