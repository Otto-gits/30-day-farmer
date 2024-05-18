#ifndef TOOL_H
#define TOOL_H

class Tool{
    protected:
        int uses;
    public:
        Tool();
        virtual void sowPlot(Plot& plot);
        virtual void digupCrop(Plot& plot);
        virtual void  waterCrop(Plot& plot);
        virtual void harvestCrop(Crop& crop);
        int getUses();
        void setUses(int uses);
    

};


#endif