#include "AdjList.h"

//#include "Analytics.h"
int main(int argc, char *argv[])
{
	strcpy(search_mode, argv[1]);
	//printf("%s", search_mode);
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

	//AAKASH:
	for (int i = 0; i < noofele; i++)
		input_node(AdjacencyListArray);
	//AAKASH-OVER

    //printAdjacencyList(AdjacencyListArray,noofele);
	pushListToPQ(AdjacencyListArray,pq,noofele);
	printAnalysis(noofele);
    deleteAdjacencyList(AdjacencyListArray, noofele);
    deletePQ(pq);
	return 0;
}
