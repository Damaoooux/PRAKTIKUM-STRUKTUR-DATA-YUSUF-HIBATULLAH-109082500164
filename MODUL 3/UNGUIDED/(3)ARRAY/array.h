#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;
typedef int Matriks[3][3];
void tampilArray(Matriks &arr);
void tukarArray(Matriks &arr1, Matriks &arr2, int baris, int kolom);
void tukarPointer(int *ptr1, int *ptr2);
#endif
