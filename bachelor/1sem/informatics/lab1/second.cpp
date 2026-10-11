#include <iostream>
using namespace std;

int main() {
    int n, m; // Declares two integer variables named n and m

    cout << "Type n and m: "; // Prompts the user to enter two integers
    cin >> n >> m; // Reads two integers from the keyboard and stores them in n and m

    cout << "1) " << (n++ - m) << endl; // Prints n minus m, then increments n by 1 (post-increment)
    cout << "2) " << (m-- > n) << endl; // Compares the current value of m with n, then decrements m by 1 (post-decrement); prints 1 if true, otherwise 0
    cout << "3) " << (n-- > m) << endl; // Compares the current value of n with m, then decrements n by 1 (post-decrement); prints 1 if true, otherwise 0

    return 0;
}