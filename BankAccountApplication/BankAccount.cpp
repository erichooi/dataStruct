#include <iostream>
#include <iomanip>
#include "BankAccount.h"


int BankAccount::NUMACC = 1;

int BankAccount::getAccID()
{
    return this->AccountID;
}

std::string BankAccount::getAccHolder()
{
    return this->AccountHolder;
}

std::string BankAccount::getAddress()
{
    return this->Address;
}

int BankAccount::getAccNum() 
{
    return this->AccountNumber;
}

int BankAccount::getPhoneNum() 
{
    return this->PhoneNumber;
}

float BankAccount::getDeposit()
{
    return this->Deposit;
}

void BankAccount::openAccount()
{
    this->AccountID = NUMACC;
    std::cout << "Enter Account's Holder Name: ";
    std::cin.ignore();
    std::getline(std::cin, this->AccountHolder);
    std::cout << "Enter Address: ";
    std::getline(std::cin, this->Address);
    std::cout << "Enter Account's Number: ";
    std::cin >> this->AccountNumber;
    std::cout << "Enter Phone Number: ";
    std::cin >> this->PhoneNumber;
    std::cout << "Enter the deposit: ";
    std::cin >> this->Deposit;
    NUMACC++;
}

void BankAccount::depositMoney()
{
    float deposit;
    std::cout << "Enter the amount you wish to deposit: ";
    std::cin >> deposit;
    this->Deposit += deposit;
}

void BankAccount::withdrawMoney()
{
    float withdraw;
    std::cout << "Enter the amount you wish to withdraw: ";
    std::cin >> withdraw;
    if (withdraw > this->Deposit) {
        std::cout << "You cannot withdraw that much money!" << std::endl;
    } else {
        this->Deposit -= withdraw;
        std::cout << "You have withdraw RM" << withdraw << std::endl;
    }
}

void BankAccount::printAccountDetail()
{
    std::cout << std::setw(2) << "ID" << "|" << std::setw(20) << "Account Holder"
              << "|" << std::setw(30) << "Address" << "|" << std::setw(20) 
              << "Account Number" << "|" << std::setw(20) << "Phone Number" 
              << "|" << std::setw(20) << "Deposit" << "|" << std::endl;
    std::cout << std::setw(2) << this->AccountID << "|" << std::setw(20) << this->AccountHolder
              << "|" << std::setw(30) << this->Address << "|" << std::setw(20)
              << this->AccountNumber << "|" << std::setw(20) << this->PhoneNumber
              << "|" << std::setw(20) << this->Deposit << "|" << std::endl;
}
