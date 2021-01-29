#include <stdio.h>
#include <stdlib.h>

typedef struct Kitap
{
    int basimyili, isbn;
    char ad[100], yazar[100];
    struct Kitap *sonraki;
} Kliste;

Kliste *ilk= NULL, *gecici, *bironceki=NULL, *temp =NULL;

Kliste *bilgial()
{

    Kliste *bilgi = (Kliste*)malloc(sizeof(Kliste));
    printf("\nBasim Yili giriniz : ");
    scanf("%d", &bilgi->basimyili);
    printf("\nISBN giriniz : ");
    scanf("%d", &bilgi->isbn);
    printf("\nKitap Adi giriniz : ");
    fflush(stdin);
    gets(bilgi->ad);
    printf("\nYazar giriniz : ");
    fflush(stdin);
    gets(bilgi->yazar);
    return bilgi;
}

// Kucukten Buyuge Siralama
int SiraliEkle(Kliste *bilgi)
{

    if(ilk == NULL)
    {
        ilk = bilgi;
        ilk->sonraki = NULL;
        return 0;
    }
    if(ilk->basimyili > bilgi->basimyili)
    {
        bilgi->sonraki = ilk;
        ilk = bilgi;
        return 0;
    }
    gecici = ilk;
    while(gecici->sonraki!=NULL && gecici->sonraki->basimyili < bilgi->basimyili)
        gecici = gecici->sonraki;
    bilgi->sonraki = gecici->sonraki;
    gecici->sonraki = bilgi;
}

void silme(int silisbn)
{

    gecici = ilk;

    while(gecici)
    {
        if(gecici->isbn == silisbn)
        {
            break;
        }
        else
        {
            bironceki = gecici;
            gecici = gecici->sonraki;
        }

    }
    if(gecici!=NULL)
    {
        if(bironceki==NULL)
        {
            if(ilk->sonraki==NULL)
            {
                ilk = NULL;
            }
            else
            {
                ilk = ilk->sonraki;
            }
        }
        else
        {
            bironceki ->sonraki = gecici->sonraki;
        }
        free(gecici);
        printf("Kayit silindi..");
    }
    else
    {
        printf("Kayit silinemedi..");
    }
}
int Listele(Kliste *siradaki)
{
    if(siradaki == NULL)
    {
        return 0;
    }
    printf("\nBasim Yili : %d ", siradaki->basimyili);
    printf("\nISBN : %d ", siradaki->isbn);
    printf("\nKitap Adi : %s ", siradaki->ad);
    printf("\nYazar : %s ", siradaki->yazar);
    Listele(siradaki->sonraki);
}
int main()
{
    printf("1)Ekle\n2)Listeleme\n3)Sil\n0)Cikis\n");


    int secim, sayi;

    Kliste *bilgi, *bul;

    while(1 == 1)
    {
        printf("\nMenu seciniz : ");
        scanf("%d",&secim);

        switch(secim)
        {

        case 1:
            bilgi = bilgial();
            SiraliEkle(bilgi);
            break;
        case 2:
            Listele(ilk);
            break;
        case 3:
            printf("Silinecek numarayi giriniz : ");
            scanf("%d",&sayi);
            silme(sayi);
            break;
        case 0:
            exit(0);
        default:
            printf("Geçersiz islem!");
            break;

        }
    }
}
