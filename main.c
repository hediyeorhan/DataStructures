#include <stdio.h>
#include <stdlib.h>

double Banka(double anapara, double faiz, int ay)
{
    if(ay == 0)
    {
        printf("\nBankada  biriken toplam para : %f TL'dir.\n", anapara);
        return anapara;
    }

    else
    {
        faiz += faiz * ((double)1/100);
        anapara += anapara * faiz;

        Banka(anapara, faiz, ay-1);
    }
}

int main()
{
    double anapara = 35.000;
    double bas_faiz_orani = 0.15; // yuzde cinsinden yazdim.
    int ay = 5; // Para bankada 5 ay kalmıs.
    Banka(anapara, bas_faiz_orani, ay);
    return 0;
}
