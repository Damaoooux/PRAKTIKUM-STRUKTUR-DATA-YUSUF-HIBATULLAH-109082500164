#include "array.h"

int main() {
    Matriks arr1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matriks arr2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int a = 10, b = 20;
    int *ptr1 = &a;
    int *ptr2 = &b;

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilArray(arr1);

    cout << "\nArray 2 sebelum ditukar:" << endl;
    tampilArray(arr2);
    tukarArray(arr1, arr2, 0, 0);

    cout << "\nArray 1 setelah ditukar:" << endl;
    tampilArray(arr1);

    cout << "\nArray 2 setelah ditukar:" << endl;
    tampilArray(arr2);

    cout << "\nSebelum tukar pointer:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    tukarPointer(ptr1, ptr2);
    cout << "\nSetelah tukar pointer:" << endl;
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
