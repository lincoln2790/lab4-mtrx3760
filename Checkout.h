#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <vector>
#include "Teller.h"

class Checkout{
    private:
        std::vector<Teller> StandardTellers;
        std::vector<Teller> ExpressTellers;
        int NumStandard,NumExpress;

    public:
        Checkout(int numStandard, int numExpress);
};


#endif