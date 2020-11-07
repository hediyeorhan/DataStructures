#include <stdio.h>
#include <stdlib.h>

typedef struct rehber
{
    char tel[15];
    char ad[30];
    char soyad[30];

    struct rehber *next;
} Bliste;

Bliste *ekle(Bliste *ll)
{
    if(ll == NULL)
    {
        ll = (Bliste*)malloc(sizeof(Bliste));
        printf("\nTelefon numarasi giriniz : ");
        scanf("%s", ll->tel);
        printf("\nAd giriniz : ");
        scanf("%s", ll->ad);
        printf("\nSoyad giriniz : ");
        scanf("%s", ll->soyad);
        ll->next = ll;
        return ll;
    }
    Bliste *temp = (Bliste*)malloc(sizeof(Bliste));
    Bliste *iter = ll;
    while(iter->next != ll)
    {
        iter = iter->next;
    }
    printf("\nTelefon numarasi giriniz : ");
    scanf("%s", temp->tel);
    printf("\nAd giriniz : ");
    scanf("%s", temp->ad);
    printf("\nSoyad giriniz : ");
    scanf("%s", temp->soyad);
    iter->next = temp;
    temp->next = ll;
    return ll;
}

void Listele(Bliste *ll)
{
    Bliste *iter = ll;
    printf("\n");
    if(ll == NULL)
    {
        return NULL;
    }
    while(iter->next != ll)
    {
        printf("\nTel : %s", iter->tel);
        printf("\nAd : %s", iter->ad);
        printf("\nSoyad : %s", iter->soyad);
        printf("\n---------------------------------\n");
        iter=iter->next;
    }

    printf("\nTel : %s", iter->tel);
    printf("\nAd : %s", iter->ad);
    printf("\nSoyad : %s", iter->soyad);
}

Bliste *NumaraDegistirme(Bliste *ll)
{
    char degisecektel[15], yenitel[15];
    printf("\nDegisecek telefon numarasini  giriniz : ");
    fflush(stdin);
    scanf("%s", &degisecektel);
    printf("\nYeni telefon numarasini giriniz : ");
    fflush(stdin);
    scanf("%s", &yenitel);

    int uz = strlen(degisecektel);
    int kelimeuz = 0;

    if(ll == NULL)
    {
        return NULL;
    }

    else if(ll->next == ll)
    {
        for(int i=0; i<uz; i++)
        {
            if(ll->tel[i] == degisecektel[i])
            {
                kelimeuz++;

            }
        }
        if(kelimeuz == uz)
        {
            for(int i=0; i<uz; i++)
            {
                ll->tel[i] = yenitel[i];
            }

            return ll;

        }
    }
    else
    {
        Bliste *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->tel[i] == degisecektel[i])
                {
                    kelimeuz++;

                }

            }
            if(kelimeuz == uz)
            {
                for(int i=0; i<uz; i++)
            {
                iter->next->tel[i] = yenitel[i];
            }

                return iter->next;
            }


            iter = iter->next;


        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {

            if(iter->next->tel[i] == degisecektel[i])
            {
                kelimeuz++;

            }

        }
        if(kelimeuz == uz)
        {
                for(int i=0; i<uz; i++)
            {
                iter->next->tel[i] = yenitel[i];
            }
            return iter->next;
        }
    }
}


void AraNumara(Bliste *ll)
{
    int kontrol = 0;
    char aranantel[15];

    printf("\nAranacak numarayi giriniz : ");
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
            if(ll->tel[i] == aranantel[i])
            {
                kelimeuz++;

            }
        }
        if(kelimeuz == uz)
        {
            printf("\nTel : %s", ll->tel);
            printf("\nAd : %s", ll->ad);
            printf("\nSoyad : %s", ll->soyad);
            printf("\n---------------------------------\n");

        }
    }
    else
    {
        Bliste *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->tel[i] == aranantel[i])
                {
                    kelimeuz++;

                }

            }
            if(kelimeuz == uz)
            {
                printf("\nTel : %s", iter->next->tel);
                printf("\nAd : %s", iter->next->ad);
                printf("\nSoyad : %s", iter->next->soyad);
                printf("\n---------------------------------\n");
            }


            iter = iter->next;


        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {

            if(iter->next->tel[i] == aranantel[i])
            {
                kelimeuz++;

            }

        }
        if(kelimeuz == uz)
        {
            printf("\nTel : %s", iter->next->tel);
            printf("\nAd : %s", iter->next->ad);
            printf("\nSoyad : %s", iter->next->soyad);
            printf("\n---------------------------------\n");
        }
    }
}



Bliste *Sil(Bliste *ll)
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
            if(ll->tel[i] == silinecektel[i]) // listede sadece bir deger var ise
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
        Bliste *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->tel[i] == silinecektel[i])
                {
                    kelimeuz++;

                }
            }
            if(kelimeuz == uz)
            {
                Bliste *temp = iter->next;
                iter->next = temp->next;
                free(temp);
                return ll;
            }

            iter = iter->next;
        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {
            if(iter->next->tel[i] == silinecektel[i])
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

void AraAd(Bliste *ll)
{

    char arananad[30];

    printf("\nAranacak adi giriniz : ");
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
            if(ll->ad[i] == arananad[i])
            {
                kelimeuz++;

            }
        }
        if(kelimeuz == uz)
        {
            printf("\nTel : %s", ll->tel);
            printf("\nAd : %s", ll->ad);
            printf("\nSoyad : %s", ll->soyad);
            printf("\n---------------------------------\n");

        }
    }
    else
    {
        Bliste *iter = ll;
        while(iter->next != ll)
        {
            kelimeuz = 0;
            for(int i=0; i<uz; i++)
            {
                if(iter->next->ad[i] == arananad[i])
                {
                    kelimeuz++;

                }

            }
            if(kelimeuz == uz)
            {
                printf("\nTel : %s", iter->next->tel);
                printf("\nAd : %s", iter->next->ad);
                printf("\nSoyad : %s", iter->next->soyad);
                printf("\n---------------------------------\n");
            }


            iter = iter->next;


        }
        kelimeuz = 0;
        for(int i=0; i<uz; i++)
        {

            if(iter->next->ad[i] == arananad[i])
            {
                kelimeuz++;

            }

        }
        if(kelimeuz == uz)
        {
            printf("\nTel : %s", iter->next->tel);
            printf("\nAd : %s", iter->next->ad);
            printf("\nSoyad : %s", iter->next->soyad);
            printf("\n---------------------------------\n");
        }
    }
}
int main()
{
   Bliste *ll = NULL;

    int menu;


    printf("1)Ekle\n2)Listele\n3)Numaraya gore arama\n4)Isime gore arama\n5)Sil\n6)Numara degistirme\n0)Cikis\n");
    printf("\n-----------------------------------\n");

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
            ll = NumaraDegistirme(ll);
            break;
        case 0:
            exit(0);
        }
    }

    return 0;
}
