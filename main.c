#include "AdjList.h"
int main()
{
	int noofele;
	scanf("%d", &noofele);

	//create our two main structures, the priority queue and the adjacency list
	ptr *pq = createPQ(noofele+10);//pq capacity made much larger than noofele, can be EQUAL to noofele
	struct node *AdjacencyListArray[noofele];

	//int VisitedArray[noofele]; //not needed for now
	
	for (int i = 0; i < noofele; i++)
	{
		AdjacencyListArray[i] = NULL;
	}

	for (int i = 0; i < noofele; i++)
	{
		int statenum, val, parentnum;
		scanf(" %d %d %d", &statenum, &val, &parentnum);
		PushInAdjacencyListarray(AdjacencyListArray, statenum-1, val, parentnum-1);
	}
    printAdjacencyList(AdjacencyListArray,noofele);
	pushListToPQ(AdjacencyListArray,pq,noofele);
    deleteAdjacencyList(AdjacencyListArray, noofele);
    deletePQ(pq);
	return 0;
}