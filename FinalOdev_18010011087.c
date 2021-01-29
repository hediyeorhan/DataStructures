#include <stdio.h>
#include <stdlib.h>
#define N 100

// HEDIYE ORHAN - 18010011087

typedef struct node
{
    int indis;
    int eleman[N];

} Yiginlar;

Yiginlar *YiginOlustur()
{
    Yiginlar *yeni_yigin;
    yeni_yigin = (Yiginlar*)malloc(sizeof(Yiginlar));
    yeni_yigin->indis=0;
    return yeni_yigin;
}

int DegerDondur(char isaret)
{
    if(isaret == '^')
    {
        return 3;
    }
    else if(isaret == '*' || isaret == '/')
    {
        return 2;
    }
    else if(isaret == '+' || isaret == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int YiginaEkle(Yiginlar *yeni_yigin, char ekle)
{
    if(yeni_yigin->indis >= N)
    {
        printf("Yigin dolu !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->eleman[yeni_yigin->indis] = ekle;
        yeni_yigin->indis++;
        return 1;
    }
}


char YigindanCikar(Yiginlar *yeni_yigin)
{
    char cikan;
    if(yeni_yigin->indis == 0)
    {
        printf("Yigin bos !\n");
        getch();
        return -1;
    }
    else
    {
        yeni_yigin->indis--;
        cikan = yeni_yigin->eleman[yeni_yigin->indis];
        return cikan;
    }
}


int HarfKontrol(char i)
{
    if(i<= 'z' && i>= 'a')
        return 1;
    else if(i<= 'Z' && i>= 'A')
        return 1;
    else
        return 0;
}

int RakamKontrol(char r)
{
    if(r == '0' || r == '1' || r == '2' || r == '3' || r == '4' || r == '5' || r == '6' || r == '7' || r == '8' || r == '9')
        return 1;
    else
        return 0;
}

void InfixPostfixDonusum(Yiginlar *yigin, char *infix, char *postfix, int i, int j)
{
    char deger;
    char cikan;


    deger = infix[i];

    if (deger == '\0')
    {
        postfix[j] = '\0';
        return;
    }


    if(deger == '(' )
    {
        YiginaEkle(yigin, deger);
    }
    else if(RakamKontrol(deger) == 1 || HarfKontrol(deger) == 1)
    {
        postfix[j] = deger;
        j++;
    }
    else if(deger == '^' || deger == '*' || deger == '/' || deger == '+' || deger == '-')
    {
        cikan=YigindanCikar(yigin);
        while(DegerDondur(cikan) >= DegerDondur(deger))
        {
            postfix[j] = cikan;
            j++;
            cikan = YigindanCikar(yigin);
        }
        YiginaEkle(yigin, cikan);
        YiginaEkle(yigin, deger);
    }
    else if(deger == ')')
    {
        cikan = YigindanCikar(yigin);
        while(cikan != '(')
        {
            postfix[j] = cikan;
            j++;
            cikan = YigindanCikar(yigin);
        }
    }
    else
    {
        printf("\n GECERSIZ KARAKTER !!");
        exit(0);
    }

    i++;
    deger = infix[i];
    InfixPostfixDonusum(yigin, infix, postfix, i, j);

}



void Hesaplama(Yiginlar *yeni_yigin, char *postfix, int i)
{
    int x=0, a=0, b=0;
    if(postfix[i] == '\0')
    {
        printf("\n\n\t --> POSTFIX IFADENIN ISLEM SONUCU  : %d\n", YigindanCikar(yeni_yigin));
        return;
    }

    if(postfix[i] == '+')
    {
        a = YigindanCikar(yeni_yigin);
        b = YigindanCikar(yeni_yigin);
        YiginaEkle(yeni_yigin, a+b);
        printf("\n%d+%d = %d", a, b, a+b);
    }
    else if(postfix[i] == '-')
    {
        a = YigindanCikar(yeni_yigin);
        b = YigindanCikar(yeni_yigin);
        if(a >= b)
        {
            YiginaEkle(yeni_yigin, a-b);
            printf("\n%d-%d = %d", b, a, a-b);
        }
        else
        {
            YiginaEkle(yeni_yigin, b-a);
            printf("\n%d-%d = %d", b, a, b-a);
        }

    }
    else if(postfix[i] == '/')
    {
        a = YigindanCikar(yeni_yigin);
        b = YigindanCikar(yeni_yigin);
        if(a >= b)
        {
            YiginaEkle(yeni_yigin, a/b);
            printf("\n%d/%d = %d", b, a, a/b);
        }
        else
        {
            YiginaEkle(yeni_yigin, b/a);
            printf("\n%d/%d = %d", b, a, b/a);
        }

    }
    else if(postfix[i] == '*')
    {
        a = YigindanCikar(yeni_yigin);
        b = YigindanCikar(yeni_yigin);
        YiginaEkle(yeni_yigin, a*b);
        printf("\n%d*%d = %d", a, b, a*b);

    }
    if(postfix[i] >= '0' && postfix[i] <= '9')
    {
        x = postfix[i] - '0';
        YiginaEkle(yeni_yigin, x);
    }
    i++;
    Hesaplama(yeni_yigin, postfix, i);
}

char *strcatfonksiyonu(char *str1,char *str2)
{

    int c = 0;
    int s;

    while(str1[c] != 0)
    {
        c++;
    }

    for(s=0; s<strlen(str2); s++)
    {
        str1[s+c] = str2[s];
    }

    str1[s+c] = 0;

    return str1;

}

int main()
{

    Yiginlar *yigin = YiginOlustur();
    char infix[N];
    char postfix[N];

    int menu;

    while(1 == 1)
    {
        printf("\n-----------------------------------\n");
        printf("\t 1) Hesaplama Yap \n\t 0) Cikis \n Secim yapiniz : ");
        scanf("%d", &menu);
        printf("\n-----------------------------------\n");
        switch(menu)
        {
        case 1:
            printf("\nHesaplamak istediginiz infix ifadeyi giriniz : ");
            fflush(stdin);
            gets(infix);
            printf("\n\n\t --> INFIX : %s\n", infix);
            YiginaEkle(yigin, '(');
            strcatfonksiyonu(infix, ")");
            printf("\n\nInfix ifade postfixe donusturuluyor ..");
            sleep(2);
            InfixPostfixDonusum(yigin, infix, postfix, 0, 0);
            printf("\n\n\t --> POSTFIX : %s\n", postfix);
            printf("\n\nPostfix ifade islem sonucu hesaplaniyor ..");
            sleep(2);
            printf("\n\nISLEM \n-----------");
            Hesaplama(yigin, postfix, 0);
            break;
        case 0:
            printf("\n Cikis Yapiliyor...\n");
            return 0;
        default:
            printf("\nGecersiz Secim !!\n");
            break;
        }
    }

    return 0;

}
