#include <stdio.h>
#include <stdbool.h>
#include "PriorityQueue.h"

// Create a node
struct node *createNode(int statenum, int val, int parentnum)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    //newNode->next = NULL;
    newNode->seen_time=0;
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
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
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

void pushListToPQ(struct node *AdjacencyListArray[], ptr* heap, int maxnode)
{ 
    struct node *T = AdjacencyListArray[0];
    ptr popped_node;
    int tstamp = 1;
    push(heap, T);
    T->seen_time = tstamp;
    tstamp++;
    int i;
    for(i = 0; i < maxnode; i++) //maxnode is total number of nodes in tree
    {
        popped_node = pop(heap);
        printf("[statenum=%d,val=%d,parentnum =%d]\n", popped_node->state_number,popped_node->value,popped_node->parent);
        T = AdjacencyListArray[(popped_node->state_number - 1)];
        while(T->next != NULL)
        {
            push(heap,T ->next );
            T = T->next;
            T->seen_time = tstamp;
            tstamp++;
        }
    }
}