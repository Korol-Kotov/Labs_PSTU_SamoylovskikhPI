#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a = 5, b = 8;
    int& r = a;
    int& s = a;
    int copy = a;
    r = b;
    s += 2;
    b = copy;
    cout << a << " " << b << " " << r << " " << s << " " << copy;
    return 0;
}