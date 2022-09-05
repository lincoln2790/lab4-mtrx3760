#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <unordered_map>
#include <iostream>
#include <vector>
#include "Teller.h"
class Checkout{
    private:
        std::unordered_map<std::string, std::vector<Teller> > Tellers;

    public:
        // Checkout(int numStd, int numExp);
        void CheckoutInit(int numStd, int numExp);
        int FindShortestQueue(std::string tellerType);
        void AddNewCustomers();
        // void CheckInit();
};


#endif