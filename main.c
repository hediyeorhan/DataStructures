#include <stdio.h>
#include <stdlib.h>
#define K_BOYUT 5

typedef struct Kuyruk
{
    int son;
    int eleman[K_BOYUT];
} Kuyruklar;

Kuyruklar *KuyrukOlustur()
{
    Kuyruklar *yeni_kuyruk;
    yeni_kuyruk = (Kuyruklar*)malloc(sizeof(Kuyruklar));
    yeni_kuyruk->son = -1;
    return yeni_kuyruk;
}

int Enqueu(Kuyruklar *yeni_kuyruk, int data)
{
    if(yeni_kuyruk->son >= K_BOYUT-1)
    {
        printf("\nKuyruk dolu !\n");
        return -1;
    }
    else
    {
        yeni_kuyruk->son++;
        yeni_kuyruk->eleman[yeni_kuyruk->son] = data;
        return 1;
    }

}

int Dequeu(Kuyruklar *yeni_kuyruk)
{
    int i, cikan_eleman;
    if(yeni_kuyruk->son == -1)
    {
        printf("\nKuyruk bos !\n");
        return -1;
    }
    else
    {
        cikan_eleman = yeni_kuyruk->eleman[0];
        for(i=1; i<=yeni_kuyruk->son; i++)
        {
            yeni_kuyruk->eleman[i-1] = yeni_kuyruk->eleman[i];
        }
        yeni_kuyruk->son--;
        return cikan_eleman;
    }
}
void Listele(Kuyruklar *yeni_kuyruk)
{
    int i;
    for(i=0; i<=yeni_kuyruk->son; i++)
    {
        printf("%d -> ", yeni_kuyruk->eleman[i]);

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


}
