//
// Created by sam on 09/01/2020.
//

#ifndef C_EX3_WARANDPEACE_TRIE_H
#define C_EX3_WARANDPEACE_TRIE_H

typedef enum {FALSE=0, TRUE=1} boolean;
#define NUM_LETTERS 26

typedef struct node {
    char letter; // the char of the node
    long unsigned int count; // how many word there is that end's here
    struct node* children[NUM_LETTERS]; // a arr of pointers to children.
} node;

typedef struct trie
{
    struct node *root;
} trie;
static const int numberOFLetters = 26;
char* addChar(char * str , char c );
struct node *newNode(char letter, long unsigned int count);
trie *newTrie();
void insertWord(node *root, char *c);
void printWord(char* word, long unsigned int  value);
void printTree(node *nodeP,char* tempWord);
void printTreeReverse(node *root);
void printTreeRevers(node *nodeP,char* tempWord);
void buildTrieFromInput(trie *pTrie);
#endif //C_EX3_WARANDPEACE_TRIE_H
