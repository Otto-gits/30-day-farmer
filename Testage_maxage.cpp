#include "Crop.h"
#include <iostream>

int main() {
    Crop crop(0, 3); // Create a new plant with age 0 and max age 3

    char input;
    std::cout << "Press Enter to age the plant ('q' to quit): ";
    while ((input = std::cin.get()) != 'q') {
        if (input == '\n') {
            // Age the plant by one year
            crop.ageOneDay();

            // Print the updated age
            std::cout << "Plant age: " << crop.getAge() << std::endl;

            // Check if the plant has reached maximum age
            if (crop.getAge() == crop.getMaxAge()) {
                std::cout << "The plant has reached its maximum age and stops growing." << std::endl;
                break;
            }

            // Prompt for next action
            std::cout << "Press Enter to age the plant ('q' to quit): ";
        }
    }

    return 0;
}


