#include "Wheat.h"

#include <iostream>

using namespace std;

Wheat::Wheat(){
    salePrice = 3;
    plant_age = 0;
    max_age = 10; // Max age before dying 
    plant_size = 0;
    max_size = 4;  
    growth_rate = 2; //Grows by size two every day  
    profit = 3; 
    waterSchedule = 2; // Every four days 
    waterLevel = 0;
}

