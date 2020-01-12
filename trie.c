//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

/**
 * Get word in lower case from standard input.
 * @param w - pointer for storing a word.
   @return the number of chars we've got.
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

void freeNode(node *nodeP)
{
    free(nodeP);
}

void printTree(node *nodeP)
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

// 12 January 2020 - Yevgeny
node *newNode(char letter, long unsigned int count)
{
    node *nodeP = (node*)malloc(sizeof(node));

    nodeP->letter = letter;
    nodeP->count = count;


    for (int i = 0; i < NUM_LETTERS; i++)
    {
        nodeP->children[i] = NULL;
    }

    return nodeP;
}

// 12 January 2020 - Yevgeny
trie *newTrie(){
    trie *trieP = (trie*)malloc(sizeof(trie));
    node *nodeP = newNode('*',0);
    trieP -> root = nodeP;
    return trieP;
}

/**
 * 12 January 2020 - Yevgeny
 * The function inserts a given word in to a trie data structure.
 * @param root the root of trie or any other starting point
 * @param c pointer to array of chars
 */
void insertWord(node *root, char *c)
{
    if (*c == '\0') // If it's end of word we stop the recursion.
        return;
    int index = *c - 'a';
    if (!root) // If current Node is Null then it's available fo adding new Node.
    {
        root = newNode(*c,0);
    }
    if (root->children[index] == NULL) // Case 1: if index is free then we add the new Node here.
    {
        root->children[index] = newNode(*c,0);
        if(*(c+1) == '\0') // Check if next index is end of word. in that case we need to increment count by 1.
            root->children[index]->count++;
        c++; // Proceed to next char
        insertWord(root->children[index], c); // Recursively add the next char.
    }
    else // Case 2: if index is not available that means we need to proceed to next char and do nothing.
    {
         if(*(c+1) == '\0') // Check if next index is end of word. in that case we need to increment count by 1.
             root->children[index]->count++;
        c++; // Proceed to next char.
        insertWord(root->children[index], c); // Recursively add the next char.
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
 /*
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
    if (!pCurrNode) // if the root is null
    {
        *pCurrNode = (newNode(word, isEndofWord)); // take the  char and put it to a new node
        return;
    }

    if ((*pCurrNode)->children[treeIndex] == NULL)
    { // if curr node ->  at current chldren node has a place for the current char

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
*/