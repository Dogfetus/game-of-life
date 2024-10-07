#include "random.h"

#include <random>

// returns a random number from 0 to input number
size_t random(size_t num) {
    std::random_device rd;                         // Obtain a random seed
    std::mt19937 gen(rd());                        // Seed the generator
    std::uniform_int_distribution<> distr(0, num); // Define the range (0 or 1)
    return distr(gen);                             // Get a random boolean
}
