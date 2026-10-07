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

### C. Address<br/>
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

### 1. Array 1 Dimensi

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
Kode C++ di atas bertujuan untuk menyimpan lima data nilai ke dalam sebuah array satu dimensi bernama nilai yang berkapasitas lima elemen bertipe data integer. Program pertama-tama mengisikan masing-masing data nilai secara manual mulai dari indeks ke-0 hingga indeks ke-4, lalu memanfaatkan perulangan for untuk mengakses dan menampilkan setiap elemen tersebut ke layar.

### 2. Array 2 Dimensi

```C++
#include <iostream>
using namespace std;

int main(){
    int nilai[3][3] = {
        {80, 75, 90},
        {85, 95,88},
        {70, 80, 85}
    };

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << nilai[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << nilai[1][2] << endl; 
    return 0;
}
```
Program langsung menginisialisasi array dengan 3 baris dan 3 kolom data nilai. Selanjutnya, perulangan for bersarang (nested loop) digunakan untuk mencetak seluruh isi matriks ke layar, di mana baris dicetak secara berurutan dan dipisahkan oleh spasi serta baris baru. Di bagian akhir, program mengakses dan menampilkan elemen pada indeks baris ke-1 dan kolom ke-2 (nilai[1][2]), yang menghasilkan nilai 88 (karena indeks array dimulai dari angka 0).

### 3. Array 3 Dimensi

```C++
#include<iostream>
using namespace std;

int main(){
    int data[2][2][3] = {
        {
            {10, 20, 30},
            {40, 50, 60}
        },
        {
            {70, 80, 90},
            {100, 110, 120}
        }
    };

    cout << data[0][1][2] << endl;
    return 0;
}
```
Program di atas bertujuan untuk menyimpan dan mengakses kumpulan angka menggunakan array tiga dimensi bertipe int bernama data dengan ukuran 2 x 2 x 3 (2 blok, 2 baris, dan 3 kolom).

Setelah array diinisialisasi dengan kumpulan nilai, program secara spesifik mengakses dan mencetak satu elemen menggunakan indeks data[0][1][2]. Elemen ini merujuk pada blok pertama (indeks 0), baris kedua (indeks 1), dan kolom ketiga (indeks 2), sehingga nilai yang ditampilkan ke layar adalah 60.

### 4. Alamat/Address

```C++
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
```
Program mendeklarasikan variabel angka dengan nilai 100 dan sebuah pointer bertipe integer bernama pointer. Melalui perintah pointer = &angka, alamat memori dari variabel angka disimpan ke dalam variabel pointer tersebut. Saat dijalankan, program menampilkan nilai asli variabel angka (100), alamat memorinya dalam format heksadesimal (&angka), isi dari variabel pointer yang merekam alamat memori tersebut (pointer), serta nilai yang ditunjuk oleh pointer menggunakan proses dereferensi (*pointer) yang juga menghasilkan nilai 100.

### 5. Pointer

```C++
#include <iostream>
using namespace std;

int main(){
    char arr[6];

    arr[0]= 'a';
    arr[1]= 'b';
    arr[2]= 'c';
    arr[3]= 'b';
    arr[4]= 'd';
    arr[5]= 'e';

    cout << arr[3] << endl;
    cout << &(arr[4]) << endl;

    return 0;
}
```
Setelah array diisi dengan karakter 'a' hingga 'e', program pertama-tama mencetak karakter pada indeks ke-3 (arr[3]), yaitu huruf 'b'. Selanjutnya, perintah &(arr[4]) digunakan untuk mengambil alamat memori elemen indeks ke-4 (huruf 'd'). Namun, karena cout memperlakukan pointer char* sebagai string berbasis C (C-style string), perintah tersebut akan mencetak seluruh karakter mulai dari indeks ke-4 hingga menemukan karakter netral.

### 6. Function

