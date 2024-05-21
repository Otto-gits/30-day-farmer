#include "Crop.h"
#include <iostream>

#include "cropMerchant.h"
#include "Farm.h"

Crop::Crop(){
}
Crop::Crop(int ID){
    this -> ID = ID;
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

bool Crop::isMature(){
    if (plant_size == max_size){
        return true;
    }else{
        return false;
    }
}

int Crop::getSalePrice(){
    return salePrice;
}

string Crop::getType(){
    return type;
}

// Crop::CropType Crop::getType() const{
//     return CropType::Crop;
// }
