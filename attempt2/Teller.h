#ifndef TELLER_H
#define TELLER_H
#include <iostream>
#include <deque>
#include "Customer.h"

class Teller{
    private:
        std::deque<Customer> Queue ;   
        int CustomersProcessed;
        int AggregateNumCycles;
    public:
        Teller();
        int getQueueLength();
        void AddToQueue(Customer customer);
        void ProcessQueue();
        void incrementCustCycles();
        float getAvgCyclesPerProcessedCustomer();

};


#endif