#include "cropMerchant.h"

#include <iostream>

cropMerchant::cropMerchant(Farm& farm): farm(farm){
        bellPeppersSeedCost = 5;
        onionSeedCost = 7;
        carrotSeedCost = 11;
        wheatSeedCost = 1;
        cornSeedCost = 10;
        cherrySeedCost = 24;
        appleSeedCost = 30;
        scytheReplenishmentCost = 10;
        hoeReplenishmentCost = 10;
        shovelReplenishmentCost = 10;
        wateringCanReplenishmentCost = 10;   
}

void cropMerchant::buyWheat(){
        if (farm.getBalance() >= wheatSeedCost){
                Plot* availablePlot= farm.getAvailablePlot(); // Create pointer to available plot in farm
                if(availablePlot != nullptr && availablePlot->getSowed() == true){
                        availablePlot->plantCrop(new Wheat());
                        farm.removeFromBalance(wheatSeedCost); // deduct amount from farm balance
                }else{
                        cout << "No available plots to plant wheat" << endl;
                }
        }else{
                cout << "Insufficient funds to buy wheat" << endl;
        }
}

void cropMerchant:: buyBellPeppers(){
        if (farm.getBalance() >= bellPeppersSeedCost){
                Plot* availablePlot= farm.getAvailablePlot(); // Create pointer to available plot in farm
                if(availablePlot != nullptr && availablePlot->getSowed() == true){
                        availablePlot->plantCrop(new bellPeppers());
                        farm.removeFromBalance(bellPeppersSeedCost); // deduct amount from farm balance
                }else{
                        cout << "No available plots to plant bellpeppers" << endl;
                }
        }else{
                cout << "Insufficient funds to buy bellpeppers" << endl;
        }
}

void cropMerchant::buyOnion(){
        if (farm.getBalance() >= onionSeedCost){
                Plot* availablePlot= farm.getAvailablePlot(); // Create pointer to available plot in farm
                if(availablePlot != nullptr && availablePlot->getSowed() == true){
                        availablePlot->plantCrop(new Onion());
                        farm.removeFromBalance(onionSeedCost); // deduct amount from farm balance
                }else{
                        cout << "No available plots to plant onion" << endl;
                }
        }else{
                cout << "Insufficient funds to buy onion" << endl;
        }
}
void cropMerchant::buyCarrot(){
        if (farm.getBalance() >= carrotSeedCost){
                Plot* availablePlot= farm.getAvailablePlot(); // Create pointer to available plot in farm
                if(availablePlot != nullptr && availablePlot->getSowed() == true){
                        availablePlot->plantCrop(new Carrot());
                        farm.removeFromBalance(carrotSeedCost); // deduct amount from farm balance
                }else{
                        cout << "No available plots to plant carrot" << endl;
                }
        }else{
                cout << "Insufficient funds to buy carrot" << endl;
        }
}

void cropMerchant::buyCorn(){
        if (farm.getBalance() >= cornSeedCost){
                Plot* availablePlot= farm.getAvailablePlot(); // Create pointer to available plot in farm
                if(availablePlot != nullptr && availablePlot->getSowed() == true){
                        availablePlot->plantCrop(new Corn());
                        farm.removeFromBalance(cornSeedCost); // deduct amount from farm balance
                }else{
                        cout << "No available plots to plant corn" << endl;
                }
        }else{
                cout << "Insufficient funds to buy corn" << endl;
        }
}
        
void cropMerchant::buyCherry(){
        if (farm.getBalance() >= cherrySeedCost){
                Plot* availablePlot= farm.getAvailablePlot(); // Create pointer to available plot in farm
                if(availablePlot != nullptr && availablePlot->getSowed() == true){
                        availablePlot->plantCrop(new Cherry());
                        farm.removeFromBalance(cherrySeedCost); // deduct amount from farm balance
                }else{
                        cout << "No available plots to plant cherry" << endl;
                }
        }else{
                cout << "Insufficient funds to buy cherry" << endl;
        }
}

void cropMerchant::buyApple(){
        if (farm.getBalance() >= appleSeedCost){
                Plot* availablePlot= farm.getAvailablePlot();
                if(availablePlot != nullptr && availablePlot->getSowed() == true){ // Create pointer to available plot in farm
                        availablePlot->plantCrop(new Apple());
                        farm.removeFromBalance(appleSeedCost); // deduct amount from farm balance
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
                farm.removeFromBalance(scytheReplenishmentCost);  // deduct amount from farm balance
                cout << "Scythe sucessfully replenished" << endl;
        }else{
                cout << "Scythe could not be replenished" << endl;
        }
}

void cropMerchant::replenishHoe(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= hoeReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(hoeReplenishmentCost);  // deduct amount from farm balance
                cout << "Hoe sucessfully replenished" << endl;
        }else{
                cout << "Hoe could not be replenished" << endl;
        }
}
        
void cropMerchant::replenishShovel(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= shovelReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(shovelReplenishmentCost);  // deduct amount from farm balance
                cout << "Shovel sucessfully replenished" << endl;
        }else{
                cout << "Shovel could not be replenished" << endl;
        }
}

void cropMerchant::replenishWateringCan(Tool& tool, Farm& farm){
        if (tool.getUses() == 0 & farm.getBalance() >= wateringCanReplenishmentCost){
                tool.setUses(4);
                farm.removeFromBalance(wateringCanReplenishmentCost);  // deduct amount from farm balance
                cout << "Watering can sucessfully replenished" << endl;
        }else{
                cout << "Watering can could not be replenished" << endl;
        }
}

