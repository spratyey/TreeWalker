#ifndef ADJLIST_H
#define ADJLIST_H
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
long long int MaxDepth(ptr node, long long int prev);
long long int MaxChildren(ptr node,long long int prev);
double AvgDepth(ptr node);
void printAnalysis(int maxnode);
double BranchingFactor(ptr Node,double Prev);

struct node *createNode(struct node *AdjacencyListArray[],int statenum, int val, int parentnum);
void printAdjacencyList(struct node *AdjacencyListArray[], int maxnode);
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum);
void deleteAdjacencyList(struct node *AdjacencyListArray[], int maxnode);
void displayTable();
void pushListToPQ(struct node *AdjacencyListArray[], ptr *heap, int maxnode);
#endif
