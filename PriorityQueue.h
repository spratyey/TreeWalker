#ifndef PQ_H
#define PQ_H
#include "node.h"
//auxillary functions
int parent(int index);
void swap(ptr *a, ptr *b);
void siftUp(ptr *heap, int index);
int lef(int index);
int ri(int index);
void siftDown(ptr *heap, int index);

//interface provided to user
ptr* createPQ(int capacity);//create a blank priority queue with given capacity
void push(ptr *heap, ptr newnode);//Adds element to PQ
ptr pop(ptr *heap);//pops the element with the highest priority
ptr peek(ptr *heap);//Returns highest priority element
void deletePQ(ptr* heap); //frees malloc'd memory for heap.
int isEmpty(); //To check if PQ is empty

#endif