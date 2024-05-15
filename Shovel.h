#ifndef SHOVEL_H
#define SHOVEL_H

#include "Tool.h"
#include "Plot.h"


class Shovel: public Tool{
    public:
        Shovel();
        void plant(Plot& plot);
};


#endif