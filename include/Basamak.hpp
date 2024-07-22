/**
* @file Basamak.hpp

* @description Bir node oluşturma dosyası.
 Sayi listesinin node cinsi işte bu sınıftır.
  Tuttuğu değer sayısal basamak olduğu için haliyle integerdır, ve "sonraki" isimli pointer ile
  bir sonraki adresteki "Basamak" düğümüne ulaşılır.

* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 25/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr 
*/

#ifndef BASAMAK_HPP
#define BASAMAK_HPP

class Basamak {
public:
    int deger;
    Basamak* sonraki;

    Basamak(int deger);
};

#endif // BASAMAK_HPP
