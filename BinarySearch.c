#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int A[], int bas, int son, int element) {
   if(bas>son) return -1;
      int orta = (bas+son)/2;
   if( A[orta] == element ) return orta;
   else if( element < A[orta] )
      BinarySearch(A, bas, orta-1, element);
   else
      BinarySearch(A, orta+1, son, element);
}

int main()
{
   int dizi[] = {2, 35, 84, 90, 42, 85, 12};
   int n = sizeof(dizi)/ sizeof(dizi[0]);
   int x = 12;
   int indeks = BinarySearch(dizi, 0, n-1, x);
   if(indeks == -1)
      printf("\nDeger dizide bulunmuyor !!\n");
   else
      printf("\nDeger bulundu ! Index :  %d\n", indeks);
                
   return 0;
}
