#include "Checkout.h"

Checkout::Checkout(int numStandard, int numExpress){
    for(int i = 0; i<numStandard; i++){
        Teller teller;
        StandardTellers.push_back(teller);
    }

}