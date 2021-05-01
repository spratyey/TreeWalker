#ifndef __ANALYS
#define __ANALYS
#include "node.h"
/*TEST AREA*/
extern long int __COUNT;  
extern double BRANCHING_F[(long int)1e6];
extern double AVERGAE_D[(long int)1e6];
extern int MAX_DEPTH[(long int)1e6];
extern int BF_SUM;
extern int WEIGHTED_D;
/****************/

int MaxDepth(ptr node, int prev);
double AvgDepth(ptr node);
void printAnalysis(int maxnode);
double BranchingFactor(ptr Node);
#endif