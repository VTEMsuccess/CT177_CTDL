
#include <stdio.h>

/*__DEFINE__TYPE__*/
typedef int ElementType; // kieu cua phan tu du lieu

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position; // kieu vi tri
typedef Position List;
/*__END__DEFINE__TYPE__*/

/*__FUNCTION__DECLARATION__*/

void deleteList(Position P, List *pL);                // xoa phan tu sau vi tri P

int emptyList(List L);                                //  kiem tra danh sach co rong hay khong

Position first(List L);                               // tra ve vi tri dau tien

Position endList(List L);                             // tra ve vi tri phan tu cuoi cung

void insertList(ElementType X, Position P, List *pL); // chen them mot phan tu

Position locate(ElementType x, List L);               // tra ve vi tri phan tu dau tien co gia tri X

Position myLocate(ElementType x, int i, List L);      // tra ve phan tu x thu i

void makenullList(List *pL);                          // khoi tao danh sach rong

Position next(Position P, List L);                    // tra ve vi tri tiep theo

Position previous(Position P, List L);                // tra ve vi tri truoc P

ElementType retrieve(Position P, List L);             // tra ve gia tri phan tu

/*__END__FUNCTION__DECLARATION__*/

/*__FUNCTION__*/

// xoa phan tu sau vi tri P
void deleteList(Position P, List *pL)
{
    Position Temp;
    if (P->Next != NULL)
    {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}
//  kiem tra danh sach co rong hay khong
int emptyList(List L)
{
    return L->Next == NULL;
}
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
 // tra ve vi tri dau tien
Position first(List L)
{
    return L;
}
// chen them mot phan tu
void insertList(ElementType x, Position P, List *pL)
{
    Position T;
    T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}
// tra ve vi tri phan tu dau tien co gia tri X
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
// khoi tao danh sach rong
void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}
// tra ve phan tu x thu i
Position myLocate(ElementType x, int i, List L)
{
    Position P = L;
    int count = 0;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            count++;
        if (count == i)
            return P->Next;
        P = P->Next;
    }
    return P->Next;
}
// tra ve vi tri tiep theo
Position next(Position P, List L)
{
    return P->Next;
}
// tra ve vi tri truoc P
Position previous(Position P, List L)
{
    Position Q = L;
    while (Q->Next->Next != NULL)
    {
        if (Q->Next->Next == P)
            Q = Q->Next;
    }
    return Q->Next;
}
// tra ve gia tri phan tu
ElementType retrieve(Position P, List L)
{
    if (P->Next != NULL)
        return P->Next->Element;
}
/*__END__FUNCTION__*/
// #define USE_ALL 1

/*__OTHER__FUNCTION__*/
/*__DECLARATION__*/

void addFirst(ElementType x, List *pL);  // them phan tu vao vi tri dau tien

void append(ElementType x, List *pL);    // them phan tu vao cuoi ds

void copyEvenNumbers(List L, List *pL);  // sao chep so le tu L qua pL

void deleteX(ElementType x, List *pL);   // xoa phan tu x

List difference(List L1, List L2);       // tra ve tap hieu cua L1 L2

void erase(ElementType x, List *pL);     // xoa phan tu x dau tien

float getAvg(List L);                    // tra ve trung binh cong

List intersection(List L1, List L2);     // tra ve tap giao cua L1 L2

int member(ElementType x, List L);       // kiem tra phan tu co trong L

void normalize(List *pL);                // bien danh sach thanh tap hop

void printList(List L);                  // hien thi danh sach phan tu

void printOddNumbers(List L);            // in so le

List readSet();                          // nhap tap hop

void removeAll(ElementType x, List *pL); // xoa tat ca phan tu x

void readList(List *pL);                 // nhap danh sach tu ban phim

void sort(List *pL);                     // sap xep danh sach

List unionSet(List L1, List L2);         // tinh tap hop cua 2 ds

/*__END__DECLARATION__*/

/*__FUNCTION__BODY__*/

// them phan tu vao vi tri dau tien
void addFirst(ElementType x, List *pL)
{
    Position P;
    P = (Position)malloc(sizeof(struct Node));
    P->Element = x;
    P->Next = (*pL)->Next;
    (*pL)->Next = P;
}
// neu de chua cho truoc ham endList thi phai viet them ham endList
void append(ElementType x, List *pL)
{
    Position P = endList(*pL);
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}
// ham chep cac so chan sang danh sach liên ket
void copyEvenNumbers(List L, List *pL)
{
    makenullList(pL);
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 == 0)
            append(P->Next->Element, pL);
        P = P->Next;
    }
}
// xoa phan tu x
void deleteX(ElementType x, List *pL)
{
    Position P = first(*pL);
    while (P != endList(*pL))
    {
        if (retrieve(P, *pL) == x)
            deleteList(P, pL);
        else
            P = next(P, *pL);
    }
}
// tra ve tap hieu cua L1 L2
List difference(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L) && !member(P->Next->Element, L2))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}
// xoa phan tu x dau tien
void erase(ElementType x, List *pL)
{
    if (locate(x, *pL)->Next != NULL)
        deleteList(locate(x, *pL), pL);
}
//tra ve trung binh cong
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
// tra ve tap giao cua L1 L2
List intersection(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L2;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L) && member(P->Next->Element, L1))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}
 // kiem tra phan tu co trong danh sach L
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
// bien danh sach thanh tap hop
void normalize(List *pL)
{
    Position P = *pL, Q;
    while (P->Next != NULL)
    {
        Q = P->Next;
        while (Q->Next != NULL)
        {
            if (Q->Next->Element == P->Next->Element)
                deleteList(Q, pL);
            Q = Q->Next;
        }
        P = P->Next;
    }
}
//ham in ra danh sach
void printList(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}
// in so le
void printOddNumbers(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 != 0)
            printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}
// nhap tap hop
List readSet()
{	int i;
    List L;
    makenullList(&L);
    int n, x;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!member(x, L))
            addFirst(x, &L);
    }
    return L;
}
// xoa tat ca phan tu x
void removeAll(ElementType x, List *pL)
{
    while (locate(x, *pL)->Next != NULL)
        deleteList(locate(x, *pL), pL);
}
// nhap danh sach tu ban phim
void readList(List *pL)
{
    makenullList(pL);
    int n,i;
    Position P = *pL,
             N;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        P->Next = N;
        P = P->Next;
    }
}
//ham sap xep danh sach
void sort(List *pL)
{
    Position P = *pL,
             N;
    while (P->Next != NULL)
    {
        N = P->Next;
        while (N->Next != NULL)
        {
            if (P->Next->Element > N->Next->Element)
            {
                ElementType Temp = P->Next->Element;
                P->Next->Element = N->Next->Element;
                N->Next->Element = Temp;
            }
            N = N->Next;
        }
        P = P->Next;
    }
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

