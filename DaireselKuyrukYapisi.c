#include <stdio.h>
#include <stdlib.h>

#define K_BOYUT 5

typedef struct Kuyruk
{
    int son;
    int bas;
    int sayi;

    int eleman[K_BOYUT];
}Kuyruklar;

Kuyruklar *KuyrukOlustur()
{
    Kuyruklar *yeni_kuyruk;
    yeni_kuyruk = (Kuyruklar*)malloc(sizeof(Kuyruklar));
    yeni_kuyruk->bas = 0;
    yeni_kuyruk->son = 0;
    yeni_kuyruk->sayi = 0;
    return yeni_kuyruk;
}

int Enqueu(Kuyruklar *yeni_kuyruk, int data)
{
    if(yeni_kuyruk->sayi >= K_BOYUT)
    {
        printf("\nKuyruk dolu!!\n");
        return -1;
    }
    else
    {
        yeni_kuyruk->eleman[yeni_kuyruk->son] = data;
        yeni_kuyruk->son = (yeni_kuyruk->son+1)%K_BOYUT;
        yeni_kuyruk->sayi++;
        return 1;
    }
}

int Dequeu(Kuyruklar *yeni_kuyruk)
{
    int cikan_eleman;
    if(yeni_kuyruk->sayi == 0)
    {
        printf("\nKuyruk bos !!\n");
        return -1;
    }
    else
    {
        cikan_eleman = yeni_kuyruk->eleman[yeni_kuyruk->bas];
        yeni_kuyruk->bas = (yeni_kuyruk->bas+1)%K_BOYUT;
        yeni_kuyruk->sayi--;
        return cikan_eleman;
    }
}

void Listele(Kuyruklar *yeni_kuyruk)
{
    int i;
    for(i=yeni_kuyruk->bas; i<yeni_kuyruk->bas + yeni_kuyruk->sayi; i++)
    {
        printf("%d -> ", yeni_kuyruk->eleman[i%K_BOYUT]);
    }
    printf("\n");
}
int main()
{
    Kuyruklar *yeni_kuyruk = KuyrukOlustur();

    Enqueu(yeni_kuyruk, 10);
    Enqueu(yeni_kuyruk, 20);
    Enqueu(yeni_kuyruk, 30);
    Listele(yeni_kuyruk);
    Enqueu(yeni_kuyruk, 40);
    Enqueu(yeni_kuyruk, 50);
    Listele(yeni_kuyruk);

    printf("Dequeu : %d\n", Dequeu(yeni_kuyruk));
    printf("Dequeu : %d\n", Dequeu(yeni_kuyruk));
    Listele(yeni_kuyruk);
    printf("Dequeu : %d\n", Dequeu(yeni_kuyruk));
    printf("Dequeu : %d\n", Dequeu(yeni_kuyruk));
    Listele(yeni_kuyruk);
    return 0;
}
