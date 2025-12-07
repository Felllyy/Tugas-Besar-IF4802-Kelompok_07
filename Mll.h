#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

typedef struct elemenBuku *adrBuku;
typedef struct elemenPenulis *adrPenulis;

struct buku {
    string idBuku;
    string judul;
    int tahunTerbit;
};

struct penulis {
    string idPenulis;
    string nama;
    int tahunLahir;
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





