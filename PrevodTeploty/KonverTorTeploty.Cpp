#include <iostream>
using namespace std;

// Function to convert Celsius to Fahrenheit
double celsiusToFahrenheit(double celsius) {
    return (celsius * 9 / 5) + 32; // Conversion formula
}

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9; // Conversion formula
}

int main() {
    char choice; // Variable to store user's choice
    double temperature; // Variable to store the temperature value entered by the user

    // Display the conversion options to the user
    cout << "Choose a conversion option:" << endl;
    cout << "a. Celsius -> Fahrenheit" << endl;
    cout << "b. Fahrenheit -> Celsius" << endl;
    cout << "Your choice: ";
    cin >> choice; // Get the user's choice

    // Perform the conversion based on user's selection
    switch (choice) {
        case 'a': // If the user chooses Celsius to Fahrenheit
            cout << "Enter the temperature in Celsius: ";
            cin >> temperature; // Get the temperature in Celsius
            // Convert and display the result in Fahrenheit
            cout << temperature << " degrees Celsius is " << celsiusToFahrenheit(temperature) << " degrees Fahrenheit." << endl;
            break;
        case 'b': // If the user chooses Fahrenheit to Celsius
            cout << "Enter the temperature in Fahrenheit: ";
            cin >> temperature; // Get the temperature in Fahrenheit
            // Convert and display the result in Celsius
            cout << temperature << " degrees Fahrenheit is " << fahrenheitToCelsius(temperature) << " degrees Celsius." << endl;
            break;
        default: // If the user enters an invalid option
            cout << "Invalid choice." << endl;
            break;
    }

    return 0; // Exit the program
}
