#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"
int size=-1;





void siftDown(ptr heap, long long int size, long long int index) 
{
	/*
	long long int w = 2 * index + 1;
  	while (w < size) 
  	{
	  	if (w + 1 < size) 
	  	{
			if (heap[w + 1] > heap[w])
				w++;
		}
		if (heap[index] > heap[w]) 
			return;
		
		swap(&heap[index], &heap[w]);
		index = w;
		w = 2 * index + 1;
	}
	*/
}




void heapify(ptr heap, long long int size) 
{
	/*
	for (long long int i = (size - 2) / 2; i >= 0; i--) 
  	  siftDown(heap, size, i);
		*/
}

void deleteByValue(ptr heap, node Todelete, long long int *size) 
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
void updateByPos(ptr heap, long long int index, node UpdatedP, long long int size) 
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

ptr* createPQ(int capacity) 
{
	ptr* heap = (ptr*)malloc(sizeof(ptr)*capacity);
  	assert(heap != NULL);
	return heap;
}

void push(ptr* heap, ptr newnode) 
{
	heap[++size]= newnode;
	siftUp(heap,size);
}



