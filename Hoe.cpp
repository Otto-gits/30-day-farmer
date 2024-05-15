#include "Hoe.h"

Hoe::Hoe(){
    uses = 4;
}

void Hoe::sowPlot(Plot& plot){
    plot.sow();
    uses--;
}

// Need to fix this