#include "Checkout.h"

Checkout::Checkout(int numStandard, int numExpress): NumStandard(numStandard), NumExpress(numExpress){
    for(int i = 0; i<numStandard; i++){
        Teller teller;
        StandardTellers.push_back(teller);
    }
    for(int i = 0; i<numExpress; i++){
        Teller teller;
        ExpressTellers.push_back(teller);
    }

}