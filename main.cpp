#include "OrderBook.hpp"
#include "Order.hpp"
#include <iostream>

int main(){
    OrderBook book;

    Order compra1 = Order(100, 'B', 10.0, 1);
    Order venda1 = Order(101, 'S', 11.0, 2);
    Order venda2 = Order(102, 'S', 9.0, 3);
    Order compra2 = Order(104, 'B', 5.0, 4);
    Order compra3 = Order(105, 'B', 15.0, 5);
    Order compra4 = Order(110, 'B', 100.0, 6);
    Order venda3 = Order(111, 'S', 150.0, 7);
    Order compra5 = Order(120, 'B', 140.0, 8);
    Order venda4 = Order(139, 'S', 1302.0, 9);
    Order compra6 = Order(106, 'B', 1123.0, 10);
    Order compra7 = Order(140, 'B', 132.0, 11);
    Order venda5 = Order(137, 'S', 1349.0, 12);
    Order compra8 = Order(124, 'B', 13742.0, 13);
    Order venda6 = Order(192, 'S', 10.0, 14);
    Order compra9 = Order(130, 'B', 16780.0, 15);

    book.submit(venda1);
    book.submit(venda2);
    book.submit(venda3);
    book.submit(venda4);
    book.submit(venda5);
    book.submit(venda6);
    book.submit(compra1);
    book.submit(compra2);
    book.submit(compra3);
    book.submit(compra4);
    book.submit(compra5);
    book.submit(compra6);
    book.submit(compra7);
    book.submit(compra8);
    book.submit(compra9);
    
    book.printBuyOrders();
    book.printSellOrders();
    book.printTransactions();

    book.cancel(120);

    book.printBuyOrders();

    int size_buy;
    Order* buy = book.getBuyOrders(&size_buy);

    int size_sell;
    Order* sell = book.getSellOrders(&size_sell);

    int size_tran;
    Transaction* tran = book.getTransactions(&size_tran);

    cout << size_buy << endl << size_sell << endl << size_tran <<endl;
    

}