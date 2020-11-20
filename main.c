#include <stdio.h>
#include <stdlib.h>

typedef struct Kuyruk
{
    int data;
    struct Kuyruk *next;

};

struct Kuyruk *root;
int size=0;

void Enqueu(int data)
{
    if(size==0)
    {
        root = (struct Kuyruk*)malloc(sizeof(struct Kuyruk));
        root->data = data;
        root->next = NULL;
        size++;
    }
    else
    {
        struct Kuyruk *iter = (struct Kuyruk*)malloc(sizeof(struct Kuyruk));
        iter->data = data;
        iter->next=root;
        size++;
        root = iter;
    }
}

int Dequeu()
{
    int i;
    if(size==0)
    {
        return -1;
    }
    if(size==1)
    {
        int result = root->data;
        root=NULL;
        size--;
        return result;
    }
    else
    {
        struct Kuyruk *iter = root;
        for(i=0; i<size-2; i++)
        {
            iter=iter->next;
        }
        struct Kuyruk *temp = iter->next;
        int result = iter->next->data;
        iter->next = NULL;
        free(temp);
        size--;
        return result;
    }
}

void Listele()
{
    int i;
    struct Kuyruk *iter = root;
    printf("\n");
    for(i=0; i<size; i++)
    {
        printf("%d -> ", iter->data);
        iter=iter->next;
    }
}
int main()
{
    Enqueu(10);
    Enqueu(20);
    Enqueu(30);
    Listele();
    Enqueu(40);
    Enqueu(50);
    Listele();

    printf("\nDequeu : %d\n", Dequeu());
    printf("Dequeu : %d\n", Dequeu());
    Listele();
    printf("\nDequeu : %d\n", Dequeu());
    printf("Dequeu : %d\n", Dequeu());
    Listele();
    return 0;
}
