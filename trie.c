//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

typedef struct trie {
struct node root;
} trie,*p_trie;


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

void printNode(p_node nodeP){
    printf("%c\t",nodeP -> letter);
    printf("%lu",nodeP -> count);
}

void freeNode(node *nodeP){
    free(nodeP);
}

// 10 January 2020 - Yevgeny - added boolean hasChildren
node *newNode(char letter,boolean hasChildren, long unsigned int count){
    node *nodeP = (node*)malloc(sizeof(node));

    nodeP -> letter = letter;
    nodeP -> count = count;
    nodeP -> hasChildren = hasChildren;

    for(int i = 0; i < NUM_LETTERS; i++){
        nodeP -> children[i] = NULL;
    }

    return nodeP;
}

node *indexOf(node *root, char c){
    if(root -> letter == c){
        return root;
    }
    for(int i = 0; i < NUM_LETTERS; i++){
        if(root -> children[i] != NULL){
            indexOf(root -> children[i],c);
        }
    }
    return NULL;
}

node *insert(node *index, node *new){
    index = new;
    return index;
}


//node *traverse(node *root){
//    node *p = root;
//    printf("%c", root -> letter);
//    for(int i = 0; i < NUM_LETTERS; i++){
//        if(p -> children[i] != NULL){
//            traverse(p);
//        }
//        p++;
//    }
//    return p;
//}

/**
 * 10 January 2020 - Yevgeny
 * insert word to a trie
 * @param root the root of trie or any other starting point
 * @param c pointer to array of chars
 */
void addNode(p_node root, char *c){
    if(*c == '\0')
        return;
    int index = *c-'a';
    if(!root){
        root = newNode(*c,FALSE,0);
    }
    if(root -> children[index] == NULL){
        root -> children[index] = newNode(*c,FALSE,0);
        c++;
        addNode(root -> children[index],c);
    }else{
        c++;
        addNode(root -> children[index],c);
    }
}

//node *newNode(char letter, long unsigned int count){


void addWordToTrie (p_node pCurrNode,char currChar,boolean isEndofWord) { //currChar must be between 0-25 ! 

if( currChar>'z') { // if the input is not valid 
    printf("Bad input at curr char '%c' ",currChar);
    return;
}


   if(!pCurrNode) // if the root is null 
{
   *pCurrNode=*(newNode(currChar,isEndofWord,0)); // take the  char and put it to a new node
   return;
} 

  if(pCurrNode->children[currChar-'a']==NULL) { // if curr node ->  at current chldren node has a place for the current char 

      // 10 January 2020 - Yevgeny - Maybe need to chnage *(newNode(currChar,isEndofWord,0)) to newNode(currChar,isEndofWord)
*(pCurrNode->children[currChar-'a'])=*(newNode(currChar,isEndofWord,0)); // take the  char and put it to a new node
}

else { // recuer  with the right child 
pCurrNode=pCurrNode->children[currChar-'a'];
addWordToTrie(pCurrNode,currChar, isEndofWord);
return;

}





}







