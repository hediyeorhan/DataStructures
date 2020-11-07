#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Bliste;

Bliste *SiraliEkle(Bliste *root, int data)
{
    if(root == NULL)
    {
        root = (Bliste*)malloc(sizeof(Bliste));
        root->data = data;
        root->next = root;
        root->prev = root;
        return root;
    }
    Bliste *iter = root;
    if(iter->data > data)
    {
        Bliste *temp = (Bliste*)malloc(sizeof(Bliste));
        temp->data = data;
        temp->next = root;
        temp->prev = root->prev;
        root->prev = temp;
        temp->prev->next = temp;
        return temp;
    }

    while(iter->next->data < data)
    {
        if(iter->next == root)
        {
            iter->next = (Bliste*)malloc(sizeof(Bliste));
            iter->next->data = data;
            iter->next->next = root;
            iter->next->prev = iter;
            root->prev = iter->next;
            return root;
        }
        iter = iter->next;
    }
    Bliste *temp = (Bliste*)malloc(sizeof(Bliste));
    temp->data = data;
    temp->next = iter->next;
    temp->prev = iter;
    iter->next = temp;
    temp->next->prev = temp;
    return root;
}

void Listele(Bliste *root)
{
    Bliste *iter = root;
    if(root == NULL)
        return NULL;
    while(iter->next != root)
    {
        printf("%d <-> ", iter->data);
        iter = iter->next;
    }
    printf("%d\n", iter->data);
}

Bliste *Sil(Bliste *root, int data)
{

    if(root == NULL)
        return NULL;

    else if(root->next == root && root->data == data)
    {
        free(root);
        return NULL;
    }
    if(root->data == data)
    {
        Bliste *temp = root->next;
        temp->prev = root->prev;
        root->prev->next = temp;
        free(root);
        return temp;
    }
    Bliste *iter = root;
    while(iter->data != data)
    {
        iter = iter->next;
    }
    iter->next->prev = iter->prev;
    iter->prev->next = iter->next;
    free(iter);
    return root;
}

Bliste *DegerDegistirme(Bliste *root, int data, int new_data)
{
    Bliste *iter = root;
    if(root == NULL)
        return NULL;
    else if(root->data == data)
    {
        root->data = new_data;
        return root;
    }

    while(iter->next != root)
    {
        if(iter->next->data == data)
        {
            iter->next->data = new_data;
            return root;
        }
        iter = iter->next;
    }
    return root;
}

Bliste *Ara(Bliste *root, int data)
{
    Bliste *iter = root;
    if(root == NULL)
        return NULL;

    else if(root->data == data)
        return root;

    while(iter->next != root)
    {
        if(iter->next->data == data)
            return iter->next;
        iter = iter->next;
    }
    return NULL;
}


Bliste *SonaEkle(Bliste *root, int data)
{
    if(root == NULL)
    {
        root = (Bliste*)malloc(sizeof(Bliste));
        root->data = data;
        root->next = root;
        root->prev = root;
        return root;
    }
    Bliste *iter = root;

    while(iter->next != root)
    {
        iter = iter->next;
    }
    iter->next = (Bliste*)malloc(sizeof(Bliste));
    iter->next->data = data;
    iter->next->next = root;
    iter->next->prev = iter;
    root->prev = iter->next;
    return root;
}

int main()
{
    int menu, data, silinecek, aranacak, degisecek, new_data;
    Bliste *root = NULL, *bul;

    printf("\n\n\t\t -- MENU -- \n\t----------------------------\n\t1)Sirali Ekle\n\t2)Sona Ekle\n\t3)Listele\n\t4)Sil\n\t5)Ara\n\t6)Deger Degistirme\n\t0)Cikis\n\t----------------------------\n");
    while(1 == 1)
    {
        printf("Menu seciniz : ");
        scanf("%d", &menu);
        printf("\n----------------------------\n");
        switch(menu)
        {
        case 1:
            printf("\nSIRALI EKLEME\n\n");
            printf("Eklemek istediginiz sayiyi giriniz : ");
            scanf("%d", &data);
            root = SiraliEkle(root,data);
            break;
        case 2:
            printf("\nSONA EKLEME\n\n");
            printf("Eklemek istediginiz sayiyi giriniz : ");
            scanf("%d", &data);
            root = SonaEkle(root, data);
            break;
        case 3:
            printf("\nLISTELEME\n\n");
            Listele(root);
            break;
        case 4:
            printf("\nSILME\n\n");
            printf("Silmek istediginiz sayiyi giriniz : ");
            scanf("%d", &silinecek);
            root = Sil(root, silinecek);
            break;
        case 5:
            printf("\nARAMA\n\n");
            printf("Aranacak sayiyi giriniz : ");
            scanf("%d", &aranacak);
            bul = Ara(root, aranacak);
            if(bul == NULL)
                printf("Aranan sayi bulunamadi..\n");
            else
                printf("Aranan sayi bulundu.\n");
            break;
        case 6:
            printf("\nDEGER DEGISTIRME\n\n");
            printf("Degistirmek istediginiz sayiyi giriniz : ");
            scanf("%d", &degisecek);
            printf("\nSayinin yeni degerini giriniz : ");
            scanf("%d", &new_data);
            root = DegerDegistirme(root, degisecek, new_data);
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
