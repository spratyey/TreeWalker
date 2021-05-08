#ifndef ADJLIST_H
#define ADJLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PriorityQueue.h"

#define TRUE 1
#define FALSE 0

double BranchingFactor(ptr Node,double Prev);
long long int MaxChildren(ptr node,long long int prev);
long long int MaxDepth(ptr node, long long int prev);
double AvgDepth(ptr node);
void printAnalysis(long long int maxnode);
void Analyse(ptr popped_node);

struct node *createNode(struct node *AdjacencyListArray[],long long statenum, long long val, long long parentnum);
void printAdjacencyList(struct node *AdjacencyListArray[], long long maxnode);
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], long long statenum, long long val, long long parentnum);
void deleteAdjacencyList(struct node *AdjacencyListArray[], long long maxnode);
void checkValidSearch();
void displayTable();
void pushListToPQ(struct node *AdjacencyListArray[], ptr *heap, long long maxnode);
#endif
