#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int s = 0, n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int p = 1;
        for (int j = i; j <= i * 2; ++j)
            p *= j;
        s += p;
    }
    cout << "Sum: " << s << endl;
    return 0;
}