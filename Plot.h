#ifndef PLOT_H
#define PLOT_H

#include <string>
#include "Crop.h"

using namespace std;

class Plot{
    protected:
        bool sowed; // Boolean status of whether the plot is sowed or not, allowing for crop planting 
        Crop* crop; // Create a pointer to a crop
    public:
        Plot(); // Default constructor for Plot, sets sowed to be false and crop to initially be a nullptr
        ~Plot(); // Default destructor for Plot, deleting the crop in the plot. 
        bool getSowed(); // Returns the status of whether the plot is sowed 
        void sow(); // Sowes the plot 
        void plantCrop(Crop* newCrop); // Plants a crop in the plot 
        void removeCrop(); // Removes a crop from the plot
        bool hasCrop(); // Returns a boolean depended on whether a plot has a crop in it 
        Crop* getCrop(); // Returns a pointer to a crop in the plot
        string getPlotCropType(); // Returns a string depended on the type of the crop in the plot
};

#endif