#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
class Teller;
class Checkout;

class Customer{
    private:
        int NumItems;
        int CyclesInQueue;
    public:
        Customer();
        int getNumItems();
        // void incrementCyclesInQueue();

};

class CustomerAllocator{
    private:
        std::unordered_map<std::string, std::vector<Teller> > *Tellers;
        Checkout *checkout;
    public:
        void Allocate(std::string tellerType);
        CustomerAllocator(Checkout *pCheckout): checkout(pCheckout){};
};



class Teller{
    private:
        std::queue<Customer> Queue;   
        int CustomersProcessed;
        int AggregateNumCycles;
    public:
        int getQueueLength();
        void AddToQueue(Customer customer);

};
class Checkout{
    private:
        std::unordered_map<std::string, std::vector<Teller> > Tellers;
        CustomerAllocator *custAllocator;
    public:
        Checkout(int numStd, int numExp);
        void AddToQueue(std::string tellerType, int tellerNum);
        int FindShortestQueue(std::string tellerType);
        void AddNewCustomers();
};

class Simulator{
    public:
        Checkout* checkout;
        Simulator(int numStd, int numExp);
        void runSimulation();
};

int Teller::getQueueLength(){
    return Queue.size();
}
void Teller::AddToQueue(Customer customer){
    Queue.push(customer);
}

int Checkout::FindShortestQueue(std::string tellerType){
    int ShortestQueueIndex = 0;
    std::cout <<  Tellers["Express"].size() << std::endl;
    // int ShortestQueueLength = Tellers[tellerType].front().getQueueLength();
    // int ShortestQueueLength = Tellers[tellerType][0].getQueueLength();
    // for(int i = 0;i< Tellers[tellerType].size(); i++){
    //     if(Tellers[tellerType][i].getQueueLength() < ShortestQueueLength){
    //         ShortestQueueLength = Tellers[tellerType][i].getQueueLength();
    //         ShortestQueueIndex = i;
    //     }
    // }
    // return ShortestQueueIndex;
    return 0;

}
void Checkout::AddToQueue(std::string tellerType, int tellerNum){
    Customer cust;
    std::cout << "New Customer with " << cust.getNumItems()<< "Items\n"<< std::endl;
    Tellers[tellerType][tellerNum].AddToQueue(cust);
}

void Checkout::AddNewCustomers(){
    int NumNewCustomers = (rand() % (9+1)); 
    std::cout << "Allocating " << NumNewCustomers << " new customers" << std::endl;

    for(int i = 0; i < NumNewCustomers ; i++){
        Customer customer;
        // std::string tellerType = (customer.getNumItems() < 5) ? "Express" : "Standard";
        std::string tellerType = "Express";
        std::cout << tellerType << std::endl;
        custAllocator->Allocate(tellerType);
    }

}

Checkout::Checkout(int numStd, int numExp) {
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
    CustomerAllocator custAlloc = CustomerAllocator(this);
    custAllocator = &custAlloc;

    std::cout << "Checkout Initialised with "<< Tellers["Standard"].size()<< " Standard and " << Tellers["Express"].size() << " Express Tellers" << std::endl;
}
Simulator::Simulator(int numStd, int numExp){
    Checkout myCheckout(numStd,numExp);
    
    // checkout = ;
    std::cout << "Simulator initialisation complete"<< std::endl;
}
void Simulator::runSimulation(){
    for(int i = 0; i<250;i++){
        std::cout << "\nRunning simulation cycle " << i << std::endl;
        checkout->AddNewCustomers();

       
    }
}


void CustomerAllocator::Allocate(std::string tellerType){
    
    int shortestQueue = checkout->FindShortestQueue(tellerType);
    // checkout->AddToQueue(tellerType, shortestQueue);

        // checkout.
        // if(customer.getNumItems()<10){
            // checkout->AddToQueue("Express", checkout->FindShortestQueue("Express")-1);
        // } else {
        //     checkout->AddToQueue("Standard", checkout->FindShortestQueue("Standard"));
        // }
}
    

Customer::Customer(): CyclesInQueue(0){
    NumItems = rand() % 10;

}

int Customer::getNumItems(){
    return NumItems;
}

int main(){
    Simulator sim1(10,5); 
    sim1.runSimulation();
    return 0;
}