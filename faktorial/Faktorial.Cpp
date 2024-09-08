#include<iostream>
using namespace std;

/**
 * Function to calculate the factorial of a number.
 * @param n The number for which the factorial is to be calculated.
 * @return The factorial of the given number as an unsigned long long.
 */
unsigned long long faktorial(int n) {
    // Algorithm to calculate factorial
    unsigned long long result = 1;  // Initialize result as 1
    for(int i = 1; i <= n; i++) {  // Loop starts from 1 and multiplies up to n
        result *= i;  // Multiply result by i in each iteration
    }  
    return result;  // Return the calculated factorial
}

int main() {
    int cislo;  // Variable to store user input
    cout << "Enter an integer" << endl;
    cin >> cislo;  // Take input from user
    
    // Condition to check if the number is non-negative
    if(cislo < 0) {
        cout << "Factorial is not defined for negative numbers" << endl;
    } else {
        // If the number is non-negative, calculate and display the factorial
        cout << "The factorial of " << cislo << " is " << faktorial(cislo) << endl;
    }

    return 0;
}
