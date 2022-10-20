//
// Created by Lucas Vas on 10/18/2022.
//

#include <iostream>
#include "Purse.h"
using namespace std;
using Coin = Purse::Coin;

int compareQuarters(const void *a, const void *b);
int compareDimes(const void *a, const void *b);

int main() {
    // This is where the Purse pointers will be sorted

    Coin nickel;

    Purse first = Purse();



    return 0;
}

int compareQuarters(const void *a, const void *b) {
    const Purse* x = (Purse*) a;
    const Purse* y = (Purse*) b;

    return (x->countQuarters() - y->countQuarters());
}

int compareDimes(const void *a, const void *b) {
    const Purse* x = (Purse*) a;
    const Purse* y = (Purse*) b;

    return (x->countDimes() - y->countDimes());
}