/*
 * @file Bp3_Project1
 * @description Program fonksiyonlarinin bulundugu dosya.
 * @assignment 1.proje
 * @date 08.12.2023
 * @author Ali Enes Gürel 2121221032 alienes.gurel@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "proje1.h"

#define MAX_OGRENCI 100
#define MAX_DERS 50

Ogrenci *globalOgrenciler[MAX_OGRENCI];
int globalOgrenciSayisi = 0;
Ders *globalDersler[MAX_DERS];
int globalDersSayisi = 0;

Ogrenci *yeniOgrenci(char *adi, char *soyadi, char *bolumu, float ortalama)
{
    Ogrenci *o = malloc(sizeof(Ogrenci));
    if (o == NULL)
    {
        return NULL;
    }

    o->ogrAdi = malloc(strlen(adi) + 1); //+1 ile sonlandirma karakterine de yer aciyoruz '\0'
    if (o->ogrAdi != NULL)
        strcpy(o->ogrAdi, adi);

    o->ogrSoyAdi = malloc(strlen(soyadi) + 1);
    if (o->ogrSoyAdi != NULL)
        strcpy(o->ogrSoyAdi, soyadi);

    o->bolumu = malloc(strlen(bolumu) + 1);
    if (o->bolumu != NULL)
        strcpy(o->bolumu, bolumu);

    o->ortalama = ortalama;
    o->aldigiDersler = NULL; // Başlangıçta ders yok

    return o;
}

Ders *yeniDers(char *ad, unsigned short int kredi)
{
    Ders *d = (Ders *)malloc(sizeof(Ders));
    if (d == NULL)
    {
        return NULL;
    }
    d->dersAdi = malloc(strlen(ad) + 1);
    if (d->dersAdi != NULL)
        strcpy(d->dersAdi, ad);
    d->kredi = kredi;
    d->puan = -1;
    return d;
}

void ogrenciyeDersEkle(Ogrenci *ogrenciler[], int ogrenciSayisi, char *ogrAdi, char *dersAdi, unsigned short int puan)
{
    Ogrenci *bulunanOgrenci = NULL;
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        if (strcmp(ogrenciler[i]->ogrAdi, ogrAdi) == 0) // strcmp ile karsilastiriyoruz
        {
            bulunanOgrenci = ogrenciler[i];
            break;
        }
    }

    if (bulunanOgrenci == NULL)
    {
        printf("Ogrenci bulunamadi.\n");
        return;
    }
    int dersSayisi = 0;
    while (bulunanOgrenci->aldigiDersler && bulunanOgrenci->aldigiDersler[dersSayisi].puan != 0)
    {
        dersSayisi++;
    }

    Ders *yeniDersler = realloc(bulunanOgrenci->aldigiDersler, (dersSayisi + 2) * sizeof(Ders));
    if (yeniDersler == NULL)
    {
        printf("hata!\n");
        return;
    }
    bulunanOgrenci->aldigiDersler = yeniDersler;
    bulunanOgrenci->aldigiDersler[dersSayisi].dersAdi = dersAdi;
    bulunanOgrenci->aldigiDersler[dersSayisi].puan = puan;
    // 0 puan ekleyerek liste sonunu belirliyoruz
    bulunanOgrenci->aldigiDersler[dersSayisi + 1].dersAdi = NULL;
    bulunanOgrenci->aldigiDersler[dersSayisi + 1].puan = 0;
}

// Öğrencinin aldigi derslerin ayrintilarini yazdirma
void dersleriYazdir(const Ders *dersler)
{
    int i = 0;
    while (dersler[i].puan != 0)
    { // Sonlandirici ders 0 puanla belirlendi
        printf("\tDers Adi: %s, Puan: %hu\n", dersler[i].dersAdi, dersler[i].puan);
        i++;
    }
}

// Ogrenci bilgilerini yazdirma
void ogrBilgileriniYazdir(const Ogrenci *o)
{

    printf("Ogrenci Adi: %s\n", o->ogrAdi);
    printf("Ogrenci Soyadi: %s\n", o->ogrSoyAdi);
    printf("Bolumu: %s\n", o->bolumu);
    printf("Ortalama: %.2f\n", o->ortalama);
    if (o->aldigiDersler != NULL)
    {
        printf("Aldigi Dersler:\n");
        dersleriYazdir(o->aldigiDersler);
    }
    else
    {
        printf("Ogrencinin kayitli dersi bulunmamaktadir.\n");
    }
}
float dersinOrtalamaPuaniniHesapla(Ogrenci *ogrenciler[], int ogrenciSayisi, char *dersAdi)
{
    int toplamPuan = 0;
    int dersiAlanOgrenciSayisi = 0;

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        Ogrenci *o = ogrenciler[i];
        int j = 0;
        while (o->aldigiDersler && o->aldigiDersler[j].puan != 0)
        {
            if (strcmp(o->aldigiDersler[j].dersAdi, dersAdi) == 0)
            {
                toplamPuan += o->aldigiDersler[j].puan;
                dersiAlanOgrenciSayisi++;
            }
            j++;
        }
    }

    if (dersiAlanOgrenciSayisi == 0)
        return 0.0; // Dersi alan öğrenci yoksa
    return (float)toplamPuan / dersiAlanOgrenciSayisi;
}
void dersListesiniYazdir(Ders *dersler[], int dersSayisi)
{
    printf("Ders Listesi:\n");
    for (int i = 0; i < dersSayisi; i++)
    {
        if (dersler[i] != NULL)
        {
            float ortalamaPuan = dersinOrtalamaPuaniniHesapla(globalOgrenciler, globalOgrenciSayisi, dersler[i]->dersAdi);
            printf("Ders Adi: %s, Kredi: %hu, Ortalama Puan: %.2f\n", dersler[i]->dersAdi, dersler[i]->kredi, ortalamaPuan);
        }
    }
}

void dersinOrtalamasi(char *dersAdi)
{
    int dersBulundu = 0;
    for (int i = 0; i < globalDersSayisi; i++)
    {
        if (strcmp(globalDersler[i]->dersAdi, dersAdi) == 0)
        {
            float ortalamaPuan = dersinOrtalamaPuaniniHesapla(globalOgrenciler, globalOgrenciSayisi, globalDersler[i]->dersAdi);
            printf("Ders Adi: %s, Kredi: %hu, Ortalama Puan: %.2f\n", globalDersler[i]->dersAdi, globalDersler[i]->kredi, ortalamaPuan);
            dersBulundu = 1;
            break;
        }
    }
    if (!dersBulundu)
    {
        printf("Ders bulunamadi!\n");
    }
}
float dersinStandartSapmasi(char *dersAdi)
{
    float ortalama = dersinOrtalamaPuaniniHesapla(globalOgrenciler, globalOgrenciSayisi, dersAdi);
    float toplamKareFark = 0;
    int dersiAlanOgrenciSayisi = 0;

    for (int i = 0; i < globalOgrenciSayisi; i++)
    {
        Ogrenci *o = globalOgrenciler[i];
        int j = 0;
        while (o->aldigiDersler && o->aldigiDersler[j].puan != 0)
        {
            if (strcmp(o->aldigiDersler[j].dersAdi, dersAdi) == 0) // dersi bulduk
            {
                float fark = o->aldigiDersler[j].puan - ortalama; //(puan-ortalama)
                // printf("\n%d\n", globalOgrenciler[i]->aldigiDersler[j].puan);
                toplamKareFark += fark * fark; //(puan-ortalama)^2
                dersiAlanOgrenciSayisi++;
            }
            j++;
        }
    }

    if (dersiAlanOgrenciSayisi <= 1)
        return 0.0; // Standart sapma hesaplanamaz

    float varyans = toplamKareFark / (dersiAlanOgrenciSayisi); // karekok((puan-ortalama)^2/(dersi alan ogr sayisi))
    return sqrt(varyans);
}
void standartSapmayiYaz(char *dersAdi)
{
    float standartSapma = dersinStandartSapmasi(dersAdi);
    printf("%s dersinin standart sapmasi: %.2f\n", dersAdi, standartSapma);
}
float dersKovaryansi(Ogrenci *ogrenciler[], int ogrenciSayisi, char *dersAdi1, char *dersAdi2)
{
    float ortalama1 = dersinOrtalamaPuaniniHesapla(ogrenciler, ogrenciSayisi, dersAdi1);
    float ortalama2 = dersinOrtalamaPuaniniHesapla(ogrenciler, ogrenciSayisi, dersAdi2);

    float toplamCarpim = 0;
    int ortakDersSayisi = 0;

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        int puan1 = -1, puan2 = -1;

        for (int j = 0; ogrenciler[i]->aldigiDersler[j].puan != 0; j++)
        {
            if (strcmp(ogrenciler[i]->aldigiDersler[j].dersAdi, dersAdi1) == 0)
            {
                puan1 = ogrenciler[i]->aldigiDersler[j].puan;
            }
            if (strcmp(ogrenciler[i]->aldigiDersler[j].dersAdi, dersAdi2) == 0)
            {
                puan2 = ogrenciler[i]->aldigiDersler[j].puan;
            }
        }
        if (puan1 != -1 && puan2 != -1)
        {
            toplamCarpim += (puan1 - ortalama1) * (puan2 - ortalama2); // ∑i=0 n (Xi - Xortalama)(Yi - Yortalama)
            ortakDersSayisi++;                                         //----------------------------------------------
        }                                                              //            (n)
    }

    if (ortakDersSayisi == 0)
        return 0.0; // Ortak ders yoksa
    return toplamCarpim / (ortakDersSayisi);
}
void kovaryansiYaz(char *dersAdi1, char *dersAdi2)
{
    float kovaryans = dersKovaryansi(globalOgrenciler, globalOgrenciSayisi, dersAdi1, dersAdi2);
    printf("%s ile %s dersinin kovaryansi = %.2f \n", dersAdi1, dersAdi2, kovaryans);
}
void ortalamaninUstundeOgrenciler(char *dersAdi)
{
    float ortalamaPuan = dersinOrtalamaPuaniniHesapla(globalOgrenciler, globalOgrenciSayisi, dersAdi);
    printf("----------------------------------");
    printf("\n%s dersinin ortalama puani: %.2f\n", dersAdi, ortalamaPuan);
    printf("Ortalama puanin uzerinde not alan ogrenciler:\n");

    for (int i = 0; i < globalOgrenciSayisi; i++)
    {
        Ogrenci *o = globalOgrenciler[i];
        int j = 0;
        while (o->aldigiDersler && o->aldigiDersler[j].puan != 0)
        {
            if (strcmp(o->aldigiDersler[j].dersAdi, dersAdi) == 0 && o->aldigiDersler[j].puan > ortalamaPuan)
            {
                printf("\t%s %s\tpuani: %d\n", o->ogrAdi, o->ogrSoyAdi, o->aldigiDersler[j].puan);
                break; // Öğrenciyi sadece bir kez listele
            }
            j++;
        }
    }
}

// Tüm öğrencileri ve aldıkları dersleri yazdırma
void ogrenciListesiniYazdir(Ogrenci *ogrenciler[], int ogrenciSayisi)
{
    printf("Ogrenci Listesi:\n");
    for (int i = 0; i < ogrenciSayisi; i++)
    {
        if (ogrenciler[i] != NULL)
        {
            ogrBilgileriniYazdir(ogrenciler[i]);
            printf("\n");
        }
    }
}

// Ders yapısını temizleme
void temizleDers(Ders *d)
{
    if (d != NULL)
    {
        free(d->dersAdi);
        free(d); // Ders yapısını serbest bırak
    }
}
// Ogrenci yapısını ve ilişkili dersleri temizleme
void temizleOgrenci(Ogrenci *o)
{
    if (o != NULL)
    {
        free(o->ogrAdi);
        free(o->ogrSoyAdi);
        free(o->bolumu);

        // Dersleri serbest bırak
        if (o->aldigiDersler != NULL)
        {
            free(o->aldigiDersler); // Dersler dizisini serbest bırak
        }

        free(o); // Ogrenci yapısını serbest bırak
    }
}
void ogrencileriDosyayaYaz(Ogrenci *ogrenciler[], int ogrenciSayisi, const char *dosyaAdi)
{
    FILE *dosya = fopen(dosyaAdi, "w"); // Dosyayı yazma modunda aç
    if (dosya == NULL)
    {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < ogrenciSayisi; i++)
    {
        Ogrenci *o = ogrenciler[i];
        fprintf(dosya, "Ogrenci Adi: %s, Ogrenci Soyadi: %s, Bolum: %s\n", o->ogrAdi, o->ogrSoyAdi, o->bolumu);
        fprintf(dosya, "Aldigi Dersler:\n");
        int j = 0;
        while (o->aldigiDersler && o->aldigiDersler[j].puan != 0)
        {
            fprintf(dosya, "\tDers Adi: %s, Puan: %hu\n", o->aldigiDersler[j].dersAdi, o->aldigiDersler[j].puan);
            j++;
        }
        fprintf(dosya, "\n");
    }

    fclose(dosya); // Dosyayı kapat
}