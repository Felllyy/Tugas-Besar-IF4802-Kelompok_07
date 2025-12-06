#include "Mll.h"
void deleteFirstBuku(adrpenulis P, adrBuku &B) {
    B = nullptr;

    if (P->firstBook == nullptr) {
        cout << "Error: List Buku kosong." << endl;

    } else {
        adrBuku currentB = P->firstBook;
        B = currentB;
        if (currentB->next == nullptr) {
            P->firstBook = nullptr;

        } else {
            P->firstBook = currentB->next;
            P->firstBook->prev = nullptr;
        }
        B->next = nullptr;
        B->prev = nullptr;
        P->info.bukuterbit--;
    }
}
}
void deleteLastBuku(adrpenulis P,adrBuku &B){

    if (P == nullptr || P->firstBook == nullptr) {
        cout << "Error: Penulis tidak valid atau List Buku kosong." << endl;
    } else {
        adrBuku currentB = P->firstBook;
        while (currentB ->next != nullptr) {
            currentB  = currentB ->next;
        }
        B = currentB;

        if (B->prev == nullptr) {
            P->firstBook = nullptr;
        } else {
            B->prev->next = nullptr;
        }

        B->prev = nullptr;
        B->next = nullptr;
        P->info.bukuterbit--;
    }
}
void deleteAfterBuku(adrpenulis P, adrBuku prec, adrBuku &B){
    bool canDelete = true;

    if (P == nullptr || P->firstBook == nullptr) {
        cout << "Error: List kosong atau Penulis tidak valid." << endl;
        canDelete = false;
    } else if (prec == nullptr) {
        cout << "Error: Predecessor (prec) tidak ditemukan." << endl;
        canDelete = false;
    } else if (prec->next == nullptr) {
        cout << "Error: Tidak ada elemen setelah predecessor." << endl;
        canDelete = false;
    }

    if (canDelete) {
        B = prec->next;
        if (B->next == nullptr) {
            prec->next = nullptr;
        } else {
            adrBuku after = B->next;
            prec->next = after;
            after->prev = prec;
        }
        B->next = nullptr;
        B->prev = nullptr;
        P->info.bukuterbit--;
    }
}
