#include <iostream>
#include "MLL.h"
using namespace std;

void mainAdmin(listPenulis &L) {
    int pilihan;
    do {
        cout << "\n=========== MENU ADMIN ===========\n";
        cout << "1. CreateListPenulis\n";
        cout << "2. CreateElementPenulis\n";
        cout << "3. CreateElementBuku\n";
        cout << "4. Tambah Penulis (insertFirstPenulis)\n";
        cout << "5. Tambah Penulis (insertAfterPenulis)\n";
        cout << "6. Tambah Penulis (insertLastPenulis)\n";
        cout << "7. Hapus Penulis Pertama (deleteFirstPenulis)\n";
        cout << "8. Hapus Penulis Terakhir (deleteLastPenulis)\n";
        cout << "9. Hapus Penulis Setelah (deleteAfterPenulis)\n";
        cout << "10. Tambah Buku (insertFirstBuku)\n";
        cout << "11. Tambah Buku (insertAfterBuku)\n";
        cout << "12. Tambah Buku (insertLastBuku)\n";
        cout << "13. Hapus Buku Pertama (deleteFirstBuku)\n";
        cout << "14. Hapus Buku Terakhir (deleteLastBuku)\n";
        cout << "15. Hapus Buku Setelah (deleteAfterBuku)\n";
        cout << "16. Cari Buku\n";
        cout << "17. Cari Penulis\n";
        cout << "18. Lihat Semua Penulis\n";
        cout << "19. Lihat Semua Buku dari Penulis\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Pilih: ";
        cin >> pilihan;


        // 1. CREATE LIST PENULIS
        if (pilihan == 1) {
            createListPenulis(L);
            cout << "List Penulis berhasil dibuat!\n";
        }
        // 2. CREATE ELEMENT PENULIS
            else if (pilihan == 2) {
            string idP, nama;
            int terbit;

            cout << "Masukkan ID Penulis: ";
            cin >> idP;

            while (findElemenPenulis(L, idP) != nullptr) {
                cout << "ID sudah ada! Masukkan ID lain: ";
                cin >> idP;
            }

            cout << "Nama Penulis: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Jumlah Buku Terbit: ";
            cin >> terbit;

            adrPenulis P = createElemenPenulis(idP, nama, terbit);
            createListBuku(P);

            cout << "Element Penulis berhasil dibuat!\n";
        }

        // 3. CREATE ELEMENT BUKU
        else if (pilihan == 3) {
            string idB, judul;
            int tahun;

            cout << "Masukkan ID Buku: ";
            cin >> idB;

            cout << "Judul Buku: ";
            cin.ignore();
            getline(cin, judul);

            cout << "Tahun Terbit: ";
            cin >> tahun;

            adrBuku B = createElmBuku(idB, judul, tahun);
            cout << "Element Buku berhasil dibuat!\n";
        }
        // 4. INSERT FIRST PENULIS
        else if (pilihan == 4) {
            string idP, nama;
            int terbit;

            cout << "Masukkan ID Penulis: ";
            cin >> idP;

            while (findElemenPenulis(L, idP)) {
                cout << "ID sudah ada! Masukkan ID lain: ";
                cin >> idP;
            }

            cout << "Nama Penulis: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Jumlah buku terbit: ";
            cin >> terbit;

            adrPenulis P = createElemenPenulis(idP, nama, terbit);
            createListBuku(P);
            insertFirstPenulis(L, P);

            cout << "Insert First Penulis berhasil!\n";
        }
        // 5. INSERT AFTER PENULIS
        else if (pilihan == 5) {
            string precID, idP, nama;
            int terbit;

            cout << "Masukkan ID Penulis sebelum posisi insert: ";
            cin >> precID;

            adrPenulis Prec = findElemenPenulis(L, precID);

            if (!Prec) cout << "ID tersebut tidak ditemukan!\n";
            else {
                cout << "Masukkan ID Penulis Baru: ";
                cin >> idP;

                while (findElemenPenulis(L, idP)) {
                    cout << "ID sudah ada! Masukkan ID lain: ";
                    cin >> idP;
                }

                cout << "Nama Penulis Baru: ";
                cin.ignore();
                getline(cin, nama);

                cout << "Jumlah Buku Terbit: ";
                cin >> terbit;

                adrPenulis P = createElemenPenulis(idP, nama, terbit);
                createListBuku(P);

                insertAfterPenulis(L, Prec, P);
                cout << "Insert After Penulis berhasil!\n";
            }
        }
        // 6. INSERT LAST PENULIS
        else if (pilihan == 6) {
            string idP, nama;
            int terbit;

            cout << "Masukkan ID Penulis: ";
            cin >> idP;

            while (findElemenPenulis(L, idP)) {
                cout << "ID sudah ada! Masukkan ID lain: ";
                cin >> idP;
            }

            cout << "Nama Penulis: ";
            cin.ignore();
            getline(cin, nama);

            cout << "Jumlah Buku Terbit: ";
            cin >> terbit;

            adrPenulis P = createElemenPenulis(idP, nama, terbit);
            createListBuku(P);

            insertLastPenulis(L, P);
            cout << "Insert Last Penulis berhasil!\n";
        }
        // 7. DELETE FIRST PENULIS
        else if (pilihan == 7) {
            adrPenulis P;
            deleteFirstPenulis(L, P);
            cout << "Delete First Penulis berhasil!\n";
        }
        // 8. DELETE LAST PENULIS
        else if (pilihan == 8) {
            adrPenulis P;
            deleteLastPenulis(L, P);
            cout << "Delete Last Penulis berhasil!\n";
        }
        // 9. DELETE AFTER PENULIS
        else if (pilihan == 9) {
            string precID;
            cout << "Masukkan ID Penulis (prec): ";
            cin >> precID;

            adrPenulis Prec = findElemenPenulis(L, precID);

            if (!Prec) cout << "Penulis tidak ditemukan!\n";
            else {
                adrPenulis del;
                deleteAfterPenulis(L, Prec, del);
                cout << "Delete After Penulis berhasil!\n";
            }
        }
        // 10. INSERT FIRST BUKU
        else if (pilihan == 10) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                string idB, judul;
                int tahun;

                cout << "ID Buku: ";
                cin >> idB;

                cout << "Judul: ";
                cin.ignore();
                getline(cin, judul);

                cout << "Tahun: ";
                cin >> tahun;

                insertFirstBuku(P, createElmBuku(idB, judul, tahun));
                cout << "Insert First Buku berhasil!\n";
            }
        }
        // 11. INSERT AFTER BUKU
        else if (pilihan == 11) {
            string idP, precID;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                cout << "ID Buku sebelum posisi insert: ";
                cin >> precID;

                adrBuku Prec = findElemenBuku(P, precID);
                if (!Prec) cout << "Buku tidak ditemukan!\n";
                else {
                    string idB, judul;
                    int tahun;

                    cout << "ID Buku Baru: ";
                    cin >> idB;

                    cout << "Judul: ";
                    cin.ignore();
                    getline(cin, judul);

                    cout << "Tahun: ";
                    cin >> tahun;

                    insertAfterBuku(P, Prec, createElmBuku(idB, judul, tahun));
                    cout << "Insert After Buku berhasil!\n";
                }
            }
        }
        // 12. INSERT LAST BUKU
        else if (pilihan == 12) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                string idB, judul;
                int tahun;

                cout << "ID Buku: ";
                cin >> idB;

                cout << "Judul Buku: ";
                cin.ignore();
                getline(cin, judul);

                cout << "Tahun Terbit: ";
                cin >> tahun;

                insertLastBuku(P, createElmBuku(idB, judul, tahun));
                cout << "Insert Last Buku berhasil!\n";
            }
        }
        // 13. DELETE FIRST BUKU
        else if (pilihan == 13) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);
            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                adrBuku del;
                deleteFirstBuku(P, del);
                cout << "Delete First Buku berhasil!\n";
            }
        }
        // 14. DELETE LAST BUKU
        else if (pilihan == 14) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);

            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                adrBuku del;
                deleteLastBuku(P, del);
                cout << "Delete Last Buku berhasil!\n";
            }
        }
        // 15. DELETE AFTER BUKU
        else if (pilihan == 15) {
            string idP, precID;

            cout << "ID Penulis: ";
            cin >> idP;
            adrPenulis P = findElemenPenulis(L, idP);

            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                cout << "ID Buku sebelum delete: ";
                cin >> precID;

                adrBuku Prec = findElemenBuku(P, precID);

                if (!Prec) cout << "Buku tidak ditemukan!\n";
                else {
                    adrBuku del;
                    deleteAfterBuku(P, Prec, del);
                    cout << "Delete After Buku berhasil!\n";
                }
            }
        }
        // 16. CARI BUKU

        else if (pilihan == 16) {
            string idP, idB;

            cout << "ID Penulis: ";
            cin >> idP;

            cout << "ID Buku: ";
            cin >> idB;

            adrPenulis P = findElemenPenulis(L, idP);

            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                adrBuku B = findElemenBuku(P, idB);

                if (!B) cout << "Buku tidak ditemukan!\n";
                else {
                    cout << "\n===== DATA BUKU =====\n";
                    cout << "ID Buku  : " << B->infoBuku.idBuku << endl;
                    cout << "Judul    : " << B->infoBuku.judul << endl;
                    cout << "Tahun    : " << B->infoBuku.tahunTerbit << endl;
                }
            }
        }
        // 17. CARI PENULIS
            else if (pilihan == 17) {
            string idP;

            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);

            if (!P) cout << "Penulis tidak ditemukan!\n";
            else {
                cout << "\n===== DATA PENULIS =====\n";
                cout << "ID Penulis : " << P->infoPenulis.idPenulis << endl;
                cout << "Nama       : " << P->infoPenulis.nama << endl;
                cout << "Buku Terbit: " << P->infoPenulis.bukuTerbit << endl;
            }
        }

        // 18. VIEW ALL PENULIS
        else if (pilihan == 18) {
            viewPenulis(L);
        }
        // 19. VIEW ALL BUKU DARI PENULIS
        else if (pilihan == 19) {
            string idP;
            cout << "ID Penulis: ";
            cin >> idP;

            adrPenulis P = findElemenPenulis(L, idP);

            if (!P) cout << "Penulis tidak ditemukan!\n";
            else viewBuku(P);
        }

    } while (pilihan != 0);
}
