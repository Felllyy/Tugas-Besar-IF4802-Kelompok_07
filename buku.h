#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>;
using namespace std;
typedef struct Buku infotypeBuku;
typedef struct elmslistBuku *adrbuku;

struct Buku{
  string idBuku;
  string judulBuku;
  int tahun;
};

struct elmlistBuku{
  infotypeBuku info;
  adrbuku next;
  adrbuku prev;
};

struct ListBuku{
  adrBuku first;
  adrbuku last;
};




#endif // BUKU_H_INCLUDED
