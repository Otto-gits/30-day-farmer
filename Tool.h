#ifndef TOOL_H
#define TOOL_H

#include "Plot.h"
#include "Crop.h"

class Tool{
    protected:
        int uses;
    public:
        Tool();
        int getUses();
        void setUses(int uses);
    

};


#endif