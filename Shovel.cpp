#include "Shovel.h"
#include <iostream>

using namespace std;

Shovel::Shovel(){
    uses = 4;
}


void Shovel::digupCrop(Plot& plot){
    if(plot.hasCrop()){
        plot.removeCrop();
        cout << "Crop dug up succesfully" << endl;
        uses--;
    }else{
        cout <<"Crop could not be dug up" << endl;
    }
}


void Shovel::use(Plot& plot) {
    digupCrop(plot); // Call the specific action for the Shovel
}
