#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class BankAccount
{
    private:
        int AccountID;
        std::string AccountHolder;
        std::string Address;
        int AccountNumber;
        int PhoneNumber;
        float Deposit;
    public:
        static int NUMACC;
        BankAccount() {};
        ~BankAccount() {};
        int getAccID();
        std::string getAccHolder();
        std::string getAddress();
        int getAccNum();
        int getPhoneNum();
        float getDeposit();
        void openAccount();
        void depositMoney();
        void withdrawMoney();
        void printAccountDetail();
        void exportToFile();
};

#endif
