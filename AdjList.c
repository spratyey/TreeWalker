#include "AdjList.h"
#include "Analytics.h"
struct node *createNode(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
    newNode->seen_time = 0;
    if (parentnum < 0)
    {
        newNode->depth = 0;
    }
    else
    {
        newNode->depth = AdjacencyListArray[parentnum]->depth + 1;
    }
    return newNode;
}

// Print the graph
void printAdjacencyList(struct node *AdjacencyListArray[], int maxnode)
{
    int v;
    for (v = 0; v < maxnode; v++)
    {
        struct node *temp = AdjacencyListArray[v];
        //Uncomment while debugging
        printf("\n Vertex %d\n: ", v);
        while (temp)
        {
            printf("[statenum=%d,val=%d,parentnum =%d,depth=%d,no.ofchildren=%d] -> ", temp->state_number, temp->value, temp->parent, temp->depth, temp->number_of_children);
            temp = temp->next;
        }
        printf("\n");
    }
}

void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
{
    struct node *newNode = createNode(AdjacencyListArray, statenum, val, parentnum);

    if (parentnum >= 0)
    {
        AdjacencyListArray[parentnum]->number_of_children += 1;

        if (parentnum > 0)
        {
            struct node *temp = AdjacencyListArray[AdjacencyListArray[parentnum]->parent];
            while (temp->value != AdjacencyListArray[parentnum]->value)
            {
                temp = temp->next;
            }
            temp->number_of_children += 1;
        }
    }

    if (parentnum >= 0)
    {
        assert(AdjacencyListArray[parentnum] != NULL);

        newNode->next = AdjacencyListArray[parentnum]->next;
        AdjacencyListArray[parentnum]->next = newNode;
    }
    else
        free(newNode);
    // Add edge from d to s
    struct node *newThing = createNode(AdjacencyListArray, statenum, val, parentnum);
    newThing->next = AdjacencyListArray[statenum];
    AdjacencyListArray[statenum] = newThing;
}

void deleteAdjacencyList(struct node *AdjacencyListArray[], int maxnode)
{
    for (int i = 0; i < maxnode; i++)
    {
        struct node *T = AdjacencyListArray[i];
        struct node *temp;
        while (T != NULL)
        {
            temp = T;
            T = T->next;
            free(temp);
        }
    }
}

void pushListToPQ(struct node *AdjacencyListArray[], ptr *heap, int maxnode)
{
    struct node *T = AdjacencyListArray[0];
    ptr popped_node;
    int tstamp = 1;
    T->seen_time = tstamp;
    tstamp++;
    push(heap, T);
    //printf("[statenum=%d,val=%d,parentnum =%d]\n", heap[0]->state_number,heap[0]->value,heap[0]->parent);
    int i;
    for (i = 0; i < maxnode; i++) //maxnode is total number of nodes in tree
    {
        popped_node = pop(heap);
        MAX_DEPTH[__COUNT] = MaxDepth(popped_node, MAX_DEPTH[__COUNT-1]);
        AVERGAE_D[__COUNT] = AvgDepth(popped_node);
        BRANCHING_F[__COUNT]=BranchingFactor(popped_node);
        __COUNT++;
        printf("[statenum=%d,val=%d,parentnum =%d,seentime=%d]\n", popped_node->state_number + 1,popped_node->value,popped_node->parent + 1,popped_node->seen_time);
        T = AdjacencyListArray[(popped_node->state_number)];
        while (T->next != NULL)
        {
            T->next->seen_time = tstamp;
            push(heap, T->next);
            T = T->next;
            tstamp++;
        }
    }
}
