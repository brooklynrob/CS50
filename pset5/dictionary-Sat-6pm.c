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


// This is what to optimize in this PSET! (Or do tries!)
int hash_function(char* key)
{
    int hash = toupper(key[0] - 'A');
    return hash % SIZE;
}

node* hashtable[50];

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // for each letter in input word
        //go to corresponding element in children
        //if NULL, word is misspelled
        //if not NULL, move to next letter
        //once at end of input word
        //chec if is_word is true
    int search_word_len = strlen(word);
    char search_word[LENGTH+1];
    for (int i=0; i < search_word_len; i++)
    {
        search_word[i] = word[i];
    }
    search_word[search_word_len] = '\0';
    
    
    
    
    //strcpy(word,search_word);
    printf("New check for the word %s\n", search_word);  
    int hash_val;

    hash_val = hash_function(search_word);
    printf("hash_val - %i\n", hash_val);  
    node* search_node = malloc(sizeof(node));
    search_node=hashtable[hash_val];
    printf("The head word is %s and the \n", search_node->word);
    printf("The word after the head word is %s.\n",search_node->next->word);
    
    int spelled_ok = 0;
    
 
    do
    {
        printf("Compare the word %s with %s.\n", search_word, search_node->word);
        if (strcmp(search_word, search_node->word) == 0)
        {
            printf("Not misspelled\n");
            spelled_ok = 1;
            break;
        }
        
        search_node = search_node->next;
    }
    
    while (search_node->next != NULL);
 
    
    if (spelled_ok == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    
    for (int i=0;i<50;i++)
    {
        hashtable[i] = malloc(sizeof(node));
        hashtable[i]->word[0] = '\0';
        hashtable[i]->next = NULL;
    }
    
   
    
    char *curr_word = (char*) malloc(LENGTH);
    node* cursor_node = malloc(sizeof(node));
    
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
        printf("The word %s is in the load node with address %p and will be put in the chain at hashtable index %i\n",load_node->word, load_node, hash_val);
        
        printf("The word at head of hashtable[%i] is %s\n", hash_val, hashtable[hash_val]->word);

        //Set the cursor node to start of linked list
        
        
     
        
        
        

       
        if (hashtable[hash_val]->word == '\0')
        {
            printf("hashtable[%i]->next is null!\n", hash_val);
            strcpy(hashtable[hash_val]->word,load_node->word);
            
            printf("The word at hed of hashtable[%i] is %s\n", hash_val, hashtable[hash_val]->word);
        }
        
        else
        {
            cursor_node = hashtable[hash_val];
            printf("cursor_node->word is equal to %s\n",cursor_node->word);
            printf("The word at hed of hashtable[%i] is %s\n", hash_val, hashtable[hash_val]->word);
     
            while (cursor_node->next != NULL)
            {
                cursor_node = cursor_node->next;
                printf("    cursor_node->next is equal to %p and the NEXT word there %s\n",cursor_node->next, cursor_node->word);
            }
                printf("cursor_node->next is equal to %p so let's add the new word to the end of the chain\n",cursor_node->next);
                printf("Let's add %s to a new entry, hashtable[%i], at location %p\n",curr_word,hash_val,cursor_node);
            cursor_node->next = load_node;
        }
        printf("\n\n");

        
    }
    
        printf("hashtable[2]->word is %s\n",hashtable[2]->word);
        printf("hashtable[2]->next->word is %s\n",hashtable[2]->next->word);
        printf("hashtable[2]->next->word->word is %s\n",hashtable[2]->next->next->word);
        
        printf("hashtable[2]->word is %s\n",hashtable[2]->word);
        printf("hashtable[2]->next->word is %s\n",hashtable[2]->next->word);
        printf("hashtable[2]->next->word->word is %s\n",hashtable[2]->next->next->word);
        

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
    // TODO
    /* 
    node* cursor = head;

  
    while (cursor != NULL)
    {
	    node* temp = cursor;
	    cursor = cursor->next;
    	free(temp)	
    }
    
    */
    
    
    return false;
}
