#include "AdjList.h"
/*TEST AREA*/
long int __COUNT=1;  
double BRANCHING_F[(long int)1e6];
double AVERGAE_D[(long int)1e6];
int MAX_DEPTH[(long int)1e6];
int BF_SUM=0;
int WEIGHTED_D=0;
/****************/

int MaxDepth(ptr node, int prev);
double AvgDepth(ptr node);
void printAnalysis(int maxnode);
double BranchingFactor(ptr Node);