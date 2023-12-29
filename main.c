/*
 * @file Bp3_Project1
 * @description tum fonksiyonlar burada cagirilir.
 * @assignment 1.proje
 * @date 08.12.2023
 * @author Ali Enes Gürel 2121221032 alienes.gurel@stu.fsm.edu.tr
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proje1.h"

int main(int argc, char const *argv[])
{
    // dosyadan okuma
    if (argc < 2)
    {
        fprintf(stderr, "Dosya ismi eksik.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        perror("Dosya acilamadi");
        return 1;
    }

    char temp[200];
    while (!feof(fp))
    {
        if (fgets(temp, 200, fp) == NULL)
        {
            break;
        }

        temp[strcspn(temp, "\n")] = 0; // Satir sonu karakterini sil
        char *k1 = strtok(temp, ",");  // butun satiri yazdi strtok ile , den sonrasini ayirdi
        char *k2 = strtok(NULL, ",");
        char *k3 = strtok(NULL, ",");
        char *k4_str = strtok(NULL, ",");

        if (k1 && k2 && k3 && k4_str)
        {
            float k4 = atof(k4_str); // String'i float'a dönüştür
            globalOgrenciler[globalOgrenciSayisi++] = yeniOgrenci(k1, k2, k3, k4);
        }
    }
    fclose(fp);
    // Dosyadaki ogrenci bilgilerini yazdirma
    printf("\n**********DOSYADAN OKUMA**********\n");
    ogrenciListesiniYazdir(globalOgrenciler, globalOgrenciSayisi);
    printf("************************************\n");
    // ders ekleme
    globalDersler[globalDersSayisi++] = yeniDers("Programlama", 4);
    globalDersler[globalDersSayisi++] = yeniDers("Ayrik yapilar", 3);
    globalDersler[globalDersSayisi++] = yeniDers("Sayisal sistemler", 4);
    globalDersler[globalDersSayisi++] = yeniDers("Sayisal yontemler", 5);
    globalDersler[globalDersSayisi++] = yeniDers("Diferansiyel Denklemler", 6);
    // ogrenci ekleme
    globalOgrenciler[globalOgrenciSayisi++] = yeniOgrenci("Alper", "Gurel", "Yazilim Muhendisligi", 3.5);
    globalOgrenciler[globalOgrenciSayisi++] = yeniOgrenci("Yunus Emre", "Daldal", "Yazilim Muhendisligi", 1.35);
    globalOgrenciler[globalOgrenciSayisi++] = yeniOgrenci("Alp", "Tuncer", "Bilgisayar Muhendisligi", 2.42);
    // ogrenciye ders ekleme
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Ali Enes", "Programlama", 7);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Ali Enes", "Ayrik yapilar", 78);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Ali Enes", "Sayisal sistemler", 60);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Ali Enes", "Sayisal yontemler", 89);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Ali Enes", "Diferansiyel Denklemler", 51);

    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alper", "Programlama", 42);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alper", "Ayrik yapilar", 13);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alper", "Sayisal sistemler", 100);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alper", "Sayisal yontemler", 86);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alper", "Diferansiyel Denklemler", 76);

    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Yunus Emre", "Programlama", 85);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Yunus Emre", "Ayrik yapilar", 70);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Yunus Emre", "Sayisal sistemler", 90);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Yunus Emre", "Sayisal yontemler", 10);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Yunus Emre", "Diferansiyel Denklemler", 5);

    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Burak", "Programlama", 30);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Burak", "Ayrik yapilar", 50);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Burak", "Sayisal sistemler", 80);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Burak", "Sayisal yontemler", 84);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Burak", "Diferansiyel Denklemler", 100);

    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Emirhan", "Programlama", 20);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Emirhan", "Ayrik yapilar", 50);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Emirhan", "Sayisal sistemler", 70);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Emirhan", "Sayisal yontemler", 100);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Emirhan", "Diferansiyel Denklemler", 65);

    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alp", "Programlama", 20);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alp", "Ayrik yapilar", 50);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alp", "Sayisal sistemler", 10);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alp", "Sayisal yontemler", 25);
    ogrenciyeDersEkle(globalOgrenciler, globalOgrenciSayisi, "Alp", "Diferansiyel Denklemler", 15);
    printf("\n\n");
    // Tüm derslerin ve öğrencilerin listesini yazdırma

    printf("************************************\n");
    dersListesiniYazdir(globalDersler, globalDersSayisi);
    printf("\n************************************\n");
    printf("\n\n");
    printf("Ogrenci Sayisi : %d\n\n", globalOgrenciSayisi);
    ogrenciListesiniYazdir(globalOgrenciler, globalOgrenciSayisi);
    printf("\n");
    // parametre olarak verilen dersin ortalamasi
    printf("\n**********DERSLERIN ORTALAMALARI**********\n");
    dersinOrtalamasi("Programlama");
    dersinOrtalamasi("Ayrik yapilar");
    dersinOrtalamasi("Sayisal sistemler");
    dersinOrtalamasi("Sayisal yontemler");
    dersinOrtalamasi("Diferansiyel Denklemler");
    printf("********************************************\n");
    printf("\n");
    // parametre olarak verilen dersin standart sapmasi,
    printf("\n**********DERSLERIN STANDART SAPMALARI**********\n");
    standartSapmayiYaz("Programlama");
    standartSapmayiYaz("Ayrik yapilar");
    standartSapmayiYaz("Sayisal sistemler");
    standartSapmayiYaz("Sayisal yontemler");
    standartSapmayiYaz("Diferansiyel Denklemler");
    printf("**************************************************\n");
    printf("\n");
    // kovaryans
    printf("\n**********DERSLERIN KOVARYANSI*********\n");
    kovaryansiYaz("Programlama", "Ayrik yapilar");
    kovaryansiYaz("Sayisal sistemler", "Ayrik yapilar");
    kovaryansiYaz("Programlama", "Sayisal sistemler");
    printf("\n***************************************\n");
    printf("\n\n");
    // ort ustundeki ogrenciler
    printf("\n**********ORTALAMANIN USTUNDEKI OGRENCILER*********\n");
    ortalamaninUstundeOgrenciler("Programlama");
    ortalamaninUstundeOgrenciler("Sayisal sistemler");
    ortalamaninUstundeOgrenciler("Sayisal yontemler");
    ortalamaninUstundeOgrenciler("Ayrik yapilar");
    ortalamaninUstundeOgrenciler("Diferansiyel Denklemler");
    printf("*****************************************************\n");
    // ogrencileri dosyaya yazdirma
    ogrencileriDosyayaYaz(globalOgrenciler, globalOgrenciSayisi, "dosyayaYaz.txt");
    // Bellek temizleme işlemi
    for (int i = 0; i < globalDersSayisi; i++)
    {
        temizleDers(globalDersler[i]);
    }
    for (int i = 0; i < globalOgrenciSayisi; i++)
    {
        temizleOgrenci(globalOgrenciler[i]);
    }
    return 0;
}