void cropMerchant::sellWheat() {
    bool wheatSold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "Wheat" && plot->getCrop()->isMature()) {
            Crop* wheat = new Wheat; // Create pointer to wheat in plot
            wheat = plot->getCrop();
            
            if (wheat != nullptr) {
                farm.addToBalance(wheat->getSalePrice()); // add amount to farm balance
                cout << "Wheat from plot " << i + 1 << " sold for " << wheat->getSalePrice() << endl;
                plot->removeCrop();
                wheatSold = true;
            }
        } else {
            cout << "Wheat in plot " << i + 1 << " is not yet ready for sale." << endl;
        }
    }

    if (!wheatSold) {
        cout << "No wheat crops available for sale" << endl;
    }
}

void cropMerchant::sellBellPeppers() {
    bool bellPeppersSold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "BellPeppers" && plot->getCrop()->isMature()) {
            Crop* BellPeppers = new bellPeppers; // Create pointer to wheat in plot
            BellPeppers = plot->getCrop();
            
            if (BellPeppers != nullptr) {
                farm.addToBalance(BellPeppers->getSalePrice()); // add amount to farm balance
                cout << "Bell Peppers from plot " << i + 1 << " sold for " << BellPeppers->getSalePrice() << endl;
                plot->removeCrop();
                bellPeppersSold = true;
            }
        } else { 
            cout << "Bell Peppers in plot " << i + 1 << " are not yet ready for sale." << endl;
        }
    }

    if (!bellPeppersSold) {
        cout << "No Bell Peppers crops available for sale" << endl;
    }
}

void cropMerchant::sellOnion() {
    bool onionSold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "Onion" && plot->getCrop()->isMature()) {
            Crop* onion = new Onion; // Create pointer to wheat in plot
            onion = plot->getCrop();
            
            if (onion != nullptr) {
                farm.addToBalance(onion->getSalePrice()); // add amount to farm balance
                cout << "Onion from plot " << i + 1 << " sold for " << onion->getSalePrice() << endl;
                plot->removeCrop();
                onionSold = true;
            }
        } else {
            cout << "Onion in plot " << i + 1 << " is not yet ready for sale." << endl;
        }
    }

    if (!onionSold) {
        cout << "No Onion crops available for sale" << endl;
    }
}

void cropMerchant::sellCarrot() {
    bool carrotSold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "Carrot" && plot->getCrop()->isMature()) {
            Crop* carrot = new Carrot; // Create pointer to wheat in plot
            carrot = plot->getCrop();
            
            if (carrot != nullptr) {
                farm.addToBalance(carrot->getSalePrice()); // add amount to farm balance
                cout << "Carrot from plot " << i + 1 << " sold for " << carrot->getSalePrice() << endl;
                plot->removeCrop();
                carrotSold = true;
            }
        } else {
            cout << "Carrot in plot " << i + 1 << " is not yet ready for sale." << endl;
        }
    }

    if (!carrotSold) {
        cout << "No Carrot crops available for sale" << endl;
    }
}

void cropMerchant::sellCorn() {
    bool cornSold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "Corn" && plot->getCrop()->isMature()) {
            Crop* corn = new Corn; // Create pointer to wheat in plot
            corn = plot->getCrop(); 
            
            if (corn != nullptr) {
                farm.addToBalance(corn->getSalePrice()); // add amount to farm balance 
                cout << "Corn from plot " << i + 1 << " sold for " << corn->getSalePrice() << endl;
                plot->removeCrop();
                cornSold = true;
            }
        } else {
            cout << "Corn in plot " << i + 1 << " is not yet ready for sale." << endl;
        }
    }

    if (!cornSold) {
        cout << "No Corn crops available for sale" << endl;
    }
}

void cropMerchant::sellCherry() {
    bool cherrySold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "Cherry" && plot->getCrop()->isMature()) {
            Crop* cherry = new Cherry; // Create pointer to wheat in plot
            cherry = plot->getCrop();
            
            if (cherry != nullptr) {
                farm.addToBalance(cherry->getSalePrice());  // add amount to farm balance 
                cout << "Cherry from plot " << i + 1 << " sold for " << cherry->getSalePrice() << endl;
                plot->removeCrop();
                cherrySold = true;
            }
        } else {
            cout << "Cherry in plot " << i + 1 << " is not yet ready for sale." << endl;
        }
    }

    if (!cherrySold) {
        cout << "No Cherry crops available for sale" << endl;
    }
}

void cropMerchant::sellApple() {
    bool appleSold = false;

    for (int i = 0; i < farm.getNumPlots(); i++) {
        Plot* plot = farm.getPlot(i);

        if (plot->hasCrop() && plot->getCrop()->getType() == "Apple" && plot->getCrop()->isMature()) {
            Crop* apple = new Apple; // Create pointer to wheat in plot
            apple = plot->getCrop();
            
            if (apple != nullptr) {
                farm.addToBalance(apple->getSalePrice());  // add amount to farm balance 
                cout << "Apple from plot " << i + 1 << " sold for " << apple->getSalePrice() << endl;
                plot->removeCrop();
                appleSold = true;
            }
        } else {
            cout << "Apple in plot " << i + 1 << " is not yet ready for sale." << endl;
        }
    }

    if (!appleSold) {
        cout << "No Apple crops available for sale" << endl;
    }
}