```C++
#include<iostream>
using namespace std;

int maks3(int a, int b, int c){
   int temp_max = a;
   if(b > temp_max){
      temp_max = b;
   }
    if(c > temp_max){
        temp_max = c;
    }
    return temp_max;
}

int main(){
    int x, y, z;

    cout << "Masukkan nlai 1 : ";
    cin >> x;

    cout << "Masukkan nlai 2 : ";
    cin >> y;

    cout << "Masukkan nlai 3 : ";
    cin >> z;

    cout << "Nilai Maksimum adalah : " << maks3(x, y, z) << endl;
    return 0;
}
```
Program mendefinisikan fungsi maks3 yang menerima tiga parameter bertipe integer (a, b, c). Di dalam fungsi tersebut, nilai a dijadikan sebagai acuan awal nilai maksimum (temp_max), lalu dibandingkan secara bertahap dengan b dan c untuk memperbarui nilai terbesar sebelum dikembalikan (return). Pada fungsi utama (main), pengguna diminta memasukkan tiga nilai yang disimpan ke dalam variabel x, y, dan z, yang kemudian dikirim ke fungsi maks3 untuk mencetak nilai maksimumnya ke layar.

### 7. Procedure

```C++
#include <iostream>
using namespace std;

void sapa(){
    cout << "Hello World" << endl;
}

int main() {
    sapa();
    return 0;
}
```
Program mendefinisikan fungsi bernama sapa dengan tipe void, yang berarti fungsi ini hanya bertugas menjalankan perintah di dalamnya—yaitu mencetak teks "Hello World"—tanpa mengembalikan nilai apa pun (no return value). Pada fungsi utama (main), fungsi sapa() dipanggil satu kali sehingga pesan "Hello World" berhasil ditampilkan ke layar saat program dijalankan.

### 8. Call By Value/Pointer/Reference

```C++
#include<iostream>
using namespace std;

void tukar(int &x, int &y){
    int temp;
    temp= x;
    x = y;
    y = temp;
}

int main(){
    int a = 4;
    int b = 6;

    cout << "Sebelum ditukar : " << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;

    tukar(a, b);

    cout << "Setelah ditukar : " << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;

    return 0;
}
```
Program mendefinisikan fungsi tukar yang menerima dua parameter bertipe integer yang melekat pada acuan memori (int &x dan int &y). Fungsi ini menggunakan variabel bantuan temp untuk menukar isi dari variabel yang dikirimkan. Di dalam fungsi main, program mendeklarasikan variabel a = 4 dan b = 6, mencetak nilainya sebelum ditukar, lalu memanggil fungsi tukar(a, b). Karena perubahan dilakukan langsung pada alamat memori asli melalui pass by reference, nilai variabel a dan b secara permanen berubah menjadi a = 6 dan b = 4 setelah pemanggilan fungsi.

## Unguided 

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 

```C++
#include <iostream>
using namespace std;

int main() {
    int A[3][3], B[3][3];
    int jumlah[3][3], kurang[3][3], kali[3][3];

    // MATRIX A //
    cout << "Masukkan elemen Matriks A (3x3):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }

    // MATRIX B
    cout << "\nMasukkan elemen Matriks B (3x3):" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "B[" << i << "][" << j << "] = ";
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jumlah[i][j] = A[i][j] + B[i][j];
            kurang[i][j] = A[i][j] - B[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            kali[i][j] = 0;

            for (int k = 0; k < 3; k++) {
                kali[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nMatriks A:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nMatriks B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Penjumlahan A + B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << jumlah[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Pengurangan A - B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << kurang[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nHasil Perkalian A x B:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << kali[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal1.0.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal1.1.png)

Program C++ tersebut digunakan untuk melakukan tiga jenis operasi pada dua buah matriks berukuran 3×3, yaitu penjumlahan, pengurangan, dan perkalian matriks. Program terlebih dahulu meminta pengguna memasukkan sembilan elemen untuk Matriks A dan sembilan elemen untuk Matriks B menggunakan perulangan for bersarang. Hasil penjumlahan diperoleh dengan menjumlahkan elemen A dan B pada posisi yang sama, sedangkan hasil pengurangan diperoleh dengan mengurangkan elemen Matriks B dari Matriks A pada posisi yang sama. Untuk perkalian matriks, program menggunakan tiga perulangan for, di mana setiap elemen hasil dihitung dari jumlah perkalian elemen pada baris Matriks A dengan elemen pada kolom Matriks B yang bersesuaian. Setelah seluruh proses selesai, program menampilkan Matriks A, Matriks B, serta hasil penjumlahan, pengurangan, dan perkalian dalam bentuk matriks 3×3. 

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel 

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal2.png)

Program C++ tersebut digunakan untuk menukar nilai dari tiga variabel menggunakan reference. Pada awal program, variabel a, b, dan c masing-masing memiliki nilai 4, 6, dan 8. Fungsi tukar() menerima ketiga variabel menggunakan parameter reference (&), sehingga perubahan yang dilakukan di dalam fungsi akan langsung memengaruhi variabel asli. Variabel sementara temp digunakan untuk menyimpan nilai x sebelum proses pertukaran dilakukan. Proses pertukaran menghasilkan x menerima nilai y, y menerima nilai z, dan z menerima nilai awal x. Dengan demikian, setelah fungsi tukar() dijalankan, nilai a menjadi 6, b menjadi 8, dan c menjadi 4.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut : arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55} Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case

```C++
#include <iostream>
using namespace std;

