#include "DLList.hpp"
#include "Order.hpp"
using namespace std;

OrderNode::OrderNode(Order value){
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

OrderNode::~OrderNode(){}

OrdersList::OrdersList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
}

OrdersList::~OrdersList(){

}

void OrdersList::insert(Order value){
    OrderNode* newNode = new OrderNode(value);

    if (this->tail == nullptr) {
        this->head = this->tail = newNode;
    } else {
        newNode->prev = this->tail;
        this->tail->next = newNode;
        this->tail = newNode;
    }

    this->size++;
}

void OrdersList::removeFront(){

}

void OrdersList::removeEnd(){

}

void OrdersList::remove(Order value){
    
}