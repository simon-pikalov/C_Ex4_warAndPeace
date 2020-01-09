//
// Created by sam on 09/01/2020.
//

#ifndef C_EX3_WARANDPEACE_TRIE_H
#define C_EX3_WARANDPEACE_TRIE_H

int getWord(char w[]);
struct node *newNode(char letter, long unsigned int count);
void freeNode(struct node *nodeP);
void printNode(struct node *nodeP);
struct node *indexOf(struct node *root, char c);


#endif //C_EX3_WARANDPEACE_TRIE_H
