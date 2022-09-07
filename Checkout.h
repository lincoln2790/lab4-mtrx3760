// Checkout.h
// Header for checkout class
// Checkout contains a hashmap with values of vectors of tellers,
// one for each type of teller, Express and Standard.
// Contains functionality to add/allocate customers to the shortest queue, process its tellers
#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <unordered_map>
#include <iostream>
#include <vector>
#include "Teller.h"

class Checkout{
    private:
        // Maximum number of customers added per cycle, ie. random number (0-6)
        static const int maxCustomersPerCycle = 6;
        // HashMap of 2 vectors, where the key is a string, either "Standard" or "Express"
        // and value is a vector of Tellers.
        std::unordered_map<std::string, std::vector<Teller> > Tellers;

    public:
        // initialises checkout with number of tellers
        void CheckoutInit(int numStd, int numExp);
        // returns index of the shortest queue for specified teller type
        int FindShortestQueue(std::string tellerType);
        // adds random number of new customers and allocates them to a queue
        void AddNewCustomers();
        // removes items from front customer in each queue, if no items, removes customer
        int ProcessTellers();
        // Prints mean time cycles for each teller queue, returns overall mean customer wait time
        float Report();
};

#endif