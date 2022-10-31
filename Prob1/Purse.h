//
// Created by Lucas Vas on 10/18/2022.
//

#ifndef CS_221_ASSIGNMENT1_PURSE_H
#define CS_221_ASSIGNMENT1_PURSE_H

#include <set>
#include <iostream>

class Purse {
public:
    typedef enum {QUARTER, DIME, NICKEL, PENNY} COIN_TYPE;
    struct Coin {
        COIN_TYPE coinType;
        int value;
        explicit Coin(COIN_TYPE coinType) : coinType(coinType) {
            switch(coinType) {
                case QUARTER:
                    value = 25;
                    break;
                case DIME:
                    value = 10;
                    break;
                case NICKEL:
                    value = 5;
                    break;
                case PENNY:
                    value = 1;
                    break;
            }
        }
    };

    void add(const std::multiset<Purse::Coin>& multiset);
    void add(COIN_TYPE coinType);
    void pay(double amount);
    [[nodiscard]] double totalMoney() const { return totalAmount; };
    [[nodiscard]] int countPennies() const { return numPennies; };
    [[nodiscard]] int countNickels() const { return numNickels; };
    [[nodiscard]] int countDimes() const { return numDimes; };
    [[nodiscard]] int countQuarters() const { return numQuarters; };
    void addQuarters(int numQuarters);
    void addDimes(int numDimes);
    void addNickels(int numNickels);
    void addPennies(int numPennies);
    void remPennies(int numPennies);
    void remNickels(int numNickels);
    void remDimes(int numDimes);
    void remQuarters(int numQuarters);

    friend std::ostream& operator<<(std::ostream& out, Purse purse);

private:
    double totalAmount=0;
    int numQuarters=0, numDimes=0, numNickels=0, numPennies=0;
};


#endif //CS_221_ASSIGNMENT1_PURSE_H
