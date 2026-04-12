# Lista2_Pedro_Pedro

## Descrição do projeto
Este projeto traz uma solução em C++ para um sistema ordens de compra e venda de uma ação, que possuem um preço, um identificador único, o seu tipo, e um timestamp que representa a hora de chegada. No sistema, foram feitas as listas das ordens, para armazenar aquelas ainda pendentes e a lista de transações que armazena as ordens executadas. 

Para que o sistema funcione é considerado que o argumento de inserção de uma ordem siga as seguintes propriedades: 
* Seu valor deve ser positivo
* Ser somente do tipo venda ou compra
* Ter um id único que ainda não esteja no sistema
* Respeitar a ordem de chegada em relação às outras ordens.

O sistema é inicializado com listas vazias de ordens e transações e conforme novas ordens são adicionadas e transações feitas, é possível extrair informações dessas listas como quais e quantos elementos de cada tipo estão armazenados, além da exibição do estado atual do sistema, imprimindo no terminal a lista de ordens de venda, de compra ou de transações. 
## Instruções de compilação
O código deve ser compilado por meio do seguinte comando em seu terminal. 

```
g++ main.cpp DLList.cpp List.cpp OrderBook.cpp Order.cpp Transaction.cpp -o order_book
```
## Instruções de execução
Assim que o arquivo for compilado, será criado um arquivo de formato .exe, o qual você poderá executar com o seguinte comando.  

```
.\order_book.exe
```
## Como os dados estão organizados internamente no sistema
Para gravar as ordens de compra e venda, foi utilizada uma lista duplamente encadeada, em que cada "nó" possui um objeto do tipo ordem como valor, um ponteiro para a próxima ordem e um ponteiro para a ordem anteior; cada nova ordem é inserida no fim dessa lista, mantendo sempre a a organização por ordem de chegada.

Além disso, para gravar as transações, foi utilizado um array dinâmico de ponteiros, em que cada ponteiro aponta para um objeto do tipo transação, já que esse tipo de estrutura permite adicionar itens dinâmicamente, aumentando a capacidade quando necessário, conforme vão surgindo novas transações.