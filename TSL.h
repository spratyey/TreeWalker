#ifndef TSL_H
#define TSL_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "PriorityQueue.h"

#define TRUE 1
#define FALSE 0

double BranchingFactor(ptr Node,double Prev); //Calculating and returning BF
long long int MaxChildren(ptr node,long long int prev); //Calculating and returning Max Children
long long int MaxDepth(ptr node, long long int prev); //Calculating and returning Max Depth
double AvgDepth(ptr node); //Calculating and returning Avg Depth
void printAnalysis(long long int maxnode); //Printing Analysed variables
void Analyse(ptr popped_node); //Storing Analysed factors in Global Arrays

struct node *createNode(struct node *AdjacencyListArray[],long long statenum, long long val, long long parentnum); //Creating a node for Adj List
void printAdjacencyList(struct node *AdjacencyListArray[], long long maxnode); // Print the graph
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], long long statenum, long long val, long long parentnum); //This function pushes the input node values to the adjacency list
void checkValidSearch(); //checks if the given search is valid or not
void displayTable(); //Displays part of the output table

void UnifiedSearch(struct node *AdjacencyListArray[], ptr *heap, long long maxnode); //interacts with priority queue and prints the output
void deleteAdjacencyList(struct node *AdjacencyListArray[], long long maxnode); //Deleting the Adjacency list to free memory
#endif
