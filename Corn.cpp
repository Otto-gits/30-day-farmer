#include "Corn.h"

#include <iostream>

using namespace std;

Corn::Corn(){
    salePrice = 13;
    plant_age = 0;
    waterLevel = 0;
    plant_size = 0;
    max_age = 15; // Max age before dying 
    max_size = 8;  
    growth_rate = 2; //Grows by size two every day  
    profit = 13; 
    waterSchedule = 4; // Every four days 
    type = "Corn";
}


