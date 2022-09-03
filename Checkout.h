#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <vector>
#include "Teller.h"

class Checkout{
    private:

        std::vector<Teller> StandardTellers;
        std::vector<Teller> ExpressTellers;

    public:
        Checkout(int numStandard, int numExpress);
        int findShortestQueue(); // Used for shortest queue strategy
        // increments queueLength for specified teller
        void allocateCustomer(int tellerIndex); 
        void processTellers(); // removes customers from each teller queue
        void report();         // reports average lengths for each teller,
        float getOverallMean(); // calculates overall mean
};


#endif