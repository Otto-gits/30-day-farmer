#ifndef TOOL_H
#define TOOL_H

class Tool{
    protected:
        int uses;
    public:
        Tool();
        virtual void sowPlot(Plot& plot) = 0 ;
        virtual void digupCrop(Plot &plot) = 0;
        virtual void  waterCrop(Crop& crop) = 0;
        virtual void harvestCrop(Crop& crop) = 0;
        int getUses();
        void setUses(int uses);
    

};


#endif