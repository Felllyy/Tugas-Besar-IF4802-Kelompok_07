#include "Mll.h"

bool isEmptyPenulis(listPenulis L){
    return L.first == nullptr;
}

void deleteFirstPenulis(listPenulis &L, adrPenulis &P){
    if(isEmptyPenulis(L)){
        cout << "List kosong";
    } 
    else if(L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
        P->next = nullptr;
    } 
    else {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLastPenulis(listPenulis &L, adrPenulis &P){
    adrPenulis q;

    if(isEmptyPenulis(L)){
        cout << "List kosong";
    } 
    else if(L.first->next == nullptr){
        P = L.first;
        L.first = nullptr;
        P->next = nullptr;
    } 
    else {
        q = L.first;
        while(q->next->next != nullptr){
            q = q->next;
        }
        P = q->next;
        q->next = nullptr;
        P->next = nullptr;
    }
}

void deleteAfterPenulis(listPenulis &L, adrPenulis prec, adrPenulis &O){
    if(prec != nullptr && prec->next != nullptr){
        O = prec->next;
        prec->next = O->next;
        O->next = nullptr;
    } else {
        O = nullptr;
    }
}

void viewPenulis(listPenulis L){
    if(L.first == nullptr){
        cout << "List Penulis kosong." << endl;
    } 
    else {
        adrPenulis P = L.first;
        int i = 1;

        while(P != nullptr){
            cout << "==================================" << endl;
            cout << "Data Penulis ke-" << i << endl;
            cout << "ID Penulis   : " << P->infoPenulis.idPenulis << endl;
            cout << "Nama Penulis : " << P->infoPenulis.nama << endl;
            cout << "Tahun Lahir  : " << P->infoPenulis.tahunLahir << endl;

            // Hitung jumlah buku
            int count = 0;
            adrBuku B = P->firstBuku;
            while(B != nullptr){
                count++;
                B = B->next;
            }

            cout << "Jumlah Buku  : " << count << endl;
            cout << "==================================" << endl << endl;

            P = P->next;
            i++;
        }
    }
}
