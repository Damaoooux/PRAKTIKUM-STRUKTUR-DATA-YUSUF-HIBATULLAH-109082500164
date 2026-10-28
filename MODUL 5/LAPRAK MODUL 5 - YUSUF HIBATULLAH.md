# <h1 align="center">Laporan Praktikum Modul 5 - SINGLY LINKED LIST (BAGIAN KEDUA)</h1>
<p align="center">YUSUF HIBATULLAH - 109082500164</p>

## Dasar Teori
Linked list adalah salah satu struktur data dinamis yang terdiri dari sekumpulan elemen yang saling terhubung melalui pointer. Berbeda dengan array yang menyimpan data pada blok memori yang berurutan dan berukuran tetap, linked list menyimpan data pada elemen-elemen yang dapat tersebar di memori, dan ukurannya dapat bertambah atau berkurang selama program berjalan. Setiap elemen pada linked list disebut node, dan hubungan antarnode dibangun dengan menyimpan alamat node berikutnya di dalam node sebelumnya.

Single linked list adalah jenis linked list yang setiap elemennya hanya memiliki satu pointer, yaitu pointer next yang menunjuk ke elemen sesudahnya. Setiap elemen terdiri dari dua bagian, yaitu info yang berisi data yang disimpan dan next yang berisi alamat elemen berikutnya. Elemen pertama pada list ditunjuk oleh sebuah pointer khusus yang disebut First (atau Head), sedangkan elemen terakhir memiliki next yang bernilai Nil (atau NULL) sebagai penanda akhir list. Apabila First bernilai Nil, maka list dalam keadaan kosong. Karena hanya memiliki satu arah penunjuk, penelusuran pada single linked list hanya dapat dilakukan satu arah, yaitu dari elemen pertama menuju elemen terakhir.

Keunggulan single linked list dibandingkan array adalah proses penyisipan dan penghapusan elemen yang lebih efisien karena tidak perlu menggeser elemen lain, serta pemakaian memori yang fleksibel. Namun, struktur ini juga memiliki kekurangan, yaitu akses ke elemen tertentu harus dilakukan secara berurutan dari awal list sehingga tidak bisa langsung diakses melalui indeks, dan setiap elemen memerlukan memori tambahan untuk menyimpan pointer next.

### A. Searching<br/>
Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node
tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari
ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan
update akan lebih mudah.


## Guided 

### 1. listBuah.h

```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif
```

### 2. listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - UPDATE -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - SEARCHING -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

### 3. main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    printList(List);
    updateLast(List);
    printList(List);
    updateAfter(List, nodeD);
    printList(List);
    
    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;
    
    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);
    
    delFirst(List);
    printList(List);
    delLast(List);
    printList(List);
    delAfter(List, nodeD, nodeC);
    printList(List);

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
Program dibagi menjadi tiga file, yaitu listBuah.h untuk deklarasi struktur data dan fungsi, listBuah.cpp untuk implementasi fungsi dan prosedur, serta main.cpp sebagai program utama. Program ini menyediakan berbagai operasi, seperti penambahan node melalui insertFirst(), insertAfter(), dan insertLast(), pembaruan data melalui updateFirst(), updateLast(), dan updateAfter(), serta pencarian data berdasarkan nama, alamat node, dan rentang harga. Selain itu, terdapat operasi penghapusan node menggunakan delFirst(), delLast(), dan delAfter(), serta deleteList() untuk menghapus seluruh isi list. Program juga menggunakan printList() untuk menampilkan data dan nbList() untuk menghitung jumlah node.

## Unguided 

### 1.  Buatlah ADT Singly Linked list sebagai berikut di dalam file “Singlylist.h”, Kemudian buat implementasi ADT Singly Linked list pada file “Singlylist.cpp”. Cobalah hasil implementasi ADT pada file “main.cpp”.

#### singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

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
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

#### singlylist.cpp
```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
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

#### main.cpp
```C++
#include "singlylist.h"

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
![Screenshot Output Unguided 1_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%205/UNGUIDED/SOAL1/output1.png)

Program terdiri dari tiga file, yaitu singlylist.h untuk deklarasi struktur data dan fungsi, singlylist.cpp untuk implementasi fungsi, serta main.cpp sebagai program utama. Program menggunakan createList() untuk membuat list kosong, alokasi() untuk membuat node baru, dan insertFirst() untuk menambahkan node pada bagian awal list. Pada program utama, terdapat lima data yang dimasukkan secara berurutan, yaitu 2, 0, 8, 12, dan 9. Karena menggunakan metode insertFirst, urutan data yang ditampilkan melalui printInfo() menjadi 9 → 12 → 8 → 0 → 2. Selain itu, tersedia fungsi dealokasi() untuk membebaskan memori node. Secara keseluruhan, program ini menunjukkan cara kerja Singly Linked List dalam menambahkan dan menampilkan data secara dinamis menggunakan pointer. 

### 2. Carilah elemen dengan info 8 dengan membuat fungsi baru. fungsi findElm( L : List, x : infotype ) : address

#### singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

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
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);

