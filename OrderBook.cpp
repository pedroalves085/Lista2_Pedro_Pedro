#include "OrderBook.hpp"
#include "Order.hpp"
#include "Transaction.hpp"
#include <iostream>
using namespace std;

OrderBook :: OrderBook(){
    this -> orders = OrdersList();
    this -> transactions = ListTransaction();
}

OrderBook :: ~OrderBook(){}

bool OrderBook :: submit(Order order){
    OrderNode* current = this -> orders.getHead();
    Order selected = Order(0,'t',0, 0);

    while(current != nullptr){

        if(order.getType() == 'B'){
            if(current->value.getType() == 'S'){
                if(current->value.getPrice() <= order.getPrice()){
                    if(selected.getType() == 't'){
                        selected = current->value;
                    }else if(current->value.getPrice() < selected.getPrice()){
                        selected = current->value;
                    }else if(current->value.getPrice() == selected.getPrice() && current->value.getTimestamp() < selected.getTimestamp()){
                        selected = current->value;
                    }
                }
            }
        }else if(order.getType() == 'S'){
            if(current->value.getType() == 'B'){
                if(current->value.getPrice() >= order.getPrice()){
                    if(selected.getType() == 't'){
                        selected = current->value;
                    }else if(current->value.getPrice() > selected.getPrice()){
                        selected = current->value;
                    }else if(current->value.getPrice() == selected.getPrice() && current->value.getTimestamp() < selected.getTimestamp()){
                        selected = current->value;
                    }
                }
            }
        }

        current = current->next;
    }

    if(selected.getType() == 't'){
        this->orders.insert(order);
        return false;
    }else{
        if(order.getType() == 'B'){

            this->transactions.InsertTransaction(order.getId(), selected.getId(), selected.getPrice());
        }else{
            this->transactions.InsertTransaction(selected.getId(), order.getId(), selected.getPrice());
        }
        
        this->orders.remove(selected);
        return true;
    }
}


bool OrderBook :: cancel(int id){
    OrderNode* current = this -> orders.getHead();
    int count = 0;

    while (current != nullptr || current->value.getId() != id){
        current = current->next;
        count ++;
    }
    
    if(count == orders.getSize()){
        return false;
    }else{
        orders.remove(current->value);
        return true;
    }
}

int OrderBook :: getBuySize(){
    int bsize = 0;
    OrderNode* current = orders.getHead();
    for(int i=0; i < this->orders.getSize(); i++){
        if(current->value.getType() == 'B'){
            bsize++;
        }
        current = current->next;
    }
    return bsize;
}

    
Transaction* OrderBook :: getTransactions(int* n){
    
    int size = transactions.getSize();

    if(size == 0){
        *n = 0;
        return nullptr;
    }

    *n = size;
    
    Transaction* new_arr = new Transaction[size];

    for(int i = 0; i < size; i++){
        new_arr[i] = *transactions.getTransaction()[i];
    }

    return new_arr;

}

Order* OrderBook :: getBuyOrders(int* n){

    int size = getBuySize();

    if(size == 0){
        *n = 0;
        return nullptr;
    }

    *n = size;

    Order* new_arr = new Order[size];
    OrderNode* current = orders.getHead();

    for(int i = 0; i < size; i++){
        if(current->value.getType() == 'B'){
            new_arr[i] = current->value;
        }
        current = current->next;
    }

    return new_arr;
}

Order* OrderBook :: getSellOrders(int* n){

    int size = this->orders.getSize() - getBuySize();

    if(size == 0){
        *n = 0;
        return nullptr;
    }

    *n = size;

    Order* new_arr = new Order[size];
    OrderNode* current = orders.getHead();

    for(int i = 0; i < size; i++){
        if(current->value.getType() == 'S'){
            new_arr[i] = current->value;
        }
        current = current->next;
    }

    return new_arr;
};

void OrderBook::printBuyOrders(){
    cout << "Buy Orders:" << endl;
    if (getBuySize() == 0){
        cout << "(empty)";
        return;
    }

    for(int i=0; i < this->orders.getSize(); i++){
        OrderNode* current = orders.getHead();
        if(current->value.getType() == 'B'){
            cout << "[" << current->value.getId() << " | " << current->value.getPrice() << " | " << current->value.getTimestamp() << "]" << endl << endl;
        }
        current = current->next;
    }
}

void OrderBook::printSellOrders(){
    cout << "Sell Orders:" << endl;
    if (this->orders.getSize() - getBuySize() == 0){
        cout << "(empty)";
        return;
    }

    for(int i=0; i < this->orders.getSize(); i++){
        OrderNode* current = orders.getHead();
        if(current->value.getType() == 'S'){
            cout << "[" << current->value.getId() << " | " << current->value.getPrice() << " | " << current->value.getTimestamp() << "]" << endl << endl;
        }
        current = current->next;
    }

}

void OrderBook::printTransactions(){
    cout << "Transactions:" << endl;
    if (this->transactions.getSize() == 0){
        cout << "(empty)";
        return;
    }

    for(int i=0; i < this->transactions.getSize(); i++){
        cout << "[" << this->transactions.getTransaction()[i]->getBuyOrderId() << " | " << this->transactions.getTransaction()[i]->getSellOrderId() << " | " << this->transactions.getTransaction()[i]->getExecutionPrice() << "]" << endl << endl;
       
    }

}
