

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
