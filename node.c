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
    long long statenum,parentnum;
    long long val;//change this line for different input types
		scanf(" %lld %lld %lld", &statenum, &val, &parentnum);
		PushInAdjacencyListarray(AdjacencyListArray, statenum-1, val, parentnum-1);
}
