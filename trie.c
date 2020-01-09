//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

#define NUM_LETTERS ((int)26)
typedef enum {FALSE=0, TRUE=1} boolean;


typedef struct node {
    char letter; // the char of the node
    long unsigned int count; // how many word there is that end's here
    struct node* children[NUM_LETTERS]; // a arr of pointers to children.
    boolean hasSuns // boolean that indicates ,if the arr of pointer empty or not
} node,*p_node;


/**
 * get char and convert it to lower case
 * @param The buff arr to store the word
   @return the number of word's was declared
 */
int getWord(char w[]) {
    int c, j = 0;
    while ((c = getchar()) != EOF && c != '\t' && c != ' ' && c != '\n' && c != '\r') {
        c= tolower( c);
        w[j] = c;
        j++;
    }

    w[j] = '\0';
    return j;


}