#endif
```

#### singlylist.cpp
```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
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

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}
```

#### main.cpp
```C++
#include "singlylist.h"

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

    address P = findElm(L, 8);
    
    if (P != Nil) {
        cout << P->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%205/UNGUIDED/SOAL2/output2.png)

Program terdiri dari tiga file, yaitu singlylist.h untuk deklarasi struktur data dan fungsi, singlylist.cpp untuk implementasi fungsi, serta main.cpp sebagai program utama. Program menggunakan createList() untuk membuat list kosong, alokasi() untuk membuat node baru, dan insertFirst() untuk menambahkan node pada awal list. Lima data dimasukkan secara berurutan, yaitu 2, 0, 8, 12, dan 9, sehingga menghasilkan urutan 9 → 12 → 8 → 0 → 2 ketika ditampilkan menggunakan printInfo(). Selain itu, terdapat fungsi findElm() yang digunakan untuk mencari data tertentu dengan menelusuri setiap node secara berurutan. Pada program utama, dilakukan pencarian angka 8 dan program menampilkan pesan bahwa angka tersebut ditemukan dalam list.

### 3. Hitunglah jumlah total info seluruh elemen (9+12+8+0+2=31)!

#### singlylist.h
```C++
#ifndef SINGLYLIST_H_INCLUDED
#define SINGLYLIST_H_INCLUDED

#include <iostream>
using namespace std;

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
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
address findElm(List L, infotype x);
int totalInfo(List L);

#endif
```

#### singlylist.cpp
```C++
#include "singlylist.h"

void createList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
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

address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

int totalInfo(List L) {
    int total = 0;
    address P = L.First;
    while (P != Nil) {
        total = total + P->info;
        P = P->next;
    }
    return total;
}
```

#### main.cpp
```C++
#include "singlylist.h"

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

    address P = findElm(L, 8);
    
    if (P != Nil) {
        cout << P->info << " ditemukan dalam list" << endl;
    } else {
        cout << "8 tidak ditemukan dalam list" << endl;
    }

    cout << "Total info dari kelima elemen adalah : " << totalInfo(L) << endl;
    return 0;
}
```

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Damaoooux/PRAKTIKUM-STRUKTUR-DATA-YUSUF-HIBATULLAH-109082500164/blob/main/MODUL%205/UNGUIDED/SOAL3/output3.png)

Program menggunakan createList() untuk membuat list kosong, alokasi() untuk membuat node baru, dan insertFirst() untuk menambahkan node pada awal list. Lima data dimasukkan secara berurutan, yaitu 2, 0, 8, 12, dan 9, sehingga menghasilkan urutan 9 → 12 → 8 → 0 → 2 ketika ditampilkan menggunakan printInfo(). Selanjutnya, fungsi findElm() digunakan untuk mencari angka 8 dan menampilkan pesan bahwa data tersebut ditemukan. Program juga menggunakan fungsi totalInfo() untuk menjumlahkan seluruh nilai yang tersimpan dalam linked list, sehingga diperoleh hasil 31

## Kesimpulan
Berdasarkan praktikum yang telah dilakukan, dapat disimpulkan bahwa single linked list merupakan struktur data dinamis yang setiap elemennya terhubung melalui pointer next, dengan pointer First sebagai penanda elemen pertama dan nilai Nil sebagai penanda akhir list. Struktur ini berhasil direpresentasikan dalam bentuk Abstract Data Type (ADT) pada bahasa C++ yang dibagi menjadi tiga file, yaitu Singlylist.h untuk definisi tipe dan deklarasi operasi, Singlylist.cpp untuk implementasi operasi, dan main.cpp untuk pengujian. Pemisahan ini membuat program lebih terstruktur, mudah dibaca, dan mudah dikembangkan.

Operasi insertFirst menyisipkan elemen baru di awal list, sehingga urutan hasil printInfo berkebalikan dengan urutan pemasukan data. Data 2, 0, 8, 12, dan 9 yang dimasukkan secara berurutan menghasilkan list dengan urutan 9, 12, 8, 0, 2, sesuai dengan ilustrasi pada soal. Fungsi findElm berhasil mencari elemen dengan info 8 melalui penelusuran dari First hingga Nil, serta mengembalikan alamat elemen jika ditemukan atau Nil jika tidak ditemukan. Fungsi totalInfo berhasil menghitung jumlah seluruh info elemen dengan hasil 31, yaitu dari penjumlahan 9 + 12 + 8 + 0 + 2.

Dari praktikum ini juga dapat disimpulkan bahwa pengelolaan memori secara dinamis menggunakan new dan delete penting dilakukan dengan benar agar tidak terjadi kebocoran memori. Selain itu, karena penelusuran hanya dapat dilakukan satu arah dari elemen pertama, akses terhadap elemen tertentu pada single linked list harus dilakukan secara berurutan, berbeda dengan array yang dapat diakses langsung melalui indeks.

## Referensi
<br>Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). Introduction to Algorithms (4th ed.). MIT Press.
<br>Weiss, M. A. (2014). Data Structures and Algorithm Analysis in C++ (4th ed.). Pearson.
