#ifndef HOE_H
#define HOE_H

#include "Tool.h"
#include "Plot.h"


class Hoe: public Tool{
    public:
        Hoe();
        void sowPlot(Plot& plot);
};


#endif
