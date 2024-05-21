#ifndef TOOL_H
#define TOOL_H

#include "Plot.h"
#include "Crop.h"

class Tool{
    protected:
        int uses; // The amount of uses a crop has before breaking
    public:
        Tool(); // Default constructor for tool, sets uses to 4
        int getUses(); // Returns the current amount of uses a tool has 
        void setUses(int uses); // Set the amount of uses for a tool
        virtual void use(Plot& plot) = 0; // Pure virtual function which allows a tool to be used, performing a specific function depending on the tool
};


#endif