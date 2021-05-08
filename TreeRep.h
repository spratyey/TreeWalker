#ifndef __REP
#define __REP
#include "AdjList.h"
typedef long long int ElementType;

typedef ElementType Vertex;

struct _queNode
{
    
    ElementType E;
    struct _queNode* Next;
    struct _queNode* Prev;

};

typedef struct _queNode queNode;

struct _que
{
    long unsigned int NumItems;
    struct _queNode* Front;
    struct _queNode* Rear;
    queNode* Head;

};
typedef struct _que Queue;

typedef Queue* Que;


// the actual functions used

queNode* InitNode();

Que InitQue();
void Push(Que Q,const ElementType E);

ElementType Pop(Que Q);

void Inject(Que Q,const ElementType E);
ElementType Eject(Que Q);

int IsEmpty(const Que Q);
int IsFull(const Que Q);

void PrintQue(const Que Q);

void ClearQue(Que Q);
void DeleteQue(Que* Q);
void printGap(char ch,ElementType dist);

void printTree(struct node *AdjacencyListArray[],ElementType maxNode);
#endif