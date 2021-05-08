#include "AdjList.h"
#include "TreeRep.h"

int main(int argc, char *argv[])
{
	//deal with argc and argv in case the 'ana' parameter is present/absent
	strcpy(search_mode, argv[1]);
	if(strcmp(search_mode,"ana")==0)
		strcpy(search_mode, argv[2]);
	
	int noofele;
	scanf("%d", &noofele);
	assert(noofele >= 0);

	//create our two main structures, the priority queue and the adjacency list
	ptr *pq = createPQ(noofele+10);
	//pq capacity made much larger than noofele, can be EQUAL to noofele
	struct node *AdjacencyListArray[noofele];

	//initialise adjacency list with all NULLS, then accept all nodes using the input_node method from node.c	
	for (int i = 0; i < noofele; i++)
	{
		AdjacencyListArray[i] = NULL;
	}
	for (int i = 0; i < noofele; i++)
		input_node(AdjacencyListArray);

	//print tree representation and search output table
	printTree(AdjacencyListArray,noofele);
	pushListToPQ(AdjacencyListArray,pq,noofele);

	//if analysis flag is enabled, print analysis table
	if(strcmp(argv[1],"ana")==0)
		printAnalysis(noofele);
	
	//free malloced memory
    deleteAdjacencyList(AdjacencyListArray, noofele);
    deletePQ(pq);
	return 0;
}
