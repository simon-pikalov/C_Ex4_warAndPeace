//
// Created by sam on 09/01/2020.
//

#include <stdio.h>
#include <string.h>
#include "trie.h"

int main() {

    printf("This is a test");
    char line[30] = "";
    getWord(line);
    printf(line);

    /*
    char *word = "allot";
    struct node *root = newNode(*word,0);
    /*
    char *p = word;
    while(*p){
        printf("%c",*p);
        p++;
    }
    printf("\n");
    printNode(root);
    //printf("Hello, World!\n");
     */
    /*
    struct node *result = indexOf(root,'a');
    if(result == NULL){
        printf("not found");
    }else{
        printf("found");
    }
    freeNode(root);
    */
    return  0;
}