#include <stdio.h>
#include <cs50.h>
#include <math.h>

float inputValue;
float presentValue;
int coinCount;
int coinCountTemp;


int calcuateCoins(float num,float num2) {
    coinCountTemp = round(num) / round(num2);
    coinCount = coinCount + coinCountTemp;
    presentValue = presentValue - (num2*coinCountTemp);
    return coinCount;
}


int main(void)
{
    
    while(inputValue <= 0)
    {
        printf ("O hai! How much change is owed?\n");
        inputValue = GetFloat();
    }
    
    presentValue = inputValue*100;
    calcuateCoins(presentValue,25);
    calcuateCoins(presentValue,10);
    calcuateCoins(presentValue,5);
    calcuateCoins(presentValue,1);
    printf("%d\n",coinCount);
  
}