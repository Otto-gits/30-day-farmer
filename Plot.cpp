#include "Plot.h"
#include <iostream>

using namespace std;

Plot::Plot(){
    sowed = false;
    numCrops = 0;
    maxCrops = 4;
    crops = new Crop*[maxCrops];
}

bool Plot::getSowed(){
    return sowed;
}

int Plot::getNumCrops(){
    return numCrops;
}

void Plot::sow(){
    sowed = true;
}

void Plot::plantCrop(Crop* crop){
    if (numCrops < maxCrops){
        crops[numCrops] = crop;
        numCrops++;
    }else{
        cout << "The plot is full" << endl;
        return;
    }
}