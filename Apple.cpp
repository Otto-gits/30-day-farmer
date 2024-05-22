#include "Apple.h"

#include <iostream>

using namespace std;

Apple::Apple(){
    plantAge = 0;
    waterLevel = 0;
    plantSize = 0;
    maxAge = 14; // Max age before dying 
    maxSize = 10;  
    growthRate = 5; //Grows by size two every day  
    salePrice = 20;
    type = "Apple";
}


