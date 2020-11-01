#include <stdio.h>
#include <stdlib.h>

typedef struct telefon
{
    char tel_tipi[10];
    char tel[11];

} Telefon;

typedef struct rehber
{
    char ad_soyad[30];


    Telefon *telefonlar;
    struct rehber *next;

} Rehber;

Telefon *iter_tel, *tela;
Rehber *ekle(Rehber *ll)
{
    
   

    if(ll == NULL)
    {
        ll = (Rehber*)malloc(sizeof(Rehber));
        printf("\nAd soyad giriniz : ");
        fflush(stdin);
        gets(ll->ad_soyad);

        ll->telefonlar = (Telefon*)malloc(sizeof(Telefon));

        printf("\nTelefon tipi(ev/is/cep vb.) : ");
        scanf("%s", ll->telefonlar->tel_tipi);
        printf("\nTelefon numarasi : ");
        scanf("%s", ll->telefonlar->tel);

        ll->next = ll;
        return ll;

    }

    Rehber *temp = (Rehber*)malloc(sizeof(Rehber));
    Rehber *iter = ll;

    while(iter->next != ll)
    {
        iter = iter->next;
    }
    printf("\nAd soyad giriniz : ");
    fflush(stdin);
    gets(temp->ad_soyad);
    temp->telefonlar = (Telefon*)malloc((tel_sayi) * sizeof(Telefon));

    printf("\nTelefon tipi(ev/is/cep vb.) : ");
    scanf("%s", temp->telefonlar->tel_tipi);
    printf("\nTelefon numarasi : ");
    scanf("%s", temp->telefonlar->tel);


    iter->next = temp;
    temp->next = ll;

    return ll;
}

void Listele(Rehber *ll)
{
    Rehber *iter = ll;
    printf("\n");


    if(ll == NULL)
    {
        return NULL;
    }


    while(iter->next != ll)
    {
        printf("\nAD : %s", iter->ad_soyad);

        printf("\nTELEFON TIPI : %s", iter->telefonlar->tel_tipi);
        printf("\nTELEFON NUMARASI : %s", iter->telefonlar->tel);


        iter = iter->next;
    }
    printf("\nAD : %s", iter->ad_soyad);

    printf("\nTELEFON TIPI : %s", iter->telefonlar->tel_tipi);
    printf("\nTELEFON NUMARASI : %s", iter->telefonlar->tel);




}

void AraAd(Rehber *ll)
{
    char arananad[30];
    int tel_sayi;


    printf("\nAranacak adi ve soyadi giriniz : ");
    fflush(stdin);
    gets(arananad);

    int uz = strlen(arananad);
    int kelimeuz = 0;

    if(ll == NULL)
    {
        return NULL;
    }

    else if(ll->next == ll)
    {
        for(int i=0; i<uz; i++)
        {
            if(ll->ad_soyad[i] == arananad[i])
            {
                kelimeuz++;

            }
        }
        if(kelimeuz == uz)
        {
            printf("\nAD : %s", ll->ad_soyad);

            printf("\nTELEFON TIPI : %s", ll->telefonlar->tel_tipi);
            printf("\nTELEFON NUMARASI : %s", ll->telefonlar->tel);

            printf("\n---------------------------------\n");

        }
    }
    else
    {
        Rehber *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->ad_soyad[i] == arananad[i])
                {
                    kelimeuz++;

                }

            }
            if(kelimeuz == uz)
            {
                printf("\nAD : %s", iter->next->ad_soyad);

                printf("\nTELEFON TIPI : %s",  iter->next->telefonlar->tel_tipi);
                printf("\nTELEFON NUMARASI : %s", iter->next->telefonlar->tel);

                printf("\n---------------------------------\n");
            }


            iter = iter->next;


        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {

            if(iter->next->ad_soyad[i] == arananad[i])
            {
                kelimeuz++;

            }

        }
        if(kelimeuz == uz)
        {
            printf("\nAD : %s", iter->next->ad_soyad);

            printf("\nTELEFON TIPI : %s", iter->next->telefonlar->tel_tipi);
            printf("\nTELEFON NUMARASI : %s", iter->next->telefonlar->tel);

            printf("\n---------------------------------\n");
        }
    }
}

