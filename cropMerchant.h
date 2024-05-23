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
        Farm& farm; // Reference to a farm 
        int bellPeppersSeedCost; // Cost for purchasing bellPeppers 
        int onionSeedCost; // Cost for purchasing onion
        int carrotSeedCost; // Cost for purchasing carrot
        int wheatSeedCost; // Cost for purchasing wheat
        int cornSeedCost; // Cost for purchasing corn
        int cherrySeedCost; // Cost for purchasing cherry
        int appleSeedCost; // Cost for purchasing apple
        int scytheReplenishmentCost; // Cost for replenishing scythe
        int hoeReplenishmentCost; // Cost for replenishing hoe
        int shovelReplenishmentCost; // Cost for replensihing shovel
        int wateringCanReplenishmentCost; // Cost for replenishing watering can
    public:
        cropMerchant(Farm& farm); // Default constructor for cropMerchant, accepting a farm by reference
        void buyWheat(); // Function for buying and planting a wheat and updating farm account balance
        void buyBellPeppers(); // Function for buying and planting bellPeppers and updating farm account balance
        void buyOnion(); // Function for buying and planting a Onion and updating farm account balance
        void buyCarrot(); // Function for buying and planting carrot and updating farm account balance
        void buyCorn(); // Function for buying and planting a corn and updating farm account balance
        void buyCherry(); // Function for buying and planting a cherry and updating farm account balance
        void buyApple(); // Function for buying and planting a apple and updating farm account balance
        void replenishScythe(Tool& tool, Farm& farm); // Function for replenishing scythe, setting the uses to default amount, accpeting a scythe by reference and farm by reference
        void replenishHoe(Tool& tool, Farm& farm); // Function for replenishing hoe, setting the uses to default amount, accepting a hoe by reference and farm by reference
        void replenishShovel(Tool& tool, Farm& farm); // Function for replenishing shovel, setting the uses to default amount, accepting a shovel by reference and farm by reference
        void replenishWateringCan(Tool& tool, Farm& farm); // Function for replenishing watering can, setting the uses to default amount, accepting a wateringCan by reference and farm by reference
        void sellWheat(); // Functions for selling wheat, removing the crop from the plot it is in and then and updating farm account balance
        void sellBellPeppers(); // Functions for selling bellPeppers, removing the crop from the plot it is in and then and updating farm account balance
        void sellOnion(); // Functions for selling Onion, removing the crop from the plot it is in and then and updating farm account balance
        void sellCarrot(); // Functions for selling carrot, removing the crop from the plot it is in and then and updating farm account balance
        void sellCorn(); // Functions for selling corn, removing the crop from the plot it is in and then and updating farm account balance
        void sellCherry(); // Functions for selling cherry, removing the crop from the plot it is in and then and updating farm account balance
        void sellApple(); // Functions for selling apple, removing the crop from the plot it is in and then and updating farm account balance
};

#endif