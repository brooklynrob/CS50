#include <stdio.h>
#include <cs50.h>
#include <string.h>

// This function does the wrapping in the event the key needs to wrap back to start of letters
int wrap(int pval, int key, int end)
{
    if ((pval+key)>end)
    {
        return pval-26+key;
    }
            
    else
    {
        return pval+key;         
    }
    
}


int main(int argc, string argv[])
{

    //If there is there are no args or more than 1, "yell" -- i.e., return 1
    if (argc != 2 ) {
        printf("Yelling\n!");
        return 1;
    }
 
    int k = atoi(argv[1]);
    
    while (k>=26) 
    {
        k = k % 26;
    }
    // Ask user for plaintext
    string p = GetString();
 
    // This variable will store our final ASCII value for the character   
    int kp;
    
    for (int i = 0, n = strlen(p); i < n; i++) {
        
        // If the character is upercase, let's offset it by the key, considering the wrap
        if (p[i]>=65 && p[i]<=90)
        {
            kp = wrap(p[i],k,90);
        } 
        
        // else if the character is lowercase, let's offset it by the key, considering the wrap
        else if (p[i]>=97 && p[i]<=122)
        {
            kp = wrap(p[i],k,122);
        }
      
        // else the character is not an upper or lowercase letter
        else
        {
            // so we'll leave it as is
            kp = p[i];
        }

    printf("%c", kp);

    }
    

printf("\n");

return 0;

}

