#ifndef TELLER_H
#define TELLER_H

#include <queue>
#include "Customer.h"

class Teller{
    private:  
        std::queue<Customer> Queue;   
        int CustomersProcessed;
        int AggregateNumCycles;
    public:
        Teller();
};
#endif