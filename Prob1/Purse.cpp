//
// Created by Lucas Vas on 10/18/2022.
//

#include "Purse.h"

#include <iostream>

void Purse::add(const std::multiset<Coin>& multiset) {
    for (const auto & iter : multiset) {
        switch (iter.coinType) {
            case QUARTER:
                addQuarters(1);
                break;
            case DIME:
                addDimes(1);
                break;
            case NICKEL:
                addNickels(1);
                break;
            case PENNY:
                addPennies(1);
                break;
        }
    }
}

void Purse::add(COIN_TYPE coinType) {
    switch (coinType) {
        case QUARTER:
            addQuarters(1);
            break;
        case DIME:
            addDimes(1);
            break;
        case NICKEL:
            addNickels(1);
            break;
        case PENNY:
            addPennies(1);
            break;
    }
}

void Purse::pay(double amount) {
    int tempQuarters = numQuarters, tempDimes = numDimes, tempNickels = numNickels, tempPennies = numPennies;

    // Use temporary values in case the user does not have enough money
    if (amount > totalAmount) return;
    while(amount - 0.25 >= 0 && tempQuarters >= 1) {
        tempQuarters--;
        amount -= .25;
    } while (amount - 0.10 >= 0 && tempDimes >= 1) {
        tempDimes--;
        amount -= .1;
    } while (amount - 0.05 >= 0 && tempNickels >= 1) {
        tempNickels--;
        amount -= .05;
    } while (amount - 0.01 >= 0 && tempPennies >= 1) {
        tempPennies--;
        amount -= .01;
    }


    if (amount > 0) {
        // If user didn't have enough money
        std::cout << "You do not have enough coins to pay this amount.\n"
                  << "Amount was not paid.\n\n"
                  << "Remaining purse balance: " << totalMoney() << "\n\n";
    } else if (amount < 0) {
        // Should never reach this point.
        std::cout << "Something has gone terribly wrong.\n";
    } else {
        // If user has enough money
        remQuarters(numQuarters - tempQuarters);
        remDimes(numDimes - tempDimes);
        remNickels(numNickels - tempNickels);
        remPennies(numPennies - tempPennies);
    }
}

void Purse::addQuarters(int numQuarters) {
    this->numQuarters += numQuarters;
    this->totalAmount += numQuarters * .25;
}

void Purse::addDimes(int numDimes) {
    this->numDimes += numDimes;
    this->totalAmount += numDimes * .1;
}

void Purse::addNickels(int numNickels) {
    this->numNickels += numNickels;
    this->totalAmount += numNickels * .05;
}

void Purse::addPennies(int numPennies) {
    this->numPennies += numPennies;
    this->totalAmount += .01 * numPennies;
}

void Purse::remPennies(int numPennies) {
    for (numPennies; numPennies > 0; numPennies--) {
        Purse::numPennies--;
        Purse::totalAmount -= 0.01;
    }
}

void Purse::remNickels(int numNickels) {
    for (numNickels; numNickels > 0; numNickels--) {
        Purse::numNickels--;
        Purse::totalAmount -= 0.05;
    }
}

void Purse::remDimes(int numDimes) {
    for (numDimes; numDimes > 0; numDimes--) {
        Purse::numDimes--;
        Purse::totalAmount -= 0.1;
    }
}

void Purse::remQuarters(int numQuarters) {
    for (numQuarters; numQuarters > 0; numQuarters--) {
        Purse::numQuarters--;
        Purse::totalAmount -= 0.25;
    }
}

std::ostream& operator<<(std::ostream& out, Purse purse) {
    out << "Total value: $" << purse.totalAmount << std::endl;
}
