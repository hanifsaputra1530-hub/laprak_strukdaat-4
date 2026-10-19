# <h1 align="center">Laporan Praktikum Modul - 4 SINGLY LINKED LIST (BAGIAN PERTAMA)</h1>
<p align="center">Naufal Hanif Saputra - 109082500209</p>
<p align="center">Kelas : S1IF-13-01</p>

## Dasar Teori
Singly Linked List adalah struktur data linear yang tersusun dari sekumpulan node, di mana setiap node berisi dua bagian, yaitu data (info) dan pointer yang menunjuk ke node berikutnya. Node terakhir menunjuk ke `NULL` (atau `nullptr`) sebagai penanda akhir list, sedangkan akses ke seluruh isi list dimulai dari pointer `first` yang menunjuk ke node pertama [1]. Berbeda dengan array yang menempati blok memori berurutan, node pada linked list dapat berada di lokasi memori mana pun karena keterhubungannya dijaga oleh pointer [2].

Operasi dasar pada Singly Linked List meliputi pembuatan list kosong, alokasi node, penyisipan (insert) di awal, tengah, dan akhir list, penghapusan (delete) node, penelusuran (traversal) untuk menampilkan isi list, serta penghitungan jumlah node. Penyisipan dan penghapusan di awal list hanya membutuhkan perubahan pointer sehingga berjalan dalam waktu konstan O(1), sedangkan operasi yang harus menelusuri list, seperti menghapus node terakhir atau menghitung jumlah node, membutuhkan waktu O(n) [1][3].

Kelebihan linked list adalah ukurannya yang dinamis dan mudah diubah tanpa perlu menggeser elemen lain. Kekurangannya adalah penggunaan memori tambahan untuk menyimpan pointer pada setiap node dan akses data yang harus dilakukan secara berurutan dari node pertama. Dalam C++, node dibuat dengan `new` dan harus dikembalikan ke sistem dengan `delete` agar tidak terjadi kebocoran memori (memory leak) [3].

## Guided 

### 1. list.h

```C++
//hear guard digunakan untuk mencegah file header yg sama
//di-include lebih dari sekali dalam satu program

#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa {
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //memberikan nama alias dataMahasiswa untuk struct mahasiswa

typedef struct node *address; //mendefinisikan alias address

struct node { //node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedList { //ini linked listnya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedList list);
void createList(linkedList &list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedList list);
void insertFirst(linkedList &list, address nodeBaru);
void insertAfter(linkedList &list, address nodeBaru, address prev);
void insertLast(linkedList &list, address nodeBaru);

void delFirst(linkedList &list);
void delLast(linkedList &list);
void delAfter(linkedList &list, address nodeHapus, address nodePrev);
int nbList(linkedList list);
void deleteList(linkedList &list);

#endif
```


### 2. list.cpp

