
#include <iostream>
#include <clocale>
#include <cmath>
using namespace std;

int main() {
    // Set the locale to support Russian language settings.
    setlocale(LC_ALL, "Russian");

    // Initialize the interval limits, the number of steps, the number of series terms, and the required precision.
    const double a = 0.1;
    const double b = 1.0;
    const int k = 10;
    const int n = 40;
    const double eps = 0.0001;

    // Calculate the step size for changing x.
    const double h = (b - a) / k;

    // Calculate the arctangent for each x value in the given interval.
    for (int i = 0; i <= k; i++) {
        // Calculate the current x value.
        double x = a + i * h;

        // Initialize the sum and the first term of the series for a fixed number of terms.
        double sn = 0.0;
        double term = x;

        // Calculate the sum of the first 41 terms of the power series.
        for (int j = 0; j <= n; j++) {
            // Add the current term to the sum.
            sn += term;

            // Calculate the next term of the series using the previous term.
            term *= (-x * x) * (2.0 * j + 1) / (2.0 * j + 3);
        }

        // Initialize the sum and the first term of the series for the required precision.
        double se = 0.0;
        term = x;
        int j = 0;

        // Calculate the sum until the absolute value of the current term becomes smaller than the required precision.
        while (fabs(term) >= eps) {
            // Add the current term to the sum.
            se += term;

            // Calculate the next term of the series.
            term *= (-x * x) * (2.0 * j + 1) / (2.0 * j + 3);

            // Increase the term index.
            j++;
        }

        // Calculate the exact arctangent value using the standard library function.
        double y = atan(x);

        // Print the current x value and the calculated results.
        cout << "X: " << x << " Sn: " << sn << " Se: " << se << " Y: " << y << endl;
    }

    return 0;
}