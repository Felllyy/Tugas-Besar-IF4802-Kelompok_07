#include <iostream>
#include "MLL.h"
using namespace std;

void mainAdmin(listPenulis &L) {
    int pilihan;
    do {
        cout << "\n=========== MENU ADMIN ===========\n";
        cout << "1. Tambah Penulis\n";
        cout << "2. Tambah Buku ke Penulis\n";
        cout << "3. Hapus Buku Pertama (deleteFirst)\n";
        cout << "4. Hapus Buku Terakhir (deleteLast)\n";
        cout << "5. Hapus Buku Setelah (deleteAfter)\n";
        cout << "6. Lihat Semua Penulis\n";
        cout << "7. Lihat Semua Buku dari Penulis\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilihan;

        // =============================
        // 1. TAMBAH PENULIS
        // =============================
        if (pilihan == 1) {
            string idP, namaP;
            int terbit;

            cout << "Masukkan ID Penulis: ";
            cin >> idP;

            // ID harus unik
            while (findElemenPenulis(L, idP) != nullptr) {
                cout << "ID sudah ada! Masukkan ID lain: ";
                cin >> idP;
            }

            cout << "Masukkan Nama Penulis: ";
            cin.ignore();
            getline(cin, namaP);

            cout << "Masukkan jumlah buku terbit: ";
            cin >> terbit;

            adrPenulis P = createElemenPenulis(idP, namaP, terbit);
            createListBuku(P);
            insertLastPenulis(L, P);

            cout << "Penulis berhasil ditambahkan!\n";
        }

        // =============================
        // 2. TAMBAH BUKU
        // =============================
        else if (pilihan == 2) {
            string idP, idB, judul;
            int tahun;

            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (P == nullptr) {
                cout << "Penulis tidak ditemukan!\n";
            }
            else {
                cout << "ID Buku: ";
                cin >> idB;

                // Hindari ID Buku kembar
                while (findElemenBuku(P, idB) != nullptr) {
                    cout << "ID buku sudah ada! Masukkan ID lain: ";
                    cin >> idB;
                }

                cout << "Judul Buku: ";
                cin.ignore();
                getline(cin, judul);

                cout << "Tahun terbit: ";
                cin >> tahun;

                adrBuku B = createElmBuku(idB, judul, tahun);
                insertLastBuku(P, B);

                cout << "Buku berhasil ditambahkan!\n";
            }
        }

        // =============================
        // 3. DELETE FIRST BUKU
        // =============================
        else if (pilihan == 3) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (P == nullptr) {
                cout << "Penulis tidak ditemukan!\n";
            } else {
                adrBuku B;
                deleteFirstBuku(P, B);
                cout << "Delete First Buku berhasil.\n";
            }
        }

        // =============================
        // 4. DELETE LAST BUKU
        // =============================
        else if (pilihan == 4) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (P == nullptr) {
                cout << "Penulis tidak ditemukan!\n";
            } else {
                adrBuku B;
                deleteLastBuku(P, B);
                cout << "Delete Last Buku berhasil.\n";
            }
        }

        // =============================
        // 5. DELETE AFTER BUKU
        // =============================
        else if (pilihan == 5) {
            string idP, precID;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (P == nullptr) {
                cout << "Penulis tidak ditemukan!\n";
            }
            else {
                cout << "ID Buku Predecessor: ";
                cin >> precID;

                adrBuku prec = findElemenBuku(P, precID);
                if (prec == nullptr) {
                    cout << "ID Buku precursor tidak ditemukan!\n";
                }
                else {
                    adrBuku B;
                    deleteAfterBuku(P, prec, B);
                    cout << "Delete After berhasil!\n";
                }
            }
        }

        // =============================
        // 6. VIEW SEMUA PENULIS
        // =============================
        else if (pilihan == 6) {
            viewPenulis(L);
        }

        // =============================
        // 7. VIEW SEMUA BUKU DARI PENULIS
        // =============================
        else if (pilihan == 7) {
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

    } while (pilihan != 0);
}

