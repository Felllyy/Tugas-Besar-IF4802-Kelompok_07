#include "MLL.h"
using namespace std;
void deleteFirstBuku(adrPenulis P, adrBuku &B) {
    B = nullptr;

    if (P->firstBuku == nullptr) {
        cout << "List Buku kosong." << endl;

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
    }
}
void deleteLastBuku(adrPenulis P,adrBuku &B){

    if (P == nullptr || P->firstBuku == nullptr) {
        cout << "Penulis tidak valid atau List Buku kosong." << endl;
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
    }
}
void deleteAfterBuku(adrPenulis P, adrBuku prec, adrBuku &B){
    bool canDelete = true;

    if (P == nullptr || P->firstBuku == nullptr) {
        cout << "List kosong atau Penulis tidak valid." << endl;
        canDelete = false;
    } else if (prec == nullptr) {
        cout << "Predecessor (prec) tidak ditemukan." << endl;
        canDelete = false;
    } else if (prec->next == nullptr) {
        cout << "Tidak ada elemen setelah predecessor." << endl;
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
    }
}
//pinjam buku hapus stock di datanya
void deleteStockBuku(listPenulis &L, arrayPinjam &AP,string idPenulis, string idBuku) {
    adrPenulis P = findElemenPenulis(L, idPenulis);
    if (P == nullptr) {
        cout << "Penulis tidak ditemukan!" << endl;
        return;
    }

    adrBuku B = findElemenBuku(P, idBuku);
    if (B == nullptr) {
        cout << "Buku tidak ditemukan!" << endl;
        return;
    }

    // CEK KAPASITAS ARRAY
    if (AP.n >= MAX_PINJAM) {
        cout << "Data peminjaman penuh!" << endl;
        return;
    }

    // SIMPAN DATA BUKU KE ARRAY PINJAM
    AP.data[AP.n].idPenulis   = idPenulis;
    AP.data[AP.n].idBuku      = B->infoBuku.idBuku;
    AP.data[AP.n].judul       = B->infoBuku.judul;
    AP.data[AP.n].tahunTerbit = B->infoBuku.tahunTerbit;
    AP.n++;

    // HAPUS BUKU DARI LIST PENULIS
    if (B == P->firstBuku) {
        deleteFirstBuku(P, B);
    }
    else if (B == P->lastBuku) {
        deleteLastBuku(P, B);
    }
    else {
        deleteAfterBuku(P, B->prev, B);
    }

    cout << "Buku dengan ID " << idBuku << " berhasil dipinjam." << endl;
}

// pengembalian buku ke data
void returnStockBuku(listPenulis &L, arrayPinjam &AP,string idPenulis, string idBuku) {

    int idx = -1;
    for (int i = 0; i < AP.n; i++) {
        if (AP.data[i].idPenulis == idPenulis &&
            AP.data[i].idBuku == idBuku) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        cout << "Buku ini tidak tercatat sebagai buku pinjaman!" << endl;
        return;
    }

    adrPenulis P = findElemenPenulis(L, idPenulis);
    if (P == nullptr) {
        cout << "Penulis tidak ditemukan!" << endl;
        return;
    }

    // BUAT ELEMENT BARU
    adrBuku B = createElmBuku(
        AP.data[idx].idBuku,
        AP.data[idx].judul,
        AP.data[idx].tahunTerbit
    );

    insertLastBuku(P, B);

    // HAPUS DATA DARI ARRAY PINJAM
    for (int i = idx; i < AP.n - 1; i++) {
        AP.data[i] = AP.data[i + 1];
    }
    AP.n--;

    cout << "Buku berhasil dikembalikan." << endl;
}
void createArrayPinjam(arrayPinjam &AP) {
    AP.n = 0;
}



