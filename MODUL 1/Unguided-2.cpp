#include <iostream>
#include <string>
using namespace std;

int main() {
    int angka;
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat",
        "lima", "enam", "tujuh", "delapan", "sembilan"
    };

    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka < 0 || angka > 100) {
        cout << "Angka harus berada antara 0 sampai 100.";
    }
    else if (angka < 10) {
        cout << satuan[angka];
    }
    else if (angka == 10) {
        cout << "sepuluh";
    }
    else if (angka == 11) {
        cout << "sebelas";
    }
    else if (angka < 20) {
        cout << satuan[angka - 10] << " belas";
    }
    else if (angka < 100) {
        int puluhan = angka / 10;
        int sisa = angka % 10;

        cout << satuan[puluhan] << " puluh";

        if (sisa != 0) {
            cout << " " << satuan[sisa];
        }
    }
    else {
        cout << "seratus";
    }

    cout << endl;

    return 0;
}