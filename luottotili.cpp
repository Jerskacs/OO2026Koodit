#include "luottotili.h"

Luottotili::Luottotili(string o, double lr)
    : Pankkitili(o)
{
    cout << "Luottotili luotu " << omistaja
         << ":lle, luottoraja " << lr << endl;
    luottoRaja = -1 * lr;
    saldo = 0;
}

bool Luottotili::deposit(double amount)
{
    cout << "Luottotili: ";
    if (saldo+amount > 0) {
        cout << "maksu " << amount << " ei sallittu" << endl;
        return false;
    } else {
        saldo += amount;
        cout << " luottovelkaa maksettu " << amount << endl;
        return true;
    }
}

bool Luottotili::withdraw(double amount)
{
    cout << "Luottotili: ";
    if (saldo-amount < luottoRaja) {
        cout << "nosto " << amount << " ei sallittu" << endl;
        return false;
    } else {
        saldo -= amount;
        cout << "nosto " << amount << " tehty,";
        cout << " luottoa jaljella " << abs(luottoRaja-saldo) << endl;
        return true;
    }
}
