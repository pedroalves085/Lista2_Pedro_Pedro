#include "Transaction.hpp"

using namespace std;

Transaction :: Transaction(int buy_order_id, int sell_order_id, float execution_price){

    this -> buy_order_id = buy_order_id;
    this -> sell_order_id = sell_order_id;
    this -> execution_price = execution_price;

}

Transaction :: ~Transaction(){
    // Não precisa de destrutor por não alocamos memória
}

int Transaction :: getBuyOrderId(){
    return this -> buy_order_id;
}

int Transaction :: getSellOrderId(){
    return this -> sell_order_id;
}

float Transaction :: getExecutionPrice(){
    return this -> execution_price;
}