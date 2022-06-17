#pragma once
#include <iostream>

struct Buku {
    std::string Nama;
    int Index;
};

class RakBuku {
    public:
        RakBuku();
        void Sortir();
        void Output();
        void FindByName(std::string);
        void FindByIndex(int column, int row);
        
        bool IsSortYet = false;
        Buku BukuTulis[24];
        Buku Rak[4][6];
};
