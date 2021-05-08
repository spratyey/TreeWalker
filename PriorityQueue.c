#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
int __SIZE=-1,__CAP;

//returns index of parent of arg
long long par(long long index) 
{
	if (index != 0)
	return (index - 1) / 2;
	else 
		return -1;
}

//returns index of left child of arg
long long lef(long long index)
{
    return (2 * index) + 1;
}

//returns index of right child of arg
long long ri(long long index)
{
    return lef(index) + 1;
}

//swaps two nodes in the heap
void swap(ptr* a, ptr* b)
{
	ptr tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
//heapify while pushing
void siftUp(ptr* heap, long long index) 
{
	while(index>0 && node_comparator(heap[index], heap[par(index)])!=0)
	{
        swap(&heap[par(index)], &heap[index]);
        index = par(index);
	}
}
//heapify while popping
void siftDown(ptr* heap,long long index) 
{
	long maxele = index;
    long left = lef(index);
 	long right = ri(index);
    if (left <= __SIZE && node_comparator(heap[left] , heap[maxele])!=0) 
        maxele = left;   
    if (right <= __SIZE && node_comparator(heap[right] , heap[maxele])!=0) 
		maxele = right;
    if (index != maxele) 
	{
        swap(&heap[index], &heap[maxele]);
        siftDown(heap,maxele);
    }	
}
//create a pq
ptr* createPQ(long long capacity) 
{
	__CAP=capacity;
	ptr* heap = (ptr*)malloc(sizeof(ptr)*capacity);
	if(!(heap != NULL)){
		printf("ERROR:heap_not_allocated_memory:ABORTED\n\n");
		exit(1);}
}

//Adds element to PQ
void push(ptr* heap, ptr newnode) 
{
	if(!(__SIZE<__CAP-1)){
		printf("ERROR:heap_capacity_less_than_0:ABORTED\n\n");
		exit(1);}
	
	heap[++__SIZE]= newnode;
	siftUp(heap,__SIZE);
}

//pops the element with the highest priority
ptr pop(ptr* heap)
{
	if(heap[0]==NULL)
		return NULL;

	ptr temp = heap[0];
	heap[0] = heap[__SIZE--];
    siftDown(heap,0);
    return temp;
}
//Returns highest priority element
ptr peek(ptr* heap)
{
	return heap[0];
}
//To check if PQ is empty
int isEmpty()
{
	return (__SIZE==-1);
}
//frees malloc'd memory for heap. Note: individual nodes are not freed here as they hve been malloc'd by the adjacency list.the heap just stores pointers to those nodes. on freeing the heap, those addresses are not lost as they are still present in the adjacency list.
void deletePQ(ptr* heap)
{
	if(!(heap!=NULL)){
		printf("ERROR:heap_not_valid:ABORTED\n\n");
		exit(1);}
	__SIZE=-1;
	free(heap);
}