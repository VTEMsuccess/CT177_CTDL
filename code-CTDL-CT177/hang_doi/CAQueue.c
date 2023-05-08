/* cai dat hang doi bang dslk */ 

//khoi tao hang doi rong

void makenullQueue(Queue *pS)
{
    pS->Front = (Position)malloc(sizeof(struct Node));
    pS->Front->Next = NULL;
    pS->Rear = pS->Front;
}

//kiem tra hang doi co rong hay khong

int emptyQueue(Queue Q)
{	
    return Q.Front == Q.Rear;
}

//tra ve gia tri dau hang

ElementType front(Queue Q)
{
    return Q.Front->Next->Element;
}

//ham xoa pt o dau hang

void deQueue(Queue *pQ)
{
    pQ->Front = pQ->Front->Next;
}

//ham them pt x vao cuoi hang

void enQueue(ElementType x, Queue *pQ)
{
    pQ->Rear->Next = (Position)malloc(sizeof(struct Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next = NULL;
}

//ham dem so luong pt trong hang

int count(Queue Q)
{
    int c = 0;
    Position P = Q.Front;
    while (P != Q.Rear)
    {
        c++;
        P = P->Next;
    }
    return c;
}
