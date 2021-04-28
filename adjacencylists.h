#ifndef Alnode_H
#define Alnode_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "PriorityQueue.h"

struct node *createNode(int statenum, int val, int parentnum);
void printAdjacencyList(struct node *AdjacencyListArray[],int maxnode);
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum);
void pushListToPQ(struct node *AdjacencyListArray[], ptr* heap, int maxnode);


#endif
