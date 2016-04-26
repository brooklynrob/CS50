#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i1 = 2;
    int* p1;
    int* p2 = malloc(sizeof(int));
    p1 = &i1;
    *p2 = 79;

    
    
    printf("value of p1 is %i\n", *p1);
    printf("value of p2 is %i\n", *p2);

    printf("Memory address of p1 is %p\n", p1);
    printf("Memory address of p2 is %p\n", p2);
    
    struct date
    {
        int month;
        int day;
        int year;
    };
    
    struct date todaysDate;
    
    struct date* datePtr;
    
    datePtr = &todaysDate;
    
    //3 ways of assigning values
    (*datePtr).day=21;
    datePtr->month=5;
    todaysDate.year=2016;
    
    printf("%i\n", (*datePtr).month);
    
    
    
    


}