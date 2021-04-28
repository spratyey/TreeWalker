#include <stdio.h>
#include <stdlib.h>
#include "adjacencylists.h"

int main()
{

	int noofele;
	scanf("%d", &noofele);

	ptr *pq = createPQ(noofele);
	struct node *AdjacencyListArray[noofele];
	int VisitedArray[noofele];
	int maxnode;
	for (int i = 0; i < noofele; i++)
	{
		AdjacencyListArray[i] = NULL;
	}

	for (int i = 0; i < noofele; i++)
	{
		int statenum, val, parentnum;
		scanf(" %d %d %d", &statenum, &val, &parentnum);
		PushInAdjacencyListarray(AdjacencyListArray, statenum, val, parentnum);
	}
    //printAdjacencyList(AdjacencyListArray,noofele);
	pushListToPQ(AdjacencyListArray,pq,noofele);
	return 0;
}