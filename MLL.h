#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elemenBuku *adrBuku;
typedef struct elemenPenulis *adrPenulis;
const int MAX_PINJAM = 100;

struct buku {
    string idBuku;
    string judul;
    int tahunTerbit;
};

struct penulis {
    string idPenulis;
    string nama;
    int bukuTerbit;
};

struct elemenBuku {
    buku infoBuku;
    adrBuku next;
    adrBuku prev;
};

struct elemenPenulis {
    penulis infoPenulis;
    adrPenulis next;
    adrBuku firstBuku;
    adrBuku lastBuku;
};

struct listPenulis {
    adrPenulis first;
};
struct arrayPinjam {
    dataPinjam data[MAX_PINJAM];
    int n;
};

// Parent : Penulis
void createListPenulis(listPenulis &L);
adrPenulis createElemenPenulis(string idPenulis, string namaPenulis, int bukuTerbit);
bool isEmptyPenulis(listPenulis L);

void insertFirstPenulis(listPenulis &L, adrPenulis P);
void insertLastPenulis(listPenulis &L, adrPenulis P);
void insertAfterPenulis(listPenulis &L, adrPenulis prec, adrPenulis P);

void deleteFirstPenulis(listPenulis &L, adrPenulis &P);
void deleteLastPenulis(listPenulis &L, adrPenulis &P);
void deleteAfterPenulis(listPenulis &L, adrPenulis prec, adrPenulis &P);

adrPenulis findElemenPenulis(listPenulis L, string idPenulis);
void viewPenulis(listPenulis L);

// Child : Buku
void createListBuku(adrPenulis P);
adrBuku createElmBuku(string idBuku, string judulBuku, int tahunTerbit);
bool isEmptyBuku(adrPenulis P);

void insertFirstBuku(adrPenulis P, adrBuku B);
void insertLastBuku(adrPenulis P, adrBuku B);
void insertAfterBuku(adrPenulis P, adrBuku prec, adrBuku B);

void deleteFirstBuku(adrPenulis P, adrBuku &B);
void deleteLastBuku(adrPenulis P, adrBuku &B);
void deleteAfterBuku(adrPenulis P, adrBuku prec, adrBuku &B);

adrBuku findElemenBuku(adrPenulis P, string idBuku);
void viewBuku(adrPenulis P);

//studycase
void deleteStockBuku(listPenulis &L, arrayPinjam &AP,string idPenulis, string idBuku);
void returnStockBuku(listPenulis &L, arrayPinjam &AP,string idPenulis, string idBuku);
void createArrayPinjam(arrayPinjam &AP);
//main
void mainAdmin(listPenulis &L);
void mainUser(listPenulis &L, arrayPinjam &AP);
#endif // MLL_H_INCLUDED




