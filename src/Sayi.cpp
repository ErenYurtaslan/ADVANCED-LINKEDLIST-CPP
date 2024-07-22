

#include "Sayi.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

Sayi::Sayi() : ilk(nullptr), deger(0) {}

Sayi::~Sayi() {
    Basamak* current = ilk;
    while (current != nullptr) {
        Basamak* next = current->sonraki;
        delete current;
        current = next;
    }
}

void Sayi::basamakEkle(int deger) {
    Basamak* yeniBasamak = new Basamak(deger);
    if (ilk == nullptr) {
        ilk = yeniBasamak;
    } else {
        Basamak* temp = ilk;
        while (temp->sonraki != nullptr) {
            temp = temp->sonraki;
        }
        temp->sonraki = yeniBasamak;
    }
}

void Sayi::hesaplaDeger() {
    deger = 0;
    Basamak* current = ilk;
    
    while (current != nullptr) {
        deger = deger * 10 + current->deger;
        current = current->sonraki;
    }
}



void Sayi::basamaklariTersCevir() {
    Basamak* prev = nullptr;
    Basamak* current = ilk;
    while (current != nullptr) {
        Basamak* next = current->sonraki;
        current->sonraki = prev;
        prev = current;
        current = next;
    }
    ilk = prev;
    // Basamakları ters çevirdikten sonra sayının değerini yeniden hesapla
    hesaplaDeger();
}





void Sayi::tekBasamaklariBasaTasi() {
    Basamak *tekBasamaklar = nullptr, *tekSon = nullptr;
    Basamak *ciftBasamaklar = nullptr, *ciftSon = nullptr;
    Basamak *mevcut = ilk;

    while (mevcut != nullptr) {
        Basamak* sonraki = mevcut->sonraki;

        if (mevcut->deger % 2 == 1) { // Tek basamak kontrolü
            if (tekBasamaklar == nullptr) {
                tekBasamaklar = mevcut;
            } else {
                tekSon->sonraki = mevcut;
            }
            tekSon = mevcut;
        } else { // Çift basamak kontrolü
            if (ciftBasamaklar == nullptr) {
                ciftBasamaklar = mevcut;
            } else {
                ciftSon->sonraki = mevcut;
            }
            ciftSon = mevcut;
        }

        mevcut->sonraki = nullptr; // Mevcut düğümün sonraki pointer'ını kes
        mevcut = sonraki; // Sonraki düğüme geç
    }

    // Tek ve çift basamaklı listeleri birleştir
    if (tekBasamaklar != nullptr) {
        ilk = tekBasamaklar;
        tekSon->sonraki = ciftBasamaklar;
    } else {
        ilk = ciftBasamaklar;
    }
    
    // Değerin güncellenmesi
    hesaplaDeger();
}



//İşler karmaşıklaştığı için adımları tek tek yazdım.

void Sayi::yazdir() {
    // Sayi nesnesi için çerçeve
    cout << "###########        ";
    Basamak* current = ilk;
    while (current) {
        // Basamak nesnesi için çerçeve
        cout << "********     ";
        current = current->sonraki;
    }
    cout << endl;

    // Sayi nesnesinin adresi
    cout << "#" << setw(9) << setfill(' ') << reinterpret_cast<uintptr_t>(this) << "#        ";
    current = ilk;
    while (current) {
        // Basamak nesnesinin adresinin son üç hanesi
        cout << "*  " << setw(3) << setfill('0') << (reinterpret_cast<uintptr_t>(current) % 1000) << " *     ";
        current = current->sonraki;
    }
    cout << endl;

    // Sayi nesnesi ve Basamak nesneleri için ayırıcı
    cout << "#---------#        ";
    current = ilk;
    while (current) {
        // Ayırıcı
        cout << "********     ";
        current = current->sonraki;
    }
    cout << endl;

    // Sayi nesnesinin değeri
    cout << "#" << setw(9) << setfill(' ') << deger << "#        ";
    current = ilk;
    while (current) {
        // Basamak nesnesinin değeri
        cout << "*  " << setw(1) << current->deger << "   *     ";
        current = current->sonraki;
    }
    cout << endl;

    // Sayi nesnesi ve Basamak nesneleri için alt çerçeve
    cout << "###########        ";
    current = ilk;
    while (current) {
        // Alt çerçeve
        cout << "********     ";
        current = current->sonraki;
    }
    cout << endl<<endl<<endl;
}
