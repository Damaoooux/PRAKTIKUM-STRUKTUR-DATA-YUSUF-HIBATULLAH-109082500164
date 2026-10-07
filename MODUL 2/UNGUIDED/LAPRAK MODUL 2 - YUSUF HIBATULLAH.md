# <h1 align="center">Laporan Praktikum Modul 2 - PENGENALAN BAHASA C++ (BAGIAN KEDUA) </h1>
<p align="center">YUSUF HIBATULLAH - 109082500164</p>

## Dasar Teori
C++ merupakan bahasa pemrograman yang banyak digunakan dalam pengembangan perangkat lunak karena mendukung berbagai konsep pemrograman, mulai dari pemrograman prosedural hingga pemrograman berorientasi objek. Dalam mempelajari dasar pemrograman C++, terdapat beberapa konsep penting yang perlu dipahami, di antaranya array, pointer, address, function, dan procedure. Array digunakan untuk menyimpan sekumpulan data dengan tipe yang sama, sedangkan pointer dan address berkaitan dengan pengelolaan serta lokasi data di dalam memori komputer. Sementara itu, function dan procedure digunakan untuk membagi program menjadi bagian-bagian yang lebih terstruktur sehingga kode lebih mudah dipahami, digunakan kembali, dan dikembangkan. Pemahaman terhadap konsep-konsep tersebut menjadi dasar penting dalam membuat program C++ yang terstruktur dan efisien.

### A. Array<br/>
Array merupakan struktur data yang digunakan untuk menyimpan sekumpulan nilai dengan tipe data yang sama dalam satu variabel. Setiap elemen di dalam array memiliki posisi tertentu yang disebut indeks. Dalam C++, indeks array dimulai dari angka 0, sehingga elemen pertama berada pada indeks 0, elemen kedua pada indeks 1, dan seterusnya. Penggunaan array mempermudah proses penyimpanan dan pengolahan data dalam jumlah banyak karena programmer tidak perlu membuat variabel secara terpisah untuk setiap nilai. Array dapat berbentuk satu dimensi maupun multidimensi, tergantung pada kebutuhan program. Array satu dimensi umumnya digunakan untuk menyimpan data dalam bentuk daftar, sedangkan array multidimensi dapat digunakan untuk merepresentasikan data dalam bentuk tabel atau matriks.

### B. Pointer<br/>
Pointer merupakan variabel khusus yang digunakan untuk menyimpan alamat memori dari variabel lain. Pointer memungkinkan programmer mengakses maupun memodifikasi nilai suatu variabel secara tidak langsung melalui alamat memorinya. Dalam C++, pointer dideklarasikan menggunakan simbol *, sedangkan simbol & dapat digunakan untuk memperoleh alamat memori suatu variabel. Pointer banyak digunakan dalam pengelolaan memori, struktur data dinamis, array, serta pengiriman data ke dalam function.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 10;
    int *ptr = &angka;

    cout << "Nilai angka: " << angka << endl;
    cout << "Nilai melalui pointer: " << *ptr << endl;

    return 0;
}
```
Pada program tersebut, ptr merupakan pointer yang menyimpan alamat memori dari variabel angka. Pernyataan &angka digunakan untuk memperoleh alamat memori variabel, sedangkan *ptr digunakan untuk mengakses nilai yang tersimpan pada alamat tersebut. Proses mengakses nilai melalui pointer disebut sebagai dereferencing.

### C. Adress<br/>
Address atau alamat memori merupakan lokasi tempat suatu data disimpan di dalam memori komputer. Setiap variabel yang dibuat dalam program akan menempati lokasi tertentu pada memori dan memiliki alamat yang dapat digunakan untuk mengidentifikasi lokasi tersebut. Dalam C++, alamat suatu variabel dapat diketahui menggunakan operator &. Konsep address memiliki hubungan yang erat dengan pointer karena pointer digunakan untuk menyimpan alamat memori dari variabel lain.

```C++
#include <iostream>
using namespace std;

int main() {
    int angka = 25;

    cout << "Nilai angka: " << angka << endl;
    cout << "Alamat angka: " << &angka << endl;

    return 0;
}
```
Pada contoh tersebut, angka merupakan variabel bertipe int yang memiliki nilai 25. Operator & pada &angka digunakan untuk memperoleh dan menampilkan alamat memori tempat variabel tersebut disimpan. Alamat yang ditampilkan dapat berbeda setiap kali program dijalankan karena pengaturan lokasi memori dilakukan oleh sistem.

### D. Function<br/>
Function atau fungsi merupakan bagian program yang berisi sekumpulan perintah untuk melakukan tugas tertentu dan dapat dipanggil dari bagian lain dalam program. Function umumnya dapat menerima parameter sebagai masukan dan menghasilkan suatu nilai melalui perintah return. Penggunaan function dapat mengurangi penulisan kode yang berulang dan membuat program menjadi lebih modular, terstruktur, serta mudah dipelihara.

```C++
#include <iostream>
using namespace std;

int tambah(int a, int b) {
    return a + b;
}

int main() {
    int hasil = tambah(5, 3);

    cout << "Hasil penjumlahan: " << hasil << endl;

    return 0;
}
```
Pada program tersebut, function tambah() menerima dua parameter bertipe int, yaitu a dan b. Kedua nilai tersebut dijumlahkan dan hasilnya dikembalikan menggunakan return. Function kemudian dipanggil pada bagian main() dengan memberikan nilai 5 dan 3 sebagai argumen.

### E. Procedure<br/>
Procedure atau prosedur merupakan bagian program yang digunakan untuk menjalankan serangkaian perintah tertentu tanpa mengembalikan suatu nilai. Dalam C++, procedure pada dasarnya dapat dibuat menggunakan function dengan tipe pengembalian void. Procedure dapat menerima parameter, tetapi tidak menggunakan return untuk menghasilkan nilai seperti pada function biasa. Penggunaan procedure bermanfaat untuk memisahkan tugas tertentu dari program utama sehingga struktur program menjadi lebih terorganisasi.

```C++
#include <iostream>
using namespace std;

void tampilkanPesan() {
    cout << "Selamat belajar C++!" << endl;
}

int main() {
    tampilkanPesan();

    return 0;
}
```
Pada contoh tersebut, tampilkanPesan() merupakan procedure karena menggunakan tipe void dan tidak mengembalikan suatu nilai. Ketika procedure tersebut dipanggil pada main(), program akan menjalankan perintah yang terdapat di dalamnya, yaitu menampilkan pesan ke layar.

## Guided 

### 1. Array 1

```C++
#include<iostream>
using namespace std;

int main(){
    int nilai[5];

    nilai[0] = 80;
    nilai[1] = 75;
    nilai[2] = 90;
    nilai[3] = 85;
    nilai[4] = 95;

    for (int i = 0; i < 5; i++){
        cout << "Nilai ke-" << i+1 << " = " << nilai[i] << endl;
    }

    return 0;
}
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
