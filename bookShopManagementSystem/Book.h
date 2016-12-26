#ifndef BOOK_H
#define BOOK_H

#include <iostream>

#define SHOPCART_SIZE 2

struct Book {
    std::string title;
    std::string author;
    std::string ISBN;
    int quantity;
    int price;
    Book* next;
};

class ListBook {
    private:
        Book* head;
    public:
        ListBook();
        ~ListBook();
        void addBook(std::string title, std::string author, std::string ISBN, int quantity, int price);
        void printBook();
        Book* searchBook_author(std::string author);
        Book* searchBook_title(std::string title);
        Book* searchBook_ISBN(std::string ISBN);

        std::string getTitle(std::string ISBN);
        std::string getAuthor(std::string ISBN);
        //std::string getISBN(std::string ISBN);
        int getQuantity(std::string ISBN);
        int getPrice(std::string ISBN);

        void setTitle(std::string title, std::string ISBN);
        void setAuthor(std::string author, std::string ISBN);
        //void setISBN(std::string ISBN, std::string ISBN);
        void setQuantity(int quantity, std::string ISBN);
        void setPrice(int price, std::string ISBN);
};

class ShoppingCartQueue {
    private:
        Book shoppingCart[SHOPCART_SIZE];
        int front, rear;
    public:
        ShoppingCartQueue();
        ~ShoppingCartQueue();
        bool isEmpty();
        bool isFull();
        void enqueue(Book book);
        void dequeue();
        void printShoppingCart();
        Book getFront();
};

#endif
