#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
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
            mainUser(L);
        }
        else if (pilih == 0) {
            cout << "Program selesai.\n";
        }

    } while (pilih != 0);

    return 0;
}

}
