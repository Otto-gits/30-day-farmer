#include "Carrot.h"

#include <iostream>

using namespace std;

Carrot::Carrot(){
    plantAge = 0;
    waterLevel = 0;
    plantSize = 0;
    maxAge = 16; // Max age before dying 
    maxSize = 8;  
    growthRate = 2; //Grows by size two every day  
    salePrice = 13;
    type = "Carrot";
}


