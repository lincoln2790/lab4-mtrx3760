#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "Checkout.h"
#include "CustomerAllocator.h"

class Simulator{
    public:
        Simulator(int numStandard, int numExpress);
        void runSimulation();
        void report(); // prints overall mean length for simulation
    private: 
        Checkout checkout;
        CustomerAllocator customerAllocator;
};
#endif