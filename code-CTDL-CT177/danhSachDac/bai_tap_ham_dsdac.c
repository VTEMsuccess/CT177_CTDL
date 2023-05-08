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

///////////////////////////////////////////////////////////////
//KHAI BAO DA THUC CHACH 2
typedef struct
{
    double he_so;
    int bac;
} DonThuc;
struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;

//CHEN DON THUC
void chenDonThuc(DonThuc x, DaThuc *pD)
{
    Position P = *pD;
    while (P->Next != NULL)
    {
        if (P->Next->e.bac == x.bac)
        {
            P->Next->e.he_so = P->Next->e.he_so + x.he_so;
            return;
        }
        if (P->Next->e.bac < x.bac)
        {
            Position T = (Position)malloc(sizeof(struct Node));
            T->e = x;
            T->Next = P->Next;
            P->Next = T;
            return;
        }
        P = P->Next;
    }
    Position T = (Position)malloc(sizeof(struct Node));
    T->e = x;
    P->Next = T;
}

//CONG DA THUC
DaThuc congDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc D = khoitao();
    Position P = D1;
    while (P->Next != NULL)
    {
        chenDonThuc(P->Next->e, &D);
        P = P->Next;
    }
    P = D2;
    while (P->Next != NULL)
    {
        chenDonThuc(P->Next->e, &D);
        P = P->Next;
    }
    return D;
}

//DAO HAM
void daoHam(DonThuc *d)
{
    d->he_so = d->he_so * d->bac;
    d->bac--;
}

//IN DA THUC
void inDaThuc(DaThuc d)
{
    DaThuc P = d;
    while (P->Next != NULL)
    {
        printf("%.3fX^%d", P->Next->e.he_so, P->Next->e.bac);
        if (P->Next->Next != NULL)
            printf(" + ");
        P = P->Next;
    }
    printf("\n");
}

//HAM KHOI TAO KIEU TRA VE LA DA THUC
DaThuc khoitao()
{
    DaThuc D = (DaThuc)malloc(sizeof(DaThuc));
    D->Next = NULL;
    return D;
}

//HAM NHAN DA THUC
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc P = D1, Q;
    DaThuc Result = khoitao();
    DonThuc E;
    while (P->Next != NULL)
    {
        Q = D2;
        while (Q->Next != NULL)
        {
            E.he_so = P->Next->e.he_so * Q->Next->e.he_so;
            E.bac = P->Next->e.bac + Q->Next->e.bac;
            chenDonThuc(E, &Result);
            Q = Q->Next;
        }
        P = P->Next;
    }
    return Result;
}

//HAM NHAP DA THUC
DaThuc nhapDaThuc()
{
    int n;
    double hs;
    int bac;
    DonThuc d;
    DaThuc D = khoitao();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %d", &hs, &bac);
        d.he_so = hs;
        d.bac = bac;
        chenDonThuc(d, &D);
    }
    return D;
}

//TINH DAO HAM
DaThuc tinhDaoHam(DaThuc D)
{
    DaThuc P = D;
    while (P->Next != NULL)
    {
        daoHam(&P->Next->e);
        P = P->Next;
    }
    return D;
}
/////////////////////////////////////////////////////////////////////////////////////


//DA THUC LA DANH SACH cua don thuc
struct DonThuc
{
    double he_so;
    int bac;
} ;

struct DaThuc
{
    DonThuc A[100];
    int so_luong;
};
//CHUOI LA DANH SACH CAC KY TU
typedef struct
{
    char c[80];
    int p;
} Line;

//DANH SACH CAC SO THUC FLOAT
typedef struct
{
    float c[100];
    int p;
} List;

// danh sach sinh vien
typedef struct
{
    char MSSV[10], hoVaTen[50];
    float LT, TH1, TH2;
} SinhVien;

typedef struct
{
    SinhVien A[40];
    int n;
} DanhSach;

//CAU TRUC Polygon
typedef struct
{
    int x, y;
} Point;

typedef struct
{
    Point c[100];
    int p;
} Polygon;





