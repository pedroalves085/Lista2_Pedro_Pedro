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
    if (head == nullptr) return;

    OrderNode* temp = this->head;
    this->head = this->head->next;

    if (this->head != nullptr) {
        this->head->prev = nullptr;
    } else {
        this->tail = nullptr;
    }

    delete temp;
    size--;
}

void OrdersList::removeEnd(){
    if (tail == nullptr) return;

    OrderNode* temp = this->tail;
    this->tail = this->tail->prev;

    if (this->tail != nullptr){
        this->tail->next = nullptr;
    } else {
        this->head = nullptr;
    }

    delete temp;
    size--;
}

//Decidir oq ue queremos comparar dos objetos order para o while, colocando preço por enquanto
void OrdersList::remove(Order value){
    OrderNode* current = this->head;
    while (current != nullptr && current->value.getPrice() != value.getPrice()){
        current = current->next;
    }
    
    if (current == nullptr) return;

    if (current == head) {
        removeFront();
        return;
    }

    if (current == tail) {
        removeEnd();
        return;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;

    delete current;
    size--;

}