#ifndef ADJLIST_H
#define ADJLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
struct node *createNode(int statenum, int val, int parentnum);
int MaxDepth(ptr node, int prev);
double AvgDepth(ptr node);
void printAnalysis(int maxnode);
void printAdjacencyList(struct node *AdjacencyListArray[], int maxnode);
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum);
void deleteAdjacencyList(struct node *AdjacencyListArray[], int maxnode);
void pushListToPQ(struct node *AdjacencyListArray[], ptr *heap, int maxnode);
#endif