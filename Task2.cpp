#include <iostream>
using namespace std;
int main() {
    double num1, num2, result;
    char operation;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << result << "\n";
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << result << "\n";
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << result << "\n";
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << "\n";
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /.\n";
            break;
    }
    return 0;
}
