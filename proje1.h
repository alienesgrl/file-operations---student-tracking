/* 
* @file Bp3_Project1 
* @description header dosyasi 
* @assignment 1.proje
* @date 08.12.2023
* @author Ali Enes Gürel 2121221032 alienes.gurel@stu.fsm.edu.tr 
*/

#ifndef proje1
#define proje1

#define MAX_OGRENCI 100
#define MAX_DERS 50

typedef struct
{
    char *dersAdi;
    unsigned short kredi;
    unsigned short puan; // Eğer puan 0 ise, bu ders sonlandırıcı olarak kabul edilebilir.
} Ders;

typedef struct
{
    char *ogrAdi;
    char *ogrSoyAdi;
    char *bolumu;
    float ortalama;
    Ders *aldigiDersler;
} Ogrenci;

extern Ogrenci *globalOgrenciler[MAX_OGRENCI];
extern int globalOgrenciSayisi;
extern Ders *globalDersler[MAX_DERS];
extern int globalDersSayisi;

// Öğrenci ve ders oluşturma fonksiyonları
Ogrenci *yeniOgrenci(char *adi, char *soyadi, char *bolumu, float ortalama);
Ders *yeniDers(char *ad, unsigned short kredi);
void ogrenciListesiniYazdir(Ogrenci *ogrenciler[], int ogrenciSayisi);
// Öğrenciye ders ekleme fonksiyonu
void ogrenciyeDersEkle(Ogrenci *ogrenciler[], int ogrenciSayisi, char *ogrAdi, char *dersAdi, unsigned short int puan);
void dersleriYazdir(const Ders *dersler);
void ogrBilgileriniYazdir(const Ogrenci *o);
// Listeleri yazdırma fonksiyonları
void dersListesiniYazdir(Ders *dersler[], int dersSayisi);
void ogrenciListesiniYazdir(Ogrenci *ogrenciler[], int ogrenciSayisi);
// ortalama
float dersinOrtalamaPuaniniHesapla(Ogrenci *ogrenciler[], int ogrenciSayisi, char *dersAdi);
void dersinOrtalamasi(char *dersAdi);
// standart sapma
float dersinStandartSapmasi(char *dersAdi);
void standartSapmayiYaz(char *dersAdi);
// kovaryans
float dersKovaryansi(Ogrenci *ogrenciler[], int ogrenciSayisi, char *dersAdi1, char *dersAdi2);
void kovaryansiYaz(char *dersAdi1, char *dersAdi2);
// ortalamanin ustunde alan ogrenciler
void ortalamaninUstundeOgrenciler(char *dersAdi);
// dosyaya ogrenci yazdirma
void ogrencileriDosyayaYaz(Ogrenci *ogrenciler[], int ogrenciSayisi, const char *dosyaAdi);
// dosyadan okuma
// void ogrenciBilgileriniDosyadanOku(Ogrenci *ogrenciler, int *ogrenciSayisi, const char *dosyaAdi);
void ogrenciBilgileriniDosyadanOku(char *dosyaAdi);
// Bellek temizleme fonksiyonları
void temizleOgrenci(Ogrenci *o);
void temizleDers(Ders *d);
#endif
