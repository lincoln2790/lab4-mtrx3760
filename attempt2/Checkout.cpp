
#include "Checkout.h"
#include "Customer.h"
int Checkout::FindShortestQueue(std::string tellerType){
    int ShortestQueueIndex = 0;
    
    // std::cout <<  Tellers[tellerType].size() << std::endl;
    int ShortestQueueLength = Tellers[tellerType].front().getQueueLength();
    // int ShortestQueueLength = Tellers[tellerType][0].getQueueLength();
    for(int i = 0;i< Tellers[tellerType].size(); i++){
        if(Tellers[tellerType][i].getQueueLength() < ShortestQueueLength){
            ShortestQueueLength = Tellers[tellerType][i].getQueueLength();
            ShortestQueueIndex = i;
        }
    }
    return ShortestQueueIndex;

}


void Checkout::AddNewCustomers(){
    int NumNewCustomers = (rand() % (20+1)); 
    std::cout << "Allocating " << NumNewCustomers << " new customers" << std::endl;

    for(int i = 0; i < NumNewCustomers ; i++){
        Customer customer;
        std::string tellerType = (customer.getNumItems() < 10) ? "Express" : "Standard";
        // std::string tellerType = "Express";
        // std::cout << tellerType << std::endl;
        int shortestQueue = FindShortestQueue(tellerType);
        
 
        // std::cout << "  New Customer with " << customer.getNumItems()<< " Items\n"<< std::endl;
        Tellers[tellerType][shortestQueue].AddToQueue(customer);
        // Tellers[tellerType][shortestQueue].AddToQueue(customer);
        // custAllocator->Allocate(tellerType);
    }

}   

void Checkout::CheckoutInit(int numStd, int numExp) {
    for(int i = 0;i< numStd;i++){
        Teller teller;
        this->Tellers["Standard"].push_back(teller);
        std::cout<< "Standard Teller "<< i+1 <<" initialised"<< std::endl;
    }
    for(int i = 0;i<numExp;i++){
        Teller teller;
        this->Tellers["Express"].push_back(teller);
        std::cout<< "Express Teller "<< i+1 <<" initialised"<< std::endl;
    }

    // std::cout << "Checkout Initialised with "<< this->Tellers["Standard"].size()<< " Standard and " << this->Tellers["Express"].size() << " Express Tellers" << std::endl;
    
}

// void Checkout::CheckInit(){
//     std::cout << Tellers["Standard"].size() << std::endl;
//     std::cout << Tellers["Express"].size() << std::endl;
// }