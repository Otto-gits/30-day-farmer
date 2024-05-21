#include "Wheat.h"

#include <iostream>

using namespace std;

Wheat::Wheat(){
    plantAge = 0;
    plantSize = 0;
    waterLevel = 0;
    maxAge = 10; // Max age before dying 
    maxSize = 4;  
    growthRate = 2; //Grows by size two every day  
    salePrice = 1;
    type = "Wheat";
}



