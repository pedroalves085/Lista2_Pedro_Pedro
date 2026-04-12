#include "OrderBook.hpp"
#include "Order.hpp"
#include <iostream>
using namespace std;

OrderBook :: OrderBook(){
    this -> orders = OrdersList();
    this -> transacions = ListTransaction();
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
    }

    if(selected.getType() == 't'){
        this->orders.insert(order);
        return false;
    }else{
        this->orders.remove(selected);
        this->transacions.InsertTransaction();
        return true;
    }
}

void OrderBook::printBuyOrders(){
    if (this->orders.getSize() == 0){
        cout << "(empty)";
    }

    for(int i=0; i < this->orders.getSize(); i++){
        OrderNode* current = orders.getHead();
        if(current->value.getType() == 'B'){
            cout << "[" << current->value.getId() << "|" << current->value.getPrice() << "|" << current->value.getTimestamp() << "]" << endl;
        }
    }


};