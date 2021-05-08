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

//Calaculating and returning BF
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

//Calaculating and returning Max Children
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

//Calaculating and returning Max Depth
long long int MaxDepth(ptr Node, long long int prev)
{
    long long int temp_max = prev;

    if (prev < Node->depth)
        temp_max = Node->depth;

    return temp_max;
}

//Calaculating and returning Avg Depth
double AvgDepth(ptr Node)
{
    WEIGHTED_D += Node->depth;
    double average = WEIGHTED_D / (double)__COUNT;
    return average;
}

//Printing Analysed variables
void printAnalysis(int maxnode)
{
    printf("===================================================================\n");
    printf("ANALYSIS\n");
    printf("-------------------------------------------------------------------\n");
    printf("Seen Time  Max Depth  Avg. Depth  Max Children  Branching Factor\n");
    printf("===================================================================\n");

    for (long long int i = 0; i <= maxnode; i++)
    {
        printf("%9lld   %8lld  %10.2lf    %10lld\t\t%8.2lf\n", i + 1, MAX_DEPTH[i], AVERGAE_D[i], MAX_CHILD[i], BRANCHING_F[i]);
    }

    printf("====================================================================\n");
}

//Storing Analysed factors in Global Arrays
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

//Creating a node for Adj List
struct node *createNode(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));//Allocates memory to node
    assert(newNode!=NULL);
    /// Assignign values to node
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
    newNode->seen_time = 0;
    newNode->number_of_children = 0;
    //
    //Initializing depth to nodes based on depth of parent
    if (parentnum < 0)
    {
        newNode->depth = 0;
    }
    else
    {
        newNode->depth = AdjacencyListArray[parentnum]->depth + 1;
    }
    //
    //returning the node
    return newNode;
}

// Print the graph
void printAdjacencyList(struct node *AdjacencyListArray[], int maxnode)
{
    int v;
    for (v = 0; v < maxnode; v++)
    {
        //Creating a temporary node to traverse adjacency list
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
//This function pushes the input node values to the adjacency list
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], int statenum, int val, int parentnum)
{   
    //Creating a node to pust at the parent index
    struct node *newNode = createNode(AdjacencyListArray, statenum, val, parentnum);
  
    if (parentnum >= 0)
    {
        assert(AdjacencyListArray[parentnum] != NULL);

        newNode->next = AdjacencyListArray[parentnum]->next;
        AdjacencyListArray[parentnum]->next = newNode;
    }
    else
        free(newNode);
    // Add edge from d to s
    // Creaing a node to push at state_number index
    struct node *newThing = createNode(AdjacencyListArray, statenum, val, parentnum);
    newThing->next = AdjacencyListArray[statenum];
    AdjacencyListArray[statenum] = newThing;
    //  
    
    //Updating the number of children as adding a new node changes no. of children
    if (parentnum >= 0)
    {
        //updates the no. of children at the parentnum index
        AdjacencyListArray[parentnum]->number_of_children += 1;
        //
        //Updates the no. of children at the parent value stored at parent of the parentnum index
        if (parentnum > 0)
        {
            struct node *temp = AdjacencyListArray[AdjacencyListArray[parentnum]->parent];
            while (temp->value != AdjacencyListArray[parentnum]->value)
            {
                temp = temp->next;
            }
            temp->number_of_children += 1;
        }
        //
    }
}

//Deleting the Adjacency list to free memory
void deleteAdjacencyList(struct node *AdjacencyListArray[], int maxnode)
{
    for (int i = 0; i < maxnode; i++)
    {
        //Creating a temporary variable to traverse adjacency list at i'th index
        struct node *T = AdjacencyListArray[i];
        struct node *temp;
        while (T != NULL)
        {
            temp = T;
            T = T->next;
            free(temp);
        }
        //
    }
    //Now looping at next index
}

//Displays part of the output table
void displayTable()
{
    printf("===========================================\n");

    //printing current search mode
    if(strcmp(search_mode,"bfs")==0)
		printf("Breadth First Search\n");

	else if(strcmp(search_mode,"greedy")==0)
    	printf("Greedy Search (least value first)\n");

	else if(strcmp(search_mode,"dfs")==0)
		printf("Depth First Search\n");

	else if(strcmp(search_mode,"greedymax")==0)
        printf("Greedy Search (greatest value first)\n");

    printf("-------------------------------------------\n");
    printf("State No.\tParent No.\tSeen Time\n");
    printf("===========================================\n");
}

//interacts with priority queue and prints the output 
void pushListToPQ(struct node *AdjacencyListArray[], ptr *heap, int maxnode)
{
    struct node *T = AdjacencyListArray[0];  //temporary node
    ptr popped_node;
    int tstamp = 1, i;
    T->seen_time = tstamp;
    tstamp++;
    push(heap, T);  //push root into PQ

    displayTable();

    for (i = 0; i < maxnode; i++) //maxnode is total number of nodes in tree
    {
        popped_node = pop(heap);  //pop from PQ
        Analyse(popped_node);
        printf("%8d\t%8d\t%8d\n", popped_node->state_number + 1, popped_node->parent + 1, popped_node->seen_time); 
        //output is right justified
        
        T = AdjacencyListArray[(popped_node->state_number)];

        //traversing through T's children and pushing them in PQ
        while (T->next != NULL)
        {
            T->next->seen_time = tstamp;
            push(heap, T->next);
            T = T->next;
            tstamp++;
        }
    }
    printf("===========================================\n");
}
