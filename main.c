//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include "trie.h"

int main(int argc, char **argv) {

    trie *myTrie = newTrie();
    buildTrieFromInput(myTrie);

    node *pNode = myTrie->root;
    char tempword[0];

    if(argc == 1) {
        printTree(pNode, tempword);
    }else if(argc == 2){
        char option = **(argv+1);
        if(option == 'r') {
            printTreeReverse(pNode, tempword);
        }else{
            printf("Illegal argument %c\n",option);
        }
    } else {
        printf("Too many arguments\n");
    }

    return  0;
}
