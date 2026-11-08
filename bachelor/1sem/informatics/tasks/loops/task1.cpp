#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    cin >> a;
    if (a == 0)
        cout << "Последовательность нулевая" << endl;
    else {
        bool f = true;
        cin >> b;
        while (f && b != 0) {
            f = a < b && f;
            if (f) {
                a = b;
                cin >> b;
            }
        }
        if (f)
            cout << "Последовательность возрастающая" << endl;
        else
            cout << "Последовательность не возрастающая" << endl;
    }
    return 0;
}