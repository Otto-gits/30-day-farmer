#ifndef CROPMERCHANT_H
#define CROPMERCHANT_H

#include "Crop.h"
#include "Tool.h"
#include "Plot.h"
#include "Farm.h"
#include "Wheat.h"
#include "bellPeppers.h"
#include "Onion.h"
#include "Carrot.h"
#include "Corn.h"
#include "Tree.h"
#include "Cherry.h"
#include "Apple.h"
#include "Scythe.h"
#include "Hoe.h"
#include "Shovel.h"
#include "wateringCan.h"

class cropMerchant{
    private:
        Farm& farm;
        int bellPeppersSeedCost;
        int onionSeedCost;
        int carrotSeedCost;
        int wheatSeedCost;
        int cornSeedCost;
        int cherrySeedCost;
        int appleSeedCost;
        int scytheReplenishmentCost;
        int hoeReplenishmentCost;
        int shovelReplenishmentCost;    
        int wateringCanReplenishmentCost;    
    public:
        cropMerchant(Farm& farm);
        void buyWheat();
        void buyBellPeppers();
        void buyOnion();
        void buyCarrot();
        void buyCorn();
        void buyCherry();
        void buyApple();
        void replenishScythe(Tool& tool, Farm& farm);
        void replenishHoe(Tool& tool, Farm& farm);
        void replenishShovel(Tool& tool, Farm& farm);
        void replenishWateringCan(Tool& tool, Farm& farm);
};

#endif