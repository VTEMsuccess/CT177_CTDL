


/////////////////////////////////////
#include<stdio.h>
typedef int ElementType; 
 struct Node
{ 	ElementType Element; 
	struct Node* Next; 
};
typedef struct Node* Position;
typedef Position List;
//ham xoa pt trong ds
void deleteList(Position p, List *pL){
	Position Temp;
	if (p->Next!=NULL)
	
	{	
		Temp=p->Next;
		p->Next=Temp->Next;
		free(Temp);
	}
}
// ham tra ve trung binh cong
float getAvg(List L)
{
    float sum = 0;
    int length = 0;
    Position P = L;
    if (P->Next == NULL)
        return -10000;
    while (P->Next != NULL)
    {
        sum += P->Next->Element;
        length++;
        P = P->Next;
    }
    return sum / length;
}

// tinh tap hop cua 2 danh sach
List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    P = L2;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}

// neu de chua cho truoc ham endList thi phai viet them ham endList
// tra ve vi tri phan tu cuoi cung
Position endList(List L)
{
    Position P = L;
    while (1)
    {
        if (P->Next == NULL)
            return P;
        P = P->Next;
    }
}

void append(ElementType x, List *pL)
{
    Position P = endList(*pL);
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}


//ham nhap danh sach tu ban phim 
 
void makenull_List (List *pL){
	(*pL)=(List) malloc (sizeof(struct Node));
	(*pL)->Next=NULL;
}


void readList(List *pL){
	makenullList (pL);  	//viet them ham makenullList neu de chua co
	int n;
	Position p=*pL,N;
	scanf(" %d ",&n);
	for (int i=0;i<n;i++)
	{
		N=(Position) malloc (sizeof(struct Node));
		scanf(" %d ",&N->Element);
		p->Next=N;
		p=p->Next;
	}
}
// ham xoa tat ca cac pt trong ds

void removeAll(ElementType x, List *pL){
	while (locate (x,*pL)->Netx !=NULL)
	deleteList (locate(x, *pL),pL);	// viet them ham deleteList neu de chua cho
}

//ham chen pt x vao dau ds

void addFirst(ElementType x, List *pL)
{
    Position P;
    P = (Position)malloc(sizeof(struct Node));
    P->Element = x;
    P->Next = (*pL)->Next;
    (*pL)->Next = P;
}
// ham kiem tra pt x co trong ds hay khong
int member(ElementType x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return 1;
        P = P->Next;
    }
    return 0;
}

//ham nhap tap hop

List readSet()
{
    List L;
    makenullList(&L); // viet ham makenull_List neu de chua cho
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!member(x, L)) // viet ham member neu de chua cho
            addFirst(x, &L); // viet ham addFirst neu de chua cho
    }
    return L;
}
// ham tra ve vi tri dau tien trong ds 

Position locate(ElementType x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return P;
        P = P->Next;
    }
    return P;
}

