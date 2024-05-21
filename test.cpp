#include <iostream>
#include "Wheat.h"
#include "Plot.h"
#include "Crop.h"
#include "Farm.h"
#include "bellPeppers.h"
#include "Onion.h"
#include "Carrot.h"
#include "Corn.h"
#include "Scythe.h"
#include "Hoe.h"
#include "Shovel.h"
#include "wateringCan.h"
#include "Tool.h"
#include "cropMerchant.h"
#include "Cherry.h"
#include "Tree.h"
#include "Apple.h"


using namespace std;

int main(){
    Farm f1;          // Create a Farm object

    Corn corn;      // Create a Corn object
    Wheat w1;  // Create a Wheat object
    bellPeppers bp1;
    Onion o1;
    Carrot ca1;
    Cherry ch1;
    Apple a1;


    wateringCan can;  // Create a wateringCan object
    Hoe hoe;          // Create a Hoe object
    Shovel shovel;    // Create a Shovel object
    Scythe scythe(f1);

    cropMerchant merchant(f1); // Create a cropMerchant object

    cout << f1.getNumPlots() << endl;

    Plot* firstPlot = f1.getPlot(0);
    
    firstPlot->plantCrop(&w1);
    

    cout << firstPlot->getCrop()->getWaterLevel() << endl;
    
    can.waterCrop(*firstPlot);

    cout << firstPlot->getCrop()->getWaterLevel() << endl;




























    // f1.addToBalance(100);      // Add balance to the farm

    // cout << "Plot sowed status before sowing: " << p1->getSowed() << endl;
    // hoe.sowPlot(*p1); // Sow the plot
    // cout << "Plot sowed status after sowing: " << p1->getSowed() << endl;
    
    // p1->plantCrop(&wheat);  // Plant corn in the plot
    // cout << "Plot has crop: " << p1->hasCrop() << endl;

    // cout << "Initial water level of Corn: " << p1->getCrop()->getWaterLevel() << endl;
    // can.waterCrop(*p1);  // Water the corn crop
    // cout << "Water level of Corn after watering: " << p1->getCrop()->getWaterLevel() << endl;

    // p1->getCrop()->setPlantSize(4);

    // cout << p1->getCrop()->getPlantSize() << endl;

    // cout << f1.getBalance() << endl;

    // merchant.sellWheat();

    // cout << p1->hasCrop() << endl;  
    // cout << f1.getBalance() << endl;

    // shovel.digupCrop(*p1); // Dig up the crop
    // cout << "Plot has crop after digging up: " << p1->hasCrop() << endl;

    // f1.addPlot(p1); // Add the plot to the farm

    // cout << "Balance before buying wheat: " << f1.getBalance() << endl;
    // merchant.buyWheat(); // Buy wheat
    // cout << "Balance after buying wheat: " << f1.getBalance() << endl;

    // cout << "Plot has crop after buying wheat: " << p1->hasCrop() << endl;

    // s1.setUses(0);

    // cout << s1.getUses() << endl;

    // merchant.replenishScythe(s1,f1);
    // // merchant.buyCorn();

    // cout << s1.getUses() << endl;
    // cout << f1.getBalance() << endl;

    return 0;
}
