#include "bellPeppers.h"

#include <iostream>

using namespace std;

bellPeppers::bellPeppers(){
    plantAge = 0;
    waterLevel = 0;
    plantSize = 0;
    maxAge = 6; // Max age before dying 
    maxSize = 2;  
    growthRate = 2; //Grows by size two every day   
    salePrice = 6;
    type = "bellPeppers";
}


