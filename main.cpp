#include "Simulator.h"

int main(){ 
    // Running 8 simulations with every possible combination of 
    // standard/express for 8 tellers
    Simulator sim1(8,0); 
    float mean1 = sim1.runSimulation();
    Simulator sim2(7,1); 
    float mean2 = sim2.runSimulation();
    Simulator sim3(6,2); 
    float mean3 = sim3.runSimulation();
    Simulator sim4(5,3); 
    float mean4 = sim4.runSimulation();
    Simulator sim5(4,4); 
    float mean5 = sim5.runSimulation();
    Simulator sim6(3,5); 
    float mean6 = sim6.runSimulation();
    Simulator sim7(2,6); 
    float mean7 = sim7.runSimulation();
    Simulator sim8(1,7); 
    float mean8 = sim8.runSimulation();

    // Printing out the resulting mean from each simulation
    std::cout << "------------------------------------------------------" << std::endl;
    std::cout << "Simulation with 8 Standard, 0 Express: Mean wait time = " << mean1 << std::endl;
    std::cout << "Simulation with 7 Standard, 1 Express: Mean wait time = " << mean2 << std::endl;
    std::cout << "Simulation with 6 Standard, 2 Express: Mean wait time = " << mean3 << std::endl;
    std::cout << "Simulation with 5 Standard, 3 Express: Mean wait time = " << mean4 << std::endl;
    std::cout << "Simulation with 4 Standard, 4 Express: Mean wait time = " << mean5 << std::endl;
    std::cout << "Simulation with 3 Standard, 5 Express: Mean wait time = " << mean6 << std::endl;
    std::cout << "Simulation with 2 Standard, 6 Express: Mean wait time = " << mean7 << std::endl;
    std::cout << "Simulation with 1 Standard, 7 Express: Mean wait time = " << mean8 << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
    return 0;
}