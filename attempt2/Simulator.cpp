#include "Simulator.h"
#include "Checkout.h"
#include <iostream>

Simulator::Simulator(int numStd, int numExp){    
    checkout.CheckoutInit(numStd,numExp);
    // checkout.CheckInit();
    
    std::cout << "Simulator initialisation complete"<< std::endl;
}
void Simulator::runSimulation(){
    for(int i = 0; i<15;i++){
        std::cout << "\nRunning simulation cycle " << i << std::endl;
        checkout.AddNewCustomers();
       
    }
}