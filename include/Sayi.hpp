/**
* @file Sayi.hpp

* @description Basamak.hpp'yi include ederek, Sayi listesinin node cinsinin Basamak sınıfı olduğunu anlıyoruz.
Basamak * türünde ilk isimli pointer, ilk elemanı gösterecek. içinde int türünden değer olacak. 
Hemen altında, Sayi.cpp'de implement edilecek olan fonksiyonlar yazmakta.


* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 25/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr
*/



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
