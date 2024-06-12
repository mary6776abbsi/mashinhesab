#include <iostream>
using namespace std;

// Recursive function to calculate power
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    else if (exponent > 0) {
        return base * power(base, exponent - 1);
    }
    else {
        return 1 / power(base, -exponent); // Handle negative exponents
    }
}

// Function to perform the requested operation
double calculate(double num1, double num2, char op) {
    switch (op) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0) {
            return num1 / num2;
        }
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    case '%':
        if (static_cast<int>(num2) != 0) {
            return static_cast<int>(num1) % static_cast<int>(num2);
        }
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    case '^':
        return power(num1, static_cast<int>(num2));
    default:
        cout << "Invalid operator!" << endl;
        return 0;
    }
}

// Function to get inputs and perform calculation
void performCalculation() {
    double num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter operator (+, -, *, /, %, ^): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    double result = calculate(num1, num2, op);

    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^') {
        cout << "Result: " << num1 << " " << op << " " << num2 << " = " << result << endl;
    }
}

int main() {
    char choice;

    do {
        performCalculation();
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
