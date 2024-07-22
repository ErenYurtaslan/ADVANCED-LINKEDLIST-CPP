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


