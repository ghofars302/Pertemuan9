#include "Class.h"

int main() {
    RakBuku rak;
    
    while (true) {
        std::cout << "1. Sortir buku" << std::endl;
        std::cout << "2. Output rak atau buku" << std::endl;
        std::cout << "3. Cari nomor Rak buku dan baris keberapa dengan nama buku" << std::endl;
        std::cout << "4. Cari nama buku berdasarkan rak buku dan baris" << std::endl;

        int n = 0;
        std::cout << "Pilih menu: "; std::cin >> n;

        switch (n) {
            case 1: {
                rak.Sortir();
                break;
            }
            case 2: {
                rak.Output();
                break;
            }
            case 3: {
                std::cin.ignore();

                std::string bookName;
                std::cout << "Nama buku: "; std::getline(std::cin, bookName);
                rak.FindByName(bookName);
                break;
            }
            case 4: {
                int row, col;
                std::cout << "Rak: "; std::cin >> row;
                std::cout << "Baris: "; std::cin >> col;

                rak.FindByIndex(row, col);
                break;
            }
            default: {
                std::cout << "Menu tidak ada" << std::endl;
                break;
            }
        }

        std::cout << std::endl; std::cout << std::endl;
    }
}
