#include <stdio.h>
#include <cs50.h>
#include <string.h>

// This function makes sure a character is upper case -- used so we can treat A and a, B and B, etc., the same
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

// This function handles the wrapping
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


// this is a utility function to handle the iterator used for the keyword
int keyIterCheck (int k_iter, int key_len) {
    if (k_iter < ((key_len)-1))
    {
        k_iter++;
        return k_iter;
    }

    else
    {
        return 0;
    }
}


int main(int argc, string argv[])
{

    //If there is there are no args or more than 1, "yell" -- i.e., return 1
    if (argc != 2 ) {
        printf("Please enter just one arguement\n!");
        return 1;
    }
    
    string k = argv[1];
    
    // Check that string is alphanumeric
    for (int i = 0, n = strlen(k); i < n; i++) {
        if (k[i]<65 || k[i]>122)
        {
            printf("Please enter an alphabetical only argument\n!"); 
            return 1;
        }
    }
    
    // Ask user for plaintext
    string p = GetString();
    
    

    int key_char;
    int key_len = strlen(k);
    // this is going to track our iterations through the characters in the key
    int key_char_iter = 0;
    
    // This variable will store our final ASCII value for the character   
    int cipher_char;

    
    // Interate over letters
    
    for (int i = 0, n = strlen(p); i < n; i++) {
        //Get the next character in the keytext, convert to uppercase if needed, and subtract 65
        key_char = (toUpper(k[key_char_iter]))-65;

        // If the character is upercase, let's offset it by the key, considering the wrap
        if (p[i]>=65 && p[i]<=90)
        {
            cipher_char = wrap(p[i],key_char,90);
            //Iterate the cipher iterator
            key_char_iter = keyIterCheck(key_char_iter,key_len);
        } 
        
        // else if the character is lowercase, let's offset it by the key, considering the wrap
        else if (p[i]>=97 && p[i]<=122)
        {
            cipher_char = wrap(p[i],key_char,122);
            //Iterate the cipher iterator
            key_char_iter = keyIterCheck(key_char_iter,key_len);
        }
        
        // else the character is not an upper or lowercase letter
        else
        {
            // so we'll leave it as is
            cipher_char = p[i];
            // and we will NOT iterate the cipher iterator
        }
        

        printf("%c", cipher_char);

    }
    
 
printf("\n");

return 0;

}