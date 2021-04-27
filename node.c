#include "node.h"
int node_comparator(node *a, node *b)
{
    // User puts in the node comparator here
    return a->value < b->value; // A sample comparator
}