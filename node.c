#include "node.h"
int node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
	return a->seen_time > b->seen_time; // Breadth first search
    //return a->value < b->value; // greedy search for least value
	//return a->seen_time > b->seen_time; //Depth First search
    //return a->value > b->value; // greedy search for greatest value
}