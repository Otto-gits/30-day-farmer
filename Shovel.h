#ifndef SHOVEL_H
#define SHOVEL_H

#include "Tool.h"
#include "Plot.h"


class Shovel: public Tool{
    public:
        Shovel();
        Plot plantCrop(Plot plot);
};


#endif