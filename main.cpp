#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{

    srand(nullptr);
    int luku = rand() % 20 + 1;
    int arvaus;
    cout << "Arvaa luku 1-20" << endl;
    cin >> arvaus;
    if(arvaus == luku){
        cout << "Oikein" << endl;
        return 0;
    }
    if(arvaus < luku){
        cout << "Liian pieni" << endl;
    }
    if(arvaus > luku){
        cout << "Liian suuri" << endl;
    }
    return 0;
}
