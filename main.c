#include "AdjList.h"
#include "TreeRep.h"

int main(int argc, char *argv[])
{
	//deal with argc and argv in case the 'ana' parameter is present/absent
	strcpy(search_mode, argv[1]);
	if(strcmp(search_mode,"ana")==0)
		strcpy(search_mode, argv[2]);
	
	long long noofele;
	scanf("%lld", &noofele);
	if(!(noofele > 0)){
		printf("ERROR:number_of_inputs_must_be_greater_than_0:ABORTED\n\n");
		exit(1);}

	//create our two main structures, the priority queue and the adjacency list
	ptr *pq = createPQ(noofele+10);
	//pq capacity made much larger than noofele, can be EQUAL to noofele
	struct node *AdjacencyListArray[noofele];

	//initialise adjacency list with all NULLS, then accept all nodes using the input_node method from node.c	
	for (long long i = 0; i < noofele; i++)
	{
		AdjacencyListArray[i] = NULL;
	}
	for (int i = 0; i < noofele; i++)
		input_node(AdjacencyListArray);

	//print tree representation and search output table
	if(noofele<=30)
	{
		printTree(AdjacencyListArray,noofele);
	}
	pushListToPQ(AdjacencyListArray,pq,noofele);

	//if analysis flag is enabled, print analysis table
	if(strcmp(argv[1],"ana")==0)
		printAnalysis(noofele);
	
	//free malloced memory
    deleteAdjacencyList(AdjacencyListArray, noofele);
    deletePQ(pq);
	return 0;
}
