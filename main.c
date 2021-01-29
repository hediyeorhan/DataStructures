#include <stdio.h>
#include <stdlib.h>

typedef struct Yigin
{
    char *data;
    struct Yigin *prev, *next;
} StackList;


StackList *iter = NULL; // Baslangic adresimiz

void push(char *data)
{
    if(iter == NULL)
    {
        iter = (StackList*)malloc(sizeof(StackList));
        iter->data = data;
        iter->next = NULL;
        iter->prev = NULL;
    }
    else
    {
        StackList *neww = (StackList*)malloc(sizeof(StackList));
        neww->data = data;
        neww->next = iter;
        neww->prev = NULL;
        iter->prev = neww;
        iter = neww;
    }
}

int pop()
{
    if(iter == NULL)
        return -1;
    int result = iter->data;

    StackList *temp = iter;
    iter = iter->next;
    free(temp);
    return result;
}

void printStack()
{
    StackList *temp = iter;
    if(iter == NULL)
        return NULL;
    while(temp->next != NULL)
    {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("%s\n", temp->data);
}

void ilerigeri()
{
    int secim;
    StackList *temp = iter;
    while(1==1)
    {
        printf("\nIleri gitmek icin -> 1\nGeri gitmek icin -> 2 : \nCikis icin -> 0 \n Secim : ");
        scanf("%d", &secim);
        printf("\n\n");
        switch(secim)
        {
        case 1:
            if(temp->next != NULL)
            {
                printf("%s ", temp->next->data);
                temp=temp->next;
            }
            else
            {
                printf("\nActiginiz sekmelerin sonuna geldiniz!!\n");
            }
            break;
        case 2:
            if(temp->prev != NULL)
            {
                printf("%s ", temp->prev->data);
                temp = temp->prev;
            }
            else
            {
                printf("\nActiginiz sekmelerin basina geldiniz !\n");
            }
            break;
        case 0:
            return 0;
        default:
            printf("\nGecersiz Secim !!\n");
            break;

        }
    }

}

int main()
{
    /*
    push("instagram.com");
    push("twitter.com");
    push("github.com");
    push("hediyeorhan.com");
    push("google.com");
    push("youtube.com");
    */
    char data[10];

    int menu;

    while(1==1)
    {
        printf("\n1)Yeni Sekme\n2)Acik Sekmelere Gitme\n3)Sekme Kapatma\n4)Siteleri Listele\n5)Cikis\n\n");
        printf("\n-----\nMenu : ");
        scanf("%d", &menu);
        switch(menu)
        {
        case 1:
            /*printf("Gitmek istediginiz siteyi giriniz : ");
            fflush(stdin);
            gets(data);

            push(data);*/
            push("instagram.com");
            push("twitter.com");
            push("github.com");
            push("hediyeorhan.com");
            push("google.com");
            push("youtube.com");
            break;
        case 2:
            ilerigeri();
            break;
        case 3:
            pop();
            break;
        case 4:
            printStack();
            break;
        case 5:
            printf("\nCikis yapiliyor..\n");
            return 0;

        }
    }


    return 0;
}
