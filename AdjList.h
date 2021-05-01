#ifndef ADJLIST_H
#define ADJLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
int MaxDepth(ptr node, int prev);
double AvgDepth(ptr node);
void printAnalysis(int maxnode);
double BranchingFactor(ptr Node);

struct node *createNode(struct node *AdjacencyListArray[],int statenum, int val, int parentnum);
void printAdjacencyList(struct node *AdjacencyListArray[], int maxnode);
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum);
void deleteAdjacencyList(struct node *AdjacencyListArray[], int maxnode);
void pushListToPQ(struct node *AdjacencyListArray[], ptr *heap, int maxnode);
#endif
