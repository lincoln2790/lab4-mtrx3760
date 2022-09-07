// Simulator.cpp
// Implementation for Simulator class functions
#include "Simulator.h"
#include "Checkout.h"
#include <iostream>

// Initialises checkout with specified numbers of standard, express tellers
Simulator::Simulator(int numStd, int numExp){    
    checkout.CheckoutInit(numStd,numExp);
    std::cout << "Simulator initialisation complete"<< std::endl;
}

float Simulator::runSimulation(){
    // for <numCycles> iterations, adds customers, and tellers processes items
    for(int i = 0; i<numCycles;i++){
        std::cout << "\nRUNNING CYCLE: " << i << std::endl;
        checkout.AddNewCustomers();
        checkout.ProcessTellers();
    }
    // after this, tellers process until no customers are left
    while(checkout.ProcessTellers()){};

    return checkout.Report(); // returns the mean wait time calculated by Report()
}

