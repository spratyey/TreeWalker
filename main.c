#include "AdjList.h"
//#include "Analytics.h"
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
		input_node(AdjacencyListArray);
    printAdjacencyList(AdjacencyListArray,noofele);
	pushListToPQ(AdjacencyListArray,pq,noofele);
	printAnalysis(noofele);
    deleteAdjacencyList(AdjacencyListArray, noofele);
    deletePQ(pq);
	return 0;
}