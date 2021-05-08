#include "node.h"
#include "AdjList.h"
char search_mode[10];
int node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
	if(strcmp(search_mode,"bfs")==0)
		return a->seen_time < b->seen_time; // Breadth first search
	else if(strcmp(search_mode,"greedy")==0)
    	return a->value < b->value; // greedy search for least value
	else if(strcmp(search_mode,"dfs")==0)
		return a->seen_time > b->seen_time; //Depth First search
	else if(strcmp(search_mode,"greedymax")==0)
    	return a->value > b->value; // greedy search for greatest value
}
void input_node(struct node *AdjacencyListArray[])
{
    int statenum,parentnum;
    int val;//change this line for different input types
		scanf(" %d %d %d", &statenum, &val, &parentnum);
	
	
	struct node *newNode = malloc(sizeof(struct node));//Allocates memory to node
    /// Assignign values to node
    newNode->state_number = statenum;
    newNode->value = val;
    newNode->parent = parentnum;
    newNode->next = NULL;
     
    
    // You (as a developer) can add any extra information here [Will not be touched by user]
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
		PushInAdjacencyListarray(AdjacencyListArray,newNode);
	free(newNode);
}
