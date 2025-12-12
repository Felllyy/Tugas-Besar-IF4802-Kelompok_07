#include <iostream>
#include "Mll.h"
using namespace std;

void mainUser(listPenulis &L) {
    int pilihan;

    do {
        cout << "\n=========== MENU USER ===========\n";
        cout << "1. Lihat Semua Penulis & Buku\n";
        cout << "2. Pinjam Buku\n";
        cout << "3. Pengembalian Buku\n";
        cout << "4. Lihat Buku\n";
        cout << "0. Keluar User\n";
        cout << "Pilih: ";
        cin >> pilihan;

        if (pilihan == 1) {
            viewPenulis(L);
        }
        else if (pilihan == 2) {
            int n;
            cout << "Jumlah buku yang ingin dipinjam: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "\nPinjam buku ke-" << (i+1) << endl;
                string idP, idB;

                cout << "ID Penulis: ";
                cin >> idP;
                cout << "ID Buku: ";
                cin >> idB;

                deleteStockBuku(L, idP, idB);
            }
        }
        else if (pilihan==3){



        }
        else if (pilihan==4){
            string idP;
            cout << "Masukkan ID Penulis: ";
            cin >> idP;
            adrPenulis P = findElemenPenulis(L, idP);
            if (P == nullptr) {
                cout << "Penulis tidak ditemukan!\n";
            } else {
                viewBuku(P);
            }
        }
        else if (pilihan == 0) {
            cout << "Keluar dari menu user...\n";
        }

    } while (pilihan != 0);
}