#include <stdio.h>
#define MaxLength 300 // So phan tu toi da
typedef int ElementType; // Kieu du lieu cua phan tu
typedef int Position; // Position = index + 1

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;

//ham hien thi danh sach
ElementType retrieve(Position i, List L)
{
        return L.Elements[i - 1];
}

void printList(List L)
{	Position p;
    for ( p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L)); // viet them ham retrieve neu chua co

    printf("\n");
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

//Tên hàm (function name): normalize()

void normalize(List *pL)
{
    for (int i = 0; i < pL->Last; i++)
        for (int j = i + 1; j < pL->Last; j++)
            if (pL->Elements[i] == pL->Elements[j])
            {
                deleteList(j + 1, pL);//Xóa pt vi  trí p trong danh sách void deleteList(Position p, List *pL); de cho.
                j--;
            }
}

//Tên hàm (function name): sort()

void swap(ElementType array[], int i, int j)
{
    ElementType temp = array[i];

    array[i] = array[j];
    array[j] = temp;
}
void sort(List *pL)	// muon sap xep thi them ham swap
{
    for (int i = 0; i < pL->Last; i++)
        for (int j = i + 1; j < pL->Last; j++)
            if (pL->Elements[i] > pL->Elements[j])
                swap(pL->Elements,i, j);
}

//Tên hàm (function name): insertList()

#define MaxLength 300	// them khai bao Maxlength
void insertList(ElementType x, Position p, List *pL)
{
	if (pL->Last==MaxLength)
		printf("Danh sach day");
	else if ((p<1) || (p>pL->Last+1))
		printf("Vi tri khong hop le");
	else {
	Position Q;
	for(Q=(pL->Last-1)+1;Q>p-1;Q--)
	pL->Elements[Q]=pL->Elements[Q-1];
	pL->Elements[p-1]=x;
	pL->Last++;
	}
}

//Tên hàm (function name): erase()

void erase(ElementType x, List *pL)
{
    deleteList(locate(x, *pL), pL);	// 2 ham nay cho truoc
}

//Tên hàm (function name): readSet() //ham  makenullList(List *pL)
									//ham int member(ElementType x, List L)
									//ham void insertSet(ElementType x, List *pL)
									/*de cho truoc 3 ham tren */

void deleteList(Position p, List *pL)
{
    if (p < 1 || p >= pL->Last)
    {
        
    }

    for (Position i = p; i < pL->Last; i++)
        pL->Elements[i - 1] = pL->Elements[i];

    pL->Last--;
}

Position endList(List list)
{
    return list.Last + 1;
}

void readList(List *pList)
{
    Position last;
    scanf("%d", &last);
    pList->Last = last;

    for (Position p = 1; p <= pList->Last; p++)
        scanf("%d", &pList->Elements[p - 1]);
}

void normalize(List *pList)
{
    for (int i = 0; i < pList->Last; i++)
        for (int j = i + 1; j < pList->Last; j++)
            if (pList->Elements[i] == pList->Elements[j])
            {
                deleteList(j + 1, pList);	// viet them ham deleteList
                j--;
            }
}

void readSet(List *pList)
{
    readList(pList);	//viet them 2 ham nay
    normalize(pList);
}

//Tên hàm (function name): locate()	/* viet them ham retrieve*/

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

//Tên hàm (function name): intersection()	//ham makenullList(List *pL)
											//ham int member(ElementType x, List L)
											//void insertSet(ElementType x, List *pL)
//de cho truoc 3 ham

void intersection(List L1, List L2, List *pL)
{
    makenullList(pL);
    for (int i = 0; i < L1.Last; i++)
        if (member(L1.Elements[i], L2))
            insertSet(L1.Elements[i], pL);
}

// ham Tên hàm (function name): copyEvenNumbers()
//hàm chép toàn bo cac so chan trong danh sách L1 sang danh sách ket qua

void copyEvenNumbers(List L1, List *pL2)
{
    pL2->Last = 0;
    for (int i = 0; i < L1.Last; i++)
        if (L1.Elements[i] % 2 == 0)
        {
            pL2->Elements[pL2->Last] = L1.Elements[i];
            pL2->Last++;
        }
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

