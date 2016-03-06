#include <stdio.h>
#include <stdlib.h>

int main(void)
    {
    
    int* x;
    int* y;
    
    x = malloc(sizeof(int));
    
    *x = 42;
    
    printf("Value at x: %d\n", *x);
    printf("Address of p1: %p\n", x);
    
    //*y = 13;
    
    y = x;
    
    printf("Value at y: %d\n", *y);
    printf("Address of y: %p\n", y);
    
    *y = 13;
    
    printf("Value at x: %d\n", *x);
    printf("Address of x: %p\n", x);
    printf("Value at y: %d\n", *y);
    printf("Address of y: %p\n", y);

    return 0;

    }
