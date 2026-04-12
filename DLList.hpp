#ifndef DLLIST_HPP
#define DLLLIST_HPP

#include "Order.hpp"
using namespace std;

class OrderNode {

public:
    Order value;
    OrderNode* next;
    OrderNode* prev;

    OrderNode(Order value);
    ~OrderNode();

};


class OrdersList {
private:
    OrderNode* head;
    OrderNode* tail;
    int size;

public:
    OrdersList();
    ~OrdersList();
    void insert(Order value);
    void removeFront();
    void removeEnd();
    void remove(Order value);
    OrderNode* getHead();
    OrderNode* getTail();
    int getSize();
};

#endif