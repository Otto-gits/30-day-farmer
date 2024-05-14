#include "Hoe.h"

Hoe::Hoe(){
    uses = 4;
}

Plot Hoe::sowPlot(Plot plot){
    plot.sow();
    return plot;
}

