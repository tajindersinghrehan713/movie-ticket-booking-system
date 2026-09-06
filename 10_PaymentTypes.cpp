#pragma once
#include <iostream>
#include <string>
#include "09_Payment.cpp"
using namespace std;

//inheritance
class UpiPayment : public Payment {
    private:
        string upiId;
        bool simulateSuccess;

    public:
        UpiPayment(string upiId, bool simulateSuccess = true) {
            this->upiId = upiId;
            this->simulateSuccess = simulateSuccess;
        }

        //Polymorphism
        bool pay(double amount) override {
            if (!this->simulateSuccess) {
                cout << "Payment timed out/failed for UPI ID: " << this->upiId << "\n";
                return false;
            }
            cout << "Authorized Rs. " << amount << " from VPA: " << this->upiId << "\n";
            return true;
        }
};

//inheritance
class CardPayment : public Payment {
    private:
        string cardNumber;

    public:
        CardPayment(string cardNumber) {
            this->cardNumber = cardNumber;
        }

        bool pay(double amount) override {
            cout << "Charged Rs. " << amount << " to Card ending ****" 
                 << this->cardNumber.substr(this->cardNumber.length() - 4) << "\n";
            return true;
        }
};

//inheritance
class CashPayment : public Payment {
    public:
        bool pay(double amount) override {
            cout << "Collected cash: Rs. " << amount << "\n";
            return true;
        }
};