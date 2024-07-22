
#ifndef SAYILAR_LISTESI_HPP
#define SAYILAR_LISTESI_HPP

#include "Dugum.hpp"

class SayilarListesi {
public:
    Dugum* ilk;

    SayilarListesi();
    ~SayilarListesi();
    void sayiEkle(Dugum* yeniDugum);
    void basamaklariTersCevir();
    void tekBasamaklariBasaTasi();
    Dugum* enBuyukSayiyiBulVeCikar();
    void yazdir();
};

#endif 
