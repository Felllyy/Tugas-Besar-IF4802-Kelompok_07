#include "MLL.h"
using namespace std;
void deleteFirstBuku(adrPenulis P, adrBuku &B) {
    B = nullptr;

    if (P->firstBuku == nullptr) {
        cout << "Error: List Buku kosong." << endl;

    } else {
        adrBuku currentB = P->firstBuku;
        B = currentB;
        if (currentB->next == nullptr) {
            P->firstBuku = nullptr;
            P->lastBuku  = nullptr;
        } else {
            P->firstBuku = currentB->next;
            P->firstBuku->prev = nullptr;
        }
        B->next = nullptr;
        B->prev = nullptr;
        P->infoPenulis.bukuTerbit--;
    }
}
void deleteLastBuku(adrPenulis P,adrBuku &B){

    if (P == nullptr || P->firstBuku == nullptr) {
        cout << "Error: Penulis tidak valid atau List Buku kosong." << endl;
    } else {
        adrBuku currentB = P->firstBuku;
        while (currentB ->next != nullptr) {
            currentB  = currentB ->next;
        }
        B = currentB;

        if (B->prev == nullptr) {
            P->firstBuku = nullptr;
            P->lastBuku  = nullptr;
        } else {
            B->prev->next = nullptr;
            P->lastBuku = B->prev;
        }

        B->prev = nullptr;
        B->next = nullptr;
        P->infoPenulis.bukuTerbit--;
    }
}
void deleteAfterBuku(adrPenulis P, adrBuku prec, adrBuku &B){
    bool canDelete = true;

    if (P == nullptr || P->firstBuku == nullptr) {
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
            P->lastBuku = prec;
        } else {
            adrBuku after = B->next;
            prec->next = after;
            after->prev = prec;
        }
        B->next = nullptr;
        B->prev = nullptr;
        P->infoPenulis.bukuTerbit--;
    }
}
//pinjam buku hapus stock di datanya
void deleteStockBuku(listPenulis &L,string idPenulis, string idBuku){
    adrPenulis P;
    adrBuku B;
    //cari si penulis dulu
    P=findElemenPenulis(L,idPenulis);
    if (P==nullptr){
        cout<<"Penulis tidak ditemukan"<<endl;

    }else{
        //cari buku
        B=findElemenBuku(P,idBuku);
        if (B==nullptr){
            cout<<"Buku tidak ditemukan!"<<endl;
        }else{
            //hapus berdasarkan tempatnya
            if (B == P->firstBuku) {
                deleteFirstBuku(P, B);
            }
            else if (B == P->lastBuku) {
                deleteLastBuku(P, B);
            }
            else {
                deleteAfterBuku(P, B->prev, B);
            }
            cout << "Buku dengan ID " << idBuku << " berhasil dihapus." << endl;
        }
    }
}

// pengembalian buku ke data
void returnStockBuku(listPenulis &L, string idPenulis, string idBuku, string judul,int tahunTerbit){
    adrPenulis P = findElemenPenulis(L, idPenulis);

    if (P == nullptr) {
        cout << "Penulis tidak ditemukan!" << endl;
        return;
    }

    adrBuku cek = findElemenBuku(P, idBuku);
    if (cek != nullptr) {
        cout << "Buku dengan ID tersebut sudah ada di data!" << endl;
        return;
    }

    adrBuku Q = createElmBuku(idBuku, judul, tahunTerbit);
    insertLastBuku(P, Q);
    P->infoPenulis.bukuTerbit++;
    cout << "Buku berhasil dikembalikan ke data." << endl;
}


