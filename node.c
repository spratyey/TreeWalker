#include "node.h"
#include "TSL.h"
char search_mode[10];
char valid_searches[10][10] = {"bfs", "dfs", "greedy", "greedymax"};  //array of valid search methods

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

void input_node(struct node *AdjacencyListArray[], long long nooele)
{
    long long statenum,parentnum;
    long long val; //change this line for different input types

	scanf(" %lld %lld %lld", &statenum, &val, &parentnum);
	if(statenum > nooele || statenum <= 0)
	{
		printf("ERROR: invalid_state_number: ABORTED\n\n");
		exit(1);
	}
	PushInAdjacencyListarray(AdjacencyListArray, statenum-1, val, parentnum-1);
}
