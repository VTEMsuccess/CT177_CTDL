//khai bao kieu List (ds_Dac) hoc phan 
typedef struct{
	char mahp[10];
	char tenhp[50];
	char mabm[10];
	int sotc, siso;
} Hocphan;

typedef int Position;
typedef struct{
	Hocphan Mhp[22];
	Position Sohp;
} Danhsach;

void insertList(Hocphan hp, Position p, List *pL)
{	
	
    if ((p < 1) || (p > pL->Sohp + 1))
    	printf("Vi tri khong hop le");
	else
	{
		Position i;
    	for (i = (pL ->Sohp-1) + 1; i >=p; i--)
        	
			pL->Mhp[i] = pL->Mhp[i - 1];
    		pL->Mhp[p - 1] = hp;
    		pL->Sohp++;
	}
}






#include <stdio.h>
#define MaxLength 300 // So phan tu toi da
typedef int ElementType; // Kieu du lieu cua phan tu
typedef int Position; // Position = index + 1

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;

// ham chen 1 phan tu vao List

void insertList(ElementType x, Position p, List *pL)
{	Position i;
    if (pL->Last==Maxlength)
        return;

    if ((p < 1) || (p > pL->Last + 1))
        return;

    for ( i = pL->Last; i >= p; i++)
        pL->Elements[i] = pL->Elements[i - 1];

    pL->Elements[p - 1] = x;
    pL->Last++;
}

/*__END__DEFINE__TYPE__*/

/* __FUNCTIONS__INTERFACE__ */

void copyEvenNumbers(List list1, List *pL2);

int countList(ElementType x, List list);

void deleteList(Position p, List *pL);

void difference(List list1, List list2, List *pL);

int emptyList(List list);

Position endList(List list);

void erase(ElementType x, List *pL);

int fullList(List list);

Position first(List list);

float getAvg(List list);

void insertList(ElementType x, Position p, List *pL);

void insertSet(ElementType x, List *pL);

void intersection(List list1, List list2, List *pL);

Position locate(ElementType x, List list);

ElementType minList(List list);

void makenullList(List *pL);

int member(ElementType x, List list);

ElementType maxList(List list);

Position next(Position p, List L);

void normalize(List *pL);

Position previous(Position p, List L);

void printList(List L);

void printOddNumbers(List list);

ElementType retrieve(Position p, List list);

void removeAll(ElementType x, List *pL);

void readList(List *pL);

void readSet(List *pL);

ElementType sumList(List list);

void swap(ElementType array[], int i, int j);

void sort(List *pL);

void unionSet(List list1, List list2, List *pL);

/* __END__FUNCTIONS__INTERFACE__*/

// hàm chép toàn bo cac so chan trong danh sách L1 sang danh sách ket qua
void copyEvenNumbers(List L1, List *pL2)
{	int i;
    pL2->Last = 0;//ds ket qua rong
    for ( i = 0; i < L1.Last; i++)
        if (L1.Elements[i] % 2 == 0)
        {
            pL2->Elements[pL2->Last] = L1.Elements[i];
            pL2->Last++;
        }
}

// dem x trong List
int countList(ElementType x, List list)
{	int i;
    int count = 0;
    for ( i = 0; i < list.Last; i++)
        if (list.Elements[i] == x)
            count++;
    return count;
}

// ham xoa mot phan tu tai vi tri p
void deleteList(Position p, List *pL)
{	Position i;
    if (p < first(*pL) || p >= endList(*pL))
    {
        printf("Vi tri khong hop le\n");
        return;
    }

    for ( i = p; i < pL->Last; i++)
        pL->Elements[i - 1] = pL->Elements[i];

    pL->Last--;
}

// tim hieu cua hai tap
void difference(List list1, List list2, List *pL)
{	int i;
    makenullList(pL);
    for ( i = 0; i < list1.Last; i++)
        if (!member(list1.Elements[i], list2))
            insertSet(list1.Elements[i], pL);
}

// ham kiem tra mot ds co rong hay khong
int emptyList(List list)
{
    return list.Last == 0;
}

// ham tra ve vi tri sau vi tri cuoi cung cua List
Position endList(List list)
{
    return list.Last + 1;
}

// Xóa phan tu dau tiên có giá tri là x trong danh sách chi boi con tro *pL
void erase(ElementType x, List *pL)
{
    deleteList(locate(x, *pL), pL);
}

// ham kiem tra ham co full khong
int fullList(List list)
{
    return list.Last == MaxLength;
}

// ham tra ve vi tri dau tien cua List
Position first(List list)
{
    return 1;
}

