#include <stdio.h>
#include <stdlib.h>

#define N 100

int yigin[N], indis = 0;
int yigina_ekle(int veri)
{
    if(indis == N)
    {
        puts("Yigin dolu !");
        return -1;
    }
    else
    {
        yigin[indis] = veri;
        indis++;
    }
}

int yigindan_Al()
{
    if(indis <= 0)
    {
        puts("Yigin bos !");
        return -1;
    }
    else
        return yigin[--indis];
}

int main()
{
    yigina_ekle(5);
    yigina_ekle(15);
    yigina_ekle(20);
    yigina_ekle(25);
    yigina_ekle(30);
    yigina_ekle(35);
    yigina_ekle(40);

    printf("\n------DEGERLER------\n\n");

    printf("%d ", yigindan_Al());
    printf("%d ", yigindan_Al());
    printf("%d ", yigindan_Al());
    printf("%d ", yigindan_Al());
    printf("%d ", yigindan_Al());
    printf("%d ", yigindan_Al());
    printf("%d \n\n", yigindan_Al());
    return 0;
}
