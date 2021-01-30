#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Bliste;


Bliste *insert(Bliste *root, int data) // Sirali ekleme
{
    Bliste *iter = root;

    if(root == NULL)
    {
        root = (Bliste*)malloc(sizeof(Bliste));
        root->data = data;
        root->next = root;
        root->prev = root;
        return root;
    }
    else if(root->data > data)
    {
        Bliste *temp = (Bliste*)malloc(sizeof(Bliste));
        temp->data = data;
        temp->next = root;
        temp->prev = root->prev;
        root->prev->next = temp;
        root->prev = temp;
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
    iter->next->prev = temp;
    temp->prev = iter;
    iter->next = temp;
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
    printf("%d \n", iter->data);
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
        {
            return iter->next;
        }
        iter = iter->next;
    }
    return NULL;
}

Bliste *Sil(Bliste *root, int data)
{
    Bliste *iter = root;

    if(root == NULL)
        return NULL;

    if(root->data == data)
    {
        if(root->next == root)
        {
            free(root);
            return NULL;
        }

        Bliste *temp = root->next;
        temp->prev = root->prev;
        root->prev->next = temp;
        free(root);
        return temp;
    }


    while(iter->data != data)
    {
        iter = iter->next;
    }

    iter->prev->next = iter->next;
    iter->next->prev = iter->prev;
    free(iter);
    return root;


}

Bliste *sonaekle(Bliste *root, int data)
{
    Bliste *iter = root;
    if(root == NULL)
    {
        root = (Bliste*)malloc(sizeof(Bliste));
        root->data = data;
        root->next = root;
        root->prev = root;
        return root;
    }
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
    Bliste *root = NULL, *bul;

    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

    printf("\n\nSIRALI EKLEME\n\n");
    Listele(root);

    root = sonaekle(root, 50);
    root = sonaekle(root, 70);
    root = sonaekle(root, 40);
    root = sonaekle(root, 30);
    root = sonaekle(root, 20);

    printf("\n\nSONA EKLEME\n\n");
    Listele(root);

    bul = Ara(root, 50);
    if(bul == NULL)
        printf("50, Deger bulunamadi \n");
    else
        printf("50, Deger bulundu \n");

    bul = Ara(root, 62);
    if(bul == NULL)
        printf("62, Deger bulunamadi \n");
    else
        printf("62, Deger bulundu \n");

    bul = Ara(root, 30);
    if(bul == NULL)
        printf("30, Deger bulunamadi \n");
    else
        printf("30, Deger bulundu \n");

    bul = Ara(root, 20);
    if(bul == NULL)
        printf("20, Deger bulunamadi \n");
    else
        printf("20, Deger bulundu \n");

    bul = Ara(root, 70);
    if(bul == NULL)
        printf("70, Deger bulunamadi \n");
    else
        printf("70, Deger bulundu \n");

    bul = Ara(root, 40);
    if(bul == NULL)
        printf("40, Deger bulunamadi \n");
    else
        printf("40, Deger bulundu \n");

    bul = Ara(root, 85);
    if(bul == NULL)
        printf("85, Deger bulunamadi \n");
    else
        printf("85, Deger bulundu \n");


    root = Sil(root, 50);
    printf("\n50 silindi \n");

    root = Sil(root, 40);
    printf("\n40 silindi \n");

    root = Sil(root, 20);
    printf("\n20 silindi \n\n");


    Listele(root);

    printf("\n");

    bul = Ara(root, 50);
    if(bul == NULL)
        printf("50, Deger bulunamadi \n");
    else
        printf("50, Deger bulundu \n");

    bul = Ara(root, 62);
    if(bul == NULL)
        printf("62, Deger bulunamadi \n");
    else
        printf("62, Deger bulundu \n");

    bul = Ara(root, 30);
    if(bul == NULL)
        printf("30, Deger bulunamadi \n");
    else
        printf("30, Deger bulundu \n");

    bul = Ara(root, 20);
    if(bul == NULL)
        printf("20, Deger bulunamadi \n");
    else
        printf("20, Deger bulundu \n");

    bul = Ara(root, 70);
    if(bul == NULL)
        printf("70, Deger bulunamadi \n");
    else
        printf("70, Deger bulundu \n");

    bul = Ara(root, 40);
    if(bul == NULL)
        printf("40, Deger bulunamadi \n");
    else
        printf("40, Deger bulundu \n");

    bul = Ara(root, 85);
    if(bul == NULL)
        printf("85, Deger bulunamadi \n");
    else
        printf("85, Deger bulundu \n");

    return 0;
}
