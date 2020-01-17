//
// Created by sam on 09/01/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int main() {

    /* 10 January 2010 - Yevgeny - working example of adding the following words to trie*/
    char *word1 = "an";
    char *word2 = "ant";
    char *word3 = "all";
    char *word4 = "allot";
    char *word5 = "alloy";
    char *word6 = "aloe";
    char *word7 = "are";
    char *word8 = "ate";
    char *word9 = "be";
    char *word10 = "allot";
    trie *myTrie = newTrie();
    insertWord(myTrie->root, word1);
    insertWord(myTrie->root, word2);
    insertWord(myTrie->root, word3);
    insertWord(myTrie->root, word4);
    insertWord(myTrie->root, word5);
    insertWord(myTrie->root, word6);
    insertWord(myTrie->root, word7);
    insertWord(myTrie->root, word8);
    insertWord(myTrie->root, word9);
    insertWord(myTrie->root, word10);
    char tempword[0];
    node *pNode = myTrie->root;
    printTree(pNode,tempword);
    printTreeRevers(pNode,tempword);
    return  0;

}
