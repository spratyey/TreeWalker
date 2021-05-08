#include "AdjList.h"
/*Global variables required for analysis*/
long long int __COUNT = 1;
long long int __COUNT_BF = 1;
double BRANCHING_F[(long int)1e6];
double AVERGAE_D[(long int)1e6];
long long int MAX_DEPTH[(long int)1e6];
long long int MAX_CHILD[(long int)1e6];
long long int CHILD_VISIT[(long int)1e6]={0};
long long int BF_SUM = 0;
long long int WEIGHTED_D = 0;
/****************************************/

double BranchingFactor(ptr Node, double prev)
{
    double average;
    if (Node->number_of_children > 0)
    {
        BF_SUM += Node->number_of_children;
        average = BF_SUM / (double)__COUNT_BF++;
        return average;
    }
    else
    {
        return prev;
    }
}
long long int MaxChildren(ptr Node, long long int prev)
{
    long long int temp_max = prev;
    long long int tmpPar=Node->parent;

    if(tmpPar>=0)
    {
        CHILD_VISIT[tmpPar]++;
        if (prev < CHILD_VISIT[tmpPar])
            temp_max = CHILD_VISIT[tmpPar];
    }

    return temp_max;
}

long long int MaxDepth(ptr Node, long long int prev)
{
    long long int temp_max = prev;

    if (prev < Node->depth)
        temp_max = Node->depth;

    return temp_max;
}

double AvgDepth(ptr Node)
{
    WEIGHTED_D += Node->depth;
    double average = WEIGHTED_D / (double)__COUNT;
    return average;
}

void printAnalysis(int maxnode)
{
    for (long long int i = 0; i <= maxnode; i++)
        printf("%lld, %lld, %lld, %lf, %lf\n", i + 1, MAX_DEPTH[i], MAX_CHILD[i], AVERGAE_D[i], BRANCHING_F[i]);
}

void Analyse(ptr popped_node)
{
    MAX_CHILD[0] = 0;
    MAX_DEPTH[0] = 0;
    MAX_DEPTH[__COUNT] = MaxDepth(popped_node, MAX_DEPTH[__COUNT - 1]);
    AVERGAE_D[__COUNT] = AvgDepth(popped_node);
    BRANCHING_F[__COUNT] = BranchingFactor(popped_node, BRANCHING_F[__COUNT - 1]);
    MAX_CHILD[__COUNT] = MaxChildren(popped_node, MAX_CHILD[__COUNT - 1]);
    __COUNT++;
}

struct node *createNode(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
    newNode->seen_time = 0;
    newNode->number_of_children = 0;
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
        Analyse(popped_node);
        printf("[statenum=%d,val=%d,parentnum =%d,seentime=%d]\n", popped_node->state_number + 1, popped_node->value, popped_node->parent + 1, popped_node->seen_time);
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
