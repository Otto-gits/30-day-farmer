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
    if (sowed == true){ // Check to see if plot is sowed
        if (hasCrop() == false){
            crop = new Crop(*newCrop); // set crop to be pointer parssed in 
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
    if(crop != nullptr){ // Check to see if crop is a null pointer 
        delete crop; // Delete the crop 
        crop = nullptr;
        sowed = false;
        cout << "Crop removed" << endl;
    }else{
        cout << "There is not crop in this plot" << endl;
    }
}

string Plot::getPlotCropType(){
    if (hasCrop()){
        return crop->getType(); // Return the type (string) of crop in the plot 
    }else{
        return "Empty";
    }
}

Plot::~Plot(){
    delete crop; // Delete the crop in the plot, freeing up any dynamically allocated space 
}



