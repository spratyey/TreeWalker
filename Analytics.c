#include "AdjList.h"

__COUNT=1;
BF_SUM=0;
MAX_DEPTH=-1;
WEIGHTED_D=0;

double BranchingFactor(ptr Node)
{
    double average;
    BF_SUM+=Node->number_of_children;
    average=BF_SUM/__COUNT++;
    return average;
}

int MaxDepth(ptr node, int prev)
{
    int temp_max = prev;

    if (prev < node->depth)
        temp_max = node->depth;

    return temp_max;
}

double AvgDepth(ptr node)
{
    WEIGHTED_D += node->depth;
    double average = WEIGHTED_D / __COUNT;
    return average;
}

void printAnalysis(int maxnode)
{
    for(int i = 0; i < maxnode; i++)
        printf("%d, %d, %lf, %lf", i, MAX_DEPTH[i], AVERGAE_D[i], BRANCHING_F[i]);
}