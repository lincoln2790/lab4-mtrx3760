#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Checkout.h"

class Simulator{
    public:
        Checkout checkout;
        Simulator(int numStd, int numExp);
        void runSimulation();
};


#endif