#include "Plot.h"

using namespace std;

Plot::Plot(){
    sowed = false;
    numCrops = 0;
    maxCrops = 4;
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