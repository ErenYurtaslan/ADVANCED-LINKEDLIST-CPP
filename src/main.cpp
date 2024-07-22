/**
* @file main.cpp


* @description 

sayilariDosyadanOku(SayilarListesi &liste, const string &dosyaYolu): Bu fonksiyon, belirtilen dosya yolu üzerinden sayıları okur.
 Her satırdaki sayılar boşluk karakterine göre ayrılır, bu sayılar Sayi nesnelerine dönüştürülür ve her Sayi nesnesi SayilarListesi'ne bir Dugum olarak eklenir.
main(): Programın ana işlevi burada gerçekleşir.
 İlk olarak, sayilariDosyadanOku fonksiyonu kullanılarak bir dosyadan sayılar okunur ve bir liste oluşturulur. 
 Daha sonra, kullanıcıya bir menü sunulur ve kullanıcıdan bir seçim yapması istenir.
  Kullanıcının seçimine bağlı olarak aşağıdaki işlemler gerçekleştirilir:

        Seçim 1: tekBasamaklariBasaTasi(), sayı listesindeki tüm sayıların tek basamaklarını başa taşır.
        Seçim 2: basamaklariTersCevir(), listedeki her sayının basamaklarını ters çevirir.
        Seçim 3: enBuyukSayiyiBulVeCikar(), listedeki en büyük sayıyı bulur, gösterir ve listeden çıkarır.
        Seçim 4: Programı sonlandırır.

Kullanıcı döngü içerisinde bu seçeneklerden birini seçene kadar program çalışmaya devam eder.
Her seçim sonrasında liste güncellenir ve tekrar yazdırılır. Program, seçim 4 yapıldığında kapanır.

Bu program, sayıları işlemek için bağlı liste veri yapısını kullanır ve bu sayılar üzerinde çeşitli işlemler yaparak kullanıcıya görsel çıktılar sunar.


* @course 1. Öğretim B Grubu
* @assignment 1. Ödev
* @date 26/11/2023 (TAM HALİ)
* @author Eren Yurtaslan abdulkadir.yurtaslan@ogr.sakarya.edu.tr
*/

#include "SayilarListesi.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


void sayilariDosyadanOku(SayilarListesi &liste, const string &dosyaYolu) {
    ifstream dosya(dosyaYolu);
    string satir;

    while (getline(dosya, satir)) {
        stringstream ss(satir);
        string sayiStr;
        
        while (getline(ss, sayiStr, ' ')) { // Boşluk karakterine göre ayır
            Sayi* yeniSayi = new Sayi();
            for (char rakam : sayiStr) {
                int sayi_degeri = rakam - '0';
                yeniSayi->basamakEkle(sayi_degeri);
            }
            yeniSayi->hesaplaDeger();
            Dugum* yeniDugum = new Dugum(yeniSayi);
            liste.sayiEkle(yeniDugum);
        }
    }
    dosya.close();
}


int main() {
    SayilarListesi liste; 
    sayilariDosyadanOku(liste, "sayilar.txt");

    int secim;
    do {
        cout << "********** Sayilar Listesi **********" << endl;
        liste.yazdir();
        cout << "*************************************" << endl;

        cout << "1. Tek basamaklari basa tasi" << endl;
        cout << "2. Sayilarin basamaklarini ters cevir" << endl;
        cout << "3. En buyuk sayiyi cikar" << endl;
        cout << "4. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
            case 1:
                liste.tekBasamaklariBasaTasi();
                cout << "Tek basamaklar basa tasindi." << endl;
                break;
            case 2:
                liste.basamaklariTersCevir();
                cout << "Basamaklar ters cevrildi." << endl;
                break;
            case 3: {
                Dugum* enBuyukDugum = liste.enBuyukSayiyiBulVeCikar();
                if (enBuyukDugum) {
                    cout << "En buyuk sayi cikarildi: "<<endl;
                    enBuyukDugum->sayi->yazdir();
                    delete enBuyukDugum->sayi;
                    delete enBuyukDugum;
                } else {
                    cout << "Listede hic sayi yok!" << endl;
                }
                break;
            }
            case 4:
                cout << "Programdan cikildi." << endl;
                break;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }
    } while (secim != 4);

    return 0;
}
