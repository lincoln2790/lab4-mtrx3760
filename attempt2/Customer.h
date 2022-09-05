#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer{
    private:
        int NumItems;
        const static int MaxItems = 20;
        int CyclesInQueue;

    public:
        Customer();
        int getNumItems();
        int getCycles();
        void removeItem();
        void incrementCyclesInQueue();
        void finishProcessing();

};


#endif