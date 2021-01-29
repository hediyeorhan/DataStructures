#include <stdio.h>
#include <stdlib.h>

typedef struct Liste
{
    int numara;
    char *ad[20];
    char *soyad[20];
    struct Liste *sonraki;
} List;

typedef struct Ogrenci
{
    int numara;
    char *ad;
    char *soyad;
    struct Ogrenci *next, *prev;
} Ogrenciler;


List *bilgial()
{
    List *bilgi = (List*)malloc(sizeof(List));
    printf("\nOgrenci numara : ");
    scanf("%d", &bilgi->numara);
    printf("\nOgrenci ad : ");
    fflush(stdin);
    gets(bilgi->ad);
    printf("\nOgrenci soyad : ");
    fflush(stdin);
    gets(bilgi->soyad);
    return bilgi;
}

List *ListEkle(List *bilgi, List *ilk)
{
    List *gecici;
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


int Listele(List *siradaki)
{
    if(siradaki == NULL)
    {
        return 0;
    }
    printf("\nOgrenci numara : %d", siradaki->numara);
    printf("\nOgrenci ad : %s", siradaki->ad);
    printf("\nOgrenci soyad : %s", siradaki->soyad);
    Listele(siradaki->sonraki);
}


Ogrenciler *SiraliEkle(Ogrenciler *root, List *bilgi)
{
    if(root == NULL)
    {
        root = (Ogrenciler*)malloc(sizeof(Ogrenciler));
        root->numara = bilgi->numara;
        root->ad = bilgi->ad;
        root->soyad = bilgi->soyad;
        root->next = root;
        root->prev = root;
        return root;
    }

    Ogrenciler *iter = root;

    if(iter->numara > bilgi->numara)
    {
        Ogrenciler *temp = (Ogrenciler*)malloc(sizeof(Ogrenciler));
        temp->numara = bilgi->numara;
        temp->ad = bilgi->ad;
        temp->soyad = bilgi->soyad;
        temp->next = root;
        temp->prev = root->prev;
        root->prev = temp;
        temp->prev->next = temp;
        return temp;
    }

    while(iter->next->numara < bilgi->numara)
    {
        if(iter->next == root)
        {
            iter->next = (Ogrenciler*)malloc(sizeof(Ogrenciler));
            iter->next->numara = bilgi->numara;
            iter->next->ad = bilgi->ad;
            iter->next->soyad = bilgi->soyad;
            iter->next->next = root;
            iter->next->prev = iter;
            root->prev = iter->next;
            return root;
        }
        iter = iter->next;
    }
    if(iter->numara == bilgi->numara && iter->ad == bilgi->ad && iter->soyad == bilgi->soyad)
    {
        return;
    }

    Ogrenciler *temp = (Ogrenciler*)malloc(sizeof(Ogrenciler));
    temp->numara = bilgi->numara;
    temp->ad = bilgi->ad;
    temp->soyad = bilgi->soyad;
    temp->next = iter->next;
    temp->prev = iter;
    iter->next = temp;
    temp->next->prev = temp;
    return root;
}



void CiftYonluListele(Ogrenciler *root)
{
    Ogrenciler *iter = root;
    if(root == NULL)
        return NULL;
    while(iter->next != root)
    {
        printf("\nOgrenci numara : %d", iter->numara);
        printf("\nOgrenci ad : %s", iter->ad);
        printf("\nOgrenci soyad : %s", iter->soyad);
        iter = iter->next;
    }

    printf("\nOgrenci numara : %d", iter->numara);
    printf("\nOgrenci ad : %s", iter->ad);
    printf("\nOgrenci soyad : %s", iter->soyad);

}

int main()
{
    List *ilk = NULL, *bilgi;
    List *ilk2 = NULL, *bilgi2;
    int secim;
    Ogrenciler *root = NULL;
    while(1 == 1)
    {
        printf("\n\t1) Liste 1' e Ekle\n\t2) Liste 2'ye Ekle\n\t3) Listele\n\t4) Cikis\n");
        printf("\nMenu seciniz : ");
        scanf("%d",&secim);

        switch(secim)
        {

        case 1:
            printf("\nListe 1 Ekleme\n");
            bilgi = bilgial();
            ilk = ListEkle(bilgi, ilk);
            root = SiraliEkle(root, ilk);
            break;
        case 2:
            printf("\nListe 2 Ekleme\n");
            bilgi2 = bilgial();
            ilk2 = ListEkle(bilgi2, ilk2);
            root = SiraliEkle(root, ilk2);
            break;
        case 3:
            printf("\nListe 1\n");
            printf("\n-------------\n");

            Listele(ilk);
            printf("\n\nListe 2\n");
            printf("\n-------------\n");
            Listele(ilk2);
            printf("\n\n --------- Cift Yonlu (Listelerin Birlesmis Hali) ----------\n");
            CiftYonluListele(root);
            break;
        case 4:
            printf("\nCikis Yapiliyor ..");
            return;
        default:
            printf("\n ! Gecersiz Secim");
        }
    }
    return 0;
}
