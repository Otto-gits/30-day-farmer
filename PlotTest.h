#include <iostream>
#include "Plot.h"
#include "Wheat.h"

class PlotTest {
public:
    void runPlotTests() {
        testDefaultConstructor();
        testGetSowed();
        testSow();
        testPlantCrop();
        testRemoveCrop();
        testHasCrop();
        testGetCrop();
        testGetPlotCropType();
    }

private:
    void testDefaultConstructor() {
        Plot plot;
        if (plot.getSowed() != false) {
            std::cout << "testDefaultConstructor failed: Expected false, got true" << std::endl;
        }
        if (plot.hasCrop() != false) {
            std::cout << "testDefaultConstructor failed: Expected false, got true" << std::endl;
        }
    }

    void testGetSowed() {
        Plot plot;
        if (plot.getSowed() != false) {
            std::cout << "testGetSowed failed: Expected false, got true" << std::endl;
        }
    }

    void testSow() {
        Plot plot;
        plot.sow();
        if (plot.getSowed() != true) {
            std::cout << "testSow failed: Expected true, got false" << std::endl;
        }
    }

    void testPlantCrop() {
        Plot plot;
        plot.sow();
        Wheat wheat;
        plot.plantCrop(&wheat);
        if (!plot.hasCrop()) {
            std::cout << "testPlantCrop failed: Expected true, got false" << std::endl;
        }
        if (plot.getPlotCropType() != "Wheat") {
            std::cout << "testPlantCrop failed: Expected Wheat, got " << plot.getPlotCropType() << std::endl;
        }
    }

    void testRemoveCrop() {
        Plot plot;
        plot.sow();
        Wheat wheat;
        plot.plantCrop(&wheat);
        plot.removeCrop();
        if (plot.hasCrop() != false) {
            std::cout << "testRemoveCrop failed: Expected false, got true" << std::endl;
        }
        if (plot.getPlotCropType() != "Empty") {
            std::cout << "testRemoveCrop failed: Expected Empty, got " << plot.getPlotCropType() << std::endl;
        }
    }

    void testHasCrop() {
        Plot plot;
        if (plot.hasCrop() != false) {
            std::cout << "testHasCrop failed: Expected false, got true" << std::endl;
        }
        plot.sow();
        Wheat wheat;
        plot.plantCrop(&wheat);
        if (plot.hasCrop() != true) {
            std::cout << "testHasCrop failed: Expected true, got false" << std::endl;
        }
    }

    void testGetCrop() {
        Plot plot;
        if (plot.getCrop() != nullptr) {
            std::cout << "testGetCrop failed: Expected nullptr, got non-null pointer" << std::endl;
        }
        plot.sow();
        Wheat wheat;
        plot.plantCrop(&wheat);
        if (plot.getCrop() == nullptr || plot.getCrop()->getType() != "Wheat") {
            std::cout << "testGetCrop failed: Expected non-null pointer to Wheat, got null or different type" << std::endl;
        }
    }

    void testGetPlotCropType() {
        Plot plot;
        if (plot.getPlotCropType() != "Empty") {
            std::cout << "testGetPlotCropType failed: Expected Empty, got " << plot.getPlotCropType() << std::endl;
        }
        plot.sow();
        Wheat wheat;
        plot.plantCrop(&wheat);
        if (plot.getPlotCropType() != "Wheat") {
            std::cout << "testGetPlotCropType failed: Expected Wheat, got " << plot.getPlotCropType() << std::endl;
        }
    }
};

