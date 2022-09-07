#include "Customer.h"
#include <cstdlib>

Customer::Customer(): CyclesInQueue(0){
    NumItems = rand() % MaxItems;
    // initialises with random number of items from 0-15
}

int Customer::getNumItems(){
    return NumItems; //returns number of items
}

int Customer::getCycles(){
    return CyclesInQueue; //returns number of cycles
}

void Customer::incrementCyclesInQueue(){
    CyclesInQueue++; //increments cycles in queue
}

void Customer::removeItem(){
    NumItems -= 2; 
    // removes 2 items per cycle for front customer
}
