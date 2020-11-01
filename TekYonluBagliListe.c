#include <stdio.h>
#include <stdlib.h>

typedef struct A
{
    int num;
    struct A *sonraki;
} Bliste;

Bliste *ilk= NULL, *gecici, *bironceki=NULL, *temp =NULL;

Bliste *bilgial(int sayi)
{
    Bliste *bilgi = (Bliste*)malloc(sizeof(Bliste));
    bilgi->num = sayi;
    return bilgi;
}

void Ekle(Bliste *bilgi)
{
    if(ilk == NULL)
    {
        ilk = bilgi;
        ilk->sonraki = NULL;
    }
    else
    {
        gecici = ilk;
        while(gecici->sonraki != NULL)
        {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = bilgi;
        bilgi->sonraki=NULL;
    }
}

int Listele(Bliste *siradaki)
{
    if(siradaki == NULL)
    {
        return 0;
    }
    printf("%d -> ", siradaki->num);
    Listele(siradaki->sonraki);
}


Bliste *ara(int sayi)
{
    gecici = ilk;
    while(gecici)
    {
        if(gecici->num == sayi)
        {
            return gecici;
        }
        gecici = gecici->sonraki;
    }
    return gecici;
}


void silme(int silnum)
{

    gecici = ilk;

    while(gecici)
    {
        if(gecici->num == silnum)
        {
            break;
        }
        else
        {
            bironceki = gecici;
            gecici = gecici->sonraki;
        }

    }
    if(gecici!=NULL) // silinecek kayit yoksa gecici null gosteriyordur.
    {
        if(bironceki==NULL) // silinecek ilk kayit ise
        {
            if(ilk->sonraki==NULL) // ilk ve tek kayit var ise
            {
                ilk = NULL;
            }
            else // silinecek ilk kayit ise ancak birden fazla kayit var ise
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

int SiraliEkle(Bliste *bilgi)
{

    if(ilk == NULL)
    {
        ilk = bilgi;
        ilk->sonraki = NULL;
        return 0;
    }
    if(ilk->num > bilgi->num)
    {
        bilgi->sonraki = ilk;
        ilk = bilgi;
        return 0;
    }
    gecici = ilk;
    while(gecici->sonraki!=NULL && gecici->sonraki->num < bilgi->num)
        gecici = gecici->sonraki;
    bilgi->sonraki = gecici->sonraki;
    gecici->sonraki = bilgi;
}



int main()
{
    printf("1)Ekle\n2)Listeleme\n3)Ara\n4)Sil\n5)Sirali Ekle\n0)Cikis\n");


    int secim;
    int sayi;
    Bliste *bilgi, *bul;

    while(1 == 1)
    {
        printf("\nMenu seciniz : ");
        scanf("%d",&secim);

        switch(secim)
        {

        case 1:
            printf("Eklemek istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            bilgi = bilgial(sayi);
            Ekle(bilgi);
            break;
        case 2:
            Listele(ilk);
            break;
        case 3:
            printf("Arancak sayiyi giriniz : ");
            scanf("%d",&sayi);
            bul = ara(sayi);
            if(bul == NULL)
                printf("Sayi bulunamadi!");
            else
                printf("Sayi bulundu.");
            break;
        case 4:
            printf("Silinecek numarayi giriniz : ");
            scanf("%d",&sayi);
            silme(sayi);
            break;
        case 5:
            printf("Eklemek istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            bilgi = bilgial(sayi);
            SiraliEkle(bilgi);
            break;
        case 0:
            exit(0);
        default:
            printf("Geçersiz islem!");
            break;

        }
    }
}
