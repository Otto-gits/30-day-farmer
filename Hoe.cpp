#include "Hoe.h"

Hoe::Hoe(){
    uses = 4;
}

void Hoe::sowPlot(Plot& plot){
    plot.sow(); // call the sow function from plot 
    uses--; // Decrement uses 
}

void Hoe::use(Plot& plot) {
    sowPlot(plot); // Call the specific action for the Hoe
}
