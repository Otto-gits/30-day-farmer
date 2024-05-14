#include "Crop.h"


Crop::Crop(){
    plant_age = 0;
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

void Crop::ageOneYear() {
    if (plant_age < max_age) {
        plant_age++;
    }
}