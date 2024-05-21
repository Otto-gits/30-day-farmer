#include "Onion.h"

#include <iostream>

using namespace std;

Onion::Onion(){
    plantAge = 0;
    plantSize = 0;
    waterLevel = 0;
    maxAge = 15; // Max age before dying 
    maxSize = 10;  
    growthRate = 3; 
    salePrice = 9;
    type = "Onion";
}

