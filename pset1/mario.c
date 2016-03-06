#include <stdio.h>
#include <cs50.h>
#include <string.h>

/* set value to -1 in order to get while loop to work */
int inputValue = -1;
int pyramidWidth;
int pyramidHeight;
int a;
int j;
int k;


int createPyramidRowSpaces(num) {
    /* print height less iterator count of spaces */
    for (j = 1; j <= (pyramidHeight-num); j = j + 1) {
        printf(" ");
    }
 
    return 0;
}


int createPyramidRowPoundSigns(num) {
    printf("#");
    for (k = 1; k <= num; k = k + 1) {
        printf("#");
    }
    
    return 0;
}


int main(void) {

    /* Check that the input an integer between 0 and 23 */
    while(inputValue < 0 || inputValue  >= 24)
    {
        printf ("Please enter a number between 0 and 23: ");
        inputValue = GetInt();

    }
    
    /* set pyramid height */
    pyramidHeight = inputValue;

    for(a = 1; a <= pyramidHeight; a = a + 1) {
    
    	createPyramidRowSpaces(a);
     	createPyramidRowPoundSigns(a);   	
    	
    	/* print character return */
    	printf("\n");
    
    }
    
}