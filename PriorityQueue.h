#ifndef PQ_H
#define PQ_H
#include "node.h"
//int SizeofAdjacencyList = 100;

int parent(int index);
void swap(ptr *a, ptr *b);
void siftUp(ptr *heap, int index);
ptr* createPQ(int capacity);
void push(ptr *heap, ptr newnode);
int lef(int index);
int ri(int index);
void siftDown(ptr *heap, int index);
ptr pop(ptr *heap);
ptr peek(ptr *heap);
void deletePQ(ptr* heap);


//SubTeam -2
/*struct Graph {
  int numVertices;
  struct node** adjLists;
};
struct Graph* createAGraph(int vertices);*/

void PushInAdjacencyListarray(struct node *AdjacencyListArray[],int statenum,int val,int parentnum);
struct node* createNode(int statenum,int val, int parentnum);
void printAdjacencyList(struct node *AdjacencyListArray[],int maxnode);



#endif