#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <iostream>
#include "pankkitili.h"
#include "luottotili.h"

class Asiakas
{
public:
    Asiakas(string n, double lr);

    string getNimi() const;
    void showSaldo() const;

    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double amount, Asiakas &saaja);

private:
    string nimi;
    Pankkitili kayttotili;
    Luottotili luottotili;
};

#endif
