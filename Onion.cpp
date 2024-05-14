#include "Onion.h"

#include <iostream>

using namespace std;

Onion::Onion(){
    plant_age = 0;
    max_age = 15; // Max age before dying 
    plant_size = 0;
    max_size = 10;  
    growth_rate = 3;
    profit = 9; 
    waterSchedule = 3; // Every three days 
    waterLevel = 0;
}

