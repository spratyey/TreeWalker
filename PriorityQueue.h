#ifndef PQ_H
#define PQ_H
#include "node.h"
int parent(int index);
void swap(ptr *a, ptr *b);
void siftUp(ptr *heap, int index);
ptr* createPQ(int capacity);
void push(ptr *heap, ptr newnode);
int lef(int index);
int ri(int index);
void siftDown(ptr *heap, int size, int index);
ptr pop(ptr *heap);
ptr peek(ptr *heap);
#endif