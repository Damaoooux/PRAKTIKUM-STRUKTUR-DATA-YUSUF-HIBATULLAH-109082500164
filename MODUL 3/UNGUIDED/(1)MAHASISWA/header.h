#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilaiAkhir;
};

typedef Mahasiswa DataMahasiswa[MAX];
float hitungNilaiAkhir(float uts, float uas, float tugas);

void inputMahasiswa(DataMahasiswa &data, int &n);

void tampilMahasiswa(const DataMahasiswa &data, int n);

#endif
