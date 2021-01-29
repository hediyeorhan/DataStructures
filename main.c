#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef struct Yigin
{
    int indis;
    char eleman[N];
} Yiginlar;

Yiginlar *iter = NULL;

Yiginlar *YiginOlustur()
{
    Yiginlar *yeni_yigin;
    yeni_yigin = (Yiginlar*)malloc(sizeof(Yiginlar));
    yeni_yigin->indis=0;
    return yeni_yigin;
}

int YiginBosMu(Yiginlar *yeni_yigin)
{
    if(yeni_yigin->indis == 0)
        return -1;
    else
        return 1;
}
int YiginDoluMu(Yiginlar *yeni_yigin)
{
    if(yeni_yigin->indis >= N)
        return -1;
    else
        return 1;
}

void YiginaEkle(Yiginlar *yeni_yigin, char ekle)
{
    if(YiginDoluMu(yeni_yigin) == -1)
    {
        printf("Yigin dolu !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->eleman[yeni_yigin->indis] = ekle;
        yeni_yigin->indis++;
    }
}


void YigindanCikar(Yiginlar *yeni_yigin)
{
    char cikan;
    if(YiginBosMu(yeni_yigin) == -1)
    {
        printf("Yigin bos !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->indis--;
        yeni_yigin->eleman[yeni_yigin->indis];
    }
}

int ParantezKontrol(Yiginlar *yeni_yigin, char *islem)
{
    int i;
    for(i=0; i<strlen(islem); i++)
    {
        if(islem[i] == '(')
            YiginaEkle(yeni_yigin, islem[i]);
        else
        {
            if(islem[i] == ')')
                if(YiginBosMu(yeni_yigin) == -1)
                    return -1;
                else
                    YigindanCikar(yeni_yigin);
        }
        if(islem[i] == '{')
            YiginaEkle(yeni_yigin, islem[i]);
        else
        {
            if(islem[i] == '}')
                if(YiginBosMu(yeni_yigin) == -1)
                    return -1;
                else
                    YigindanCikar(yeni_yigin);
        }
        if(islem[i] == '[')
            YiginaEkle(yeni_yigin, islem[i]);
        else
        {
            if(islem[i] == ']')
                if(YiginBosMu(yeni_yigin) == -1)
                    return -1;
                else
                    YigindanCikar(yeni_yigin);
        }
    }
    if(YiginBosMu(yeni_yigin)!= -1)
        return 0;
    else
        return 1;
}
int main()
{
    Yiginlar *yeni_yigin = YiginOlustur();
    printf("\nYeni yigin olustu.\n");

    int i;
    char islem[100];

    printf("Kontrol stringi : ");
    scanf("%s", islem);

    i = ParantezKontrol(yeni_yigin, islem);

    switch(i)
    {
    case -1:
        printf("\nHata : Acma parantezi eksik !.\n");
        break;
    case 0:
        printf("\nHata : Kapatma parantezi eksik !.\n");
        break;
    case 1:
        printf("\nHata Yok..\n");
        break;
    }
    return 0;
}