```C++

#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// Fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedList List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

// Pembuatan linked list kosong
void createList(linkedList &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// Pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) {
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isi data sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// Penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// Prosedur untuk insert / menambahkan node baru ke dalam list
void insertFirst(linkedList &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list
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

// Prosedur-prosedur untuk delete / menghapus node
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
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List) {
    /* I.S. list tidak kosong
       F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first = Nil;
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
        cout << "List kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev) {
    /* I.S. list tidak kosong, alamat salah satu elemen list
       F.S. nodeBantu adalah alamat dari Prev->next,
       menghapus Prev->next dari list */
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
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

// Prosedur untuk menampilkan isi list
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
                << ", Usia : " << nodeBantu->isidata.umur
                << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// Function untuk menampilkan jumlah node di dalam list
int nbList(linkedList List) {
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node di dalam list */
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// Prosedur untuk menghapus list (menghapus semua node di dalam list)
void deleteList(linkedList &List) {
    /* I.S. list sudah ada
       F.S. menghapus semua node di dalam list */
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

int main() {
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

### Penjelasan Guided
Program guided ini mengelola data mahasiswa (nama, NIM, dan umur) menggunakan Singlylist yang kodenya dipisah menjadi tiga file: `list.h` untuk deklarasi struct dan prototype fungsi, `list.cpp` untuk implementasi operasi list, dan `main.cpp` sebagai program utama. Setiap node menyimpan satu data mahasiswa beserta pointer `next`, dan list diakses melalui pointer `first`.

Pada `main.cpp`, lima node dibuat dengan fungsi `alokasi()` lalu disisipkan ke dalam list. Urutan insert adalah `insertFirst` node A, `insertLast` node B, `insertAfter` node C setelah A, `insertAfter` node D setelah C, dan `insertLast` node E, sehingga urutan list menjadi A (Dhimas) → C (Rizal) → D (Satrio) → B (Arvin) → E (Joshua) dengan jumlah 5 node.

Tahap berikutnya adalah penghapusan. `delFirst` menghapus node pertama (Dhimas), `delLast` menghapus node terakhir (Joshua), dan `delAfter` menghapus node setelah Rizal (Satrio). Sisa list adalah Rizal → Arvin dengan jumlah 2 node. Terakhir, `deleteList` menelusuri list dan men-dealokasi seluruh node sehingga `first` kembali bernilai `Nil` dan jumlah node menjadi 0. Setiap node yang dihapus dikembalikan ke sistem melalui `dealokasi()` dengan `delete`, sehingga memori tidak bocor.

## Unguided 

### 1.1 Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address prev);
int nbList(List L);
void deleteList(List &L);

#endif
```

### 1.2 Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == nullptr) {
        return;
    }

    if (L.first->next == nullptr) {
        dealokasi(L.first);
        return;
    }

    address P = L.first;

    while (P->next->next != nullptr) {
        P = P->next;
    }

    address H = P->next;
    P->next = nullptr;
    dealokasi(H);
}

void deleteAfter(List &L, address prev) {
    if (prev != nullptr && prev->next != nullptr) {
        address P = prev->next;
        prev->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }

    cout << "- List Berhasil Terhapus -" << endl;
}
```

### 1.3 main.cpp
```C++

#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

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
![Screenshot Output Unguided 1_1](https://github.com/hanifsaputra1530-hub/laprak_strukdaat-4/blob/main/unguided/Screenshot%202026-10-19%20222306.png?raw=true)

### Penjelasan Unguided 1
Pada soal ini, Singlylist dibuat untuk menyimpan data bertipe integer (`infotype`). Program membuat list kosong dengan `createList()`, lalu setiap nilai dibuatkan node baru oleh `alokasi()` dan dipasang di depan list dengan `insertFirst()`. Nilai yang dimasukkan secara berurutan adalah 2, 0, 8, 12, dan 9.

Karena `insertFirst()` selalu menempatkan node baru di posisi paling depan, node yang dimasukkan terakhir akan menjadi node pertama. Itulah sebabnya hasil `printInfo()` tampil terbalik dari urutan pemasukan, yaitu `9 12 8 0 2`. Fungsi `printInfo()` sendiri bekerja dengan menelusuri list dari `first` sampai pointer bernilai `nullptr` sambil mencetak isi tiap node.

### 2.1 Singlylist.h

```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H

typedef int infotype;
typedef struct elmList *address;

struct elmList{
    infotype info;
    address next;
};

struct List{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

void deleteFirst(List &L);
void deleteLast(List &L);
void deleteAfter(List &L, address prev);
int nbList(List L);
void deleteList(List &L);

#endif
```

### 2.2 Singlylist.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    if (P != nullptr) {
        delete P;
        P = nullptr;
    }
}

