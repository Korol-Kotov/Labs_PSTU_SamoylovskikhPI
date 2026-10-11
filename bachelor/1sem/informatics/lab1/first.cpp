#include <iostream>
#include <cmath>
using namespace std;

// Calculates the expression using single-precision floating-point numbers (float).
float calcFloat(float a, float b) {
    // Calculate (a - b)^4.
    float c = powf(a - b, 4.f);

    // Calculate a^4 - 4a^3b + 6a^2b^2.
    float d = powf(a, 4.f) - 4 * powf(a, 3.f) * b + 6 * powf(a, 2.f) * powf(b, 2.f);

    // Calculate b^4 - 4ab^3.
    float e = powf(b, 4.f) - 4 * a * powf(b, 3.f);

    // Calculate the final result:
    // ((a - b)^4 - (a^4 - 4a^3b + 6a^2b^2)) / (b^4 - 4ab^3).
    return (c - d) / e;
}

// Calculates the same expression using double-precision floating-point numbers (double).
double calcDouble(double a, double b) {
    // Calculate (a - b)^4.
    double c = pow(a - b, 4.);

    // Calculate a^4 - 4a^3b + 6a^2b^2.
    double d = pow(a, 4.) - 4 * pow(a, 3.) * b + 6 * pow(a, 2.) * pow(b, 2.);

    // Calculate b^4 - 4ab^3.
    double e = pow(b, 4.) - 4 * a * pow(b, 3.);

    // Calculate the final result using the same formula as calcFloat().
    return (c - d) / e;
}

int main() {
    // Define the input values using float precision.
    float aFloat = 100.0f;
    float bFloat = 0.001f;

    // Define the same input values using double precision.
    double aDouble = 100.0;
    double bDouble = 0.001;

    // Calculate the expression using float precision.
    float resultFloat = calcFloat(aFloat, bFloat);

    // Calculate the expression using double precision.
    double resultDouble = calcDouble(aDouble, bDouble);

    // Print the result obtained using float.
    cout << "Float: " << resultFloat << endl;

    // Print the result obtained using double.
    cout << "Double: " << resultDouble << endl;

    return 0;
}