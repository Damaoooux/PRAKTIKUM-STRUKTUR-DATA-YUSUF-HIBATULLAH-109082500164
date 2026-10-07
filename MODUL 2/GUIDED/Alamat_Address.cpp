#include <iostream>
using namespace std;

int main(){
    int angka = 100;
    int *pointer;

    pointer = &angka;
    cout << "Nilai Angka        = " << angka << endl;
    cout << "Alamat Angka       = " << &angka << endl;
    cout << "Isi Pointer        = " << pointer << endl;
    cout << "Nilai Pointer      = " << *pointer << endl;

    return 0;
}