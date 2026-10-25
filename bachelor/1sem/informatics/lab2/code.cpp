#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

// Calculates the factorial of a given number n.
long double factorial(int n) {
    // Initialize the result to 1.
    long double result = 1.;

    // Calculate the factorial by multiplying numbers from 1 to n.
    for (int i = 1; i <= n; i++) result *= i;

    // Return the calculated factorial.
    return result;
}

int main() {
    // Set the locale to support Russian language settings.
    setlocale(LC_ALL, "Russian");

    // Initialize the sum, the upper limit, and the current term.
    long double s = 0, n = 13, a;

    // Calculate the sum of the series from i = 1 to i = 13.
    for (int i = 1; i <= 13; i++) {
        // Calculate the current term: ln(i!) / i^2.
        a = log(factorial(i)) / (i * i);

        // Add the current term to the total sum.
        s += a;
    }

    // Print the final sum.
    cout << "Sum: " << s;

    return 0;
}