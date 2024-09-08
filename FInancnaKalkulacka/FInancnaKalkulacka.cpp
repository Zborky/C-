#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

/**
 * The Calculator class provides functions for interest, payment, and investment calculations.
 */
class Calculator {
private:
    bool isAnnual; // Indicates whether the payments are annual (true) or not (false)
    bool isMonthly; // Indicates whether the payments are monthly (true) or not (false)
    double timePeriod; // Time period in years
    string paymentType; // Type of payment
    double borrowedAmount; // Borrowed amount
    double interestRate; // Interest rate
    int numberOfMonths; // Number of months
    double investmentInterestRate; // Interest rate on investments
    double investedAmount; // Invested amount

public:
    /**
     * Constructor for the Calculator class.
     * @param isAnnual Indicates whether the payments are annual.
     * @param isMonthly Indicates whether the payments are monthly.
     * @param interestRate Interest rate for loans.
     * @param timePeriod Time period in years.
     * @param paymentType Type of payment.
     * @param borrowedAmount Borrowed amount.
     * @param numberOfMonths Number of months for payments.
     * @param investmentInterestRate Interest rate on investments.
     * @param investedAmount Invested amount.
     */
    Calculator(bool isAnnual, bool isMonthly, double interestRate, double timePeriod, string paymentType, double borrowedAmount, int numberOfMonths, double investmentInterestRate, double investedAmount) {
        this->isAnnual = isAnnual;
        this->isMonthly = isMonthly;
        this->interestRate = interestRate;
        this->timePeriod = timePeriod;
        this->paymentType = paymentType;
        this->borrowedAmount = borrowedAmount;
        this->numberOfMonths = numberOfMonths;
        this->investmentInterestRate = investmentInterestRate;
        this->investedAmount = investedAmount;
    }

    /**
     * Returns the time period in years.
     * @return Time period.
     */
    double getTimePeriod() {
        return this->timePeriod;
    }

    /**
     * Returns the type of payment.
     * @return Payment type.
     */
    string getPaymentType() {
        return this->paymentType;
    }

    /**
     * Returns the borrowed amount.
     * @return Borrowed amount.
     */
    double getBorrowedAmount() {
        return this->borrowedAmount;
    }

    /**
     * Calculates simple interest.
     * @return Simple interest.
     */
    double calculateSimpleInterest() {
        return this->borrowedAmount * interestRate * timePeriod;
    }

    /**
     * Calculates compound interest.
     * @return Compound interest.
     */
    double calculateCompoundInterest() {
        return this->borrowedAmount * pow(1 + interestRate, this->timePeriod);
    }

    /**
     * Calculates the payment amount based on the selected parameters.
     * @return Payment amount.
     */
    double calculatePayment() {
        if (this->isAnnual) {
            return this->borrowedAmount * this->interestRate / 12;
        } else {
            return this->borrowedAmount * interestRate / this->numberOfMonths;
        }
    }

    /**
     * Calculates the return on investment.
     * @return Return on investment.
     */
    double calculateInvestmentReturn() {
        return this->investedAmount * this->numberOfMonths * this->investmentInterestRate;
    }

    /**
     * Saves data to a file.
     * @param filename Name of the file where data will be saved.
     */
    void saveToFile(string filename) {
        ofstream outputFile(filename, ios::app);

        if (outputFile.is_open()) {
            // Get the current time
            time_t now = time(0);
            tm *ltm = std::localtime(&now);

            // Format the time as a string
            char dateTime[30];
            strftime(dateTime, sizeof(dateTime), "%Y-%m-%d %H:%M:%S", ltm);

            // Write the data to the file
            outputFile << dateTime << endl;
            outputFile << "Payment type: " << paymentType << endl;
            outputFile << "Borrowed amount: " << borrowedAmount << " EUR" << endl;
            outputFile << "Interest rate: " << interestRate * 100 << " %" << endl;
            outputFile << "Time period: " << timePeriod << " years" << endl;
            outputFile << "Number of months: " << numberOfMonths << endl;
            outputFile << "-------------------------------" << endl;

            outputFile.close();
        } else {
            cerr << "\033[31mError opening file: " << filename << "\033[0m" << endl;
        }
    }

    /**
     * Reads data from a file and prints it to the console.
     * @param filename Name of the file to read data from.
     */
    void readFromFile(string filename) {
        ifstream inputFile(filename);

        if (inputFile.is_open()) {
            string line;
            while (getline(inputFile, line)) {
                cout << "\033[32m" << line << "\033[0m" << endl;
            }
            inputFile.close();
        } else {
            cerr << "\033[31mError opening file: " << filename << "\033[0m" << endl;
        }
    }
};

/**
 * Prints a title with colors.
 * @param text Title text.
 */
void printTitle(const string &text) {
    cout << "\033[34m╔══════════════════════════════════════════╗\033[0m" << endl;
    cout << "\033[34m║\033[0m " << text << " \033[34m║\033[0m" << endl;
    cout << "\033[34m╚══════════════════════════════════════════╝\033[0m" << endl;
}

int main() {
    // Print the title
    printTitle("Financial Operations Calculator");

    // Declare variables for user input
    bool isAnnual, isMonthly;
    double interestRate, timePeriod, borrowedAmount, investmentInterestRate, investedAmount;
    int numberOfMonths;
    string paymentType;

    // User input
    cout << "\033[33mEnter if the payment is annual (1 = yes, 0 = no): \033[0m";
    cin >> isAnnual;
    cout << "\033[33mEnter if the payment is monthly (1 = yes, 0 = no): \033[0m";
    cin >> isMonthly;
    cout << "\033[33mEnter the interest rate (e.g., 0.05 for 5%): \033[0m";
    cin >> interestRate;
    cout << "\033[33mEnter the time period in years: \033[0m";
    cin >> timePeriod;
    cout << "\033[33mEnter the payment type: \033[0m";
    cin >> paymentType;
    cout << "\033[33mEnter the borrowed amount: \033[0m";
    cin >> borrowedAmount;
    cout << "\033[33mEnter the number of months: \033[0m";
    cin >> numberOfMonths;
    cout << "\033[33mEnter the interest rate on investments (e.g., 0.035 for 3.5%): \033[0m";
    cin >> investmentInterestRate;
    cout << "\033[33mEnter the invested amount: \033[0m";
    cin >> investedAmount;

    // Create a Calculator object with the provided data
    Calculator calculator(isAnnual, isMonthly, interestRate, timePeriod, paymentType, borrowedAmount, numberOfMonths, investmentInterestRate, investedAmount);

    // Output calculation results
    cout << "\033[32mTime period: \033[0m" << calculator.getTimePeriod() << " years" << endl;
    cout << "\033[32mPayment type: \033[0m" << calculator.getPaymentType() << endl;
    cout << "\033[32mBorrowed amount: \033[0m" << calculator.getBorrowedAmount() << " EUR" << endl;

    double simpleInterest = calculator.calculateSimpleInterest();
    cout << "\033[32mSimple interest: \033[0m" << simpleInterest << " EUR" << endl;

    double compoundInterest = calculator.calculateCompoundInterest();
    cout << "\033[32mCompound interest: \033[0m" << compoundInterest << " EUR" << endl;

    double payment = calculator.calculatePayment();
    cout << "\033[32mPayment: \033[0m" << payment << " EUR monthly" << endl;

    double investmentReturn = calculator.calculateInvestmentReturn();
    cout << "\033[32mInvestment return: \033[0m" << investmentReturn << " EUR" << endl;

    // Save data to file and read it back
    calculator.saveToFile("List.txt");
    calculator.readFromFile("List.txt");

    return 0;
}
