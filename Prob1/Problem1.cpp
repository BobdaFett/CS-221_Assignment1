//
// Created by Lucas Vas on 10/18/2022.
//

#include <iostream>
#include <vector>
#include "Purse.h"
using namespace std;
using Coin = Purse::Coin;

/**
 * Compares the number of quarters in each of the passed Purse objects.
 * @return Value of 0, 1, or -1 to be used with qsort.
 */
int compareQuarters(const void *a, const void *b);

/**
 * Compares the number of dimes in each of the passed Purse objects.
 * @return Value of 0, 1, or -1 to be used with qsort.
 */
int compareDimes(const void *a, const void *b);

int main() {

    // Create 3 Purse objects to be sorted
    Purse moreQuarters, lessQuarters, midQuarters;
    moreQuarters.addQuarters(5);
    moreQuarters.addDimes(1);
    lessQuarters.addQuarters(1);
    lessQuarters.addDimes(5);
    midQuarters.addQuarters(3);
    midQuarters.addDimes(32);

    // Create the arrays to sort
    Purse quarters[3] = {lessQuarters, moreQuarters, midQuarters};
    Purse dimes[3] = {lessQuarters, moreQuarters, midQuarters};
    std::vector<Purse> byTotal (quarters, quarters+3);

    cout << "more: " << moreQuarters;
    cout << "less: " << lessQuarters;
    cout << "mid: " << midQuarters;

    // Sort arrays by order of quarters and order of dimes
    qsort(quarters, 3, sizeof(Purse), compareQuarters);
    qsort(dimes, 3, sizeof(Purse), compareDimes);
    sort(byTotal.begin(), byTotal.end());

    // Print contents of Purse objects.
    for (Purse p : quarters)
        cout << p.countQuarters() << " ";
    cout << "\n";
    for (Purse p : dimes)
        cout << p.countDimes() << " ";
    cout << "\n";
    for (Purse p : byTotal)
        cout << p.totalMoney() << " ";

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