#ifndef PQ_H
#define PQ_H
#include "node.h"
int parent(int index);
void swap(ptr *a, ptr *b);
void siftUp(ptr *heap, int index);
ptr* createPQ(int capacity);
void push(ptr *heap, ptr newnode);
#endif