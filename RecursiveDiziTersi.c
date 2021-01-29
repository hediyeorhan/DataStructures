#include <stdio.h>
#include <stdlib.h>

int *TersDizi(int s[], int c[], int uzunluk, int i)
{
    if(uzunluk < 0)

        return s;

    s[i] = c[uzunluk];
    TersDizi(s, c, uzunluk-1, i=i+1);
}


int main()
{
    //int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int c[] = {15, 85, 95, 12, 64, 32, 50};
    int uzunluk = sizeof(c) / sizeof(int);
    int s[uzunluk];

    printf("\n -- Dizinin Duz Hali -- \n");
    for(int i=0; i<uzunluk; i++)
    {
        printf("dizi[%d] : %d\n",i, *(c+i));
    }

    int *sonuc = TersDizi(s, c, uzunluk-1, 0);

    printf("\n -- Dizinin Ters Hali -- \n");
    for(int i=0; i<uzunluk; i++)
    {
        printf("dizi[%d] : %d\n",i, *(sonuc+i));
    }

}
