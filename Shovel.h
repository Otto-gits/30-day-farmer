#ifndef SHOVEL_H
#define SHOVEL_H

#include "Tool.h"
#include "Plot.h"

class Shovel: public Tool{
    private:
    public:
        Shovel();
        void digupCrop(Plot& plot);
        void use (Plot& plot)override;
        
};


#endif