#include <iostream>
using namespace std;

void tukar(int &x, int &y, int &z) {
    int temp;

    temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int a = 4;
    int b = 6;
    int c = 8;

    cout << "Sebelum ditukar:" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;
    cout << "Nilai c = " << c << endl;

    tukar(a, b, c);

    cout << "\nSetelah ditukar:" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;
    cout << "Nilai c = " << c << endl;

    return 0;
}