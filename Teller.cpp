// Teller.cpp
// implementation for Teller class functions
#include "Teller.h"
#include "Customer.h"

int Teller::getQueueLength(){
    return queue.size(); //returns integer length of queue
}

void Teller::addToQueue(Customer customer){
    queue.push_back(customer); // adds customer to teller's queue
}

Teller::Teller(): customersProcessed(0), aggregateNumCycles(0){};

// If queue isn't empty, processes front customer's items, if customer has no items left
// remove them from queue
void Teller::processQueue(){
    if(queue.size() != 0){
        queue.front().removeItem();
        if(queue.front().getNumItems() <= 0){
            queue.pop_front();
            aggregateNumCycles += queue.front().getCycles();
            customersProcessed++;   
        }
    }
}   

// For each customer in the queue, increment the number of cycles
void Teller::incrementCustCycles(){
    for(int i = 0; i<queue.size();i++){
        queue[i].incrementCyclesInQueue();
    }
}

// Return the average number of cycles each customer has waited in queue
float Teller::getAvgCyclesPerProcessedCustomer(){
    float avg = aggregateNumCycles/(customersProcessed*1.0);
    return avg;
}