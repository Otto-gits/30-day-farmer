#include "Carrot.h"

#include <iostream>

using namespace std;

Carrot::Carrot(){
    salePrice = 13;
    plant_age = 0;
    waterLevel = 0;
    plant_size = 0;
    max_age = 16; // Max age before dying 
    max_size = 8;  
    growth_rate = 2; //Grows by size two every day  
    profit = 11; 
    waterSchedule = 3; // Every four days 
    type = "Carrot";
}


