//
// Created by Lucas Vas on 10/18/2022.
//

#ifndef CS_221_ASSIGNMENT1_PURSE_H
#define CS_221_ASSIGNMENT1_PURSE_H

#include <set>

class Purse {
public:
    typedef enum coinType {QUARTER, DIME, NICKEL, PENNY};
    struct Coin;
    Purse(const std::multiset<Coin>& ms);
    void add(const std::multiset<Purse::Coin>& multiset);
    void pay(double amount);
    double totalMoney() const { return totalAmount; };
    int countPennies() const { return numPennies; };
    int countNickels() const { return numNickels; };
    int countDimes() const { return numDimes; };
    int countQuarters() const { return numQuarters; };
    void addQuarters(int numQuarters);
    void addDimes(int numDimes);
    void addNickels(int numNickels);
    void addPennies(int numPennies);
    void remPennies(int numPennies);
    void remNickels(int numNickels);
    void remDimes(int numDimes);
    void remQuarters(int numQuarters);

private:
    double totalAmount{};
    int numQuarters{}, numDimes{}, numNickels{}, numPennies{};
};


#endif //CS_221_ASSIGNMENT1_PURSE_H
