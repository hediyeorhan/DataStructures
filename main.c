#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}StackList;

StackList *iter = NULL; // Baslangic adresimiz

void push(int data)
{
    if(iter == NULL)
    {
        iter = (StackList*)malloc(sizeof(StackList));
        iter->data = data;
        iter->next = NULL;
    }
    else
    {
        StackList *neww = (StackList*)malloc(sizeof(StackList));
        neww->data = data;
        neww->next = iter;
        iter = neww; // en basa ekliyoruz yeni iterimiz neww oluyor.
    }
}

int pop()
{
    if(iter == NULL)
        return-1;
    int result = iter->data;

    StackList *temp = iter;
    iter = iter->next;
    free(temp);
    return result;
}

void printStack()
{
    printf("\n");
    StackList *temp = iter;
    if(iter == NULL)
        return-1;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{

    // Yigina ekleme ve yazdirma islemleri

    push(10);
    printStack();
    push(20);
    printStack();
    push(30);
    printStack();
    push(40);
    printStack();
    push(50);
    printStack();

    printf("\n\n--------------------\n\n");

    // Yigindan eleman silme ve listeleme islemleri

    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    pop();
    printStack();
    return 0;
}
