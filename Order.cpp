#include <iostream>
using namespace std;
#include "Order.hpp"

Order::Order(int id, char type, float price, int timestamp){
    this->id = id;
    this-> type = type;
    this->price = price;
    this->timestamp = timestamp;
}

Order::~Order(){};