/* 
Kodu Derleme ve Calistirma
1- g++ -std=c++17 DosyaIsimleri.cpp -o Dosya
2- ./Dosya
*/

#include <iostream>
#include <cstring>
#include <filesystem>

#define MAKSIMUM_DOSYA_SAYISI 50 //Klasorde bulunabilecek tahmini maksimum dosya sayisi...

namespace fs = std::filesystem; //c++17'ye ozel...

int main (void){

    int dosyaSayisi = 0; //Yazdirirken kullanilacak.
    const char *dosyaYolu="/home/zeobora/Desktop"; //Icindeki dosyalari bulmak istediginiz klasorun konumu...
    char *dosyalarinKonumlari[MAKSIMUM_DOSYA_SAYISI]; //Dosyalarin konumlarini tutacak...
    char *dosyaIsimleri[MAKSIMUM_DOSYA_SAYISI]; //Dosyalarin isimlerini tutacak...

    /*
    Asagida dosyalarin isimleri ve konumlarinin char pointer hali icin bellekte yer ayiriyoruz.
    Isim ve konumlar string halde geliyor diye c_str() fonskiyonu ile char pointer'a ceviriyoruz.
    Isim ve konumlari char pointer dizisine atayarak sakliyoruz.
    */
   
    for (const auto & yol : fs::directory_iterator(dosyaYolu)){ 
        dosyaIsimleri[dosyaSayisi] = new char[strlen( yol.path().c_str() ) - strlen(dosyaYolu) + 1];
        strncpy(dosyaIsimleri[dosyaSayisi], ( yol.path().c_str() + strlen(dosyaYolu) ), ( strlen( yol.path().c_str()) - strlen(dosyaYolu) + 1 ));

        dosyalarinKonumlari[dosyaSayisi]=new char[strlen( yol.path().c_str() ) + 1];
        strncpy(dosyalarinKonumlari[dosyaSayisi++], ( yol.path().c_str() ), ( strlen( yol.path().c_str()) + 1 )); 
    } 

    std::cout << "Dosya Isimleri: "; //Dosyalarin isimlerini ekrana yazdiriyoruz.
    for ( int i = 0 ; i < dosyaSayisi ; i++ ){
        std::cout << dosyaIsimleri[i] << " " << std::endl;
    }
    
    std::cout << "Dosyalarin Konumlari: " << std::endl; //Dosyalarin konumlarini ekrana yazdiriyoruz.
    for( int i = 0 ; i < dosyaSayisi ; i++ ){
        std::cout << dosyalarinKonumlari[i] << std::endl;
    }
    
    for (int i = 0; i < dosyaSayisi; i++) { //Bellekten siliyoruz.
        delete[] dosyaIsimleri[i]; 
        delete[] dosyalarinKonumlari[i]; 
    }
    
    return 0;
}
