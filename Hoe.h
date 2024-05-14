#ifndef HOE_H
#define HOE_H

#include "Tool.h"
#include "Plot.h"


class Hoe: public Tool{
    public:
        Hoe();
        Plot sowPlot(Plot plot);

};



#endif