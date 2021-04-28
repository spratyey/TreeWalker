#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
struct node *createNode(int statenum, int val, int parentnum)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
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
    else
        free(newNode);
    // Add edge from d to s
    struct node *newThing = createNode(statenum, val, parentnum);
    newThing->next = AdjacencyListArray[statenum];
    AdjacencyListArray[statenum] = newThing;
}

void deleteAdjacencyList(struct node *AdjacencyListArray[], int maxnode)
{
    for(int i = 0; i < maxnode; i++)
    {
        struct node *T = AdjacencyListArray[i];
        struct node *temp;
        while(T != NULL)
        {
            temp = T;
            T = T->next;
            free(temp);
        }

    }
}

void pushListToPQ(struct node *AdjacencyListArray[], ptr* heap, int maxnode)
{ 
    struct node *T = AdjacencyListArray[0];
    ptr popped_node;
    int tstamp = 1;
    T->seen_time = tstamp;
    tstamp++;
    push(heap, T);
    //printf("[statenum=%d,val=%d,parentnum =%d]\n", heap[0]->state_number,heap[0]->value,heap[0]->parent);
    int i;
    for(i = 0; i < maxnode; i++) //maxnode is total number of nodes in tree
    {
        popped_node = pop(heap);
        printf("[statenum=%d,val=%d,parentnum =%d]\n", popped_node->state_number + 1,popped_node->value,popped_node->parent + 1);
        T = AdjacencyListArray[(popped_node->state_number)];
        while(T->next != NULL)
        {
            push(heap,T ->next );
            T = T->next;
            T->seen_time = tstamp;
            tstamp++;
        }
    }
}

/*ptr makenode(int statenum, int val, int parentnum)
{
	ptr mynode = (ptr)malloc(sizeof(node));
	mynode->state_number = statenum;
	mynode->value = val;
	mynode->parent = parentnum;
	return mynode;
}*/

int main()
{

	int noofele;
	scanf("%d", &noofele);

	ptr *pq = createPQ(noofele + 10);
	struct node *AdjacencyListArray[noofele];
	int VisitedArray[noofele];
	int maxnode;
	for (int i = 0; i < noofele; i++)
	{
		AdjacencyListArray[i] = NULL;
	}

	for (int i = 0; i < noofele; i++)
	{
		int statenum, val, parentnum;
		scanf(" %d %d %d", &statenum, &val, &parentnum);
		PushInAdjacencyListarray(AdjacencyListArray, statenum-1, val, parentnum-1);
	}
    printAdjacencyList(AdjacencyListArray,noofele);
	pushListToPQ(AdjacencyListArray,pq,noofele);
    deleteAdjacencyList(AdjacencyListArray, noofele);
    deletePQ(pq);
	return 0;
}