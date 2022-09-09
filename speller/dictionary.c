// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int dict_size = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Hash word to obtain hash value
    int hash_value = hash(word);

    // Access linked list at that index in hash table
    node *n = table[hash_value];

    // Traverse linked list, looking for word (strcasecomp)
    while (n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int hash = 0;

    for (int i = 0; i < strlen(word); i++)
    {
        hash += tolower(word[i]);
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary file
    FILE *ptr = fopen(dictionary, "r");
    if (ptr == NULL)
    {
            printf("Could not open file.\n");
            return false;
    }

    // Initialize word array
    char next_word[LENGTH + 1];

    //read strings from file one at a time
    while (fscanf(ptr, "%s", next_word) == 1)
    {
        // create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }

        //copy word into node using strcopy
        strcpy(n->word, next_word);

        //hash word to obtain hash value
        int hash_value = hash(next_word);

        // Insert node into hash table at that location
        n->next = table[hash_value];
        table[hash_value] = n;
        dict_size++;

    }

    // close file
    fclose(ptr);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate over hash table and free nodes in each linked list
    for (int i = 0; i < N; i++)
    {
        // Assign cursor
        node *n = table[i];

        // Loop through linked list
        while (n != NULL)
        {
            // Make temp equal cursor
            node *tmp = n;
            //point cursor to next element
            n = n->next;
            // free temp
            free(tmp);
        }

        if (n == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}
