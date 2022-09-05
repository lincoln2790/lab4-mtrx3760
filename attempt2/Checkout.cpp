
#include "Checkout.h"
#include "Customer.h"

int Checkout::FindShortestQueue(std::string tellerType){
    int ShortestQueueIndex = 0;
    int ShortestQueueLength = Tellers[tellerType].front().getQueueLength();

    for(int i = 0;i< Tellers[tellerType].size(); i++){
        if(Tellers[tellerType][i].getQueueLength() < ShortestQueueLength){
            ShortestQueueLength = Tellers[tellerType][i].getQueueLength();
            ShortestQueueIndex = i;
        }
    }
    return ShortestQueueIndex;
}

void Checkout::AddNewCustomers(){
    int NumNewCustomers = (rand() % (maxCustomersPerCycle+1)); 
    std::cout << "  Allocating " << NumNewCustomers << " new customers" << std::endl;

    for(int i = 0; i < NumNewCustomers ; i++){
        Customer customer;
        std::string tellerType = (customer.getNumItems() < 10) ? "Express" : "Standard";
        int shortestQueue = FindShortestQueue(tellerType);
 
        std::cout << "      New Customer with " << customer.getNumItems()<< " Items added to "<<tellerType << " queue " << shortestQueue << std::endl;
        
        Tellers[tellerType][shortestQueue].AddToQueue(customer);
    }
    for(int i = 0; i<Tellers["Standard"].size();i++){
        Tellers["Standard"][i].incrementCustCycles();
    }
    for(int i = 0; i<Tellers["Express"].size();i++){
        Tellers["Express"][i].incrementCustCycles();
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

    std::cout << "Checkout Initialised with "<< this->Tellers["Standard"].size()<< " Standard and " << this->Tellers["Express"].size() << " Express Tellers" << std::endl;   
}

void Checkout::ProcessTellers(){ 
    for(int i = 0;i<Tellers["Standard"].size(); i++){
        Tellers["Standard"][i].ProcessQueue();
    }
    for(int i = 0;i<Tellers["Express"].size(); i++){
        Tellers["Express"][i].ProcessQueue();
    }
}


float Checkout::Report(){
    
    float net = 0;
    int num = Tellers["Standard"].size() + Tellers["Express"].size();
    for(int i = 0; i<Tellers["Standard"].size();i++){
        float meanCycles = Tellers["Standard"][i].getAvgCyclesPerProcessedCustomer();
        std::cout << "Mean cycles per processed customer for Standard Teller " << i << ": " << meanCycles << std::endl;
        net += meanCycles;

    }
    for(int i = 0; i<Tellers["Express"].size();i++){
        float meanCycles = Tellers["Express"][i].getAvgCyclesPerProcessedCustomer();
        std::cout << "Mean cycles per processed customer for Express Teller " << i << ": " << meanCycles << std::endl;
        net += meanCycles;
    }
    return net/(num*1.0);
}