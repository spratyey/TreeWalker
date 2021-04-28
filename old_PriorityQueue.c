#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
int __SIZE=-1,__CAP;
void heapify(ptr heap)//, long long int __SIZE) 
{
	/*
	for (long long int i = (size - 2) / 2; i >= 0; i--) 
  	  siftDown(heap, size, i);
		*/
}

void deleteByValue(ptr heap, node Todelete)//, long long int __SIZE) 
{
	/*
	int flag = 0;
	long long int i;
	for (i = 0; i < *size; i++) 
	{
		if (heap[i] == Todelete) 
		{
			swap(&heap[i], &heap[*size - 1]);
			(*size) -= 1;
			flag = 1;
			break;
		}
	}
	if (flag) 
		siftDown(heap, *size, i);
	*/
}

/*
void deleteByPos(ptr heap, long long int index, long long int *size) 
{
	assert(index < *size);
	heap[index] = heap[0] + 1; // store a value greater than max value
	siftUp(heap, *size, index);

	swap(&heap[0], &heap[*size - 1]);
	(*size)--;

	siftDown(heap, *size, 0);
}
*/

/*This function updates priority/value by passing position in heap*/
void updateByPos(ptr heap, long long int index, node UpdatedP)//, long long int size) 
{
	/*	assert(index < size);
	heap[index] = heap[0] + 1; // store a value greater than max value
	siftUp(heap, size, index);

	heap[0] = UpdatedP;

	siftDown(heap, size, 0);
	*/
}
//refined from here on below
int par(int index) 
{
	if (index != 0)
	return (index - 1) / 2;
	else 
		return -1;
}
int lef(int index)
{
    return (2 * index) + 1;
}
int ri(int index)
{
    return lef(index) + 1;
}
void swap(ptr* a, ptr* b)
{
	ptr tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void siftUp(ptr* heap, int index) 
{
	//assert(index < size);
	while(index>0 && node_comparator(heap[index], heap[par(index)])!=0)
	{
        swap(&heap[par(index)], &heap[index]);
        index = par(index);
	}
}
void siftDown(ptr* heap,int index) 
{
	int maxele = index;
    int left = lef(index);
 	int right = ri(index);
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

ptr* createPQ(int capacity) 
{
	__CAP=capacity;
	ptr* heap = (ptr*)malloc(sizeof(ptr)*capacity);
  	assert(heap != NULL);
	return heap;
}
/*Add element to PQ*/
void push(ptr* heap, ptr newnode) 
{
	assert(__SIZE<__CAP-1);
	
	heap[++__SIZE]= newnode;
	siftUp(heap,__SIZE);
}
/*Pop the most priority elem*/
ptr pop(ptr* heap)
{
	if(heap[0]==NULL)
		return NULL;

	ptr temp = heap[0];
	heap[0] = heap[__SIZE--];
    siftDown(heap,0);
    return temp;
}
/*Returns highest priority element*/
ptr peek(ptr* heap)
{
	return heap[0];
}
/*To check if PQ is empty*/
int isEmpty()
{
	return (__SIZE==-1);
}
void deletePQ(ptr* heap)
{
	assert(heap!=NULL);
	// for(int i=0;i<__SIZE;i++)
	// {
	// 	if(heap[i]!=NULL)
	// 	{
	// 		free(heap[i]);
	// 	}
	// }
	__SIZE=-1;
	free(heap);
}

