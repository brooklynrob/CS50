#include <stdio.h>
#include <cs50.h>

int inputValue;
int result;

int main(void)
{

    /* Check that the input is a natural number - not 0 or not negative) */
    while(inputValue < 1)
    {
        printf ("minutes: ");
        inputValue = GetInt();
    }
    
    result = inputValue * 12;
    printf("bottles: ");
    printf("%i", result);
    printf("\n");
    
}