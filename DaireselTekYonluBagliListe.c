#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Bliste;


Bliste *insert(Bliste *ll, int data)
{
    if(ll == NULL)
    {
        ll = (Bliste*)malloc(sizeof(Bliste));
        ll->data = data;
        ll->next = ll;
        return ll;
    }

    Bliste *temp = (Bliste*)malloc(sizeof(Bliste));
    Bliste *iter = ll;
    while(iter->next != ll)
    {
        iter = iter->next;
    }
    temp->data = data;
    iter->next = temp;
    temp->next = ll;

    return ll;
}

Bliste *insert_sequentially(Bliste *ll, int data)
{

    if(ll == NULL)
    {
        ll = (Bliste*)malloc(sizeof(Bliste));
        ll->data = data;
        ll->next = ll;
        return ll;
    }
    if(ll->data > data)
    {
        Bliste *temp = (Bliste*)malloc(sizeof(Bliste));

        temp->data = data;
        temp->next = ll;

        Bliste *iter = ll;
        while(iter->next != ll)
        {
            iter = iter->next;
        }
        iter->next = temp;
        return temp;

    }

    Bliste *iter = ll;
    while(iter->next != ll && iter->next->data < data)
    {

        iter = iter->next;
    }
    Bliste *temp = (Bliste*)malloc(sizeof(Bliste));

    temp->data = data;
    temp->next = iter->next;
    iter->next = temp;
    //temp->data = data;
    return ll;

}

void printll(Bliste *ll)
{
    Bliste *iter = ll;
    printf("\n");
    while(iter->next != ll)
    {
        printf("%d\t", iter->data);
        iter=iter->next;
    }
    printf("%d\t", iter->data); // en son elemani da yazmasi icin ekledik.

}

Bliste *del(Bliste *ll, int data)
{
    if(ll == NULL)
    {
        return NULL;
    }
    else if(ll->next == ll && ll->data == data) // listede sadece bir deger var ise
    {
        return NULL; // listedeki tek degeri siliyoruz ve listeyi bosaltiyoruz
    }
    else
    {
        Bliste *iter = ll;
        while(iter->next != ll)
        {
            if(iter->next->data == data)
            {
                Bliste *temp = iter->next;
                iter->next = temp->next;
                free(temp);
                return ll;
            }
            iter = iter->next;
        }
        if(iter->data == data)
        {
            iter->next = iter->next->next;
            free(ll);
            ll = iter->next;
            return ll;
        }
    }
    return ll;
}

Bliste *Search(Bliste *ll, int data)
{
    Bliste *iter = ll;
    if(ll->data == data) // Listedeki ilk elemani ariyorsak
    {
        return NULL;
    }

    while(iter->next != ll)
    {

        if(iter->next->data == data)
        {
            return iter->next;
        }

        iter = iter->next;
    }
    return iter->next;

}

int main()
{

    Bliste *ll = NULL, *bul = NULL;


    /*ll = insert_sequentially(ll, 400);
    ll = insert_sequentially(ll, 30);
    ll = insert_sequentially(ll, 15);
    ll = insert_sequentially(ll, 38);
    */
    ll = insert(ll, 400);
    ll = insert(ll, 30);
    ll = insert(ll, 15);
    ll = insert(ll, 38);
    printll(ll);
    //ll = del(ll, 38);
    //printll(ll);

    printf("\n----------------------\n");
    bul = Search(ll, 400);
    if(bul != ll)
    {
        printf("\nSayi bulundu ..\n");
    }

    else
    {
        printf("\nSayi bulunamadi ..\n");
    }


    return 0;
}
