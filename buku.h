#ifndef BUKU_H_INCLUDED
#define BUKU_H_INCLUDED
#include <iostream>;
using namespace std;
typedef struct Buku *infotype;
typedef struct elmslist *adrbuku;
struct Buku{
  string idBuku;
  string judulBuku;
  int tahun;
};
struct elmlist{
  adrbuku first;
  adrbuku last;
};




#endif // BUKU_H_INCLUDED
