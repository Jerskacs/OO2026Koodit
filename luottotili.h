#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include <iostream>
#include "pankkitili.h"

class Luottotili: public Pankkitili
{
public:
    Luottotili(string o, double lr);

    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;

protected:
    double luottoRaja = 0;
};

#endif