int cariMinimum(int arr[], int n) {
    int minimum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minimum) {
            minimum = arr[i];
        }
    }

    return minimum;
}

int cariMaksimum(int arr[], int n) {
    int maksimum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maksimum) {
            maksimum = arr[i];
        }
    }

    return maksimum;
}

void hitungRataRata(int arr[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        total += arr[i];
    }

    float rataRata = (float) total / n;
    cout << "Nilai rata-rata = " << rataRata << endl;
}

int main() {
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int n = 10;
    int pilihan;

    do {
        cout << "\n--- Menu Program Array ---" << endl;
        cout << "1. Tampilkan isi array" << endl;
        cout << "2. Cari nilai maksimum" << endl;
        cout << "3. Cari nilai minimum" << endl;
        cout << "4. Hitung nilai rata-rata" << endl;
        cout << "5. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "Isi array: ";
                for (int i = 0; i < n; i++) {
                    cout << arrA[i] << " ";
                }
                cout << endl;
                break;

            case 2:
                cout << "Nilai maksimum = "
                     << cariMaksimum(arrA, n) << endl;
                break;

            case 3:
                cout << "Nilai minimum = "
                     << cariMinimum(arrA, n) << endl;
                break;

            case 4:
                hitungRataRata(arrA, n);
                break;

            case 5:
                cout << "Program selesai." << endl;
                break;

            default:
                cout << "Pilihan tidak tersedia!" << endl;
        }

    } while (pilihan != 5);

    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal3.0.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal3.1.png)

##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal3.2.png)

##### Output 4
![Screenshot Output Unguided 3_3](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%202/UNGUIDED/Output_Soal3.3.png)

Program C++ tersebut digunakan untuk mengolah data dalam sebuah array yang berisi 10 bilangan bulat. Program menyediakan menu yang memungkinkan pengguna untuk menampilkan seluruh isi array, mencari nilai maksimum, mencari nilai minimum, menghitung nilai rata-rata, atau keluar dari program. Pencarian nilai minimum dan maksimum dilakukan melalui fungsi cariMinimum() dan cariMaksimum() dengan membandingkan setiap elemen array, sedangkan fungsi hitungRataRata() menjumlahkan seluruh elemen kemudian membaginya dengan jumlah data. Pemilihan menu menggunakan struktur switch-case dan diulang dengan perulangan do-while sampai pengguna memilih opsi keluar. Berdasarkan data array {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}, diperoleh nilai maksimum 55, nilai minimum 3, dan nilai rata-rata 21,4.

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa bahasa C++ memiliki berbagai konsep dasar yang dapat digunakan untuk menyelesaikan permasalahan pemrograman secara terstruktur. Melalui program operasi matriks, dapat dipahami penggunaan array dua dimensi dan perulangan dalam melakukan pengolahan data. Program pertukaran tiga variabel memberikan pemahaman mengenai penggunaan fungsi dan reference untuk mengubah nilai variabel secara langsung. Sementara itu, program pengolahan array menunjukkan penerapan array, fungsi, perulangan, percabangan, serta switch-case dalam membuat program berbasis menu. Secara keseluruhan, praktikum ini memberikan pemahaman mengenai dasar-dasar C++ seperti variabel, array, fungsi, reference, percabangan, dan perulangan yang menjadi dasar dalam membuat program yang lebih kompleks.

