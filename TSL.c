#include "TSL.h"

//global variable to check if no. of root nodes do not exceed 1
bool check_root = FALSE;

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

//Calculating and returning BF
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

//Calculating and returning Max Children
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

//Calculating and returning Max Depth
long long int MaxDepth(ptr Node, long long int prev)
{
    long long int temp_max = prev;

    if (prev < Node->depth)
        temp_max = Node->depth;

    return temp_max;
}

//Calculating and returning Avg Depth
double AvgDepth(ptr Node)
{
    WEIGHTED_D += Node->depth;
    double average = WEIGHTED_D / (double)__COUNT;
    return average;
}

//Printing Analysed variables
void printAnalysis(long long maxnode)
{
	FILE *fptr;
	if ((fptr = fopen("plot.csv","w")) == NULL)
	{
		printf("Error! opening file");
		exit(1);
	}
    printf("===================================================================\n");
    printf("ANALYSIS\n");
    printf("-------------------------------------------------------------------\n");
    printf("Iteration  Max Depth  Avg. Depth  Max Children  Branching Factor\n");
    printf("===================================================================\n");

    for (long long int i = 0; i <= maxnode; i++)
    {
        printf("%9lld   %8lld  %10.2lf    %10lld\t\t%8.2lf\n", i + 1, MAX_DEPTH[i], AVERGAE_D[i], MAX_CHILD[i], BRANCHING_F[i]);
		fprintf(fptr,"%lld,%lld,%lf,%lld,%lf\n", i+1, MAX_DEPTH[i], AVERGAE_D[i],MAX_CHILD[i], BRANCHING_F[i]);
    }
	fclose(fptr);
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
struct node *createNode(struct node *AdjacencyListArray[], long long statenum, long long val, long long parentnum)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));//Allocates memory to node
    if(!(newNode!=NULL))
    {
        printf("ERROR: node_not_allocated_memory: ABORTED\n\n");
        exit(1);
    }

    /// Assignign values to node
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
    newNode->seen_time = 0;
    newNode->number_of_children = 0;
    //Initializing depth to nodes based on depth of parent
    if (parentnum < 0)
    {
        newNode->depth = 0;
    }
    else
    {
        newNode->depth = AdjacencyListArray[parentnum]->depth + 1;
    }
    //returning the node
    return newNode;
}

// Print the graph
void printAdjacencyList(struct node *AdjacencyListArray[], long long maxnode)
{
    long long v;
    for (v = 0; v < maxnode; v++)
    {
        //Creating a temporary node to traverse adjacency list
        struct node *temp = AdjacencyListArray[v];
        //Uncomment while debugging
        printf("\n Vertex %lld\n: ", v);
        while (temp)
        {
            printf("[statenum=%lld,val=%lld,parentnum =%lld,depth=%lld,no.ofchildren=%lld] -> ", temp->state_number, temp->value, temp->parent, temp->depth, temp->number_of_children);
            temp = temp->next;
        }
        printf("\n");
    }
}
//This function pushes the input node values to the adjacency list
void PushInAdjacencyListarray(struct node *AdjacencyListArray[], long long statenum, long long val, long long parentnum)
{   
    if(parentnum < 0 && check_root == TRUE)
    {
        printf("ERROR: more_than_one_root_not_possible: ABORTED\n\n");
        exit(1);
    }

    //Creating a node to pust at the parent index
	if(parentnum>=0&&(AdjacencyListArray[parentnum] == NULL))
	{
		printf("ERROR: parentnum_var_not_present: ABORTED\n\n");
		exit(1);
	}
    struct node *newNode = createNode(AdjacencyListArray, statenum, val, parentnum);
  
    if (parentnum >= 0)
    {   
        newNode->next = AdjacencyListArray[parentnum]->next;
        AdjacencyListArray[parentnum]->next = newNode;
    }
    else
    {
        free(newNode);   //newNode is not needed if node is root
        check_root = TRUE;  
    }
    // Add edge from d to s
    // Creating a node to push at state_number index
    struct node *newThing = createNode(AdjacencyListArray, statenum, val, parentnum);
    if(!(AdjacencyListArray[statenum]==NULL))
    {
        printf("ERROR:invalid_state_number:ABORTED\n\n");
        exit(1);
    }
    newThing->next = AdjacencyListArray[statenum];
    AdjacencyListArray[statenum] = newThing;
    //  
    
    //Updating the number of children as adding a new node changes no. of children
    if (parentnum >= 0)
    {
        //updates the no. of children at the parentnum index
        AdjacencyListArray[parentnum]->number_of_children += 1;
        //Updates the no. of children at the parent value stored at parent of the parentnum index
        if (parentnum > 0)
        {
            struct node *temp = AdjacencyListArray[AdjacencyListArray[parentnum]->parent];
            while (temp->state_number != AdjacencyListArray[parentnum]->state_number)
            {
                temp = temp->next;
            }
            temp->number_of_children += 1;
        }
    }
}

//Deleting the Adjacency list to free memory
void deleteAdjacencyList(struct node *AdjacencyListArray[], long long maxnode)
{
    for (long long i = 0; i < maxnode; i++)
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
	else
		printf("Custom Search\n");
    printf("-------------------------------------------\n");
    printf("State No.\tParent No.\tSeen Time\n");
    printf("===========================================\n");
}

//checks if the given search is valid or not
void checkValidSearch()
{
	bool flag = FALSE;
    for(int i = 0; i < 10; i++)
    {
        flag = (strcmp(search_mode, valid_searches[i]) == 0);
        if(flag == TRUE)
            break;
    }

    if(flag)
        return;
    else
    {
        printf("ERROR: invalid_search_mode: ABORTED\n\n");
        exit(1);
    }
}

//interacts with priority queue and prints the output 
void UnifiedSearch(struct node *AdjacencyListArray[], ptr *heap, long long maxnode)
{
    struct node *T = AdjacencyListArray[0];  //temporary node
    ptr popped_node;
    long long tstamp = 1, i;
    T->seen_time = tstamp;
    tstamp++;
    push(heap, T);  //push root into PQ

    checkValidSearch();
    displayTable();

    for (i = 0; i < maxnode; i++) //maxnode is total number of nodes in tree
    {
        popped_node = pop(heap);  //pop from PQ
        Analyse(popped_node);
        printf("%8lld\t%8lld\t%8lld\n", popped_node->state_number + 1, popped_node->parent + 1, popped_node->seen_time); 
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
