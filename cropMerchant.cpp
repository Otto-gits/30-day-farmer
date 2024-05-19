#include "cropMerchant.h"

#include <iostream>

cropMerchant::cropMerchant(Farm& farm): farm(farm){
        bellPeppersSeedCost = 5;
        onionSeedCost = 7;
        carrotSeedCost = 11;
        wheatSeedCost = 1;
        cornSeedCost = 10;
        cherrySeedCost = 24;
        appleSeedCost = 25;
        scytheReplenishmentCost = 10;
        hoeReplenishmentCost = 10;
        shovelReplenishmentCost = 10;
        wateringCanReplenishmentCost = 10;   
}

void cropMerchant::buyWheat(){
        if (farm.getBalance() >= wheatSeedCost){
                farm.removeFromBalance(wheatSeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new Wheat());
                }else{
                        cout << "No available plots to plant wheat" << endl;
                }
        }else{
                cout << "Insufficient funds to buy wheat" << endl;
        }
}

void cropMerchant:: buyBellPeppers(){
        if (farm.getBalance() >= bellPeppersSeedCost){
                farm.removeFromBalance(bellPeppersSeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new bellPeppers());
                }else{
                        cout << "No available plots to plant bellpeppers" << endl;
                }
        }else{
                cout << "Insufficient funds to buy bellpeppers" << endl;
        }
}

void cropMerchant::buyOnion(){
        if (farm.getBalance() >= onionSeedCost){
                farm.removeFromBalance(onionSeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new Onion());
                }else{
                        cout << "No available plots to plant onion" << endl;
                }
        }else{
                cout << "Insufficient funds to buy onion" << endl;
        }
}
void cropMerchant::buyCarrot(){
        if (farm.getBalance() >= carrotSeedCost){
                farm.removeFromBalance(carrotSeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new Carrot());
                }else{
                        cout << "No available plots to plant carrot" << endl;
                }
        }else{
                cout << "Insufficient funds to buy carrot" << endl;
        }
}

void cropMerchant::buyCorn(){
        if (farm.getBalance() >= cornSeedCost){
                farm.removeFromBalance(cornSeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new Corn());
                }else{
                        cout << "No available plots to plant corn" << endl;
                }
        }else{
                cout << "Insufficient funds to buy corn" << endl;
        }
}
        
void cropMerchant::buyCherry(){
        if (farm.getBalance() >= cherrySeedCost){
                farm.removeFromBalance(cherrySeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new Cherry());
                }else{
                        cout << "No available plots to plant cherry" << endl;
                }
        }else{
                cout << "Insufficient funds to buy cherry" << endl;
        }
}

void cropMerchant::buyApple(){
        if (farm.getBalance() >= appleSeedCost){
                farm.removeFromBalance(appleSeedCost);
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr){
                        availablePlot->plantCrop(new Apple());
                }else{
                        cout << "No available plots to plant apple" << endl;
                }
        }else{
                cout << "Insufficient funds to buy apple" << endl;
        }
}

void cropMerchant::replenishScythe(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= scytheReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(scytheReplenishmentCost);
                cout << "Scythe sucessfully replenished" << endl;
        }else{
                cout << "Scythe could not be replenished" << endl;
        }
}

void cropMerchant::replenishHoe(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= hoeReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(hoeReplenishmentCost);
                cout << "Hoe sucessfully replenished" << endl;
        }else{
                cout << "Hoe could not be replenished" << endl;
        }
}
        
void cropMerchant::replenishShovel(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= shovelReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(shovelReplenishmentCost);
                cout << "Shovel sucessfully replenished" << endl;
        }else{
                cout << "Shovel could not be replenished" << endl;
        }
}

void cropMerchant::replenishWateringCan(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= wateringCanReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(wateringCanReplenishmentCost);
                cout << "Watering can sucessfully replenished" << endl;
        }else{
                cout << "Watering can could not be replenished" << endl;
        }
}

