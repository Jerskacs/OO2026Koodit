#include "pankkitili.h"
#include <cmath>

Pankkitili::Pankkitili(string o)
{
    omistaja = o;
    saldo = 0;
    cout << "Pankkitili luotu " << omistaja << ":lle" << endl;
}

double Pankkitili::getBalance() const
{
    return saldo;
}

bool Pankkitili::withdraw(double amount)
{
    cout << "Pankkitili: ";
    if (amount < 0.0) {
        cout << "nosto " << amount << " ei sallittu" << endl;
        return false;
    }
    if (saldo > amount) {
        saldo -= amount;
        cout << "nosto " << amount << " tehty" << endl;
        return true;
    } else {
        cout << "ei katetta nostaa " << amount << endl;
        return false;
    }
}

bool Pankkitili::deposit(double amount)
{
    cout << "Pankkitili: ";
    if (amount < 0.0) {
        cout << "talletusta " << amount << " ei sallita" << endl;
        return false;
    }
    saldo += amount;
    cout << "talletus " << amount << " tehty" << endl;
    return true;
}
