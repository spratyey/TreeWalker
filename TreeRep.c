#include "TreeRep.h"

/*Queue implementation*/
queNode *InitNode(ElementType element)
{
    queNode *tmp = (queNode *)malloc(sizeof(queNode));
    tmp->E = element;
    tmp->Next = NULL;
    tmp->Prev = NULL;
    return tmp;
}

Que InitQue()
{
    Que Q = (Que)malloc(sizeof(Queue));
    if (!(Q != NULL))
    {
        printf("ERROR:queue_not_allocated_memory:ABORTED\n\n");
        exit(1);
    }
    ElementType e = 0;

    Q->Head = InitNode(e);

    Q->NumItems = 0;
    if (!(Q->Head != NULL))
    {
        printf("ERROR:queue_head_not_present:ABORTED\n\n");
        exit(1);
    }
    assert(Q->Head != NULL);

    //TODO___
    //       |
    //       v

    Q->Front = Q->Head;

    Q->Rear = Q->Head; // or -1

    return Q;
}

void Inject(Que Q, ElementType E) 
{
    

    queNode *tmp = InitNode(E);
    if (!IsEmpty(Q))
    {
        tmp->Prev = Q->Rear;
        Q->Rear->Next = tmp;

        Q->Rear = Q->Rear->Next;
    }
    else
    {
        tmp->Prev = Q->Head;
        Q->Head->Next = tmp;
        Q->Rear = tmp;
        Q->Front = tmp;
    }

    (Q->NumItems)++;
}

ElementType Eject(Que Q)
{
    if (!IsEmpty(Q))

    {
        ElementType e = Q->Rear->E;

        queNode *tmp = Q->Rear;

        Q->Rear = Q->Rear->Prev;
        Q->Rear->Next = NULL;

        free(tmp);

        --(Q->NumItems);

        return e;
    }
    ElementType exit = (0);

    return exit;
}

ElementType Pop(Que Q)
{
    if (!IsEmpty(Q))
    {
        ElementType e = Q->Front->E;

        queNode *tmp = Q->Front;

        Q->Front = Q->Front->Next;
        free(tmp);
        Q->Head->Next = Q->Front;
        if (Q->Front != NULL)
            Q->Front->Prev = Q->Head;
        else
        {
            Q->Front = Q->Head; //NOT necessary
        }

        --(Q->NumItems);

        return e;
    }
    ElementType exit = 0;

    return exit;
}

void Push(Que Q, ElementType E)
{

    queNode *tmp = InitNode(E);
    if (IsEmpty(Q))
    {
        Q->Rear = tmp;
        Q->Front = tmp;
        tmp->Prev = Q->Head;
        Q->Head->Next = tmp;
    }
    else
    {
        tmp->Next = Q->Head->Next;

        Q->Front->Prev = tmp;
        tmp->Prev = Q->Head;
        Q->Front = tmp;

        Q->Head->Next = Q->Front;
    }

    Q->NumItems++;
}

int IsEmpty(const Que Q)
{
    return (Q->NumItems == 0);
}

void ClearQueue(Que Q)
{
    if (Q != NULL)
    {
        while (!IsEmpty(Q))
            Eject(Q);
    }
}

void DeleteQue(Que *QP)
{
    ClearQueue(*QP);
    free((*QP)->Head);
    free(*QP);
    *QP = NULL;
}

void PrintQue(const Que Q)
{
    if (Q->NumItems > 0)
    {
        queNode *walk = Q->Head->Next;
        // Print from front to rear

        printf("\n");
        while (walk != NULL)
        {
            printf("%lld ", walk->E);

            walk = walk->Next;
        }
    }

    else
    {
        printf("The deque is empty");
    }

    printf("\n\n");
}

void printGap(char ch, ElementType dist)
{
    for (ElementType i = 0; i < dist; i++)
    {
        printf("%c", ch);
    }
}
/*******************************************/
/*Print tree implementation here*/
/*To convert number into string*/
ElementType toString(char Snum[], ElementType n)
{
    ElementType num = n;
    ElementType len = 0;
    while (num > 0)
    {
        len++;
        num = num / 10;
    }
    ElementType c = 0;
    while (n > 0)
    {
        Snum[len - (c + 1)] = '0' + n % 10;
        n = n / 10;
        c++;
    }
    Snum[len] = '\0';
    return len;
}
/*to insert a number*/
int setChar(char ch[], ElementType value, ElementType pos)
{
    char Snum[20];
    int flag1=0;
    ElementType len = toString(Snum, value);
    for (ElementType i = pos, j = 0; j < len; i++, j++)
    {
        if(ch[i]>='0'&&ch[i]<='9')
        {
            flag1=1;
        }
        ch[i] = Snum[j];
    }
    return flag1;

}
/*******************************/
/*To modify a subtring in a string*/
void setCharRange(char ch[], char ch2, ElementType size, ElementType start, ElementType end)
{
    if (end > size)
    {
        end = size;
    }
    if(start<0)
    {
        start=0;
    }
    for (ElementType i = start; i < end; i++)
    {
        ch[i] = ch2;
    }
}

