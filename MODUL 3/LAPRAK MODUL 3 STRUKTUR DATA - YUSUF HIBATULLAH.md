# <h1 align="center">Laporan Praktikum Modul 3 - ABSTRACT DATA TYPE (ADT)</h1>
<p align="center">YUSUF HIBATULLAH - 109082500164</p>

## Dasar Teori
ADT adalah TYPE dan sekumpulan PRIMITIF (operasi dasar) terhadap TYPE tersebut. Selain itu, dalam
sebuah ADT yang lengkap, disertakan pula definisi invarian dari TYPE dan aksioma yang berlaku. ADT
merupakan definisi STATIK.

Definisi type dari sebuah ADT dapat mengandung sebuah definisi ADT lain. Misalnya :

<ol>
    <li>ADT waktu yang terdiri dari ADT JAM dan ADT DATE</li>
    <li>Garis terdiri dari duah buah ADT POINT</li>
</ol>

SEGI4 yang terdiri dari pasangan dua buah POINT (Top,Left) dan (Bottom,Right)
TYPE diterjemahkan menjadi type terdefinisi dalam bahasa yang bersangkutan. Jika dalam bahasa C
menggunakan struct PRIMITIF, dalam konteks prosedural, diterjemahkan menjadi fungsi atau
prosedur. PRIMITIF dikelompokan menjadi:

<ol>
    <li>Konstruktor/Kreator</li>
    <li>Selector</li>
    <li>Prosedur pengubah nilai komponen</li>
    <li>Tipe validator komponen</li>
    <li>Destruktor/Dealokator</li>
    <li>Baca/Tulis</li>
    <li>Operator relasional</li>
    <li>Aritmatika terhadap tipe tersebut, karena biasanya aritmatika dalam bahasa C hanya terdefinisi untuk bilangan numerik.</li>
    <li>Konversi dari tipe tersebut ke tipe dasar dan sebaliknya.</li>
</ol>

ADT biasanya diimplementasikan menjadi dua buah modul utama dan 1 modul interface program
utama (driver). Dua modul tersebut adalah sebagai berikut:

<ol>
    <li>Definisi/Spesifikasi Type dan Primitif/Header fungsi (.h)</li>
    <li>Body/realisasi dari primitif (.c)</li>
</ol>

Untuk menerapkan konsep ADT, kita harus memisah deklarasi tipe, variabel, dan fungsi dari program ke dalam sebuah <b>file.h</b> dan memisah definisi fungsi dari program ke sebuah <b>file.cpp</b>

## Guided 

### mahasiswa.h

```C++
#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED

struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);
#endif
```

### mahasiswa.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m) {
    cout << "Masukkan NIM: ";
    cin >> (m).nim;
    cout << "Masukkan Nilai 1: ";
    cin >> (m).nilai1;
    cout << "Masukkan Nilai 2: ";
    cin >> (m).nilai2;
}

float rata2(mahasiswa m) {
    return float((m).nilai1 + (m).nilai2) / 2;
}
```

### main.cpp

```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

int main() {
    mahasiswa mhs;
    inputMhs(mhs);
    cout << "Rata-rata nilai: " << rata2(mhs) << endl;
    return 0;
}
```
Program ini menerapkan konsep Abstract Data Type (ADT) dalam bahasa C++ dengan memisahkan program menjadi tiga file, yaitu mahasiswa.h, mahasiswa.cpp, dan main.cpp. File mahasiswa.h berfungsi untuk mendefinisikan struktur data mahasiswa yang terdiri dari NIM dan dua nilai, serta mendeklarasikan fungsi yang digunakan. File mahasiswa.cpp berisi implementasi prosedur inputMhs() untuk memasukkan data mahasiswa dan fungsi rata2() untuk menghitung rata-rata dari kedua nilai. Sementara itu, file main.cpp berfungsi sebagai program utama yang memanggil prosedur dan fungsi tersebut untuk menerima input serta menampilkan hasil perhitungan rata-rata.

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3*uts+0.4*uas+0.3*tugas

#### header.h

```C++
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
```

#### body.cpp

```C++
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
```

#### main.cpp

```C++
#include "header.h"
int main() {
    DataMahasiswa data;
    int n = 0;

    inputMahasiswa(data, n);
    tampilMahasiswa(data, n);

    return 0;
}
```

#### Output Unguided 1 :
![Screenshot Output Unguided 1_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%203/UNGUIDED/(1)MAHASISWA/OUTPUT1.png)

Program dibagi menjadi tiga file, yaitu header.h, body.cpp, dan main.cpp. File header.h berfungsi untuk mendefinisikan struktur data mahasiswa yang terdiri dari nama, NIM, nilai UTS, UAS, tugas, dan nilai akhir, serta mendeklarasikan fungsi dan prosedur yang digunakan. File body.cpp berisi implementasi fungsi hitungNilaiAkhir() yang menghitung nilai akhir berdasarkan bobot 30% UTS, 40% UAS, dan 30% tugas, serta prosedur inputMahasiswa() untuk memasukkan data dan tampilMahasiswa() untuk menampilkan hasilnya. Sementara itu, file main.cpp berfungsi sebagai program utama yang memanggil kedua prosedur tersebut. Cara kerja program dimulai dengan meminta jumlah mahasiswa, kemudian memvalidasi agar jumlahnya tidak melebihi 10. Selanjutnya, pengguna memasukkan data setiap mahasiswa melalui perulangan, dan program secara otomatis menghitung nilai akhirnya. Setelah seluruh data dimasukkan, program menampilkan informasi mahasiswa beserta nilai akhirnya dalam bentuk tabel. 

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file “pelajaran.h”, Buatlah implementasi ADT pelajaran pada file “pelajaran.cpp” dan Cobalah hasil implementasi ADT pada file “main.cpp”!

#### pelajaran.h

```C++

