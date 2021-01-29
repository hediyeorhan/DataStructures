#include <stdio.h>
#include <stdlib.h>

typedef struct Banka
{
    int para;
    int musteri_id;
    struct Banka *next;
}Bank;



Bank *insert(Bank *ll, int musteri_id, int para)
{
    if(ll == NULL)
    {
        ll = (Bank*)malloc(sizeof(Bank));
        ll->musteri_id = musteri_id;
        ll->para = 0;
        ll->para += para;
        ll->next = ll;
        return ll;
    }

    Bank *temp = (Bank*)malloc(sizeof(Bank));
    Bank *iter = ll;
    while(iter->next != ll)
    {
        iter = iter->next;
    }
    temp->musteri_id = musteri_id;
    temp->para =0;
    temp->para += para;
    iter->next = temp;
    temp->next = ll;

    return ll;
}
void printll(Bank *ll)
{
    Bank *iter = ll;
    printf("\n");
    while(iter->next != ll)
    {
        printf("\nMusteri id : %d", iter->musteri_id);
        printf("\nMusteri para : %d", iter->para);
        printf("\n--------------------------------\n");
        iter=iter->next;
    }
    printf("\nMusteri id : %d", iter->musteri_id);
    printf("\nMusteri para : %d TL", iter->para);
    printf("\n--------------------------------\n");

}

Bank *ParaYatirma(Bank *ll, int id, int yatirilacak)
{
    Bank *iter = ll;
    if(ll->musteri_id == id)
    {
        ll->para +=yatirilacak;

        return ll;
    }

    while(iter->next != ll)
    {

        if(iter->next->musteri_id == id)
        {
            iter->next->para += yatirilacak;
            return ll;
        }

        iter = iter->next;
    }
    return ll;

}

Bank *ParaCekme(Bank *ll, int id)
{
    Bank *iter = ll;
    if(ll->musteri_id == id) // Listedeki ilk elemani ariyorsak
    {
        ll->para = 0;

        return ll;
    }

    while(iter->next != ll)
    {

        if(iter->next->musteri_id == id)
        {
            iter->next->para = 0;

            return ll;
        }

        iter = iter->next;
    }
    return ll;

}

int ToplamPara(Bank *ll)
{
    Bank *iter = ll;
    printf("\n");
    int toplam_para=0;
    while(iter->next != ll)
    {
        toplam_para += iter->para;
        iter = iter->next;
    }
    toplam_para += iter->para;
    return toplam_para;
}

int main()
{
    Bank *ll = NULL;

    ll = insert(ll, 1548, 1500);
    ll = insert(ll, 756, 250000);
    printf("\nToplam Para : %d TL", ToplamPara(ll));
    printll(ll);

    ll = ParaYatirma(ll, 1548, 30000);
    printf("\nToplam Para : %d TL", ToplamPara(ll));
    printll(ll);

    ll = ParaCekme(ll, 756);
    printf("\nToplam Para : %d TL", ToplamPara(ll));
    printll(ll);
    return 0;
}
