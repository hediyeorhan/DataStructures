#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int aranma_sayisi;
    char kelime[30];
    struct node *next;
    struct node *prev;

} Bliste;

int boyut=0;

Bliste *Ekle(Bliste *root)
{
    if(boyut < 20)
    {
        if(root == NULL)
        {
            root = (Bliste*)malloc(sizeof(Bliste));
            printf("Aramak istediginiz kelimeyi giriniz : ");
            fflush(stdin);
            gets(root->kelime);
            root->next = root;
            root->prev = root;
            boyut++;
            return root;
        }
        Bliste *iter = root;

        while(iter->next != root)
        {
            iter = iter->next;
        }
        iter->next = (Bliste*)malloc(sizeof(Bliste));
        printf("Aramak istediginiz kelimeyi giriniz : ");
        fflush(stdin);
        gets(iter->next->kelime);
        iter->next->next = root;
        iter->next->prev = iter;
        root->prev = iter->next;
        boyut++;
        return root;
    }
    else
    {
        printf("\nBagli listede yer kalmadi !!\n");
    }

}

Bliste *Siralama(Bliste *root)
{
    Bliste *temp;
    int swap;

    for(int i=0; i<boyut; i++)
    {
        temp=root;
        while(temp->next != root)
        {
            if(temp->aranma_sayisi < temp->next->aranma_sayisi)
            {
                swap=temp->next->aranma_sayisi;

                temp->next->aranma_sayisi=temp->aranma_sayisi;

                temp->aranma_sayisi=swap;


            }
            temp=temp->next;
        }
    }

    return root;
}

void Listele(Bliste *root)
{
    Bliste *iter = root;
    if(root == NULL)
        return NULL;
    while(iter->next != root)
    {
        printf("Kelime : %s\n", iter->kelime);
        printf("Tekrar sayisi : %d\n", iter->aranma_sayisi);
        printf("\n------------------------------\n");
        iter = iter->next;
    }
    printf("Kelime : %s\n", iter->kelime);
    printf("Tekrar sayisi : %d\n", iter->aranma_sayisi);
}

Bliste *KelimeAranmaSayilari(Bliste *root)
{
    Bliste *iter = root;
    while(iter->next != root)
    {
        iter->aranma_sayisi = Ara(root, iter->kelime);
        iter = iter->next;
    }
    iter->aranma_sayisi = Ara(root, iter->kelime);
    return root;
}

int Ara(Bliste *root, char kelime[30])
{
    int size=0;
    Bliste *iter = root;
    if(root == NULL)
        return NULL;

    else if(strcmp(root->kelime, kelime) == 0)
        size++;
    while(iter->next != root)
    {
        if(strcmp(iter->next->kelime, kelime) == 0)
            size++;
        iter = iter->next;
    }
    return size;
}

int main()
{
    int menu, sonuc;
    Bliste *root = NULL;
    char aranan[30];

    printf("\n\n\t\t -- MENU -- \n\t----------------------------\n\t1)Ekle\n\t2)Listele\n\t----------------------------\n");
    while(1 == 1)
    {
        printf("Menu seciniz : ");
        scanf("%d", &menu);
        printf("\n----------------------------\n");
        switch(menu)
        {
        case 1:
            printf("\nEKLEME\n\n");
            root = Ekle(root);
            root = KelimeAranmaSayilari(root);
            break;
        case 2:
            printf("\nLISTELEME\n\n");
            Listele(root);
            break;
        case 3:
            printf("\nSIRALI LISTELEME\n");
            root = Siralama(root);
            Listele(root);
            break;
        case 0:
            printf("\nCIKIS YAPILIYOR..\n\n");
            exit(0);
        default:
            printf("\nGECERSIZ MENU SECIMI !!\n\n");
            break;
        }
    }
    return 0;
}
