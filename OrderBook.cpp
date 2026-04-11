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

        current = current->next;
    }

    if(selected.getType() == 't'){
        this->orders.insert(order);
        return false;
    }else{
        if(order.getType() == 'B'){

            this->transacions.InsertTransaction(order.getId(), selected.getId(), selected.getPrice());
        }else{
            this->transacions.InsertTransaction(selected.getId(), order.getId(), selected.getPrice());
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
    }
}