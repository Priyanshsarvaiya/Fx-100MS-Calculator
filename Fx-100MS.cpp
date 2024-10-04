#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

void showMenu() {
    cout << "\nScientific Calculator Menu\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Power (x^y)\n";
    cout << "6. Square root\n";
    cout << "7. Logarithm (base 10)\n";
    cout << "8. Natural logarithm (ln)\n";
    cout << "9. Sine\n";
    cout << "10. Cosine\n";
    cout << "11. Tangent\n";
    cout << "12. Derivative (d/dx)\n";
    cout << "13. Integration\n";
    cout << "14. Permutation (nPr)\n";
    cout << "15. Combination (nCr)\n";
    cout << "16. Exit\n";
}

// Define a function for testing (for derivative and integration)
double f(double x) {
    return sin(x);  // You can change this function to any other like x^2, exp(x), etc.
}

double getOperand() {
    double num;
    cin >> num;
    return num;
}

// Numerical approximation of derivative using central difference
double derivative(double (*func)(double), double x, double h = 1e-5) {
    return (func(x + h) - func(x - h)) / (2 * h);
}

// Numerical approximation of integration using Simpson's Rule
double simpsonsRule(double (*func)(double), double a, double b, int n = 1000) {
    double h = (b - a) / n;
    double sum = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        sum += 4 * func(a + i * h);
    }
    for (int i = 2; i < n; i += 2) {
        sum += 2 * func(a + i * h);
    }
    return (h / 3) * sum;
}

// Factorial function
unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; ++i)
        fact *= i;
    return fact;
}

// Permutation (nPr)
unsigned long long permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Combination (nCr)
unsigned long long combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int choice;
    double num1, num2, x, a, b;
    int n, r;

    do {
        showMenu();
        cout << "Enter your choice (1-16): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 + num2 << endl;
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 - num2 << endl;
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << num1 * num2 << endl;
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero\n";
                break;
            case 5:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << pow(num1, num2) << endl;
                break;
            case 6:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 >= 0)
                    cout << "Result: " << sqrt(num1) << endl;
                else
                    cout << "Error: Negative input\n";
                break;
            case 7:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 > 0)
                    cout << "Result: " << log10(num1) << endl;
                else
                    cout << "Error: Non-positive input\n";
                break;
            case 8:
                cout << "Enter a number: ";
                cin >> num1;
                if (num1 > 0)
                    cout << "Result: " << log(num1) << endl;
                else
                    cout << "Error: Non-positive input\n";
                break;
            case 9:
                cout << "Enter angle in degrees: ";
                cin >> num1;
                cout << "Result: " << sin(num1 * M_PI / 180) << endl;
                break;
            case 10:
                cout << "Enter angle in degrees: ";
                cin >> num1;
                cout << "Result: " << cos(num1 * M_PI / 180) << endl;
                break;
            case 11:
                cout << "Enter angle in degrees: ";
                cin >> num1;
                cout << "Result: " << tan(num1 * M_PI / 180) << endl;
                break;
            case 12:
                cout << "Enter the value of x to find d/dx of the function sin(x) at that point: ";
                cin >> x;
                cout << "Result (f'(x)): " << derivative(f, x) << endl;
                break;
            case 13:
                cout << "Enter the limits of integration (a and b): ";
                cin >> a >> b;
                cout << "Result (integral): " << simpsonsRule(f, a, b) << endl;
                break;
            case 14:
                cout << "Enter values for n and r (n >= r): ";
                cin >> n >> r;
                cout << "Permutation (nPr): " << permutation(n, r) << endl;
                break;
            case 15:
                cout << "Enter values for n and r (n >= r): ";
                cin >> n >> r;
                cout << "Combination (nCr): " << combination(n, r) << endl;
                break;
            case 16:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, try again.\n";
        }
    } while (choice != 16);

    return 0;
}