void printInfo(List L) {
    address P = L.first;

    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirst(List &L) {
    if (L.first != nullptr) {
        address P = L.first;
        L.first = P->next;
        dealokasi(P);
    }
}

void deleteLast(List &L) {
    if (L.first == nullptr) {
        return;
    }

    if (L.first->next == nullptr) {
        dealokasi(L.first);
        return;
    }

    address P = L.first;

    while (P->next->next != nullptr) {
        P = P->next;
    }

    address H = P->next;
    P->next = nullptr;
    dealokasi(H);
}

void deleteAfter(List &L, address prev) {
    if (prev != nullptr && prev->next != nullptr) {
        address P = prev->next;
        prev->next = P->next;
        dealokasi(P);
    }
}

int nbList(List L) {
    int jumlah = 0;
    address P = L.first;

    while (P != nullptr) {
        jumlah++;
        P = P->next;
    }

    return jumlah;
}

void deleteList(List &L) {
    while (L.first != nullptr) {
        deleteFirst(L);
    }

    cout << "- List Berhasil Terhapus -" << endl;
}
```

### 2.3 main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(2));
    insertFirst(L, alokasi(0));
    insertFirst(L, alokasi(8));
    insertFirst(L, alokasi(12));
    insertFirst(L, alokasi(9));

    deleteFirst(L);
    deleteLast(L);
    deleteAfter(L, L.first);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}
```

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/hanifsaputra1530-hub/laprak_strukdaat-4/blob/main/guided/Screenshot%202026-10-19%20223036.png?raw=true)

### Penjelasan Unguided 2
Soal kedua memakai struktur dan fungsi yang sama dengan soal pertama, tetapi `main.cpp` ditambah operasi penghapusan dan penghitungan node. Setelah lima node dimasukkan, isi list adalah `9 12 8 0 2`. Kemudian `deleteFirst()` menghapus node pertama (9) sehingga list menjadi `12 8 0 2`, `deleteLast()` menelusuri list sampai node sebelum terakhir lalu menghapus node terakhir (2) sehingga menjadi `12 8 0`, dan `deleteAfter(L, L.first)` menghapus node setelah node pertama (8) sehingga list menjadi `12 0`.

Hasil akhirnya ditampilkan oleh `printInfo()` dan `nbList()`, yaitu `12 0` dengan jumlah node 2. Terakhir, `deleteList()` menghapus semua node yang tersisa satu per satu dan mencetak pesan "- List Berhasil Terhapus -", sehingga jumlah node kembali menjadi 0. Pada fungsi-fungsi penghapusan, pengecekan `nullptr` dilakukan terlebih dahulu agar program tidak error ketika list kosong atau node yang dituju tidak ada.


## Kesimpulan
Dari praktikum ini dapat disimpulkan bahwa Singlylist adalah struktur data dinamis yang tersusun dari node-node yang dihubungkan oleh pointer, sehingga penambahan dan penghapusan data dapat dilakukan hanya dengan mengatur ulang pointer tanpa menggeser elemen lain. Pada bagian guided, list dipakai untuk menyimpan data mahasiswa dengan operasi insert di awal, tengah, dan akhir serta delete di awal, tengah, dan akhir. Pada bagian unguided, list dipakai untuk menyimpan bilangan integer dengan fungsi `createList()`, `alokasi()`, `dealokasi()`, `insertFirst()`, `printInfo()`, `deleteFirst()`, `deleteLast()`, `deleteAfter()`, `nbList()`, dan `deleteList()`.

Praktikum ini juga menunjukkan bahwa `insertFirst()` menghasilkan urutan list yang terbalik dari urutan pemasukan data, dan bahwa pengelolaan memori dengan `new` dan `delete` perlu dilakukan dengan benar agar tidak terjadi kebocoran memori. Dengan demikian, praktikum ini membantu memahami konsep dasar Singlylist beserta penerapannya dalam bahasa C++.

## Referensi
[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2022). *Introduction to Algorithms* (4th ed.). MIT Press. Bab 10: Elementary Data Structures.
<br>[2] Goodrich, M. T., Tamassia, R., & Mount, D. M. (2011). *Data Structures and Algorithms in C++* (2nd ed.). Wiley.
<br>[3] Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C++* (4th ed.). Pearson. Bab 3: Lists, Stacks, and Queues.<br>
