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

using namespace std;

int main(){
    Farm f1;          // Create a Farm object
    Corn c1;          // Create a Corn object
    wateringCan can;  // Create a wateringCan object
    Plot* p1 = new Plot(); // Create a Plot object dynamically
    Hoe hoe;          // Create a Hoe object
    Shovel shovel;    // Create a Shovel object
    Wheat wheat;      // Create a Wheat object

    cropMerchant merchant(f1); // Create a cropMerchant object
    f1.addToBalance(100);      // Add balance to the farm

    Scythe s1(f1, *p1);  // Create a Scythe object with references to Farm and Plot

    cout << "Initial water level of Corn: " << c1.getWaterLevel() << endl;
    can.waterCrop(c1);  // Water the corn crop
    cout << "Water level of Corn after watering: " << c1.getWaterLevel() << endl;

    cout << "Plot sowed status before sowing: " << p1->getSowed() << endl;
    hoe.sowPlot(*p1); // Sow the plot
    cout << "Plot sowed status after sowing: " << p1->getSowed() << endl;

    p1->plantCrop(&c1);  // Plant corn in the plot
    cout << "Plot has crop: " << p1->hasCrop() << endl;

    shovel.digupCrop(*p1); // Dig up the crop
    cout << "Plot has crop after digging up: " << p1->hasCrop() << endl;

    f1.addPlot(p1); // Add the plot to the farm

    cout << "Balance before buying wheat: " << f1.getBalance() << endl;
    merchant.buyWheat(); // Buy wheat
    cout << "Balance after buying wheat: " << f1.getBalance() << endl;

    cout << "Plot has crop after buying wheat: " << p1->hasCrop() << endl;

    

    merchant.buyCorn();




    delete p1;  // Delete the dynamically created plot

    return 0;
}
