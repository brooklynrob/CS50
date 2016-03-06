#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Function to check if a letter is upper case or lower case; of lower make upper
int toUpper(int ascii_code)
{
    // If ASCII code is between 65 and 90, do nothing
    if (ascii_code >= 65 && ascii_code <=90)
    {
        return ascii_code;
    }
    
    // If ASCII code is 97 and 122, subtract 32
    else
    {
        ascii_code = ascii_code-32;
        return ascii_code; 
    }
}


int main(void)
{
    char charLetter;
    string inputString;
    inputString = GetString();
    
    // Get first character, convert if need be, and print
    charLetter = inputString[0];
    charLetter = toUpper(charLetter);
    printf("%c", charLetter);
    
    //Look for spaces, then convert and print next character
    for (int i=0; i < strlen(inputString); i++)
        if (inputString[i] == 32)
        {
            charLetter = inputString[i+1];
            charLetter = toUpper(charLetter); 
            printf("%c", charLetter);
        }
        
        
    printf("\n");

}