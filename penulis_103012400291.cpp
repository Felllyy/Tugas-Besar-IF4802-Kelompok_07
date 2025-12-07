#include "MLL.h"
using namespace std;
void createListPenulis(listPenulis &L){
    L.first = nullptr;
}
adrPenulis createElemenPenulis(string idPenulis, string namaPenulis, int bukuTerbit){
    adrPenulis P = new elemenPenulis;
    P->infoPenulis.idPenulis = idPenulis;
    P->infoPenulis.nama= namaPenulis;
    P->infoPenulis.bukuTerbit=bukuTerbit;
    P->next = nullptr;
    P->firstBuku = nullptr;
    return P;
}

void insertFirstPenulis(listPenulis &L, adrPenulis P){
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
void insertLastPenulis(listPenulis &L, adrPenulis P){
    adrPenulis q;
    if (L.first == nullptr) {
        L.first = P;
    } else {
        q = L.first;
        while (q->next != nullptr) {
            q = q->next;
        }
        q->next = P;
    }
}
void insertAfterPenulis(listPenulis &L, adrPenulis prec, adrPenulis P){
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = prec->next;
        prec->next = P;
    }
}
adrPenulis findElemenPenulis(listPenulis L, string idPenulis){
    adrPenulis P = L.first;
    while (P != nullptr) {
        if (P->infoPenulis.idPenulis == idPenulis) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
