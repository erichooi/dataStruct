#include "Book.h"
#include <iostream>
#include <iomanip>

#define SHOPCART_SIZE 2 


// {{{----------------------------------------ListBook----------------------------------------

ListBook::ListBook() 
{
    head = nullptr;
}

ListBook::~ListBook() 
{
}

void ListBook::addBook(std::string title, std::string author, std::string ISBN, int quantity, int price) 
{
    Book* newBook = new Book;
    newBook->title = title;
    newBook->author = author;
    newBook->ISBN = ISBN;
    newBook->quantity = quantity;
    newBook->price = price;
    newBook->next = nullptr;

    if (head == nullptr) {
        head = newBook;
    } else {
        Book* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newBook;
    }
}

void ListBook::printBook()
{
    Book* temp = head;
    std::cout << std::setw(112) << std::setfill('-') << " " <<  std::setfill(' ') << std::endl;
    std::cout << '|' << std::setw(50) << "Title" << '|' << std::setw(20) << "Author"
              << '|' << std::setw(15) << "ISBN" << '|' << std::setw(10) << "Quantity"
              << '|' << std::setw(10) << "Price" << '|' << std::endl;
    std::cout << std::setw(112) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
    while (temp != nullptr) {
        std::cout << '|' << std::setw(50) << temp->title << '|' << std::setw(20) << temp->author
                  << '|' << std::setw(15) << temp->ISBN << '|' << std::setw(10) << temp->quantity
                  << '|' << std::setw(10) << temp->price << '|' << std::endl;
        temp = temp->next;
    }
    std::cout << std::setw(112) << std::setfill('-') << " " << std::setfill(' ') << std::endl;
}

Book* ListBook::searchBook_author(std::string author) 
{
    Book* temp = head;
    while (temp != nullptr) {
        if (temp->author == author) {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

Book* ListBook::searchBook_title(std::string title)
{
    Book* temp = head;
    while (temp != nullptr) {
        if (temp->title == title) {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

Book* ListBook::searchBook_ISBN(std::string ISBN)
{
    Book* temp = head;
    while (temp != nullptr) {
        if (temp->ISBN == ISBN) {
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

std::string ListBook::getTitle(std::string ISBN)
{
    Book* temp = this->searchBook_ISBN(ISBN);
    std::string bookTitle;
    if (temp == nullptr) {
        std::cout << "No such title in the system" << std::endl;
        bookTitle = "";
    } else {
        bookTitle = temp->title;
    }
    return bookTitle;
}

std::string ListBook::getAuthor(std::string ISBN)
{
    Book* temp = this->searchBook_ISBN(ISBN);
    std::string bookAuthor;
    if (temp == nullptr) {
        std::cout << "No such author in the system" << std::endl;
        bookAuthor = "";
    } else {
        bookAuthor = temp->author;
    }
    return bookAuthor;
}

int ListBook::getQuantity(std::string ISBN)
{
    Book* temp = this->searchBook_ISBN(ISBN);
    int quantity;
    if (temp == nullptr) {
        std::cout << "Cannot find the item in the system" << std::endl;
        quantity = 0;
    } else {
        quantity = temp->quantity;
    }
    return quantity;
}

int ListBook::getPrice(std::string ISBN) 
{
    Book* temp = this->searchBook_ISBN(ISBN);
    int price;
    if (temp == nullptr) {
        std::cout << "Cannot find the item in the system" << std::endl;
        price = 0;
    } else {
        price = temp->price;
    }
    return price;
}

void ListBook::setTitle(std::string title, std::string ISBN) 
{
    Book* temp = this->searchBook_ISBN(ISBN);
    temp->title = title;
}

void ListBook::setAuthor(std::string author, std::string ISBN)
{
    Book* temp = this->searchBook_ISBN(ISBN);
    temp->author = author;
}

void ListBook::setQuantity(int quantity, std::string ISBN)
{
    Book* temp = this->searchBook_ISBN(ISBN);
    temp->quantity = quantity;
}

void ListBook::setPrice(int price, std::string ISBN)
{
    Book* temp = this->searchBook_ISBN(ISBN);
    temp->price = price;
}

// }}}----------------------------------------EndListBook----------------------------------------


// {{{----------------------------------------ShoppingQueue----------------------------------------
ShoppingCartQueue::ShoppingCartQueue() 
{
    front = -1;
    rear =  -1;
}

ShoppingCartQueue::~ShoppingCartQueue()
{
}

bool ShoppingCartQueue::isEmpty()
{
    return (front == -1 && rear == -1);
}

bool ShoppingCartQueue::isFull()
{
    return (rear + 1) % SHOPCART_SIZE == front ? true : false;
}

void ShoppingCartQueue::enqueue(Book book)
{
    std::cout << "Adding to the shopping cart..." << std::endl;
    if (this->isFull()) {
        std::cout << "Your shopping cart is full" << std::endl;
        return;
    } else if (this->isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SHOPCART_SIZE;
    }
    shoppingCart[rear] = book;
}

void ShoppingCartQueue::dequeue() 
{
    std::cout << "Deleting from the shopping cart..." << std::endl;
    if (this->isEmpty()) {
        std::cout << "You haven't buy anything yet" << std::endl;
    } else if (front == rear) {
        rear = front = -1;
    } else {
        front = (front+1) % SHOPCART_SIZE;
    }
}

void ShoppingCartQueue::printShoppingCart()
{
    int count = (rear + SHOPCART_SIZE - front) % SHOPCART_SIZE + 1;
    for (int i = 0; i < count; i++) {
        int index = (front + i) % SHOPCART_SIZE;
        std::cout << i + 1 << ". ";
        std::cout << std::left;
        std::cout << std::setw(50) << shoppingCart[index].title;
        std::cout << "RM " << shoppingCart[index].price;
        std::cout << std::right;
        std::cout << "\n";
    }
}

Book ShoppingCartQueue::getFront()
{
    return shoppingCart[front];
}
// }}}----------------------------------------EndShoppingQueue----------------------------------------
