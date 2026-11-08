#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a = 4, b = 9;
    int* p = &a;
    int* q = p;
    int& r = *p;
    p = &b;
    *q += *p;
    *p = r - 3;
    q = p;
    *q += r;
    cout << a << " " << b << " " << r;
    return 0;
}