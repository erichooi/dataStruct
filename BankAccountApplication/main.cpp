#include <iostream>
#include <iomanip>
#include <fstream>
#include "BankAccount.h"


int main() {
    const int maxAcc = 10;
    int curAcc = 0, AccNum, input, i;
    BankAccount bankAccount[maxAcc];
    bool exit_flag = false;
    std::fstream outputfile;
    outputfile.open("detailStatement.txt", std::ios::out);
    do {
        std::cout << "Bank Account Creation System" << std::endl;
        std::cout << "1. Create Account" << std::endl;
        std::cout << "2. Deposit Money" << std::endl;
        std::cout << "3. Withdraw Money" << std::endl;
        std::cout << "4. Print Detail Statement" << std::endl;
        std::cout << "5. Output to text file" << std::endl;
        std::cout << "6. Exit" << "\n\n";
        std::cout << ">>> ";
        std::cin >> input;
        std::cout << "\n";

        switch (input) {
            case 1:
                if (curAcc < maxAcc) {
                    bankAccount[curAcc].openAccount();
                    curAcc++;
                } else {
                    std::cout << "Reach the maximum account can be created" << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter the Account Number: ";
                std::cin >> AccNum;
                for (i = 0; i < curAcc; i++) {
                    if (bankAccount[i].getAccNum() == AccNum) {
                        bankAccount[i].depositMoney();
                    } else {
                        std::cout << "Cannot find the account" << std::endl;
                    }
                }
                break;
            case 3:
                std::cout << "Enter the Account Number: ";
                std::cin >> AccNum;
                for (int i = 0; i < curAcc; i++) {
                    if (bankAccount[i].getAccNum() == AccNum) {
                        bankAccount[i].withdrawMoney();
                    } else {
                        std::cout << "Cannot find the account" << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Enter the Account Number: ";
                std::cin >> AccNum;
                for (int i = 0; i < curAcc; i++) {
                    if (bankAccount[i].getAccNum() == AccNum) {
                        bankAccount[i].printAccountDetail();
                    } else {
                        std::cout << "Cannot find the account" << std::endl;
                    }
                }
                break;
            case 5:
                outputfile << std::setw(2) << "ID" << "|" << std::setw(20) << "Account Holder" 
                           << "|" << std::setw(30) << "Address" << "|" << std::setw(20)
                           << "Account Number" << "|" << std::setw(20) << "Phone Number"
                           << "|" << std::setw(20) << "Deposit" << "|" << std::endl;
                for (i = 0; i < curAcc; i++) {
                    outputfile << std::setw(2) << bankAccount[i].getAccID() << "|" << std::setw(20) << bankAccount[i].getAccHolder()
                               << "|" << std::setw(30) << bankAccount[i].getAddress() << "|" << std::setw(20)
                               << bankAccount[i].getAccNum() << "|" << std::setw(20) << bankAccount[i].getPhoneNum()
                               << "|" << std::setw(20) << bankAccount[i].getDeposit() << "|" << std::endl;
                }
                std::cout << "Successfully write the file!" << std::endl;
                break;
            case 6:
                exit_flag = true;
                break;
        }
        std::cout << "\n\n\n";
    } while (exit_flag == false);
    return 0;
}
