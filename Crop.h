#ifndef CROP_H
#define CROP_H

 class Crop {
    protected:
    int plant_age;
    int max_age;
    public:
    Crop();
    Crop(int plant_age, int max_age);
    int getAge();
    int getMaxAge();
    void ageOneYear();
 };

#endif

