# <h1 align="center">Laporan Praktikum Modul 4 -  SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Yusuf Hibatullah - 109082500164</p>

## Dasar Teori
Linked list (biasa disebut list saja) adalah salah satu bentuk struktur data (representasi penyimpanan) berupa serangkaian elemen data yang saling berkait (berhubungan) dan bersifat fleksibel karena dapat tumbuh dan mengerut sesuai kebutuhan. Data yang disimpan dalam Linked list bisa berupa data tunggal atau data majemuk. Data tunggal merupakan data yang hanya terdiri dari satu data (variabel), misalnya: nama bertipe string. Sedangkan data majemuk  merupakan sekumpulan data (record) yang di dalamnya terdiri dari berbagai tipe data, misalnya: Data Mahasiswa, terdiri dari Nama bertipe string, NIM bertipe long integer, dan Alamat bertipe string.  
Dalam implementasinya, pengaksesan elemen pada Linked list dengan pointer bisa menggunakan  (->) atau tanda titik (.). 

Setiap node pada singly linked list terdiri dari dua bagian, yaitu bagian info yang menyimpan data, dan bagian next yang berisi alamat node selanjutnya. Linked list sendiri dikelola melalui sebuah penunjuk bernama First (atau Head) yang menunjuk ke node pertama. Node terakhir memiliki next bernilai Nil (NULL) sebagai penanda akhir list. Apabila First bernilai Nil, berarti list dalam keadaan kosong. Seperti pada program yang telah dibuat, tipe ElmList merepresentasikan node, sedangkan tipe List menyimpan pointer First.

Terdapat beberapa jenis linked list. Singly linked list hanya memiliki satu pointer per node sehingga penelusuran hanya bisa dilakukan satu arah, dari depan ke belakang. Doubly linked list memiliki dua pointer, next dan prev, sehingga dapat ditelusuri dua arah. Sementara itu, circular linked list adalah bentuk di mana node terakhir menunjuk kembali ke node pertama, sehingga membentuk lingkaran dan tidak ada pointer yang bernilai Nil.

Operasi dasar pada linked list meliputi pembuatan list (createList), alokasi dan dealokasi node (alokasi dan dealokasi), penyisipan (insert), penghapusan (delete), penelusuran (traversal), dan pencarian (search). Penyisipan dapat dilakukan di awal (insertFirst), di akhir (insertLast), atau setelah node tertentu (insertAfter). Penghapusan juga mengikuti pola yang sama, yaitu deleteFirst, deleteLast, dan deleteAfter. Dalam setiap operasi, urutan pengaturan pointer sangat penting. Kesalahan dalam mengubah pointer dapat menyebabkan node di belakangnya hilang dari jangkauan atau terjadi kebocoran memori (memory leak).

Keunggulan linked list adalah ukurannya yang fleksibel, penggunaan memori yang efisien karena hanya mengalokasikan node sesuai kebutuhan, serta proses penyisipan dan penghapusan yang mudah tanpa perlu menggeser elemen lain. Kelemahannya adalah memerlukan memori tambahan untuk menyimpan pointer pada setiap node, tidak mendukung akses acak, dan pengelolaan pointer yang lebih rumit sehingga rentan terhadap kesalahan. Karena karakteristik tersebut, linked list banyak dimanfaatkan sebagai dasar implementasi struktur data lain seperti stack, queue, dan graf, serta pada aplikasi yang sering melakukan perubahan data secara dinamis.

## Guided 

### 1. list.h

```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<Iostream>
using namespace std;

struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node{
    dataMahasiswa isidata;
    address next;
};

struct linkedList{
    address first;
};

bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodeBaru);
void insertAfter(linkedList &List, address nodeBaru, address prev);
void insertLast(linkedList &List, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList List);
void deleteList(linkedList &List);
#endif
```

### 2. list.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

// I.S - Initial State / kondisi awal
// F.S - Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node pertama di list terhapus */
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "list kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, Prev alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next, menghapus Prev->next dari list */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedList List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama : " << nodeBantu->isidata.nama
                 << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node dalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list */
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

### 3. main.cpp

```C++

#include "list.h"

#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Single Linked List ini digunakan untuk mengelola data mahasiswa (nama, NIM, dan umur) secara dinamis. Struktur dasarnya dibangun oleh mahasiswa untuk data, node untuk menghubungkan antar-elemen, dan linkedList yang mencatat node pertama (first). Operasi dasar program mencakup pembuatan list kosong, alokasi node baru, dan dealokasi memori. Penambahan data dapat dilakukan di awal (insertFirst), di akhir (insertLast), atau di tengah (insertAfter), sedangkan penghapusan data menyediakan fungsi delFirst, delLast, delAfter, dan deleteList untuk mengosongkan seluruh list. Selain itu, terdapat fungsi printList untuk menampilkan data dan nbList untuk menghitung jumlah node.

alur program diawali dengan membuat list kosong dan mengalokasikan lima data mahasiswa. Kelima data tersebut dimasukkan ke dalam list menggunakan berbagai metode insert, lalu ditampilkan isi dan jumlah nodenya. Selanjutnya, program menguji fungsi penghapusan (delFirst, delLast, dan delAfter) untuk menghapus sebagian data, dilanjutkan dengan memanggil deleteList untuk menghapus seluruh elemen hingga list kembali kosong.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”, Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”.

### singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};


void createList(List &L);
address alokasi(infotype X);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

### singlylist.cpp
```C++
#include <iostream>
#include "singlylist.h"
using namespace std;


void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype X) {
    address P = new ElmList;

    P->info = X;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }

    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
```

### main.cpp
```C++
#include <iostream>
#include "singlylist.h"

using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%204/UNGUIDED/SOAL1/output1.png)

File singlylist.h berisi deklarasi: tipe data infotype (int), pointer address yang menunjuk ke struktur ElmList (elemen berisi info dan pointer next), serta struktur List yang menyimpan pointer First sebagai penanda elemen pertama. Di dalamnya juga terdapat konstanta Nil (NULL) dan prototipe lima fungsi dasar.

File singlylist.cpp berisi implementasi fungsi-fungsinya. createList menginisialisasi list kosong dengan mengisi First dengan Nil. alokasi membuat elemen baru secara dinamis dengan new, mengisi nilai info, dan mengatur next ke Nil. dealokasi menghapus elemen dari memori dengan delete lalu mengembalikan pointernya ke Nil. insertFirst menyisipkan elemen di awal list dengan mengarahkan next elemen baru ke elemen pertama saat ini, kemudian menjadikannya First. printInfo menelusuri list dari elemen pertama sampai Nil sambil mencetak setiap nilai info.

File main.cpp adalah program utama yang menguji ADT tersebut. List dibuat, lalu lima elemen dialokasikan dengan nilai 2, 0, 8, 12, dan 9, masing-masing disisipkan di awal list menggunakan insertFirst. Karena setiap elemen baru ditaruh di depan, urutan list menjadi kebalikan dari urutan penyisipan, sehingga output yang tercetak adalah 9 12 8 0 2. 

### 2. Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

##
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
