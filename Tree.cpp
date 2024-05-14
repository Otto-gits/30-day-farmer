#include "Carrot.h"

#include <iostream>

using namespace std;

Carrot::Carrot(){
    plant_age = 0;
    waterLevel = 0;
    plant_size = 0;
    max_age = 0; // Max age before dying 
    max_size = 0;  
    growth_rate = 0; //Grows by size two every day  
    profit = 0; 
    waterSchedule = 0; // Every four days 
}


