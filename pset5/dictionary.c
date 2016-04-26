/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>

// Need for malloc
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <ctype.h>

#include "dictionary.h"

int const SIZE = 10;

int word_counter;


typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}
node;

// Create the hashtable
node* hashtable[SIZE];


// This is what to optimize in this PSET! (Or do tries!)
int hash_function(char* key)
{
    int hash = (toupper(key[0] - 'A'))+(toupper(key[1] - 'A'))+strlen(key);

    return hash;
    //return hash % SIZE;
}



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{


    int search_word_len = strlen(word);
    char search_word[LENGTH+1];
    for (int i=0; i < search_word_len; i++)
    {
        search_word[i] = tolower(word[i]);
    }
    search_word[search_word_len] = '\0';
    
    int hash_val;

    hash_val = hash_function(search_word);
    
    node* search_node=hashtable[hash_val];
    
    while (search_node != NULL)
    {

        if ((strncmp(search_word, search_node->word, search_word_len)==0) && (search_word_len == strlen(search_node->word)))

        {
            return true;
        }
        
        else if (search_node->next == NULL) 
        {
            return false;
        }
        
        else
        {
            search_node = search_node->next;
        }
    }
    
    free(search_node);
    return false;
    
}



/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //load dictioary 
    FILE* dp = fopen(dictionary, "r");
    if (dp == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        unload();
        return false;
    }
    

    char *curr_word = (char*) malloc(LENGTH);
    //node* cursor_node = malloc(sizeof(node));
    
    while (fscanf(dp, "%s", curr_word) != EOF)
    {
        //Increment word counter
        word_counter++;
        
        //take scanned word and load into the new load node
        node* load_node = malloc(sizeof(node));
        strcpy(load_node->word, curr_word);
        load_node->next = NULL;

        //Calculate hash value for word
        int hash_val = hash_function(load_node->word);

        // Check to see if there is a header node
        if (hashtable[hash_val] == NULL)
        {
            // Since the header is null (i.e., no collision) we need to create the head
            hashtable[hash_val] = load_node;
        }
        
        
        else
        {
            load_node->next=hashtable[hash_val];
            hashtable[hash_val]=load_node;
             
        }
    
       
 
    }

    //close the file
    fclose(dp);
    //free(load_node);    
    free(curr_word);
  

    return true;
}


/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return word_counter;
}


/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i=0;i<SIZE;i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
	        node* temp = cursor;
	        cursor = cursor->next;
    	    free(temp);
        }
    }
    

    return true;
}