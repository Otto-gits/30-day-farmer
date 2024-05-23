// CropTest.h

#include <iostream>
#include "Crop.h"
#include "Wheat.h"

using namespace std;

class CropTest {
public:
    void runCropTests() {
        testGetAndSetPlantAge();
        testGetAndSetPlantSize();
        testGetAndSetWaterLevel();
        testIsMature();
        testGetters();
    }

private:
    void testGetAndSetPlantAge() {
        Wheat wheat;
        wheat.setPlantAge(5);
        if (wheat.getAge() != 5) {
            cout << "testGetAndSetPlantAge failed: Expected 5, got " << wheat.getAge() << endl;
        }
    }

    void testGetAndSetPlantSize() {
        Wheat wheat;
        wheat.setPlantSize(3);
        if (wheat.getPlantSize() != 3) {
            cout << "testGetAndSetPlantSize failed: Expected 3, got " << wheat.getPlantSize() << endl;
        }
    }

    void testGetAndSetWaterLevel() {
        Wheat wheat;
        wheat.setWaterLevel(75.5);
        if (wheat.getWaterLevel() != 75.5) {
            cout << "testGetAndSetWaterLevel failed: Expected 75.5, got " << wheat.getWaterLevel() << endl;
        }
    }

    void testIsMature() {
        Wheat wheat;
        wheat.setPlantSize(1);  // Wheat's maxSize is 1
        if (!wheat.isMature()) {
            cout << "testIsMature failed: Expected true, got false" << endl;
        }

        wheat.setPlantSize(0);  // Not yet mature
        if (wheat.isMature()) {
            cout << "testIsMature failed: Expected false, got true" << endl;
        }
    }

    void testGetters() {
        Wheat wheat;
        wheat.setPlantAge(3);
        wheat.setPlantSize(1);
        wheat.setWaterLevel(80.0);

        // Check if getters return correct values
        if (wheat.getAge() != 3) {
            cout << "testGetters (age) failed: Expected 3, got " << wheat.getAge() << endl;
        }
        if (wheat.getPlantSize() != 1) {
            cout << "testGetters (plantSize) failed: Expected 1, got " << wheat.getPlantSize() << endl;
        }
        if (wheat.getWaterLevel() != 80.0) {
            cout << "testGetters (waterLevel) failed: Expected 80.0, got " << wheat.getWaterLevel() << endl;
        }
        if (wheat.getMaxAge() != 5) {
            cout << "testGetters (maxAge) failed: Expected 5, got " << wheat.getMaxAge() << endl;
        }
        if (wheat.getMaxSize() != 1) {
            cout << "testGetters (maxSize) failed: Expected 1, got " << wheat.getMaxSize() << endl;
        }
        if (wheat.getGrowthRate() != 0) {
            cout << "testGetters (growthRate) failed: Expected 0, got " << wheat.getGrowthRate() << endl;
        }
        if (wheat.getSalePrice() != 3) {
            cout << "testGetters (salePrice) failed: Expected 3, got " << wheat.getSalePrice() << endl;
        }
        if (wheat.getType() != "Wheat") {
            cout << "testGetters (type) failed: Expected Wheat, got " << wheat.getType() << endl;
        }
    }
};


