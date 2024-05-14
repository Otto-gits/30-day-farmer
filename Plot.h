#ifndef PLOT_H
#define PLOT_H

class Plot{
    protected:
        bool sowed;
        int numCrops;
        int maxCrops;   
    public:
        Plot();
        bool getSowed();
        int getNumCrops();
        void sow();
};

#endif