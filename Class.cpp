#include "Class.h"

RakBuku::RakBuku() {
    std::cout << "Program penyortiran 24 buku tulis ke 4 rak" << std::endl;

    Buku buku[24];
    for (int i = 0; i < 24; i++) {
        buku[i].Nama = "Buku-Tulis-" + std::to_string(i + 1);
        buku[i].Index = i;
    }

    for (int i = 0; i < 24; i++) {
        int j = rand() % 24;
        Buku temp = buku[i];
        buku[i] = buku[j];
        buku[j] = temp;
    }

    for (int i = 0; i < 24; i++) {
        BukuTulis[i] = buku[i];
    }
}

void RakBuku::Sortir() {
    // sort from lowest to highest
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 24; j++) {
            if (BukuTulis[i].Index < BukuTulis[j].Index) {
                Buku temp = BukuTulis[i];
                BukuTulis[i] = BukuTulis[j];
                BukuTulis[j] = temp;
            }
        }
    }

    for (int i = 0; i < 24; i++) {
        int row = i / 6;
        int col = i % 6;

        Rak[row][col] = BukuTulis[i];
    }

    std::cout << "Buku telah disortir dan dimasukan ke RakBuku 2D Array 4x6" << std::endl;
    IsSortYet = true;
}

void RakBuku::Output() {
    if (!IsSortYet) {
        std::cout << "Data belum di sortir" << std::endl;

        // output BukuTulis
        std::cout << "List buku" << std::endl;
        for (int i = 0; i < 24; i++) {
            std::cout << BukuTulis[i].Nama << "\n";
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        std::cout << "Rak " << i + 1 << ": ";
        for (int j = 0; j < 6; j++) {
            std::cout << Rak[i][j].Nama << "\t";
        }

        std::cout << std::endl;
    }
}

void RakBuku::FindByName(std::string bookName) {
    if (!IsSortYet) {
        std::cout << "Data belum di sortir" << std::endl;
        return;
    }

    int row = -1;
    int col = -1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (Rak[i][j].Nama == bookName) {
                row = i;
                col = j;
                break;
            }
        }
    }

    if (row == -1 || col == -1) {
        std::cout << "Buku tidak ditemukan" << std::endl;
        return;
    }

    std::cout << "Buku ditemukan di rak ke: " << row + 1 << ", baris ke: " << col + 1 << std::endl;
}

void RakBuku::FindByIndex(int column, int row) {
    if (!IsSortYet) {
        std::cout << "Data belum di sortir" << std::endl;
        return;
    }

    if (column < 1 || column > 4 || row < 1 || row > 6) {
        std::cout << "Index tidak valid" << std::endl;
        return;
    }
    
    Buku book = Rak[column - 1][row - 1];
    std::cout << "Buku ditemukan dengan nama: " << book.Nama << std::endl;
}
