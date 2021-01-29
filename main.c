#include <stdio.h>
#include <stdlib.h>

typedef struct A
{
    int num;
    struct A *sonraki;
} Bliste;

Bliste *bironceki=NULL, *temp =NULL;

Bliste *bilgial(int sayi)
{
    Bliste *bilgi = (Bliste*)malloc(sizeof(Bliste));
    bilgi->num = sayi;
    return bilgi;
}

Bliste *Ekle(Bliste *ilk, Bliste *bilgi)
{

    Bliste *gecici;
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
    return ilk;
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

int KacElemanVar(int size, Bliste *siradaki)
{
    if(siradaki == NULL)
    {
        return size;
    }
    size++;
    KacElemanVar(size, siradaki->sonraki);

}


Bliste *ara(Bliste *ilk, int sayi)
{

    Bliste *gecici;
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


Bliste *silme(Bliste *ilk, int silnum)
{
    Bliste *bironceki=NULL;
    Bliste *gecici;
    gecici = ilk;

    while(gecici)
    {
        if(gecici->num == silnum)
        {
            return NULL;
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
    return ilk;
}

int SiraliEkle(Bliste *ilk, Bliste *bilgi)
{

    Bliste *gecici;
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

Bliste *RecursiveTersten(Bliste *ilk)
{
    /*
    Bliste *iter = ilk;
    if(iter == NULL)
        return NULL;

    if(iter->sonraki == NULL)
        return iter;

    Bliste *rest = RecursiveTersten(iter->sonraki);

    iter->sonraki->sonraki = iter;

    iter->sonraki = NULL;

    return rest;
    */
    if(ilk != NULL) // sadece yazdirir ustteki kod kalici olarak ceviriyor. Menude duzenleme gerekli bu kod blogu icin.
    {
        RecursiveTersten(ilk->sonraki);
        printf("%d", ilk->num);
    }

}


int main()
{
    printf("1) Ekle\n2) Listeleme\n3) Ara\n4) Sil\n5) Sirali Ekle\n6) Kac Eleman Var?\n7) Bagli Listeyi Ters Cevir\n0) Cikis\n");

    Bliste *ilk = NULL;
    int secim;
    int sayi;
    int eleman=0;
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
            ilk = Ekle(ilk, bilgi);
            break;
        case 2:
            Listele(ilk);
            break;
        case 3:
            printf("Arancak sayiyi giriniz : ");
            scanf("%d",&sayi);
            bul = ara(ilk, sayi);
            if(bul == NULL)
                printf("Sayi bulunamadi!");
            else
                printf("Sayi bulundu.");
            break;
        case 4:
            printf("Silinecek numarayi giriniz : ");
            scanf("%d",&sayi);
            ilk = silme(ilk, sayi);
            break;
        case 5:
            printf("Eklemek istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            bilgi = bilgial(sayi);
            SiraliEkle(ilk, bilgi);
            break;
        case 6:
            printf("Bagli listedeki eleman sayisi : %d ", KacElemanVar(eleman, ilk));
        case 7:
            printf("\nTers Bagli Liste \n");
            ilk = RecursiveTersten(ilk);
            Listele(ilk);
            break;
        case 0:
            exit(0);
        default:
            printf("Geçersiz islem!");
            break;

        }
    }
}






