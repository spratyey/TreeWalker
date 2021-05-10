#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef struct node
{
    long long state_number;
    long long value;
    long long parent;
    long long seen_time;
    long long depth, number_of_children;
    // Branching factor = average number of children of each node other than leaves.
    struct node* next;
} node;

typedef struct node* ptr;
extern char search_mode[10];
extern char valid_searches[10][10];
int node_comparator(node *a, node *b);
void input_node(struct node *AdjacencyListArray[], long long noofele);


#endif