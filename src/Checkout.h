#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <vector>
#include "Teller.h"
#include "CustomerAllocator.h"

class Checkout{
    private:
        std::vector<Teller> StandardTellers;
        std::vector<Teller> ExpressTellers;
        CustomerAllocator customerAllocator;
    public:
        void SetNumTellers(int numStd, int numExp);
};


#endif