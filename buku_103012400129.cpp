#include "MLL.h"
using namespace std;
void createListBuku(adrPenulis P){
    P->firstBook = nullptr;
    P->lastBook  = nullptr;
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
    if(P->firstBook == nullptr){
        P->firstBook = B;
        P->lastBook = B;
    } 
    else {
        B->next = P->firstBuku;
        P->firstBook->prev = B;
        P->firstBook = B;
    }
}

void insertLastBuku(adrPenulis P, adrBuku B){
    if(P->firstBook == nullptr){
        P->firstBook = B;
        P->lastBook  = B;
    } 
    else {
        B->prev = P->lastBook;
        P->lastBook->next = B;
        P->lastBook = B;
    }
}

void insertAfterBuku(adrPenulis P, adrBuku prec, adrBuku B){
    if(prec != nullptr){
        B->next = prec->next;
        B->prev = prec;

        if(prec->next != nullptr){
            prec->next->prev = B;
        } else {
            P->lastBook = B;
        }

        prec->next = B;
    }
}

adrBuku findElemenBuku(adrPenulis P, string id){
    adrBuku B = P->firstBook;
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
    else if(P->firstBook == nullptr){
        cout << "Penulis " << P->infoPenulis.nama 
             << " belum memiliki buku." << endl;
    }
    else {
        cout << "Daftar Buku dari Penulis: " << P->infoPenulis.nama << endl;
        cout << "==================================" << endl;

        adrBuku B = P->firstBook;
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
