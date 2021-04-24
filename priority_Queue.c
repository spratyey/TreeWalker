#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef long long int ElementType;
// typedef heap* heapPtr;

void swap(ElementType *a, ElementType *b) {
  ElementType tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}

long long int parent(long long int index) {
  if (index != 0)
    return (index - 1) / 2;
  else {
    return -1;
  }
}

void siftDown(ElementType *heap, long long int size, long long int index) {
  long long int w = 2 * index + 1;
  while (w < size) {
    if (w + 1 < size) {
      if (heap[w + 1] > heap[w]) {
        w++;
      }
    }
    if (heap[index] > heap[w]) {
      return;
    }
    swap(&heap[index], &heap[w]);
    index = w;
    w = 2 * index + 1;
  }
}

void siftUp(ElementType *heap, long long int size, long long int index) {
  assert(index < size);
  long long int parendex = (index - 1) / 2;
  while (parendex >= 0 && heap[index] > heap[parendex]) {
    swap(&heap[index], &heap[parendex]);
    index = parendex;
    parendex = (index - 1) / 2;
  }
}

ElementType *buildHeap(long long int size) {
  ElementType *heap = (ElementType *)malloc(sizeof(ElementType));
  assert(heap != NULL);
  // for(long long int i=0;i<size;i++)
  //{
  //    heap[i]=(ElementType*)calloc(2,sizeof(ElementType)); //The second row
  //    stores frequency
  //}

  return heap;
}

void heapify(ElementType *heap, long long int size) {
  for (long long int i = (size - 2) / 2; i >= 0; i--) {
    siftDown(heap, size, i);
  }
}
/*Use to delete element by passing value */
void deleteByValue(ElementType *heap, ElementType Todelete,
                   long long int *size) {
  int flag = 0;
  long long int i;
  for (i = 0; i < *size; i++) {
    if (heap[i] == Todelete) {
      swap(&heap[i], &heap[*size - 1]);
      (*size) -= 1;
      flag = 1;
      break;
    }
  }
  if (flag) {
    siftDown(heap, *size, i);
  }
}
/**********************************/

/*Use to delete element by passing index */
void deleteByPos(ElementType *heap, long long int index, long long int *size) {
  assert(index < *size);
  heap[index] = heap[0] + 1; // store a value greater than max value
  siftUp(heap, *size, index);

  swap(&heap[0], &heap[*size - 1]);
  (*size)--;

  siftDown(heap, *size, 0);
}
/**********************************/

/*This function updates priority/value by passing position in heap*/
void updateByPos(ElementType *heap, long long int index, ElementType UpdatedP, long long int size) {
  assert(index < size);
  heap[index] = heap[0] + 1; // store a value greater than max value
  siftUp(heap, size, index);

  heap[0] = UpdatedP;

  siftDown(heap, size, 0);
}
/************************************/
/*Print a general 1D array*/
void printArr(ElementType size, ElementType *Arr) {
  for (ElementType i = 0; i < size; i++) {
    printf("%lld ", Arr[i]);
  }
  printf("\n");
}
int main() { // This has to be removed
  ElementType size = 10;
  ElementType a[10] = {14, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  heapify(a, size);
  printArr(10, a);
  ElementType n;
  // scanf("%lld",&n);
  // delete(a,n,&size);
  updateByPos(a, 4, 1, size);
  printArr(size, a);
  deleteByPos(a, 1, &size);
  printArr(size, a);
  return 0;
}
