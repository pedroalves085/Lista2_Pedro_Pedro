#include "Order.hpp"

using namespace std;

Order::Order(int id, char type, float price, int timestamp){
    this->id = id;
    this-> type = type;
    this->price = price;
    this->timestamp = timestamp;
}

Order::~Order(){
    // Não tem necessidade de implementação
};

int Order :: getId(){
    return this -> id;
}

char Order :: getType(){
    return this -> type;
}

float Order :: getPrice(){
    return this -> price;
}

int Order :: getTimestamp(){
    return this -> timestamp;
}