#include <stdio.h>
#include <stdlib.h>

#define Y_BOYUT 100

typedef struct node
{
    int indis;
    int eleman[Y_BOYUT];

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
    if(yeni_yigin->indis >= Y_BOYUT)
        return -1;
    else
        return 1;
}

int YiginBosMu(Yiginlar *yeni_yigin)
{
    if(yeni_yigin->indis == 0)
        return -1;
    else
        return 1;
}

void Cevir(Yiginlar *yeni_yigin, int sayi)
{
    int digit;
    while(sayi > 0)
    {
        digit = sayi%2;
        YiginaEkle(yeni_yigin, digit);
        sayi = sayi/2;
    }
    while(yeni_yigin->indis>0)
    {
        digit = YigindanCikar(yeni_yigin);
        printf("%d ", digit);
    }
}

int YiginaEkle(Yiginlar *yeni_yigin, int sayi)
{
    if(YiginDoluMu == -1)
    {
        printf("Yigin Dolu !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->eleman[yeni_yigin->indis] = sayi;
        yeni_yigin->indis++;
        return 1;
    }

}

int YigindanCikar(Yiginlar *yeni_yigin)
{
    int cikan_eleman;
    if(YiginBosMu == -1)
    {
        printf("Yigin Bos !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->indis--;
        cikan_eleman = yeni_yigin->eleman[yeni_yigin->indis];
        return cikan_eleman;
    }
}

int main()
{
    int sayi;
    printf("Bir sayi giriniz : ");
    scanf("%d", &sayi);

    Yiginlar *yigin = YiginOlustur();

    printf("\n");
    Cevir(yigin, sayi);
    printf("\n");
    return 0;
}
