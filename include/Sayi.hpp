

#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"

class Sayi {
public:
    Basamak* ilk;
    int deger; // Sayının toplam değeri veya başka bir ölçütü

    Sayi();
    ~Sayi();
    void basamakEkle(int deger);
    void hesaplaDeger(); // Sayının değerini hesaplayan metod
    void basamaklariTersCevir();
    void tekBasamaklariBasaTasi();
    void yazdir();
};

#endif 
