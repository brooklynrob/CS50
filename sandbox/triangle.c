#include <stdio.h>

int main(void)
{
    int n, triangularNumber;
    triangularNumber = 0;
    for(n=1; n<=200; n=n+1)
        triangularNumber = triangularNumber + n;
        printf("The %ith triangular number is %i\n", n-1, triangularNumber);
        return 0;
}