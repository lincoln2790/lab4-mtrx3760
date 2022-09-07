#include "Checkout.h"
#include "Customer.h"

// finds the shortest queue index for a specified teller type (standard/express)
int Checkout::FindShortestQueue(std::string tellerType){
    // starts with shortest queue and queue index as 0
    int ShortestQueueIndex = 0;
    int ShortestQueueLength = Tellers[tellerType].front().getQueueLength();

    // iteratively updates current shortest queue and corresponding index
    for(int i = 0;i< Tellers[tellerType].size(); i++){
        if(Tellers[tellerType][i].getQueueLength() < ShortestQueueLength){
            ShortestQueueLength = Tellers[tellerType][i].getQueueLength();
            ShortestQueueIndex = i;
        }
    }
    // returns index of the shortest queue
    return ShortestQueueIndex;
}

// Adds a random amount of new customers, and allocates them to the shortest 
// queue of the correct teller type for their number of items
void Checkout::AddNewCustomers(){
    int NumNewCustomers = (rand() % (maxCustomersPerCycle+1)); 
    std::cout << "  Allocating " << NumNewCustomers << " new customers" << std::endl;

    for(int i = 0; i < NumNewCustomers ; i++){
        Customer customer;
        std::string tellerType;
        // If number of items is <10, send to an Express teller, 
        // otherwise send to a standard teller
        if(!Tellers["Express"].empty()){
            tellerType = (customer.getNumItems() < 10) ? "Express" : "Standard";
        } else {
            tellerType = "Standard";
        }
        
        // Finds the shortest queue of that teller type, 
        // and allocates the customer to that queue
        int shortestQueue = FindShortestQueue(tellerType);
        std::cout << "      New Customer with " << customer.getNumItems()<<
         " Items added to "<<tellerType << " queue " << shortestQueue << std::endl;
        
        Tellers[tellerType][shortestQueue].AddToQueue(customer);
      
    }
    
}   

// Initialises the checkout with specified number of each teller type.
// Note: a constructor was opted against, since the simulator member checkout properties 
// aren't decided at creation, but rather when the simulator constructor is called
void Checkout::CheckoutInit(int numStd, int numExp) {
    for(int i = 0;i< numStd;i++){
        Teller teller;
        Tellers["Standard"].push_back(teller);
        std::cout<< "Standard Teller "<< i+1 <<" initialised"<< std::endl;
    }
    for(int i = 0;i<numExp;i++){
        Teller teller;
        Tellers["Express"].push_back(teller);
        std::cout<< "Express Teller "<< i+1 <<" initialised"<< std::endl;
    }

    std::cout << "Checkout Initialised with "<< Tellers["Standard"].size()<< " Standard and " << Tellers["Express"].size() << " Express Tellers" << std::endl;   
}

// For each teller,increments its queue member's time cycle, processes the front customer's item,
// returns the total number of customers left in any queue
int Checkout::ProcessTellers(){ 
    int TotalCustomersLeft = 0;
    
    for(int i = 0;i<Tellers["Standard"].size(); i++){
        Tellers["Standard"][i].incrementCustCycles();
        Tellers["Standard"][i].ProcessQueue();
        TotalCustomersLeft += Tellers["Standard"][i].getQueueLength();
    }
    for(int i = 0;i<Tellers["Express"].size(); i++){
        Tellers["Express"][i].incrementCustCycles();
        Tellers["Express"][i].ProcessQueue();
        TotalCustomersLeft += Tellers["Express"][i].getQueueLength();
    }

    return TotalCustomersLeft;
}

// Prints the mean cycles of each processed customer for every teller, returns overall mean 
float Checkout::Report(){
    float net = 0;
    int num = Tellers["Standard"].size() + Tellers["Express"].size();
    for(int i = 0; i<Tellers["Standard"].size();i++){
        float meanCycles = Tellers["Standard"][i].getAvgCyclesPerProcessedCustomer();
        std::cout << "Mean for Standard Teller " << i << ": " << meanCycles << std::endl;
        net += meanCycles;

    }
    for(int i = 0; i<Tellers["Express"].size();i++){
        float meanCycles = Tellers["Express"][i].getAvgCyclesPerProcessedCustomer();
        std::cout << "Mean for Express Teller " << i << ": " << meanCycles << std::endl;
        net += meanCycles;
    }

    return net/(num*1.0);
}