/**
* @file SayilarListesi.hpp


* @description SayilarListesi isimli bağlı listenin header dosyası.
 Dugum.hpp'yi include ederek onun özelliklerini alır ve düğümlerini "Dugum" türünde oluşturur.
 Dugum* türünde bir pointer oluşturarak bunu ilk elemanı gösterecek biçimde ayarlar.
 Hemen altında, SayilarListesi.cpp'de implement edilecek olan fonksiyonlar yazmakta.


* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 25/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr
*/



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
