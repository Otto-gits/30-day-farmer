#include "Crop.h"
#include <iostream>

#include "cropMerchant.h"
#include "Farm.h"

Crop::Crop(){
}

int Crop::getAge(){
    return plantAge;
}

int Crop::getMaxAge(){
    return maxAge;
}

float Crop::getWaterLevel(){
    return waterLevel;
}

int Crop::getPlantSize(){
    return plantSize;
}

int Crop:: getMaxSize(){
    return maxSize;
}

void Crop::setPlantAge(int plantAge){
    this->plantAge = plantAge;
}
void Crop::setPlantSize(int plantSize){
    this->plantSize = plantSize;
}

void Crop::setWaterLevel(float waterLevel){
    this->waterLevel = waterLevel;
}

bool Crop::isMature(){
    if (plantSize == maxSize){
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

