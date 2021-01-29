#include <stdio.h>
#include <stdlib.h>

typedef struct Kitap
{
    int isbn;
    char *ad;
    struct Kitap *prev, *next;
} Kliste;


Kliste *SiraliEkle(Kliste *root, char *ad, int isbn)
{

    if(root == NULL)
    {
        root = (Kliste*)malloc(sizeof(Kliste));
        root->ad = ad;
        root->isbn = isbn;
        root->next = root;
        root->prev = root;
        return root;
    }
    Kliste *iter = root;
    if(strcmp(iter->ad, ad) > 0)
    {
        Kliste *temp = (Kliste*)malloc(sizeof(Kliste));
        temp->ad = ad;
        temp->isbn = isbn;
        temp->next = root;
        temp->prev = root->prev;
        root->prev = temp;
        temp->prev->next = temp;
        return temp;
    }

    while(strcmp(iter->next->ad, ad) < 0)
    {
        if(iter->next == root)
        {
            iter->next = (Kliste*)malloc(sizeof(Kliste));
            iter->next->ad = ad;
            iter->next->isbn = isbn;
            iter->next->next = root;
            iter->next->prev = iter;
            root->prev = iter->next;
            return root;
        }
        iter = iter->next;
    }
    Kliste *temp = (Kliste*)malloc(sizeof(Kliste));
    temp->ad = ad;
    temp->isbn = isbn;
    temp->next = iter->next;
    temp->prev = iter;
    iter->next = temp;
    temp->next->prev = temp;
    return root;
}



Kliste *SiraliListeleme(Kliste *root) // tam calismiyor.
{
    Kliste *temp, *swap, *swap2;

    temp = root;


    while((temp->isbn < temp->next->isbn))
    {
        swap = temp->next->isbn;
        swap2 = temp->next->ad;
        temp->next->isbn = temp->isbn;
        temp->next->ad = temp->ad;
        temp->isbn = swap;
        temp->ad = swap2;
        SiraliListeleme(temp->next);

    }
    return root;
}


void Listele(Kliste *root)
{
    Kliste *iter = root;
    if(root == NULL)
        return NULL;
    while(iter->next != root)
    {
        printf("\nISBN : %d ", iter->isbn);
        printf("\nKitap Adi : %s  \n", iter->ad);
        iter = iter->next;
    }
    printf("\nISBN : %d ", iter->isbn);
    printf("\nKitap Adi : %s  ", iter->ad);
}


int main()
{

    Kliste *root = NULL;
    int menu;

    while(1 == 1)
    {
        printf("\n\n1) Kitap Ekle\n2) Listele\n3) Cikis\n\n");
        printf("\nMenu seciniz : ");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            root = SiraliEkle(root, "Cirak", 1887);
            root = SiraliEkle(root, "Bosluk", 1877);
            root = SiraliEkle(root, "Saatleri Anlama Enstitusu", 1842);
            root = SiraliEkle(root, "Kucuk Aga", 1702);
            root = SiraliEkle(root, "Donusum", 1452);
            root = SiraliEkle(root, "Milena'ya Mektuplar", 1945);
            break;
        case 2:
            Listele(root);
            printf("\n\n\t --- Sirali Hali (isbn ' ye gore) ---\n\n");
            root = SiraliListeleme(root);
            Listele(root);
            break;

        case 3:
            printf("\n Cikis Yapiliyor ..");
            return 0;
        default:
            printf("\n! Gecersiz menu secimi.");
            break;
        }

    }

    return 0;
}
