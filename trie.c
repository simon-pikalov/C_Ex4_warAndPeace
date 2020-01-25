//
// Created by sam on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"
#include <ctype.h>

/**
 * 18 January 2020 - Yevgeny
 * The function reads a single word from standard input.
 * @param word - Pointer to an empty word which will be used to fill with letters from input.
 * @return - Pointer to to the newly created word.
 */
char* getWordDynamically(char *word){
    int c, index = 0;
    word = (char*)malloc(sizeof(char)); // Allocate memory for one letter (char).
    *word = '\0';
    while ((c = getchar()) != EOF && c != '\t' && c != ' ' && c != '\n'){
        word = realloc(word,(index+1)* sizeof(char)); // If we got a 'good' letter then reallocate memory for being able to store it.
        if(!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) { // If letter aren't between bounds ( a-z or A-Z).
            continue; // Continue to the next char.
        } else { // Else we need to insert current char and continue to the next one.
            *(word + index) = (char) tolower(c); // Add the new letter to the array of chars.
            index++; // Go to the next letter index.
        }
    }
    if(c == EOF) { // If end of file.
        free(word); 
        char *result = NULL;
        return result; // return pointer to NULL.
    }
    word = realloc(word,(index+1)* sizeof(char)); // Finally, when we have no more letters, enlarge 'word' by 1 index.
    *(word + index) = '\0'; // Put '\0' at the end of word.
    return word;
}

/**
 * 18 January 2020 - Yevgeny
 * The function read words from standard input, then inserts it to a Trie data structure.
 * @param pTrie - pointer to the Trie.
 */
void buildTrieFromInput(trie *pTrie){
    char *word = ""; // Create empty string
    while ((word = getWordDynamically(word)) != NULL){ // Read words until it's end of file. (getWordDynamically returns pointer to NULL in such case).
        if(*word != '\0') { // If it's not an empty string (getWordDynamically may return an empty string if it reads illegal letters).
            insertWord(pTrie->root, word); // Finally after making sure it's a 'good' word we insert it to our Trie.
            free(word); // Free memory which allocated by word after insertion.
        } else{ // Else if it's and empty string.
            free(word); // Free the memory allocated by empty string.
            continue; // Continue to search for words.
        }
    }
}

/**
 * 23 January 2020 - Yevgeny
 * Helper function to check if given node has children.
 * @param pNode - node to check on.
 * @return TRUE if parent got children.
 */
boolean hasChildren(node *pNode){
    for (int i = 0; i < NUM_LETTERS; i++) {
        if(pNode->children[i] != NULL)
            return TRUE;
    }
    return FALSE;
}

/**
 * 23 January 2020 - Yevgeny
 * The function free all memory allocated by struct true.
 * @param pTrie - Pointer to trie data structure.
 */
void cleanTrie(trie *pTrie){
    node **root = &(pTrie->root); // Define double pointer to the root.
    cleanTrieRecursive(root); // Call to recursive helper function which handles all the cleanup.
    free(pTrie); // Finally free the trie struct itself.
}

/**
 * 23 January 2020 - Yevgeny
 * Recursive helper function of 'cleanTrie' which recur on all nodes of a trie and frees memory.
 * @param parent - Double pointer to first node from which need to start.
 */
void cleanTrieRecursive(node **parent){
    if(!*parent) // If parent is NULL stop recursion and return.
        return;
    for(int i = 0; i < NUM_LETTERS; i++){ // Traverse all children.
        node **child = &((*parent)->children[i]); // Define double pointer to each child.
        cleanTrieRecursive(child); // Recursive call on child.
    }
    if(!hasChildren(*parent)) { // If parent doesn't have children then it can be freed.
        free(*parent);
        *parent = NULL; // assign NULL to parent pointer after freed (for recursion stop condition).
    }
}

char* addChar(char * str , char c ) {
    if(c==0||c<'a'||c>'z') return str;
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
/**
 * 23 January - Yevgeny
 * Print all words from trie data structure by order.
 * @param pTrie - Pointer to trie data structure.
 * @param option - DEFAULT: alphabetic order. REVERSE: reverse alphabetic order.
 */
void printTreeByOrder(trie *pTrie, printOrder option){
    char *wordContainer = (char*)malloc(sizeof(char)*2);
    node *root = pTrie->root;
    if(option == DEFAULT){
        printTree(root,wordContainer);
    } else{
        printTreeReverse(root,wordContainer);
    }
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
    free(tempWord); // 23 January - Yevgeny
}

//simon 17/01
void printTreeReverse(node *nodeP, char* tempWord) {
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
        printTreeReverse(nodeP->children[i], tempWord); // recursive call
    }
    free(tempWord); // 23 January - Yevgeny
}

// 12 January 2020 - Yevgeny
    node *newNode(char letter, long unsigned int count) {
        node *nodeP = (node *) malloc(sizeof(struct node));

        nodeP->letter = letter;
        nodeP->count = count;


        for (int i = 0; i < NUM_LETTERS; i++) {
            nodeP->children[i] = NULL;
        }

        return nodeP;
}

// 12 January 2020 - Yevgeny
    trie *newTrie(){
    trie *trieP = (trie*)malloc(sizeof(struct trie));
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
        } else // Case 2: if index is not available that means we need to proceed to next char without changing current letter.
        {
            if (*(c + 1) == '\0') // Check if next index is end of word. in that case we need to increment count by 1.
                root->children[index]->count++;
            c++; // Proceed to next char.
            insertWord(root->children[index], c); // Recursively add the next char.
        }

    }
