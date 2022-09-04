#ifndef CUSTOMER_ALLOCATOR_H
#define CUSTOMER_ALLOCATOR_H

#include "Teller.h"
#include <cstdlib>  

class CustomerAllocator{
    private:
        std::vector<Teller> *stdTellers;
        std::vector<Teller> *expTellers;
    public:
        void FindTellerVectors(){
            
        };
        void AllocateCustomer(){
            Customer customer;
            if(customer.getNumItems()<10){

            }



        };

};
#endif