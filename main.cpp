#include "agent.h"
#include "market.h"
#include "system.h"
#include "RandomNumberGenerator/random.h"
#include <iostream>


int main(int, char**) {
    Random::seed(101010101010);

    System* system = new System(10);
    system->evolve(100);

    return 0;
}
