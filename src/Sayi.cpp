/**
* @file Sayi.cpp
* @description 
Constructor ve Destructor (Sayi() ve ~Sayi()): Sayi sınıfının constructor'ı (Sayi()) yeni bir Sayi nesnesi oluşturduğunda başlangıç değerleri atar.
Destructor (~Sayi()) ise Sayi nesnesi silindiğinde tüm Basamak nesnelerini siler, böylece memory leak olmaz.
basamakEkle(int deger): Bu metot, verilen değere sahip yeni bir Basamak nesnesi oluşturur ve bu nesneyi Sayi nesnesinin sonuna ekler.
hesaplaDeger(): Bu metot, bağlı listedeki tüm basamakları dolaşarak Sayi nesnesinin sayısal değerini hesaplar.
basamaklariTersCevir(): Bu metot, bağlı listeyi tersine çevirir, yani sayının basamaklarını ters sırayla yerleştirir.
tekBasamaklariBasaTasi(): Bu metot, sayının tek basamaklarını başa ve çift basamaklarını sona taşıyarak iki ayrı liste oluşturur ve sonra bu listeleri birleştirir.
yazdir(): Bu metot, Sayi nesnesinin ve içindeki tüm Basamak nesnelerinin değerlerini ve adreslerini bir çerçeve içinde görsel bir şekilde yazdırır.
setw setfill gibi özelliklerle daha estetik bir çıktı oluşturulmaya çalışılmıştır.

Kısacası bu dosya, sayısal verileri bağlı liste yapısı kullanarak işlemek
ve bu işlemlerin sonuçlarını kullanıcıya görsel bir şekilde sunmak için tasarlanmıştır.

* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 26/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr 
*/

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
