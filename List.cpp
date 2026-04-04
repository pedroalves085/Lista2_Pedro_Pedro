#include "List.hpp"

using namespace std;


ListTransaction :: ListTransaction(){
    this -> transactions = new Transaction*[4];
    this -> capacity = 4;
    this -> size = 0;
}

ListTransaction :: ~ListTransaction(){
    for(int i = 0; i < size; i++){
        delete this -> transactions[i];
    }

    delete [] this -> transactions;    
}

void ListTransaction :: InsertTransaction(int buy_order_id, int sell_order_id, float execution_price){
    
    if(this -> size == this -> capacity){

        Transaction ** new_transactions = new Transaction*[this -> capacity * 2];
        this -> capacity *= 2;

        for(int i = 0; i < size; i++){
            new_transactions[i] = this -> transactions[i];
        }

        delete[] this -> transactions;

        this -> transactions = new_transactions;

    }

    this -> transactions[this -> size] = new Transaction(buy_order_id, sell_order_id, execution_price);
    this -> size ++;
}

