// Customer.cpp
// Implementation for Customer class
#include "Customer.h"
#include <cstdlib>

Customer::Customer(): cyclesInQueue(0){
    numItems = rand() % maxItems;
    // initialises with random number of items from 0-15
}

int Customer::getNumItems(){
    return numItems; //returns number of items
}

int Customer::getCycles(){
    return cyclesInQueue; //returns number of cycles
}

void Customer::incrementCyclesInQueue(){
    cyclesInQueue++; //increments cycles in queue
}

void Customer::removeItem(){
    numItems -= 2; 
    // removes 2 items per cycle for front customer
}
