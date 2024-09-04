#include <iostream>
using namespace std;

// Funkcia na konverziu z Celzia na Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32;
}

// Funkcia na konverziu z Fahrenheit na Celzia
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    char volba;
    double teplota;

    cout << "Vyber si moznost konverzie:" << endl;
    cout << "a. Celsius -> Fahrenheit" << endl;
    cout << "b. Fahrenheit -> Celsius" << endl;
    cout << "Tvoja volba: ";
    cin >> volba;

    switch (volba) {
        case 'a':
            cout << "Zadaj teplotu v stupnoch Celsia: ";
            cin >> teplota;
            cout << teplota << " stupnov Celsius je " << celsiusToFahrenheit(teplota) << " stupnov Fahrenheit." << endl;
            break;
        case 'b':
            cout << "Zadaj teplotu v stupnoch Fahrenheita: ";
            cin >> teplota;
            cout << teplota << " stupnov Fahrenheit je " << fahrenheitToCelsius(teplota) << " stupnov Celsius." << endl;
            break;
        default:
            cout << "Neplatna volba." << endl;
            break;
    }

    return 0;
}