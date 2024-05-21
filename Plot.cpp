#include "Plot.h"
#include <iostream>

using namespace std;

Plot::Plot(){
    sowed = false;
    crop = nullptr;
}

bool Plot::getSowed(){
    return sowed;
}

bool Plot::hasCrop(){
    if (crop != nullptr){
        return true;
    }else{
        return false;
    }
}

void Plot::sow(){
    sowed = true;
}

void Plot::plantCrop(Crop* newCrop){
    if (sowed == true){
        if (hasCrop() == false){
            crop = new Crop(*newCrop);
        }
        else{
            cout << "The plot is full" << endl;
            return;
        }
    }else{
        cout << "The plot is not sowed" << endl;
    }
}

Crop* Plot::getCrop(){
    return crop;
}

void Plot::removeCrop(){
    if(crop != nullptr){
        delete crop;
        crop = nullptr;
        sowed = false;
        cout << "Crop removed" << endl;
    }else{
        cout << "There is not crop in this plot" << endl;
    }
}

string Plot::getPlotCropType(){
    if (hasCrop()){
        return crop->getType();
    }else{
        return "Empty";
    }
}