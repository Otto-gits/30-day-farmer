#ifndef SHOVEL_H
#define SHOVEL_H

#include "Tool.h"
#include "Plot.h"

using namespace std;

class Shovel: public Tool{
    private:
    public:
        Shovel();
        void digupCrop(Plot &plot);
};


#endif