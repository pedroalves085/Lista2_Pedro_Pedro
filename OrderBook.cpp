#include "OrderBook.hpp"
#include "Order.hpp"

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