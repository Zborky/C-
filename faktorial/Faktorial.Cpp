#include<iostream>
using namespace std;

unsigned long long faktorial(int n) {
    //algoritmus na vypocet faktorialu
    unsigned long long result = 1;
    for(int i = 1; i <= n; i++) {  // Cyklus začína od 1
        result *= i;
    }  
    return result;
}

int main() {
    int cislo;
    cout << "Zadaj cele cislo" << endl;
    cin >> cislo;
    //podmineka na zistenie ci je cislo vacsie ako 0
    if(cislo < 0) {
        cout << "Faktorial nie je definovany pre zaporne cisla" << endl;
    } else {
        cout << "Faktorial cisla " << cislo << " je " << faktorial(cislo) << endl;
    }
    return 0;
}