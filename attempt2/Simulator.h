#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Checkout.h"

class Simulator{
    private:
        const static int numCycles = 2500;
    public:
        Checkout checkout;
        Simulator(int numStd, int numExp);
        void runSimulation();
     
};


#endif