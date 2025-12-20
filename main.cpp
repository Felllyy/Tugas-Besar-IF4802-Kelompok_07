#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    listPenulis L;
    arrayPinjam AP;
    AP.n=0;
    createListPenulis(L);
    // =======================
    // PENULIS 1
    // =======================
    adrPenulis P1 = createElemenPenulis("P001", "Tere Liye", 5);
    insertLastPenulis(L, P1);
    createListBuku(P1);

    insertLastBuku(P1, createElmBuku("B001", "Hujan", 2016));
    insertLastBuku(P1, createElmBuku("B002", "Pulang", 2015));
    insertLastBuku(P1, createElmBuku("B003", "Pergi", 2018));
    insertLastBuku(P1, createElmBuku("B004", "Rindu", 2014));
    insertLastBuku(P1, createElmBuku("B005", "Bumi", 2014));

    // =======================
    // PENULIS 2
    // =======================
    adrPenulis P2 = createElemenPenulis("P002", "Andrea Hirata", 5);
    insertLastPenulis(L, P2);
    createListBuku(P2);

    insertLastBuku(P2, createElmBuku("B101", "Laskar Pelangi", 2005));
    insertLastBuku(P2, createElmBuku("B102", "Sang Pemimpi", 2006));
    insertLastBuku(P2, createElmBuku("B103", "Edensor", 2007));
    insertLastBuku(P2, createElmBuku("B104", "Maryamah Karpov", 2008));
    insertLastBuku(P2, createElmBuku("B105", "Ayah", 2015));

    // =======================
    // PENULIS 3
    // =======================
    adrPenulis P3 = createElemenPenulis("P003", "Dewi Lestari", 5);
    insertLastPenulis(L, P3);
    createListBuku(P3);

    insertLastBuku(P3, createElmBuku("B201", "Supernova 1", 2001));
    insertLastBuku(P3, createElmBuku("B202", "Supernova 2", 2004));
    insertLastBuku(P3, createElmBuku("B203", "Supernova 3", 2008));
    insertLastBuku(P3, createElmBuku("B204", "Partikel", 2012));
    insertLastBuku(P3, createElmBuku("B205", "Akar", 2002));

    // =======================
    // PENULIS 4
    // =======================
    adrPenulis P4 = createElemenPenulis("P004", "Fiersa Besari", 5);
    insertLastPenulis(L, P4);
    createListBuku(P4);

    insertLastBuku(P4, createElmBuku("B301", "Garis Waktu", 2016));
    insertLastBuku(P4, createElmBuku("B302", "Arah Langkah", 2018));
    insertLastBuku(P4, createElmBuku("B303", "11:11", 2020));
    insertLastBuku(P4, createElmBuku("B304", "Konspirasi Alam Semesta", 2014));
    insertLastBuku(P4, createElmBuku("B305", "Tapak Jejak", 2015));

    // =======================
    // PENULIS 5
    // =======================
    adrPenulis P5 = createElemenPenulis("P005", "Habiburrahman El Shirazy", 5);
    insertLastPenulis(L, P5);
    createListBuku(P5);

    insertLastBuku(P5, createElmBuku("B401", "Ayat-Ayat Cinta", 2004));
    insertLastBuku(P5, createElmBuku("B402", "Ketika Cinta Bertasbih", 2007));
    insertLastBuku(P5, createElmBuku("B403", "Bumi Cinta", 2010));
    insertLastBuku(P5, createElmBuku("B404", "Dalam Mihrab Cinta", 2011));
    insertLastBuku(P5, createElmBuku("B405", "Cinta Suci Zahrana", 2012));

    // =======================
    // PENULIS 6
    // =======================
    adrPenulis P6 = createElemenPenulis("P006", "Sitta Karina", 5);
    insertLastPenulis(L, P6);
    createListBuku(P6);

    insertLastBuku(P6, createElmBuku("B501", "Lunar", 2004));
    insertLastBuku(P6, createElmBuku("B502", "Selena", 2005));
    insertLastBuku(P6, createElmBuku("B503", "Crescent", 2007));
    insertLastBuku(P6, createElmBuku("B504", "Atlantis", 2010));
    insertLastBuku(P6, createElmBuku("B505", "Narnia", 2011));

    // =======================
    // PENULIS 7
    // =======================
    adrPenulis P7 = createElemenPenulis("P007", "Boim Lebon", 5);
    insertLastPenulis(L, P7);
    createListBuku(P7);

    insertLastBuku(P7, createElmBuku("B601", "Balada Si Roy 1", 1990));
    insertLastBuku(P7, createElmBuku("B602", "Balada Si Roy 2", 1991));
    insertLastBuku(P7, createElmBuku("B603", "Balada Si Roy 3", 1992));
    insertLastBuku(P7, createElmBuku("B604", "Balada Si Roy 4", 1993));
    insertLastBuku(P7, createElmBuku("B605", "Balada Si Roy 5", 1994));

    // =======================
    // PENULIS 8
    // =======================
    adrPenulis P8 = createElemenPenulis("P008", "Pramoedya A. Toer", 5);
    insertLastPenulis(L, P8);
    createListBuku(P8);

    insertLastBuku(P8, createElmBuku("B701", "Bumi Manusia", 1975));
    insertLastBuku(P8, createElmBuku("B702", "Anak Semua Bangsa", 1980));
    insertLastBuku(P8, createElmBuku("B703", "Jejak Langkah", 1985));
    insertLastBuku(P8, createElmBuku("B704", "Rumah Kaca", 1988));
    insertLastBuku(P8, createElmBuku("B705", "Gadis Pantai", 1960));

    // =======================
    // PENULIS 9
    // =======================
    adrPenulis P9 = createElemenPenulis("P009", "J.K. Rowling", 5);
    insertLastPenulis(L, P9);
    createListBuku(P9);

    insertLastBuku(P9, createElmBuku("B801", "Harry Potter 1", 1997));
    insertLastBuku(P9, createElmBuku("B802", "Harry Potter 2", 1998));
    insertLastBuku(P9, createElmBuku("B803", "Harry Potter 3", 1999));
    insertLastBuku(P9, createElmBuku("B804", "Harry Potter 4", 2000));
    insertLastBuku(P9, createElmBuku("B805", "Harry Potter 5", 2003));

    // =======================
    // PENULIS 10
    // =======================
    adrPenulis P10 = createElemenPenulis("P010", "Rick Riordan", 5);
    insertLastPenulis(L, P10);
    createListBuku(P10);

    insertLastBuku(P10, createElmBuku("B901", "Percy Jackson 1", 2005));
    insertLastBuku(P10, createElmBuku("B902", "Percy Jackson 2", 2006));
    insertLastBuku(P10, createElmBuku("B903", "Percy Jackson 3", 2007));
    insertLastBuku(P10, createElmBuku("B904", "Percy Jackson 4", 2008));
    insertLastBuku(P10, createElmBuku("B905", "Percy Jackson 5", 2009));
    int pilih;
    do {
        cout << "\n=========== MAIN MENU ===========\n";
        cout << "1. Menu Admin\n";
        cout << "2. Menu User\n";
        cout << "0. Keluar Program\n";
        cout << "Pilih: ";
        cin >> pilih;

        if (pilih == 1) {
            mainAdmin(L);
        }
        else if (pilih == 2) {
            mainUser(L,AP);
        }
        else if (pilih == 0) {
            cout << "Program selesai.\n";
        }

    } while (pilih != 0);

    return 0;
}

