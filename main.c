#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fact(int n)
{
    int x, y;
    if(n==0)
    {
        return 1;
    }
    x = n-1;
    y=fact(x);
    return(n * y);
}

// iyilestirilmis fact recursive fonk.
int bestfact(int n)
{
    return ((n==0) ? 1 : n * (bestfact(n-1)));
}

int iterativefact(int n)
{
    int i, fact = 1;
    for(i=n; i>0; i--)
    {
        fact *= i;
    }
    return fact;
}

int recursiveFibonacci(int n)
{
    if(n<=1)
        return n;
    return recursiveFibonacci(n-1) + recursiveFibonacci(n-2);
}

void iterativeFibonacci(int n)
{
    int i, sonsayi=1, onsayi=0, tut=0;
    printf("%d %d ", onsayi, sonsayi);
    for(i=0; i<=n; i++)
    {
       tut = sonsayi + onsayi;
       onsayi = sonsayi;
       sonsayi = tut;
       printf(" %d ", tut);
    }
}

int main()
{
/*
    clock_t start_t, end_t;
    start_t = clock();
    printf("5! : %d\n", fact(5));
    printf("6! : %d\n", fact(6));
    printf("7! : %d\n", fact(7));
    end_t = clock();

    printf("\nCalisma suresi : %f\n" ,(double)(end_t-start_t)/CLOCKS_PER_SEC);

    printf("\n IYILESTIRILMIS\n");

    start_t = clock();
    printf("5! : %d\n", fact(5));
    printf("6! : %d\n", fact(6));
    printf("7! : %d\n", fact(7));
    end_t = clock();
    printf("\nCalisma suresi : %f\n" ,(double)(end_t-start_t)/CLOCKS_PER_SEC);
    return 0;

    printf("5! : %d\n", iterativefact(5));
    printf("6! : %d\n", iterativefact(6));
    printf("7! : %d\n", iterativefact(7));
*/
/*
    printf("5.deger : %d\n", recursiveFibonacci(5));
    printf("6.deger : %d\n", recursiveFibonacci(6));
    printf("7.deger : %d\n", recursiveFibonacci(7));
*/
    printf("\nILK 5\n");
    iterativeFibonacci(5);
    printf("\nILK 10\n");
    iterativeFibonacci(10);
    printf("\nILK 20\n");
    iterativeFibonacci(20);
}
