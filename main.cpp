#include "OrderBook.hpp"
#include "Order.hpp"

int main(){
    OrderBook book;
    Order teste = Order(1, 'B', 10.0, 1);
    book.submit(teste);
    book.printBuyOrders();
    book.printSellOrders();
}


// inserção de ordens;
// execuções bem-sucedidas;
// ordens não executadas;
// cancelamentos;
// recuperação dos dados por meio dos métodos get...;
// exibição do estado do sistema.