void AraNumara(Rehber *ll)
{
    char aranantel[11];
 
    printf("\nAranacak telefon numarasini giriniz : ");
    fflush(stdin);
    gets(aranantel);

    int uz = strlen(aranantel);
    int kelimeuz = 0;

    if(ll == NULL)
    {
        return NULL;
    }

    else if(ll->next == ll)
    {
        for(int i=0; i<uz; i++)
        {
            if(ll->telefonlar->tel[i] == aranantel[i])
            {
                kelimeuz++;

            }
        }
        if(kelimeuz == uz)
        {
            printf("\nAD : %s", ll->ad_soyad);

            printf("\nTELEFON TIPI : %s", ll->telefonlar->tel_tipi);
            printf("\nTELEFON NUMARASI : %s", ll->telefonlar->tel);

            printf("\n---------------------------------\n");

        }
    }
    else
    {
        Rehber *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->telefonlar->tel[i] == aranantel[i])
                {
                    kelimeuz++;

                }

            }
            if(kelimeuz == uz)
            {
                printf("\nAD : %s", iter->next->ad_soyad);

                printf("\nTELEFON TIPI : %s",  iter->next->telefonlar->tel_tipi);
                printf("\nTELEFON NUMARASI : %s", iter->next->telefonlar->tel);

                printf("\n---------------------------------\n");
            }


            iter = iter->next;


        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {

            if(iter->next->telefonlar->tel[i] == aranantel[i])
            {
                kelimeuz++;

            }

        }
        if(kelimeuz == uz)
        {
            printf("\nAD : %s", iter->next->ad_soyad);

            printf("\nTELEFON TIPI : %s", iter->next->telefonlar->tel_tipi);
            printf("\nTELEFON NUMARASI : %s", iter->next->telefonlar->tel);

            printf("\n---------------------------------\n");
        }
    }
}

Rehber *Sil(Rehber *ll)
{
    char silinecektel[15];
    printf("\nSilinecek telefon numarasini giriniz : ");
    fflush(stdin);
    scanf("%s", &silinecektel);
    int kelimeuz = 0;
    int uz = strlen(silinecektel);
    if(ll == NULL)
    {
        return NULL;
    }
    else if(ll->next == ll)
    {
        for(int i=0; i<uz; i++)
        {
            if(ll->telefonlar->tel[i] == silinecektel[i]) // listede sadece bir deger var ise
            {
                kelimeuz++;
            }
        }
        if(kelimeuz == uz)
        {
            return NULL; // listedeki tek degeri siliyoruz ve listeyi bosaltiyoruz
        }
    }
    else
    {
        Rehber *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->telefonlar->tel[i] == silinecektel[i])
                {
                    kelimeuz++;

                }
            }
            if(kelimeuz == uz)
            {
                Rehber *temp = iter->next;
                iter->next = temp->next;
                free(temp);
                return ll;
            }

            iter = iter->next;
        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {
            if(iter->next->telefonlar->tel[i] == silinecektel[i])
            {
                kelimeuz++;

            }
        }
        if(kelimeuz == uz)
        {
            iter->next = iter->next->next;
            free(ll);
            ll = iter->next;
            return ll;
        }
    }
    return ll;
}

int main()
{
    Rehber *ll = NULL;

    int menu;

    printf("\n\t\t  MENU\n");
    printf("******************************************\n1)Ekle\n2)Listele\n3)Numaraya gore arama\n4)Isime gore arama\n5)Sil\n6)Cikis\n******************************************\n");


    while(1 == 1)
    {
        printf("\n\nMenu giriniz : ");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            ll = ekle(ll);
            break;
        case 2:
            Listele(ll);
            break;
        case 3:
            AraNumara(ll);
            break;
        case 4:
            AraAd(ll);
            break;
        case 5:
            ll = Sil(ll);
            break;
        case 6:
            exit(0);
        }
    }

    return 0;
}
