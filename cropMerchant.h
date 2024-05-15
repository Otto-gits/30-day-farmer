#ifndef CROPMERCHANT_H
#define CROPMERCHANT_H

#include "Crop.h"
#include "Tool.h"
#include "Plot.h"
#include "Farm.h"

class cropMerchant{
    private:
        int bellPeppersSeedCost;
        int onionSeedCost;
        int carrotSeedCost;
        int wheatSeedCost;
        int cornSeedCost;
        int cherrySeedCost;
        int appleSeedCost;
        int bellPeppersSalePrice;
        int onionSeedSalePrice;
        int carrotSeedSalePrice;
        int wheatSeedSalePrice;
        int cornSeedSalePrice;
        int cherrySeedSalePrice;
        int appleSeedSalePrice;
        int scytheReplenishmentCost;
        int hoeReplenishmentCost;
        int shovelReplenishmentCost;    
        int wateringCanReplenishmentCost;    
    public:
        cropMerchant();
        void buyWheat(Crop& crop);
        void buyBellPeppers(Crop& crop);
        void buyOnion(Crop& crop);
        void buyCarrot(Crop& crop);
        void buyCorn(Crop& crop);
        void buyCherry(Crop& crop);
        void buyApple(Crop& corp);
        void replenishScythe(Tool& tool);
        void replenishHoe(Tool& tool);
        void replenishShovel(Tool& tool);
        void replenishWateringCan(Tool& tool);
};

#endif