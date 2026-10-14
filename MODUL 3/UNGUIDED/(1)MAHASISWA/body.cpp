#include "header.h"
#include <iomanip>

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputMahasiswa(DataMahasiswa &data, int &n) {
    cout << "Masukkan jumlah mahasiswa (max 10): ";
    cin >> n;

    if (n < 1 || n > MAX) {
        cout << "Jumlah mahasiswa tidak valid!" << endl;
        n = 0;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama  : ";
        cin >> ws;
        getline(cin, data[i].nama);
        cout << "NIM   : ";
        cin >> data[i].nim;
        cout << "UTS   : ";
        cin >> data[i].uts;
        cout << "UAS   : ";
        cin >> data[i].uas;
        cout << "Tugas : ";
        cin >> data[i].tugas;

        data[i].nilaiAkhir = hitungNilaiAkhir(
            data[i].uts,
            data[i].uas,
            data[i].tugas
        );
    }
}

void tampilMahasiswa(const DataMahasiswa &data, int n) {
    cout << "\n===== DATA MAHASISWA =====" << endl;
    cout << left
         << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "NIM"
         << setw(10) << "UTS"
         << setw(10) << "UAS"
         << setw(10) << "Tugas"
         << setw(12) << "Nilai Akhir"
         << endl;
    cout << string(82, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << left << fixed << setprecision(2)
             << setw(5) << i + 1
             << setw(20) << data[i].nama
             << setw(15) << data[i].nim
             << setw(10) << data[i].uts
             << setw(10) << data[i].uas
             << setw(10) << data[i].tugas
             << setw(12) << data[i].nilaiAkhir
             << endl;
    }
}
