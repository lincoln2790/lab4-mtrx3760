#ifndef TELLER_H
#define TELLER_H
#include <iostream>
#include <deque>
#include "Customer.h"

class Teller{
    private:
        std::deque<Customer> Queue ; // double ended queue of customers
        //  note: deque was opted over queue since it allows access to elements within the queue, 
        //   which allowed number of cycles to be incremented 
        int CustomersProcessed; 
        // number of customers finished processing (for finding mean)
        int AggregateNumCycles; 
        // sum of the number of cycles for each processed customer (for finding mean)
    public:
        Teller();
        int getQueueLength(); //returns queue length
        void AddToQueue(Customer customer); // adds customer to queue
        void ProcessQueue(); // removes items from the front customer
        void incrementCustCycles(); // increments cycles for each customer
        float getAvgCyclesPerProcessedCustomer(); 
        // after all customers are processed, computes and returns the mean cycles for the queue

};


#endif