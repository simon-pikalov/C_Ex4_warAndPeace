//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include "trie.h"

int main(int argc, char **argv) {

    trie *myTrie = newTrie();
    buildTrieFromInput(myTrie);

    if(argc == 1) {
        printTreeByOrder(myTrie,DEFAULT);
        cleanTrie(myTrie);
    }else if(argc == 2){
        char option = **(argv+1);
        if(option == 'r') {
            printTreeByOrder(myTrie,REVERSE);
            cleanTrie(myTrie);
        }else{
            printf("Illegal argument %c\n",option);
        }
    } else {
        printf("Too many arguments\n");
    }

    return  0;

}