#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
#include <string>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran create_pelajaran(string namapel, string kodepel);
void tampil_pelajaran(pelajaran pel);
#endif
```

#### pelajaran.cpp

```C++
#include "pelajaran.h"

pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
```

#### main.cpp

```C++

#include "pelajaran.h"
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

#### Output Unguided 2 :
![Screenshot Output Unguided 2_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%203/UNGUIDED/(2)PELAJARAN/OUTPUT2.png)

File pelajaran.h berfungsi untuk mendefinisikan struktur data pelajaran yang terdiri dari nama dan kode mata pelajaran, serta mendeklarasikan fungsi dan prosedur yang digunakan. File pelajaran.cpp berisi implementasi fungsi create_pelajaran() untuk membuat dan mengisi data mata pelajaran, serta prosedur tampil_pelajaran() untuk menampilkan informasi tersebut. Sementara itu, file main.cpp berfungsi sebagai program utama yang menginisialisasi nama mata pelajaran "Struktur Data" dan kode "STD". Cara kerja program dimulai dengan membuat variabel nama dan kode mata pelajaran, kemudian memanggil fungsi create_pelajaran() untuk menyimpan kedua data tersebut ke dalam struktur pelajaran. Selanjutnya, prosedur tampil_pelajaran() dipanggil untuk menampilkan nama dan kode mata pelajaran ke layar.

### Buatlah program dengan ketentuan berikut:

<ol>
    <li>2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer</li>
    <li>fungsi/prosedur yang menampilkan isi sebuah array integer 2D</li>
    <li>fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu</li>
    <li>fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer</li>
</ol>

#### array.h

```C++
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
using namespace std;
typedef int Matriks[3][3];
void tampilArray(Matriks &arr);
void tukarArray(Matriks &arr1, Matriks &arr2, int baris, int kolom);
void tukarPointer(int *ptr1, int *ptr2);
#endif
```

#### array.cpp

```C++
#include "array.h"
void tampilArray(Matriks &arr) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarArray(Matriks &arr1, Matriks &arr2, int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int *ptr1, int *ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
```

#### array.cpp

```C++
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
```

#### Output Unguided 3 :
![Screenshot Output Unguided 3_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%203/UNGUIDED/(3)ARRAY/OUTPUT3.png)

File array.h berfungsi untuk mendefinisikan tipe data matriks berukuran 3×3 menggunakan typedef serta mendeklarasikan prosedur yang digunakan. File array.cpp berisi implementasi prosedur tampilArray() untuk menampilkan isi matriks, tukarArray() untuk menukar elemen pada posisi tertentu dari dua matriks, dan tukarPointer() untuk menukar nilai variabel melalui pointer. Cara kerja program dimulai dengan menginisialisasi dua matriks berukuran 3×3 serta dua variabel integer bernilai 10 dan 20 yang alamatnya disimpan dalam pointer. Selanjutnya, program menampilkan kedua matriks sebelum melakukan pertukaran elemen pada indeks [0][0], kemudian menampilkan hasil pertukarannya. Setelah itu, program menggunakan pointer untuk menukar nilai kedua variabel sehingga nilai a menjadi 20 dan b menjadi 10. 

## Kesimpulan
Berdasarkan hasil praktikum yang telah dilakukan, dapat disimpulkan bahwa Abstract Data Type (ADT) merupakan konsep dalam pemrograman yang digunakan untuk mengorganisasi struktur data beserta operasi yang dapat dilakukan terhadap data tersebut. Penerapan ADT dalam bahasa C++ memungkinkan program dibagi menjadi beberapa file, yaitu header file (.h) untuk mendefinisikan struktur data dan deklarasi fungsi atau prosedur, body file (.cpp) untuk mengimplementasikan fungsi atau prosedur, serta main file (.cpp) sebagai program utama.

Penggunaan ADT dapat membuat program menjadi lebih terstruktur, modular, mudah dipahami, serta mempermudah proses pengembangan, pengujian, dan pemeliharaan kode karena setiap bagian program memiliki fungsi dan tanggung jawab yang jelas.
