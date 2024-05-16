#include "bellPeppers.h"

#include <iostream>

using namespace std;

bellPeppers::bellPeppers(){
    salePrice = 6;
    plant_age = 0;
    max_age = 20; // Max age before dying 
    plant_size = 0;
    max_size = 8;  
    growth_rate = 2; //Grows by size two every day  
    profit = 6; 
    waterSchedule = 4; // Every four days 
    waterLevel = 0;
}


