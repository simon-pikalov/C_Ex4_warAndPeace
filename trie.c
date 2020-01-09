//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

#define NUM_LETTERS 26
typedef enum {FALSE=0, TRUE=1} boolean;


typedef struct node {
    char letter; // the char of the node
    long unsigned int count; // how many word there is that end's here
    struct node* children[NUM_LETTERS]; // a arr of pointers to children.
    boolean hasSuns // boolean that indicates ,if the arr of pointer empty or not
} node,*p_node;


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

node *newNode(char letter, long unsigned int count){
    node *nodeP = (node*)malloc(sizeof(node));

    nodeP -> letter = letter;
    nodeP -> count = count;

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


p_node addNode(p_node root, p_node new){
    int index = (int)(new -> letter-'a');
    if(root -> children[index] == NULL){

    }else{
        return NULL;
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
   *pCurrNode=*(newNode(currChar,isEndofWord)); // take the  char and put it to a new node 
   return;
} 

  if(pCurrNode->children[currChar-'a']==NULL) { // if curr node ->  at current chldren node has a place for the current char 

*(pCurrNode->children[currChar-'a'])=*(newNode(currChar,isEndofWord)); // take the  char and put it to a new node 
}

else { // recuer  with the right child 
pCurrNode=pCurrNode->children[currChar-'a'];
addWordToTrie(pCurrNode,currChar, isEndofWord);
return;

}





}







