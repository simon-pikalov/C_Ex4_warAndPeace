//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

typedef struct trie
{
    struct node root;
} trie, *p_trie;

/**
 * get char and convert it to lower case
 * @param The buff arr to store the word
   @return the number of word's was declared
 */
int getWord(char w[])
{
    int c, j = 0;
    while ((c = getchar()) != EOF && c != '\t' && c != ' ' && c != '\n' && c != '\r')
    {
        c = tolower(c);
        w[j] = c;
        j++;
    }

    w[j] = '\0';
    return j;
}

void printNode(p_node nodeP)
{
    printf("%c\t", nodeP->letter);
    printf("%lu", nodeP->count);
}

void freeNode(node *nodeP)
{
    free(nodeP);
}



void printTree(p_node nodeP)
{
    if(nodeP==NULL) {
    printf("|\n_");
    return;
    }


    

    else {
        printf("(%c)\t",nodeP->letter);
        for (size_t i = 0; i < 26; i++)
        {
            printTree(nodeP);
        }
        
    }

}


void nodeInit(p_node nodeP,char let ,size_t count) {

    for (int i = 0; i < NUM_LETTERS; i++)
    {
        nodeP->children[i] = NULL;
    }
  nodeP->letter = let;
    nodeP->count = count;


}



// 10 January 2020 - Yevgeny - added boolean hasChildren
node *newNode(char letter, long unsigned int count)
{
    node *nodeP = (node *)malloc(sizeof(node));

    nodeP->letter = letter;
    nodeP->count = count;


    for (int i = 0; i < NUM_LETTERS; i++)
    {
        nodeP->children[i] = NULL;
    }

    return nodeP;
}

node *indexOf(node *root, char c)
{
    if (root->letter == c)
    {
        return root;
    }
    for (int i = 0; i < NUM_LETTERS; i++)
    {
        if (root->children[i] != NULL)
        {
            indexOf(root->children[i], c);
        }
    }
    return NULL;
}

node *insert(node *index, node *new)
{
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
void addNode(p_node root, char *c)
{
    if (*c == '\0')
        return;
    int index = *c - 'a';
    if (!root)
    {
        root = newNode(*c,0);
    }
    if (root->children[index] == NULL)
    {
        root->children[index] = newNode(*c,0);
        c++;
        addNode(root->children[index], c);
    }
    else
    {
        c++;
        addNode(root->children[index], c);
    }
}

//node *newNode(char letter, boolean hasChildren, long unsigned int count)

/**
 * 10 January 2020 - Simon
 * insert char to a trie
 * @param pCurrNode node of the Trie
 * @param currChar The char to be inserted
 * @param isEndofWord is it and of word.
 */
 /* 11 January 2020 - Yevgeny -*pCurrNode as a parameter causes children not to be NULL.
  * and as a result the function crash at line 202
  * Maybe we are not using pointer to pointer as expected */
void addWordToTrie(p_node *pCurrNode, char *word, int currWordIndex)
{ //currChar must be between 0-25 !


    if ((word[currWordIndex] > 'z' && *word < 'a')||word[currWordIndex] == '\0')
    { // if the input is not valid
        printf("Bad input at curr char '%c' ", *word);
        return;
    }
    int treeIndex = word[currWordIndex] - 'a';
    boolean isEndofWord;

    if(word[currWordIndex+1]=='\0') { // if it's the last char of the word
    isEndofWord=TRUE;
    }

    else // if it's not the last char of the word
    {
        isEndofWord=FALSE;
    }
    
    /* 11 January 2020 - Yevgeny - function newNode expects for char but receives char* */
    if (!pCurrNode) // if the root is null
    {
        *pCurrNode = (newNode(word, isEndofWord)); // take the  char and put it to a new node
        return;
    }

    /* 11 January 2020 - Yevgeny - Here the function crash */
    if ((*pCurrNode)->children[treeIndex] == NULL)
    { // if curr node ->  at current chldren node has a place for the current char

        /* 11 January 2020 - Yevgeny - function newNode expects for char but receives char* */
        ((*pCurrNode)->children[treeIndex]) = (newNode(word, isEndofWord)); // take the  char and put it to a new node
        return;
    }

    else if (isEndofWord)
    { // if there is already a node at this place
        (*pCurrNode)->children[treeIndex]->count++;
        return;
    }

    else
    { // recuer  with the next child
       currWordIndex++;
       *pCurrNode=(*pCurrNode)->children[treeIndex];
       addWordToTrie(pCurrNode, word,currWordIndex);
    }
}
