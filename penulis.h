#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include "buku.h";
#include <iostream>;
using namespace std;
typedef struct penulis *infotype;
typedef struct elmlist *adrpenulis;
struct penulis{
  string idpenulis;
  string namapenulis;
  int bukuterbit;
};
struct elmlist{
  adrpenulis first;
};


#endif // PENULIS_H_INCLUDED
