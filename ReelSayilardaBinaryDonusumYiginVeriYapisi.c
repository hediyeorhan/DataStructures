#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct Yigin
{
    int indis;
    double eleman[N];
}Yiginlar;


Yiginlar *YiginOlustur()
{
    Yiginlar *yeni_yigin;
    yeni_yigin = (Yiginlar*)malloc(sizeof(Yiginlar));
    yeni_yigin->indis = 0;
    return yeni_yigin;
}

int YiginDoluMu(Yiginlar *yeni_yigin)
{
    if(yeni_yigin->indis >= N)
        return -1;
    else
        return 0;
}

int YiginBosMu(Yiginlar *yeni_yigin)
{
    if(yeni_yigin->indis == 0)
        return -1;
    else
        return 0;
}

void YiginaEkle(Yiginlar *yeni_yigin, int sayi)
{
    if(YiginDoluMu(yeni_yigin) == -1)
    {
        printf("\nYigin dolu !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->eleman[yeni_yigin->indis] = sayi;
        yeni_yigin->indis++;
    }
}

int YigindanCikar(Yiginlar *yeni_yigin)
{
    int cikan;
    if(YiginBosMu(yeni_yigin) == -1)
    {
        printf("\nYigin bos !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->indis--;
        cikan = yeni_yigin->eleman[yeni_yigin->indis];
        return cikan;
    }
}


void Cevir(Yiginlar *yeni_yigin, double sayi)
{
    int tam = (int)sayi;
    double ondalik = sayi-tam;

    int digit, cikan, hassasiyet, tamkisim, i=0, k=0;

    printf("\nHassasiyet giriniz : ");
    scanf("%d", &hassasiyet);

    printf("\n-------- SONUC -------- \n");

    // Tam Kisim
    while(tam > 0)
    {
        digit = tam % 2;
        YiginaEkle(yeni_yigin, digit);
        tam = tam/2;
    }
    while(yeni_yigin->indis > 0)
    {
        cikan = YigindanCikar(yeni_yigin);
        printf("%d ", cikan);
    }
    // Ondalikli Kisim

    printf(".");
    int sonuc[10];

    while(i != hassasiyet)
    {
        ondalik = ondalik*2;

        tamkisim = (int)ondalik;
        if(tamkisim == 1)
        {
            ondalik = ondalik - tamkisim;

        }

        sonuc[k] = tamkisim;
        printf("%d ", sonuc[k]);
        i++;
        k++;
    }


}
int main()
{

    Yiginlar *yigin = YiginOlustur();


    double sayi;
    printf("Sayi : ");
    scanf("%lf", &sayi);
    Cevir(yigin, sayi);



    return 0;


}
