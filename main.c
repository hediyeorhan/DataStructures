#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, char *kaynak, char *ara, char *hedef)
{
    if(n==1)
    {
       printf("%s -> %s\n", kaynak, hedef);
    }

    else
    {
        hanoi(n-1, kaynak, hedef, ara);
        printf("%s -> %s\n", kaynak, hedef);
        hanoi(n-1, ara, kaynak, hedef);
    }
}

int main()
{
    hanoi(3, "A", "B", "C");
    return 0;
}
