#include <iostream>
#include "wateringCan.h"
#include "Crop.h"
#include "Corn.h"
#include "Plot.h"
#include "Farm.h"
#include "Hoe.h"


using namespace std;

int main(){

    Corn c1;
    wateringCan can;
    Plot p1;
    Farm f1;
    Hoe hoe;

    Scythe s1(f1,p1);
    
    
    cout << c1.getWaterLevel() << endl;

    can.waterCrop(c1);

    cout << c1.getWaterLevel() << endl;

    cout << p1.getSowed() << endl;
    hoe.sowPlot(p1);

    cout << p1.getSowed() << endl;

    
}