#include <stdio.h>
#include "PriorityQueue.h"

// Create a node
struct node *createNode(int statenum, int val, int parentnum)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
    return newNode;
}

// Print the graph
void printAdjacencyList(struct node *AdjacencyListArray[],int maxnode)
{
    int v;
    for (v = 0; v < maxnode;v++)
    {
        struct node *temp = AdjacencyListArray[v];
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf("[statenum=%d,val=%d,parentnum =%d] -> ", temp->state_number,temp->value,temp->parent);
            temp = temp->next;
        }
        printf("\n");
    }
}
void PushInAdjacencyListarrray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
{
    struct node *newNode = createNode(statenum, val, parentnum);
    if (parentnum >= 0)
    {
        assert(AdjacencyListArray[parentnum] != NULL);

        newNode->next = AdjacencyListArray[parentnum]->next;
        AdjacencyListArray[parentnum]->next = newNode;
    }
    // Add edge from d to s
    newNode = createNode(statenum, val, parentnum);
    newNode->next = AdjacencyListArray[statenum];
    AdjacencyListArray[statenum] = newNode;
}
