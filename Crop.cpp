#include "Crop.h"


Crop::Crop(){
    plant_age = 0;
    max_age = 10;
    int growth_rate = 4;
    int profit = 4;
    int waterSchedule = 4;
    float waterLevel = 4;
}
Crop::Crop(int plant_age, int max_age){
    this -> plant_age = plant_age;
    this -> max_age = max_age;
}

int Crop::getAge(){
    return plant_age;
}

int Crop::getMaxAge(){
    return max_age;
}

void Crop::ageOneDay() {
    if (plant_age < max_age) {
        plant_age++;
    }
}

float Crop::getWaterLevel(){
    return waterLevel;
}

int Crop::getPlantSize(){
    return plant_size;
}

int Crop:: getMaxSize(){
    return max_size;
}
int Crop::getGrowthRate(){
    return growth_rate;
}

int Crop:: getProfit(){
    return profit;
}

int Crop:: getWaterSchedule(){
    return waterSchedule;
}

void Crop::setPlantAge(int plant_age){
    this->plant_age = plant_age;
}
void Crop::setPlantSize(int plant_size){
    this->plant_size = plant_size;
}

void Crop::setWaterLevel(float waterLevel){
    this->waterLevel = waterLevel;
}