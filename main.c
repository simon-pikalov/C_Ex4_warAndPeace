//
// Created by sam on 09/01/2020.
//

#include <stdio.h>
#include <string.h>
#include "trie.h"

int main() {



    /* 10 January 2010 - Yevgeny - working example of adding the word 'allot' to trie*/
    char *word = "allot";
    node *root = newNode(*word,0);
    addWordToTrie(root,word,0);
    

    return  0;

}