//ham tinh tbcong getAvg

ElementType sumList(List L)
{	int i;
    ElementType sum = 0;
    for ( i = 0; i < L.Last; i++)
        sum += L.Elements[i];
    return sum;
}

float getAvg(List L)
{
    if (L.Last == 0)
        return -10000;
    return (float)sumList(L) / L.Last;	//viet them ham SumList neu chua co
}


// them phan tu vao cuoi List
void insertSet(ElementType x, List *pL)
{
    pL->Elements[pL->Last] = x;
    pL->Last++;
}

// ham tim tap giao cua L1 L2
void intersection(List list1, List list2, List *pL)
{	int i;
    makenullList(pL);
    for ( i = 0; i < list1.Last; i++)
        if (member(list1.Elements[i], list2))
            insertSet(list1.Elements[i], pL);
}

// ham tra ve vi tri dau tien cua phan tu x co trong List
ElementType retrieve(Position i, List L)
{
        return L.Elements[i - 1];
}

Position locate(ElementType x, List L)
{	int i;
    for ( i = 1; i <= L.Last; i++)
        if (x == retrieve(i, L))
            return i;
    return L.Last + 1;
}



// lam rong danh sach
void makenullList(List *pL)
{
    pL->Last = 0;
}

// ham kiem tra 1 phan tu co trong List hay khong
int member(ElementType x, List list)
{	int i;
    for ( i = 1; i <= list.Last; i++)
        if (x == retrieve(i, list))
            return 1;
    return 0;
}

//  tra ve gia tri lon nhat trong các phan tu cua danh sách L
ElementType maxList(List L)
{	int i;
    ElementType max = L.Elements[0];
    for ( i = 0; i < L.Last; i++)
        if (max < L.Elements[i])
            max = L.Elements[i];
    return max;
}

//  tra ve gia tri nho nhat trong các phan tu cua danh sách L
ElementType minList(List L)
{	int i;
    ElementType min = L.Elements[0];
    for ( i = 0; i < L.Last; i++)
        if (min > L.Elements[i])
            min = L.Elements[i];
    return min;
}

// tra ve vi tri sau vi tri p trong List
Position next(Position p, List L)
{
    if (p > L.Last)
        return 0;
    if (p == L.Last)
        return endList(L);
    return p + 1;
}

// lam cho List co phan tu duy nhat
void normalize(List *pL)
{	int i,j;
    for ( i = 0; i < pL->Last; i++)
        for ( j = i + 1; j < pL->Last; j++)
            if (pL->Elements[i] == pL->Elements[j])
            {
                deleteList(j + 1, pL);
                j--;
            }
}

// tra ve vi tri truoc vi tri p trong List
Position previous(Position p, List L)
{
    if (p <= first(L))
        return 0;
    return p - 1;
}

// in ra List
void printList(List L)
{	Position p;
    for ( p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L)); // viet them ham retrieve neu chua co

    printf("\n");
}

// ham in so le
void printOddNumbers(List list)
{	int i;
    for ( i = 0; i < list.Last; i++)
        if (!(list.Elements[i] % 2 == 0))
            printf("%d ", list.Elements[i]);
    printf("\n");
}


// xoa tat ca phan tu co gia tri x trong List
void removeAll(ElementType x, List *pL)
{
    while (member(x, *pL))
        deleteList(locate(x, *pL), pL);
}

// ham nhap List tu ban phim
void readList(List *pL)
{	int i;
    makenullList(pL);
    int n, e;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &e);
        insertList(e, pL->Last + 1, pL);
    }
}

// ham them n phan tu vao List neu no chua co trong List
void readSet(List *pL)
{
    readList(pL);
    normalize(pL);
}



// ham hoan doi 2 phan tu trong mang
void swap(ElementType array[], int i, int j)
{
    ElementType temp = array[i];

    array[i] = array[j];
    array[j] = temp;
}

// ham sap xep
void sort(List *pL)
{	int i,j;
    for ( i = 0; i < pL->Last; i++)
        for ( j = i + 1; j < pL->Last; j++)
            if (pL->Elements[i] > pL->Elements[j])
                swap(pL->Elements, i, j);
}

// tap hop cua 2 tap
void unionSet(List list1, List list2, List *pL)
{
    makenullList(pL);
    int i;
    for (i = 0; i < list1.Last; i++)
        insertSet(list1.Elements[i], pL);

    for (i = 0; i < list2.Last; i++)
        if (!member(list2.Elements[i], list1))
            insertSet(list2.Elements[i], pL);
}
