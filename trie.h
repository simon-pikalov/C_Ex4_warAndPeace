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
    boolean hasChildren // boolean that indicates ,if the arr of pointer empty or not
} node,*p_node;

int getWord(char w[]);
struct node *newNode(char letter,boolean hasChildren, long unsigned int count);
void freeNode(struct node *nodeP);
void printNode(struct node *nodeP);
void addNode(p_node root, char *c);
struct node *indexOf(struct node *root, char c);


#endif //C_EX3_WARANDPEACE_TRIE_H
