#ifndef LIST_HPP
#define LIST_HPP

#include "Transaction.hpp"
using namespace std;


class ListTransaction{

private:

    Transaction** transactions;
    int size;
    int capacity;


public:

    ListTransaction();

    ~ListTransaction();

    void InsertTransaction(int buy_order_id, int sell_order_id, float execution_price);

};

#endif