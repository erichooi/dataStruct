#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Book.h"


void readFile(std::fstream& infile, std::string filename, ListBook& LBook)
{
    infile.open(filename.c_str(), std::ios::in);
    std::string title;
    std::string author;
    std::string ISBN;
    std::string quantity;
    std::string price;
    while (std::getline(infile, title, ',')) {
        std::getline(infile, author, ',');
        std::getline(infile, ISBN, ',');
        std::getline(infile, quantity, ',');
        std::getline(infile, price);
        int quantity_int = std::atoi(quantity.c_str());
        int price_int = std::atoi(price.c_str());
        LBook.addBook(title, author, ISBN, quantity_int, price_int);
    }
    infile.close();
}

char getCont()
{
    char cont;
    std::cout << "Continue? (y/n): ";
    std::cin >> cont;
    std::cin.ignore();
    return cont;
}

void clrscreen()
{
    std::system("clear");
}

int main() {
    ListBook LBook;
    Book QBook;
    Book* search;
    ShoppingCartQueue SCQueue;
    std::fstream infile;
    std::string filename;
    std::string ISBN, author, title;
    int quantity, price;
    int count = 0;
    char cont;
    char input;
    char buy;
main:
    char who = 'n';
    while (who == 'n') {
        clrscreen();
        std::cout << "-------------------------------" << std::endl;
        std::cout << "| Book Shop Management System |" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        std::cout << "\n\n";
        std::cout << "Who are you?" << std::endl;
        std::cout << "a) Customer" << std::endl;
        std::cout << "b) Staff" << std::endl;
        std::cout << "c) Exit Program" << std::endl;
        std::cin >> who;
        std::cin.ignore();
        clrscreen();
    }

    switch (who) {
        case 'a':
            do {
                clrscreen();
                LBook.printBook();
                std::cout << "\n\n";
                std::cout << "-------------------------------" << std::endl;
                std::cout << "| Book Shop Management System |" << std::endl;
                std::cout << "-------------------------------" << std::endl;
                std::cout << "\n\n";
                std::cout << "a) Search book by author" << std::endl;
                std::cout << "b) Search book by title" << std::endl;
                std::cout << "c) View Shopping Cart" << std::endl;
                std::cout << "d) Pay" << std::endl;
                std::cout << "e) Exit" << std::endl;
                std::cin >> input;
                std::cin.ignore();
                clrscreen();
                switch (input) {
                    case 'a':
                        std::cout << "Enter the author that you want find: ";
                        std::getline(std::cin, author);
                        clrscreen();
                        search = LBook.searchBook_author(author);
                        if (search == nullptr) {
                            std::cout << "Cannot find the author in the system" << std::endl;
                            break;
                        } else {
                            std::cout << "Book title: " << search->title << std::endl;
                            std::cout << "Author: " << search->author << std::endl;
                            std::cout << "ISBN: " << search->ISBN << std::endl;
                            std::cout << "Quantity: " << search->quantity << std::endl;
                            std::cout << "Price: " << search->price << std::endl;
                        }
                        std::cout << "\n\n";
                        std::cout << "Do you want to buy? (y/n): ";
                        std::cin >> buy;
                        std::cin.ignore();
                        if (buy == 'y') {
                            SCQueue.enqueue(*search);
                            count += 1;
                        }
                        cont = getCont();
                        break;
                    case 'b':
                        std::cout << "Enter the title that you want find: ";
                        std::getline(std::cin, title);
                        clrscreen();
                        search = LBook.searchBook_title(title);
                        if (search == nullptr) {
                            std::cout << "Cannot find the title in the system" << std::endl;
                            break;
                        } else {
                            std::cout << "Book title: " << search->title << std::endl;
                            std::cout << "Author: " << search->author << std::endl;
                            std::cout << "ISBN: " << search->ISBN << std::endl;
                            std::cout << "Quantity: " << search->quantity << std::endl;
                            std::cout << "Price: " << search->price << std::endl;
                        }
                        std::cout << "\n\n";
                        std::cout << "Do you want to buy? (y/n): ";
                        std::cin >> buy;
                        std::cin.ignore();
                        if (buy == 'y') {
                            SCQueue.enqueue(*search);
                            count += 1;
                        }
                        cont = getCont();
                        break;
                    case 'c':
                        SCQueue.printShoppingCart();
                        cont = getCont();
                        break;
                    case 'd':
                        for (int i = 0; i < count; i++) {
                            QBook = SCQueue.getFront();
                            quantity = LBook.getQuantity(QBook.ISBN);
                            LBook.setQuantity(quantity-1, QBook.ISBN);
                            SCQueue.dequeue();
                        }
                        cont = getCont();
                        break;
                    case 'e':
                        goto main;
                        break;
                }
            } while (cont == 'y');
            break;
        case 'b':
            do {
                clrscreen();
                std::cout << "-------------------------------" << std::endl;
                std::cout << "| Book Shop Management System |" << std::endl;
                std::cout << "-------------------------------" << std::endl;
                std::cout << "\n\n";
                std::cout << "a) Read data from file (.csv)" << std::endl;
                std::cout << "b) Show data in system" << std::endl;
                std::cout << "c) Manage Stock inventory" << std::endl;
                std::cout << "d) Give Discount" << std::endl;
                //std::cout << "e) Generate Report" << std::endl;
                std::cout << "e) Exit" << std::endl;
                std::cin >> input;
                std::cin.ignore();
                clrscreen();
                switch (input) {
                    case 'a':
                        std::cout << "Enter the file's name: ";
                        std::getline(std::cin, filename);
                        readFile(infile, filename, LBook);
                        cont = getCont();
                        clrscreen();
                        break;
                    case 'b':
                        clrscreen();
                        LBook.printBook();
                        cont = getCont();
                        break;
                    case 'c':
                        std::cout << "\n\n";
                        LBook.printBook();
                        std::cout << "\n\n";
                        std::cout << "Enter the ISBN to update the book's quantity: ";
                        std::getline(std::cin, ISBN);
                        std::cout << "Enter the new book quantity: ";
                        std::cin >> quantity;
                        std::cin.ignore();
                        LBook.setQuantity(quantity, ISBN);
                        std::cout << "Update Successfully" << std::endl;
                        break;
                    case 'd':
                        std::cout << "\n\n";
                        LBook.printBook();
                        std::cout << "\n\n";
                        std::cout << "Enter the ISBN to update the book's price: ";
                        std::getline(std::cin, ISBN);
                        std::cout << "Enter the new book price: ";
                        std::cin >> price;
                        std::cin.ignore();
                        LBook.setPrice(price, ISBN);
                        std::cout << "Update Successfully" << std::endl;
                        break;
                    case 'e':
                        goto main;
                        break;
                    /*
                    case 'f':
                        break;
                    */
                }
            } while (cont == 'y');
            break;
        case 'c':
            return 0;
    }
    return 0;
}
