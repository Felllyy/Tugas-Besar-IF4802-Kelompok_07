#ifndef PENULIS_H_INCLUDED
#define PENULIS_H_INCLUDED
#include "buku.h";
#include <iostream>;
using namespace std;
typedef struct penulis infotype;
typedef struct elmlistP *addressP;
typedef struct elmslistC *addressC;

struct penulis{
  string idpenulis;
  string namapenulis;
  int bukuterbit;
};

struct elmlistP{
  infotype info;
  addressP next;
  addressC firstChild;
};

struct Listparent{
  addressP first;
};


#endif // PENULIS_H_INCLUDED
