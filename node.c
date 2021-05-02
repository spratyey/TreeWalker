#include "node.h"
#include "AdjList.h"
int node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
	return a->seen_time < b->seen_time; // Breadth first search
    //return a->value < b->value; // greedy search for least value
	//return a->seen_time > b->seen_time; //Depth First search
    //return a->value > b->value; // greedy search for greatest value
}
void input_node(struct node *AdjacencyListArray[])
{
    int statenum,parentnum;
    int val;//change this line for different input types
		scanf(" %d %d %d", &statenum, &val, &parentnum);
		PushInAdjacencyListarray(AdjacencyListArray, statenum-1, val, parentnum-1);
}