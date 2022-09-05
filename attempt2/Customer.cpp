#include "Customer.h"
#include <cstdlib>

Customer::Customer(): CyclesInQueue(0){
    NumItems = rand() % 20;

}

int Customer::getNumItems(){
    return NumItems;
}
