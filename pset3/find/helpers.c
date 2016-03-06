/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"

// Binary Search function implmeneted using recursion
int binarySearch(int val, int valarray[], int min, int max)
{
    int midpoint = ((min+max)/2);
    
    if (max < min)
    {
        return -1;
    }
    
    else
    {
        if (valarray[midpoint]<val)
        {
            return binarySearch(val, valarray, midpoint+1, max); 
        }
    
        else if (valarray[midpoint]>val)
        {
            return binarySearch(val, valarray, min, midpoint-1);   
        }
        
        else
        {
            return 1;
        }
        
    }

}



/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    while (n <= 0)
    {
        return false;
    }
    
    if ((binarySearch(value, values, 0, n))==1)
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Modified bubble sort
    int a;
    int valueswap = 1;
    
    // While loop to check if there was a valueswap
    while (valueswap == 1)
    {
    valueswap = 0;
    
        for (int k=0; k<n-1; k++)
        {
            if (values[k]>values[k+1])
            {
                a=values[k];
                values[k]=values[k+1];
                values[k+1]=a;
                valueswap=1;

            }
        }

    }  

    
    return;
}