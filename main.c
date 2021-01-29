#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int A[], int start, int end, int element) {
   if(start>end) return -1;
      int mid = (start+end)/2;
   if( A[mid] == element ) return mid;
   else if( element < A[mid] )
      BinarySearch(A, start, mid-1, element);
   else
      BinarySearch(A, mid+1, end, element);
}
int main()
{
   int arr[] = {2, 35, 84, 90, 42, 85, 12};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 12;
   int result = BinarySearch(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d", result);
   return 0;
}
