#include <stdio.h>
#include <stdlib.h>

typedef struct Agac
{
     int eleman;
     struct Agac *sag, *sol;
}Agaclar;

Agaclar *DegerAl();
void ekle_rec(Agaclar *agackok, Agaclar *yeni);
void inListele(Agaclar *agackok);
int say(Agaclar *agackok);
int full_binary_kontrol(Agaclar *agackok);
Agaclar *arama(Agaclar *agackok, int aranan);
Agaclar *enkucuk(Agaclar *agackok);
Agaclar *enbuyuk(Agaclar *agackok);
Agaclar *silme(Agaclar *agackok, int data);
int sayma;
Agaclar *kok = NULL;

Agaclar *DegerAl()
{
    Agaclar *yeni;
    yeni = (Agaclar*)malloc(sizeof(Agaclar));
    if(yeni==NULL)
    {
        puts("\nBellek dolu..");
        return NULL;
    }
    puts("\nEleman giriniz : ");
    scanf("%d",&(yeni->eleman));
    yeni->sag = NULL;
    yeni->sol = NULL;
    return yeni;
}

void ekle_rec(Agaclar *agackok, Agaclar *yeni)
{
    if(agackok == NULL)
        kok=yeni; // ilk koke(adrese) atama yaptik.
    else
    {
        if(yeni->eleman < agackok->eleman)
        {
            if(agackok->sol == NULL)
                agackok->sol = yeni;
            else
                ekle_rec(agackok->sol, yeni);
        }
        else
        {
            if(agackok->sag == NULL)
                agackok->sag = yeni;
            else
                ekle_rec(agackok->sag, yeni);
        }
    }
}

Agaclar *silme(Agaclar *agackok, int data)
{
    if(agackok == NULL)
        return agackok;
    if(data < agackok->eleman)
        agackok->sol = silme(agackok->sol, data);
    else if(data > agackok->eleman)
        agackok->sag = silme(agackok->sag, data);
    else
    {
        if(agackok->sol == NULL && agackok->sag==NULL)
        {
            free(agackok);
            agackok=NULL;
            return agackok;
        }
        else if(agackok->sol == NULL)
        {
            Agaclar *temp = agackok;
            agackok = agackok->sag;
            free(temp);
            return agackok;
        }
        else if(agackok->sag == NULL)
        {
            Agaclar *temp = agackok;
            agackok = agackok->sol;
            free(temp);
            return agackok;
        }
        else
        {
            Agaclar *temp = enkucuk(agackok->sag);
            agackok->eleman = temp->eleman;
            agackok->sag = silme(agackok->sag, temp->eleman);
        }
    }
    return agackok;
}

int say(Agaclar *agackok)
{
    if(agackok != NULL)
    {
        sayma += 1;
        say(agackok->sol);
        say(agackok->sag);
    }
    return sayma;
}

int kontrol = 0;
int full_binary_kontrol(Agaclar *agackok)
{
    if(agackok == NULL)
        return 1;
    else
    {
        if(agackok->sol != NULL && agackok->sag != NULL)
        {
            full_binary_kontrol(agackok->sol);
            full_binary_kontrol(agackok->sag);
        }
        else if(agackok->sol == NULL && agackok->sag != NULL)
        {
            kontrol = 1;
        }
        else if(agackok->sol != NULL && agackok->sag == NULL)
        {
            kontrol = 1;
        }
        else if(agackok->sol == NULL && agackok->sag == NULL)
        {
            kontrol = 0;
        }


    }
    if(kontrol == 0)
        return 1;
    else
        return 0;
}

Agaclar *enkucuk(Agaclar *agackok)
{
    if(agackok->sol == NULL)
        return agackok;
    return enkucuk(agackok->sol);
}

Agaclar *enbuyuk(Agaclar *agackok)
{
    if(agackok->sag == NULL)
        return agackok;
    return enbuyuk(agackok->sag);
}


Agaclar *arama(Agaclar *agackok, int aranan)
{
    if(agackok==NULL)
        return NULL;
    if(aranan < agackok->eleman)
        return arama(agackok->sol, aranan);
    else if(aranan > agackok->eleman)
        return arama(agackok->sag, aranan);
    else
        return agackok;
}

void preorderListele(Agaclar *agackok)
{
    if(agackok != NULL)
    {
        printf("\n %d", agackok->eleman);
        inListele(agackok->sol);
        inListele(agackok->sag);
    }
}

void inListele(Agaclar *agackok)
{
     if(agackok != NULL)
    {
        inListele(agackok->sol);
        printf("\n %d", agackok->eleman);
        inListele(agackok->sag);
    }
}

