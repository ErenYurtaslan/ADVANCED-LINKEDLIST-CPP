/**
* @file SayilarListesi.cpp

* @description Metotları açıklamak gerekirse;
-Constructor ile okunan txt'deki yeni sayılar, yeni bir SayilarListesi elemanı oluyor.
-Destructor ile memory leak'in önüne geçiliyor ve stack temizleniyor.
-sayiEkle: dosya okuma işleminde dosyadaki sayıları eklemede kullanılıyor. hiç sayı yoksa ilk
eleman ataması yapılıyor, başka sayı önceden varsa sıraya ekleniyor.
-basamaklariTersCevir: sayının basamaklarını tam tersi yönünde işaretleyerek değiştirme işlemi. bunu yaparken sayi.cpp
dosyasındaki basamaklariTersCevir metodunu kullanıyor.
-tekBasamaklariBasaTasi: tek sayı olan basamakları en başa atama işlemi. 
main.cpp'deki aynı isimli metottan faydalanıyor çünkü öncelikle işlemler bir alt listede yapılmalı ki sayının bütünü bozulmasın.
-enBuyukSayiyiBulVeCikar: bu metodun özü işte bu sayfada. çünkü sayı kıyaslaması yapmamız gerekiyor ve
bunu Sayi* türünde değer tutan bu sayfada yapmalıyız. Sonuç olarak rakamlar değil büyük sayılar kıyaslanacak ve o sayının 
sahip olduğu tüm basamaklar silinecek.
-yazdir:sayi.cpp'de aslı bulunan metotlardan biri. Yazdırma işleminin detaylarına orada yer verilecektir.

* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 26/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.hpp"
#include <iostream>


SayilarListesi::SayilarListesi() : ilk(nullptr) {}


SayilarListesi::~SayilarListesi() {
    while (ilk != nullptr) {
        Dugum* toDelete = ilk;
        ilk = ilk->sonraki;
        delete toDelete->sayi; 
        delete toDelete; 
    }
}


void SayilarListesi::sayiEkle(Dugum* yeniDugum) {
    if (ilk == nullptr) {
        ilk = yeniDugum;
    } else {
        Dugum* temp = ilk;
        while (temp->sonraki != nullptr) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeniDugum;
    }
}




void SayilarListesi::basamaklariTersCevir() {
    Dugum* current = ilk;
    while (current != nullptr) {
        current->sayi->basamaklariTersCevir();
        current = current->sonraki;
    }
}


void SayilarListesi::tekBasamaklariBasaTasi() {
    Dugum* current = ilk;
    while (current != nullptr) {
        current->sayi->tekBasamaklariBasaTasi();
        current = current->sonraki;
    }
}




Dugum* SayilarListesi::enBuyukSayiyiBulVeCikar() {
    if (ilk == nullptr) return nullptr;

    Dugum* maxDugumOnceki = nullptr;
    Dugum* maxDugum = ilk;
    Dugum* current = ilk;
    int maxDeger = ilk->sayi->deger;

    while (current->sonraki != nullptr) {
        if (current->sonraki->sayi->deger > maxDeger) {
            maxDeger = current->sonraki->sayi->deger;
            maxDugumOnceki = current;
            maxDugum = current->sonraki;
        }
        current = current->sonraki;
    }

    if (maxDugumOnceki != nullptr) {
        maxDugumOnceki->sonraki = maxDugum->sonraki;
    } else {
        ilk = maxDugum->sonraki;
    }

    maxDugum->sonraki = nullptr;
    return maxDugum; 
}


void SayilarListesi::yazdir() {
    Dugum* current = ilk;
    while (current != nullptr) {
        current->sayi->yazdir(); 
        current = current->sonraki;
    }
}


