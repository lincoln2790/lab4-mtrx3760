// Simulator.h
// Header file for simulator class
// Simulator contains a checkout which it runs a simulation on over 500 cycles.
#ifndef SIMULATOR_H
#define SIMULATOR_H
#include "Checkout.h"

class Simulator{
    private:
        const static int numCycles = 500; 
        // constant number of cycles the simulation adds customers for.
        
    public:
        Checkout checkout;
        Simulator(int numStd, int numExp); 
        // constructor which initialises checkout with specified number of
        // express and standard tellers
        float runSimulation();
        // for <numCycles> iterations, adds customers, and tellers processes items
        // after this, tellers process until no customers are left
     
};

#endif