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
