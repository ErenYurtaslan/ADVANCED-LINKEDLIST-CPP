/**
* @file Dugum.hpp
* @description İçinde Sayi* türünden sayi isminde değer tutan, Dugum* türünden "sonraki" isminde pointer saklayan,
 SayilarListesi listesinin düğüm sınıfı.

* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 25/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr
*/


#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

class Dugum {
public:
    Sayi* sayi;
    Dugum* sonraki;

    Dugum(Sayi* sayi);
};

#endif // DUGUM_HPP
