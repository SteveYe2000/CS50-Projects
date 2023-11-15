// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
unsigned int hash_num = 0;
unsigned int extra_words = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_num = hash(word);
    node *ptr = table[hash_num];
    while (ptr != 0) {
        if (strcasecmp(word, ptr -> word) == 0) {
            return true;
        }
        ptr = ptr -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long total_ascii = 0;
    unsigned int result = 0;
    for (int i = 0; i < strlen(word); i++) {
        total_ascii += tolower(word[i]);
    }
    result += total_ascii % N;
    return result;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (file == NULL) {
        printf("Cannot open %s!\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF) {
        node *n = malloc(sizeof(node));
    if (n == NULL) {
        return false;
    }
    strcpy(n -> word, word);
    hash_num = hash(word);
    n -> next = table[hash_num];
    table[hash_num] = n;
    extra_words += 1;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (extra_words > 0) {
        return extra_words;
    }
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++) {
        node *ptr = table[i];
        while (ptr != NULL) {
            node *tempo = ptr;
            ptr = ptr -> next;
            free(tempo);
        }
    }
    return true;
}
