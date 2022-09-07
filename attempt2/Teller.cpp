#include "Teller.h"
#include "Customer.h"

int Teller::getQueueLength(){
    return Queue.size(); //returns integer length of queue
}

void Teller::AddToQueue(Customer customer){
    Queue.push_back(customer); // adds customer to teller's queue
}

Teller::Teller(): CustomersProcessed(0), AggregateNumCycles(0){};

// If queue isn't empty, processes front customer's items, if customer has no items left
// remove them from queue
void Teller::ProcessQueue(){
    if(Queue.size() != 0){
        Queue.front().removeItem();
        if(Queue.front().getNumItems() <= 0){
            Queue.pop_front();
            AggregateNumCycles += Queue.front().getCycles();
            CustomersProcessed++;   
        }
    }
}   

// For each customer in the queue, increment the number of cycles
void Teller::incrementCustCycles(){
    for(int i = 0; i<Queue.size();i++){
        Queue[i].incrementCyclesInQueue();
    }
}

// Return the average number of cycles each customer has waited in queue
float Teller::getAvgCyclesPerProcessedCustomer(){
    float avg = AggregateNumCycles/(CustomersProcessed*1.0);
    return avg;
}