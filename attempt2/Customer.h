#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    private:
        int NumItems; // integer representing number of items
        const static int MaxItems =  15; 
        //maximum number of items ie. random number from (0,15)
        int CyclesInQueue;
        // integer representing the number of simulation
        //  cycles the customer her been in queue

    public:
        Customer(); 
        int getNumItems(); //returns number of items
        int getCycles();  //returns number of cycles
        void removeItem(); //decrements NumItems
        void incrementCyclesInQueue();  //increments CyclesInQueue
};


#endif