void postorderListele(Agaclar *agackok)
{
    if(agackok != NULL)
    {
        postorderListele(agackok->sol);
        postorderListele(agackok->sag);
        printf("\n %d", agackok->eleman);
    }
}

int ElemanlarinToplami(Agaclar *agackok)
{
    if(agackok != NULL)
    {
        sayma += agackok->eleman;
        ElemanlarinToplami(agackok->sol);
        ElemanlarinToplami(agackok->sag);
    }

    return sayma;
}

int AgacinYuksekligi(Agaclar *agackok)
{
    int sag, sol;
    if(agackok != NULL)
    {

        sol = AgacinYuksekligi(agackok->sol);
        sag = AgacinYuksekligi(agackok->sag);
         
        printf("Eleman : %d - Yuksekligi : %d\n", agackok->eleman, sol);
        printf("Eleman : %d - Yuksekligi : %d\n", agackok->eleman, sag);
        if(sol > sag)
        {
            return sol + 1;
        }

        else
        {
             return sag + 1;
        }
    }
    else
        return 0;
}

void AgacDengeliMi(Agaclar *agackok)
{
    int sag, sol;
    if(agackok != NULL)
    {
        sol = AgacinYuksekligi(agackok->sol);
        sag = AgacinYuksekligi(agackok->sag);
        if(abs(sol - sag) > 1)
        {
            printf("\nAgac dengesiz !\n");
        }
        else
            printf("\nAgac dengeli . \n");

    }

}
int main()
{
    Agaclar *yeni, *bul, *ekucuk, *ebuyuk;
    int aranan, sil, sayma_sonuc, binary_sonuc;
    int secim;
    while(1)
    {
        puts("\n1- Ekleme\n2- Listele\n3- Arama\n4- Silme\n5- EnKucuk\n6- EnBuyuk\n7- Say\n8- Binary Kontrol\n9- Agactaki Elemanlarin Toplami\n10- Agac ve Elemanlarin Yukseklikleri\n11- Agac Dengeli Mi?\n0- Cikis\n");
        printf("Menu seciniz : ");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
            yeni=DegerAl();
            ekle_rec(kok, yeni);
            break;
        case 2:
            if(kok != NULL)
            {
                printf("\n-- InListele --\n");
                inListele(kok);
                printf("\n-- PreorderListele --\n");
                preorderListele(kok);
                printf("\n-- PostorderListele --\n");
                postorderListele(kok);
            }
            else
                puts("Bos agac!!");
            break;
        case 3:
            printf("\n Aranan eleman : ");
            scanf("%d", &aranan);
            bul = arama(kok, aranan);
            if(bul!=NULL)
                printf("\nBulunan eleman : %d", bul->eleman);
            else
                printf("\nEleman bulunamadi.");
            break;
        case 4:
            printf("\n Silinecek eleman : ");
            scanf("%d", &sil);
            kok = silme(kok, sil);
            break;
        case 5:
            if(kok != NULL)
            {
                ekucuk = enkucuk(kok);
                printf("\nEn kucuk sayi : %d" , ekucuk->eleman);
            }
            else
                printf("\nBos liste");
            break;
        case 6:
            if(kok != NULL)
            {
                ebuyuk = enbuyuk(kok);
                printf("\nEn buyuk sayi : %d" , ebuyuk->eleman);
            }
            else
                printf("\nBos liste");
            break;
        case 7:
            sayma_sonuc = say(kok);
            printf("\nToplam eleman sayisi(Toplam dugum sayisi) : %d", sayma_sonuc);
            sayma=0;
            break;
        case 8:
            binary_sonuc = full_binary_kontrol(kok);
            printf("\nBinary Sonuc : %d", binary_sonuc);
            if(binary_sonuc == 1)
                printf("\nFull binary");
            else
                printf("\nFull binary degil");
            sayma = 0;
            break;
        case 9:
            sayma_sonuc = ElemanlarinToplami(kok);
            printf("\nElemanlarin Toplami : %d", sayma_sonuc);
            sayma = 0;
            break;
        case 10:
            sayma_sonuc = AgacinYuksekligi(kok);
            printf("Agacin Genel Yuksekligi : %d\n", sayma_sonuc - 1);
            sayma = 0;
            break;
        case 11:
            AgacDengeliMi(kok);
            break;
        case 0:
            puts("\n Cikis Yapiliyor ..");
            return 0;
        default:
            puts("\n Gecersiz menu secimi. Lutfen tekrar menu seciniz.");
            break;
        }

    }
    return 0;
}
