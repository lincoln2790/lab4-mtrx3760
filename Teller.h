// Teller.h
// Header for teller class
// Teller class has a queue of customers which it processes each cycle by removing items from 
// its front customer until they have no items, then removes them from queue.
//  Teller counts the number of customers processed and aggregates the number of cycles each 
// processed customer waited in order to find a mean wait time.
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