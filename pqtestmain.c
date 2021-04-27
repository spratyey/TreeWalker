#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
/*void printArr(node size, node *Arr)
{
  for (node i = 0; i < size; i++) 
  {
    printf("%lld ", Arr[i]);
  }
  printf("\n");
}
*/
ptr makenode(int statenum,int val,int parentnum)
{
	ptr mynode = (ptr)malloc(sizeof(node));
	mynode->state_number = statenum;
	mynode->value = val;
	mynode->parent = parentnum;
	return mynode;
}
int main() 
{
	int noofele;
	scanf("%d", &noofele);
	ptr* pq = createPQ(noofele+10);
	for (int i = 0; i < noofele;i++)
	{
		int statenum, val, parentnum;
		scanf(" %d %d %d", &statenum, &val, &parentnum);
		//printf("Read %d %d %d\n", statenum, val, parentnum);
		push(pq, makenode(statenum, val, parentnum));
	}
	printf("\nPQ:\n");
	for (int i = 0; i < noofele; i++)
	{
		printf("%d ", pq[i]->value);
	}
	
	printf("\nPopping:\n");
	for (int i = 0; i < noofele; i++)
	{
		ptr temp = pop(pq);
		printf("%d ", temp->value);
	}
	printf("\n");
	return 0;
}