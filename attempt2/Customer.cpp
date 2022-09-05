#include "Customer.h"
#include <cstdlib>

Customer::Customer(): CyclesInQueue(0){
    NumItems = rand() % MaxItems;
}

int Customer::getNumItems(){
    return NumItems;
}
int Customer::getCycles(){
    return CyclesInQueue;
}

void Customer::incrementCyclesInQueue(){
    CyclesInQueue++;
}

void Customer::removeItem(){
    NumItems--;
}
