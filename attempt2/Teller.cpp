#include "Teller.h"
#include "Customer.h"


int Teller::getQueueLength(){
    return Queue.size();
}
void Teller::AddToQueue(Customer customer){
    Queue.push_back(customer);
}

Teller::Teller(): CustomersProcessed(0), AggregateNumCycles(0){};


void Teller::ProcessQueue(){
    for(int i = 0;i< Queue.size(); i++){
        if(Queue.front().getNumItems() == 0){
            AggregateNumCycles += Queue.front().getCycles();
            CustomersProcessed++;
            Queue.pop_front();
        } else {
            Queue.front().removeItem();
        }
    }
}   

void Teller::incrementCustCycles(){
    for(int i = 0; i<Queue.size();i++){
        Queue[i].incrementCyclesInQueue();
    }
}


float Teller::getAvgCyclesPerProcessedCustomer(){
    float avg = AggregateNumCycles/(CustomersProcessed*1.0);
    // std::cout << AggregateNumCycles << "  " << CustomersProcessed << std::endl;
    return avg;
}