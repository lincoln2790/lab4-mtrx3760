#include "Checkout.h"

void Checkout::SetNumTellers(int numStd, int numExp){
    for(int i = 0; i<numStd; i++){
        Teller teller;
        StandardTellers.push_back(teller);
    }
    for(int i = 0; i<numExp; i++){
        Teller teller;
        ExpressTellers.push_back(teller);
    }
};