#include "MLL.h"
using namespace std;
void createListBuku(adrPenulis P){
    P->firstBuku = nullptr;
    P->lastBuku  = nullptr;
}

adrBuku createElmBuku(string idBuku, string judulBuku, int tahunTerbit){
    adrBuku B = new elemenBuku;
    B->infoBuku.idBuku      = idBuku;
    B->infoBuku.judul       = judulBuku;
    B->infoBuku.tahunTerbit = tahunTerbit;
    B->next = nullptr;
    B->prev = nullptr;
    return B;
}

void insertFirstBuku(adrPenulis P, adrBuku B){
    if(P->firstBuku == nullptr){
        P->firstBuku = B;
        P->lastBuku  = B;
    } 
    else {
        B->next = P->firstBuku;
        P->firstBuku->prev = B;
        P->firstBuku = B;
    }
}

void insertLastBuku(adrPenulis P, adrBuku B){
    if(P->firstBuku == nullptr){
        P->firstBuku = B;
        P->lastBuku  = B;
    } 
    else {
        B->prev = P->lastBuku;
        P->lastBuku->next = B;
        P->lastBuku = B;
    }
}

void insertAfterBuku(adrPenulis P, adrBuku prec, adrBuku B){
    if(prec != nullptr){
        B->next = prec->next;
        B->prev = prec;

        if(prec->next != nullptr){
            prec->next->prev = B;
        } else {
            P->lastBuku = B;
        }

        prec->next = B;
    }
}

adrBuku findElemenBuku(adrPenulis P, string id){
    adrBuku B = P->firstBuku;
    while(B != nullptr){
        if(B->infoBuku.idBuku == id){
            break;
        }
        B = B->next;
    }
    return B;
}

void viewBuku(adrPenulis P){
    if(P == nullptr){
        cout << "Data penulis tidak ditemukan." << endl;
    }
    else if(P->firstBuku == nullptr){
        cout << "Penulis " << P->infoPenulis.nama 
             << " belum memiliki buku." << endl;
    }
    else {
        cout << "Daftar Buku dari Penulis: " << P->infoPenulis.nama << endl;
        cout << "==================================" << endl;

        adrBuku B = P->firstBuku;
        int i = 1;

        while(B != nullptr){
            cout << i << ". ID Buku : " << B->infoBuku.idBuku << endl;
            cout << "   Judul  : " << B->infoBuku.judul << endl;
            cout << "   Tahun  : " << B->infoBuku.tahunTerbit << endl;
            cout << "----------------------------------" << endl;

            B = B->next;
            i++;
        }
    }
}