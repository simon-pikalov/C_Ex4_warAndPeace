//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

void freeNode(node *nodeP)
{
    free(nodeP);
}

char* getWordDynamically(char *word){
    int c, index = 0;
    word = (char*)malloc(sizeof(char));
    *word = '\0';
    while ((c = getchar()) != EOF && c != '\t' && c != ' ' && c != '\n'){
        word = realloc(word,(index+1)* sizeof(char));
        *(word + index) = (char)tolower(c);
        index++;
    }
    word = realloc(word,(index+1)* sizeof(char));
    *(word + index) = '\0';
    return word;
}

void buildTrieFromInput(trie *pTrie){
    char *word;
    while ((word = getWordDynamically(word))){
        insertWord(pTrie->root,word);
        free(word);
    }
}

char* addChar(char * str , char c ) {
    if(c==0||c<'a'||c>'z') return "";
    size_t len = strlen(str);
    char *str2 = malloc(len + 1 + 1 ); /* one for extra char, one for trailing zero */
    strcpy(str2, str);
    str2[len] = c;
    str2[len + 1] = '\0';
    return str2;
}

void printWord(char* word, long unsigned int  value) {

    if(*word=='\0') return;
    printf("%s %lu\n",word,value);
}

//simon 17/01
void printTree(node *nodeP,char* tempWord) {
    if (nodeP == NULL) {
        return;
    }
        tempWord=  addChar(tempWord ,(nodeP->letter));

    //printf("debud %s\n",tempWord);

    if (tempWord[0]!=0 && nodeP->count != 0) {
       printWord(tempWord, nodeP->count);
    }


    for (int i = 0; i < numberOFLetters; i++) {
        if(nodeP->children[i]==NULL||(nodeP->letter)==0 ) continue;
        printTree(nodeP->children[i], tempWord); // recursive call
    }

}

//simon 17/01
void printTreeRevers(node *nodeP,char* tempWord) {
    if (nodeP == NULL) {
        return;
    }
    tempWord=  addChar(tempWord ,(nodeP->letter));

    //printf("debud %s\n",tempWord);

    if (tempWord[0]!=0 && nodeP->count != 0) {
        printWord(tempWord, nodeP->count);
    }


    for (int i = numberOFLetters-1; i >= 0; i--) {
        if(nodeP->children[i]==NULL||(nodeP->letter)==0 ) continue;
        printTreeRevers(nodeP->children[i], tempWord); // recursive call
    }
}


// 12 January 2020 - Yevgeny
    node *newNode(char letter, long unsigned int count) {
        node *nodeP = (node *) malloc(sizeof(node));

        nodeP->letter = letter;
        nodeP->count = count;


        for (int i = 0; i < NUM_LETTERS; i++) {
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
    void insertWord(node *root, char *c) {
        if (*c == '\0') // If it's end of word we stop the recursion.
            return;
        int index = *c - 'a';
        if (!root) // If current Node is Null then it's available fo adding new Node.
        {
            root = newNode(*c, 0);
        }
        if (root->children[index] == NULL) // Case 1: if index is free then we add the new Node here.
        {
            root->children[index] = newNode(*c, 0);
            if (*(c + 1) == '\0') // Check if next index is end of word. in that case we need to increment count by 1.
                root->children[index]->count++;
            c++; // Proceed to next char
            insertWord(root->children[index], c); // Recursively add the next char.
        } else // Case 2: if index is not available that means we need to proceed to next char and do nothing.
        {
            if (*(c + 1) == '\0') // Check if next index is end of word. in that case we need to increment count by 1.
                root->children[index]->count++;
            c++; // Proceed to next char.
            insertWord(root->children[index], c); // Recursively add the next char.
        }

    }
