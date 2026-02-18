#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream>

using namespace std;

class Pankkitili
{
public:
    Pankkitili(string o);

    double getBalance() const;
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);

protected:
    double saldo = 0;
    string omistaja;
};

#endif
