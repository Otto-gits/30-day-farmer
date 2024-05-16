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
        if (hasCrop() == false){
            crop = newCrop;
        }
        else{
            cout << "The plot is full" << endl;
            return;
        }
    }


    void Plot::removeCrop(){
        delete crop;
        crop = nullptr;
    }

