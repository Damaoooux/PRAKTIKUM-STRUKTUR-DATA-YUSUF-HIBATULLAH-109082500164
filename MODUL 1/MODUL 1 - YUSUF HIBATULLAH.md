# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahasa C++ (Bagian Pertama)</h1>
<p align="center">Yusuf Hibatullah - 109082500164</p>

## Dasar Teori
C++ merupakan bahasa pemrograman tingkat tinggi yang dikembangkan dari bahasa C dengan penambahan berbagai fitur, termasuk dukungan terhadap pemrograman berorientasi objek (Object-Oriented Programming). Bahasa C++ memiliki karakteristik berupa performa yang tinggi, fleksibilitas dalam pengelolaan sumber daya, serta kemampuan untuk mengembangkan berbagai jenis perangkat lunak. Oleh karena itu, C++ banyak digunakan dalam pembelajaran dasar pemrograman maupun pengembangan aplikasi yang membutuhkan efisiensi tinggi.

Struktur dasar program C++ umumnya terdiri atas pustaka (header), fungsi utama main(), deklarasi variabel, serta sejumlah pernyataan yang membentuk alur program. C++ menyediakan berbagai tipe data seperti int, float, double, char, dan bool untuk merepresentasikan jenis data yang berbeda. Selain itu, bahasa ini menyediakan operator aritmatika, relasional, dan logika yang digunakan dalam proses pengolahan data dan pembentukan ekspresi.

Dalam proses interaksi dengan pengguna, C++ menyediakan fasilitas masukan dan keluaran melalui pustaka iostream. Objek cin digunakan untuk menerima masukan, sedangkan cout digunakan untuk menampilkan keluaran. C++ juga mendukung struktur kontrol berupa percabangan dan perulangan untuk mengatur alur eksekusi program. Pemahaman terhadap struktur program, tipe data, variabel, operator, serta mekanisme masukan dan keluaran menjadi dasar penting dalam mempelajari dan mengembangkan program menggunakan bahasa C++.


## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include<iostream>
using namespace std;


int main(){
 float a,b;
 float penjumlahan;
 float pengurangan;
 float perkalian;
 float pembagian;

 cout<<"Masukkan nilai a: ";
 cin>>a;
 cout<<"Masukkan nilai b: ";
 cin>>b;

//Penjumlahan
penjumlahan = a + b;
cout<<"Hasil penjumlahan a dan b: "<<penjumlahan<<endl;

//pengurangan
pengurangan = a - b;
cout<<"Hasil pengurangan a dan b: "<<pengurangan<<endl;

//perkalian
perkalian = a * b;
cout<<"Hasil perkalian a dan b: "<<perkalian<<endl;

//pembagian
if (b == 0) {
    cout << "Error: Pembagian dengan nol tidak diperbolehkan." << endl;
} else {
pembagian = a / b;
cout<<"Hasil pembagian a dan b: "<<pembagian<<endl;
}

 return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%201/output/Output%20Unguided-1.png)


##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%201/output/Output%20Unguided-1%20(2).png)

Pengguna diminta memasukkan dua nilai, yaitu a dan b, dengan tipe data float agar program dapat menerima bilangan desimal. Selanjutnya, program menghitung dan menampilkan hasil dari setiap operasi tersebut. Khusus pada operasi pembagian, digunakan percabangan if-else untuk memastikan nilai b tidak sama dengan nol, karena pembagian dengan nol tidak diperbolehkan. Jika b bernilai nol, program akan menampilkan pesan kesalahan.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%201/output/Output%20Unguided-2.png)


program dibuat untuk menerima input berupa bilangan bulat positif dari 0 sampai 100, kemudian mengubah nilai angka tersebut menjadi bentuk tulisan. Program menggunakan percabangan untuk membedakan angka satuan, bilangan khusus seperti sepuluh, sebelas, dan seratus, serta bilangan belasan dan puluhan.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output:" << endl;
    for (int i = n; i >= 0; i--) {
        for (int s = n; s > i; s--) {
            cout << "  ";
        }
        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }
        cout << "*";
        for (int j = 1; j <= i; j++) {
            cout << " " << j;
        }
        cout << endl;
    }
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%201/output/Output%20Unguided-3.png)

program dibuat untuk menghasilkan pola mirror (cermin) berdasarkan angka yang dimasukkan oleh pengguna. Program menggunakan perulangan bersarang (nested loop) untuk mengatur jumlah spasi dan angka pada setiap baris.

## Kesimpulan
Berdasarkan keseluruhan latihan yang telah dilakukan, dapat disimpulkan bahwa pengenalan dasar bahasa C++ mencakup pemahaman mengenai struktur program, penggunaan variabel dan tipe data, proses input dan output, operator aritmatika, percabangan, serta perulangan.


