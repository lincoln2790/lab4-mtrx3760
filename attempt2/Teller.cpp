#include "Teller.h"
#include "Customer.h"


int Teller::getQueueLength(){
    return Queue.size();
}
void Teller::AddToQueue(Customer customer){
    Queue.push(customer);
}

Teller::Teller(): CustomersProcessed(0), AggregateNumCycles(0){}