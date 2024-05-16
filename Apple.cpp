#include "Apple.h"

#include <iostream>

using namespace std;

Apple::Apple(){
    salePrice = 20;
    plant_age = 0;
    waterLevel = 0;
    plant_size = 0;
    max_age = 25; // Max age before dying 
    max_size = 20;  
    growth_rate = 5; //Grows by size two every day  
    profit = 14; 
    waterSchedule = 3; // Every four days 
}


