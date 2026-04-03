#include "Order.hpp"
#include "Transaction.hpp"

class OrderBook {

private:

    // Lista duplamente encadeada com as ordens
    // Array dinâmico com as transações

public:

    OrderBook();
    ~OrderBook();

    bool submit(Order order);
    bool cancel(int id);

    Order* getBuyOrders(int* n);
    Order* getSellOrders(int* n);
    Transaction* getTransactions(int* n);

    void printBuyOrders();
    void printSellOrders();
    void printTransactions();

    // Outros métodos auxiliares, se necessário
};