void printTree(struct node *AdjacencyListArray[], ElementType maxNode)
{

    Que Q = InitQue();
    ElementType size = 10 * maxNode;
    //  if(maxNode<6)
    //  {
    //      size=size*2;
    //  }
    ElementType strSize = 2 * size;
    char ch1[strSize + 1];
    char ch2[strSize + 1];
    Inject(Q, AdjacencyListArray[0]->state_number);
    ElementType level[maxNode*2];
    ElementType Xaxis[size];
    int flag=0;
    for (ElementType i = 0; i < maxNode; i++)
        level[i] = 0;
    for (ElementType i = 0; i < strSize; i++)
    {
        ch1[i] = ' ';
        ch2[i] = ' ';
    }
    ch1[strSize] = '\0';
    ch2[strSize] = '\0';
    ElementType Gap = 5;
    ElementType shift, prev = 0, range;
    int incre = 2, shift_inc = 1;
    printf("======================\n");
    printf("TREE REPRESENTATION\n");
    printf("======================\n");

    level[0] = 1;
    while (!IsEmpty(Q))
    {
        Vertex v = Pop(Q);
        ptr tmp = AdjacencyListArray[v];
        ptr tmp2 = AdjacencyListArray[v];
        level[tmp->depth]--;

        if (tmp->parent < 0)                    //this is to set the inital position of root
        {
            Xaxis[tmp2->state_number] = strSize / 2;
        }                       
        flag=setChar(ch1, v + 1, Xaxis[tmp2->state_number]);

        prev = Xaxis[tmp->state_number];
        if (level[tmp->depth] == 0)             //this prints the numbers
        {
            printf("%s", ch1);
            printf("\n");
            prev = 0;
            for (ElementType i = 0; i < strSize; i++)
            {
                ch1[i] = ' ';
            }
        }
        level[tmp2->depth + 1] += tmp->number_of_children;               //this calculates number of children at each level

        range = (tmp2->number_of_children) * (size /5) / (tmp2->depth+1);
        shift = range / (-2);
        
    
        setCharRange(ch2, '-', strSize, Xaxis[tmp->state_number] + shift, Xaxis[tmp->state_number] - shift + 1);
        if (tmp2->number_of_children > 0)
        {
            shift_inc = range /( (tmp2->number_of_children));
            ptr tmpArr[tmp2->number_of_children];
            Vertex c = 0;
            while (tmp!=NULL&&tmp->next != NULL)
            {
                tmp = tmp->next;
                Inject(Q, AdjacencyListArray[tmp->state_number]->state_number);
                tmpArr[c++] = AdjacencyListArray[tmp->state_number];
            }
            c = 0;
            Vertex k[2] = {0, tmp2->number_of_children - 1};
            for (Vertex i = 0; i < tmp2->number_of_children; i++)
            {
                //printf("%lld\n",tmpArr[k[c]]->state_number);
                if(tmpArr[k[c]]->parent>=0&&tmpArr[k[c]]->state_number<maxNode)
                {    
                    Xaxis[tmpArr[k[c]]->state_number] = Xaxis[tmpArr[k[c]]->parent] + shift;
                }
                setCharRange(ch2, '.', strSize, Xaxis[tmpArr[k[c]]->state_number], Xaxis[tmpArr[k[c]]->state_number] + 1);
                if (c == 0)
                {
                    k[c]++;
                }
                else
                {
                    k[c]--;
                }

                if (i%2!=0)
                {
                    shift *= -1;
                    c = 0;
                    shift += shift_inc;
                    
                }
                else
                {
                    shift *= -1;
                    c = 1;
                }
            }
        }
        if (level[tmp2->depth] == 0)        //this is printing the branches
        {
            printf("%s", ch2);
            printf("\n");
            for (ElementType i = 0; i < strSize; i++)
            {
                ch2[i] = ' ';
            }
        }
    }
    if(flag)
    {
        printf("ERROR: Data might have been overwritten because branching factor is large");
    }
    printf("\n");
    DeleteQue(&Q);
}