#include <stdio.h>
#include <stdlib.h>

typedef struct A
{
    struct A *next;
    int num;
} Bliste;

Bliste *ilk, *gecici, *bironceki;

Bliste *BilgiAl(int sayi)
{
    Bliste *bilgi = (Bliste*)malloc(sizeof(Bliste*));
    bilgi->num = sayi;
    return bilgi;
}

int Ekle(Bliste *bilgi)
{
    if(ilk == NULL)
    {
        ilk = bilgi;
        ilk->next = NULL;
        return 0;
    }
    else
    {
        gecici = ilk;
        while(gecici->next != NULL)
            gecici = gecici->next;
        gecici->next = bilgi;
        bilgi->next = NULL;
    }
}
int KacElemanVar(int size, Bliste *siradaki)
{
    if(siradaki == NULL)
    {
        return size;
    }
    size++;
    KacElemanVar(size, siradaki->next);

}

Bliste *SiraliListeleme(Bliste *root)
{
    Bliste *temp, *swap;


    int size = 0;
    size = KacElemanVar(size, root);
    printf("\nSIZE : %d\n",size);
    for(int i=0; i<size; i++)
    {
        temp=root;
        while(temp->next!=NULL)
        {
            if(temp->num > temp->next->num)
            {
                swap=temp->next->num;
                temp->next->num=temp->num;
                temp->num=swap;
            }
            temp=temp->next;
        }
    }


    return root;
}

Bliste *Ara(int aranacak)
{
    gecici = ilk;
    while(gecici)
    {
        if(gecici->num == aranacak)
        {
            return gecici;
        }
        else
        {
            gecici = gecici->next;
        }

    }
    return gecici;
}


void Sil(int silnum)
{
    gecici = ilk;
    while(gecici)
    {
        if(gecici->num == silnum)
        {
            break;
        }
        bironceki = gecici;
        gecici = gecici->next;
    }

    if(gecici != NULL)
    {
        if(bironceki == NULL)
        {
            if(ilk->next = NULL)
            {
                ilk = NULL;
            }
            else
            {
                ilk = ilk->next;
            }
        }
        else
        {
            bironceki->next = gecici->next;
        }
        free(gecici);
        printf("Kayit Silindi..");
    }
    else
    {
        printf("Kayit Silemedi !");
    }
}

int Listele(Bliste *siradaki)
{
    if(siradaki == NULL)
    {
        return 0;
    }
    printf("%d -> ", siradaki->num);
    Listele(siradaki->next);
}

int SiraliEkle(Bliste *bilgi)
{
    if(ilk == NULL)
    {
        ilk = bilgi;
        ilk->next = NULL;
        return 0;
    }
    else
    {
        if(ilk->num > bilgi->num)
        {
            bilgi->next = ilk;
            ilk = bilgi;
            return 0;
        }
    }
    gecici = ilk;
    while(gecici->next != NULL && gecici->next->num < bilgi->num)
        gecici = gecici->next;
    bilgi->next = gecici->next;
    gecici->next = bilgi;
}
int main()
{
    Bliste *bilgi, *bul;
    int sayi, menu;
    printf("1)Ekle\n2)Sil\n3)Ara\n4)Sirali Ekle\n5)Listele\n6)Sirali Listeleme\n0)Cikis\n");

    while(1 == 1)
    {


        printf("\nLutfen bir menu seciniz : ");
        scanf("%d",&menu);
        printf("\n------------------------------\n");
        switch(menu)
        {
        case 1:
            printf("Eklemek istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            bilgi = BilgiAl(sayi);
            Ekle(bilgi);
            break;
        case 2:
            printf("Silmek istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            Sil(sayi);
            break;
        case 3:
            printf("Aramak istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            bul = Ara(sayi);
            if(bul == NULL)
                printf("Sayi bulunamadi !!");
            else
                printf("Sayi bulundu..");
            break;
        case 4:
            printf("Sirali ekleme yapmak istediginiz sayiyi giriniz : ");
            scanf("%d", &sayi);
            bilgi = BilgiAl(sayi);
            SiraliEkle(bilgi);
            break;
        case 5:
            Listele(ilk);

            break;
        case 6:
            ilk = SiraliListeleme(ilk);
            Listele(ilk);
            break;
        case 0:
            exit(0);
        default:
            printf("Gecersiz Islem !!!");
            break;

        }

    }
    return 0;
}
