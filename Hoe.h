#ifndef HOE_H
#define HOE_H

#include "Tool.h"
#include "Plot.h"


class Hoe: public Tool{
    public:
        Hoe(); // Default constructor for hoe
        void sowPlot(Plot& plot); // Changes the sowed status of a plot that is passed in to be true
        void use (Plot& plot)override; // Overidden use function from tool that calls sowPlot to perform the Hoe's specific use
};


#endif
