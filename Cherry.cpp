#include "Cherry.h"

#include <iostream>

using namespace std;

Cherry::Cherry(){
    plantAge = 0;
    waterLevel = 0;
    plantSize = 0;
    maxAge = 18; // Max age before dying 
    maxSize = 20;  
    growthRate = 5; //Grows by size two every day  
    salePrice = 20;
    type = "Cherry";
}


