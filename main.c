//
// Created by sam on 09/01/2020.
//

#include <stdio.h>
#include <string.h>
#include "trie.h"

int main() {

    /*
    printf("This is a test");
    char line[30] = "";
    getWord(line);
    printf(line);
    */

    /* 10 January 2010 - Yevgeny - working example of adding the word 'allot' to trie*/
    char *word = "allot";
    node *root = newNode(*word,FALSE,0);
    word++;
    addNode(root,word);
    return  0;
}