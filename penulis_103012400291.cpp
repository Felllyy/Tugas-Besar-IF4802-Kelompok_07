#include "Mll.h"

void createListPenulis(ListPenulis &L){
    L.first = nullptr;
}
adrpenulis createElmPenulis(string idPenulis, string namaPenulis, int bukuTerbit){
    adrpenulis P = new elmlistPenulis;
    P->info.idpenulis = idPenulis;
    P->info.namapenulis= namaPenulis;
    P->info.bukuterbit=bukuTerbit;
    P->next = nullptr;
    P->firstBook = nullptr;
    return P;
}
void insertFirstPenulis(ListPenulis &L, adrpenulis P){
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}
void insertLastPenulis(ListPenulis &L, adrpenulis P){
    adrpenulis q;
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
void insertAfterPenulis(ListPenulis &L, adrpenulis prec, adrpenulis P){
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = prec->next;
        prec->next = P;
    }
}
adrpenulis findPenulis(ListPenulis L, string idpenulis){
    adrpenulis P = L.first;
    while (P != nullptr) {
        if (P->info.idpenulis == idpenulis) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}
