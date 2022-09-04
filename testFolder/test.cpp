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
        Customer(): CyclesInQueue(0){
            NumItems = rand() % 10;
            
        }
        int getNumItems(){return NumItems;};
        // void incrementCyclesInQueue();

};

class CustomerAllocator{
    private:
        std::unordered_map<std::string, std::vector<Teller> > *Tellers;
        // Checkout *checkout;
    public:
        void Allocate(std::string tellerType){
            Customer customer = Customer();
            if(customer.getNumItems()<10){
                
            }
        };
        // CustomerAllocator(Checkout *pCheckout):checkout(pCheckout){
        //     // checkout = &pCheckout;

        // };
};


class Teller{
    private:
        std::queue<Customer> Queue;   
        int CustomersProcessed;
        int AggregateNumCycles;
    public:
        int getQueueLength(){
            return Queue.size();
        }

};
class Checkout{
    private:
        std::unordered_map<std::string, std::vector<Teller> > Tellers;
        CustomerAllocator custAllocator;
    public:
        Checkout(int numStd, int numExp) {
            for(int i = 0;i< numStd;i++){
                Teller teller = Teller();
                Tellers["Standard"].push_back(teller);
                std::cout<< "Standard Teller "<< i+1 <<" initialised"<< std::endl;
            }
            for(int i = 0;i<numExp;i++){
                Teller teller= Teller();;
                Tellers["Express"].push_back(teller);
                std::cout<< "Express Teller "<< i+1 <<" initialised"<< std::endl;
            }
            // custAllocator = CustomerAllocator(this);
            std::cout << "Checkout Initialised with "<< Tellers["Standard"].size()<< " Standard and " << Tellers["Express"].size() << " Express Tellers" << std::endl;
        }
        void AddToQueue(std::string tellerType, int tellerNum){


        }
        int FindShortestQueue(std::string tellerType){
            int ShortestQueueIndex = 0;
            int ShortestQueueLength = Tellers[tellerType][0].getQueueLength();
            for(int i = 0;i< Tellers[tellerType].size(); i++){
                if(Tellers[tellerType][i].getQueueLength() < ShortestQueueLength){
                    ShortestQueueLength = Tellers[tellerType][i].getQueueLength();
                    ShortestQueueIndex = i;
                }

            }
            return ShortestQueueIndex;

        }
};

class Simulator{
    public:
        Checkout* checkout;
        Simulator(int numStd, int numExp){
            Checkout myCheckout(numStd,numExp);
            checkout = &myCheckout;
            std::cout << "Sim Initialised"<< std::endl;
        }

};



int main(){
    Simulator sim1(10,2); 
    return 0;
}