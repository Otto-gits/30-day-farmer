#ifndef CROP_H
#define CROP_H

 class Crop {
    protected:
        int plant_age;
        int max_age;
        int plant_size;
        int max_size;
        int growth_rate;
        int profit;
        int waterSchedule;
        float waterLevel;
        int ID;
        int salePrice;
    public:
        Crop();
        Crop(int ID);
        int getAge();
        int getMaxAge();
        int getPlantSize();
        int getMaxSize();
        int getGrowthRate();
        int getProfit();
        int getWaterSchedule();
        void ageOneDay();
        float getWaterLevel();
        void setPlantAge(int plant_age);
        void setPlantSize(int plant_size);
        void setWaterLevel(float waterLevel);
        bool isMature();
        int getSalePrice();
 };

#endif

