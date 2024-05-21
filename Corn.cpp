#include "Corn.h"

#include <iostream>

using namespace std;

Corn::Corn(){
    plantAge = 0;
    waterLevel = 0;
    plantSize = 0;
    maxAge = 15; // Max age before dying 
    maxSize = 8;  
    growthRate = 2; //Grows by size two every day  
    salePrice = 13; 
    type = "Corn";
}


