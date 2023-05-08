//Bang cách su dung nhung phép toán  trên danh sách, hãy vi?t chuong trình cho phép li?t kê các so le, so chan trong danh sách

#include<stdio.h>
#define Maxlenght 1000
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
} List;
void makenullList(List *pL){
	(*pL).Last=0;
}
Position first(List L) {
	return 1;
}
Position endList(List L) {
	return L.Last+1;
}
void insertList(ElementType x, Position P, List *pL) {
	if ((*pL).Last==Maxlenght)
		printf("Danh sach day\n");
	else if (0>P||P>(*pL).Last+1)
			printf("Vi tri khong hop le\n");
		else {
			Position Q;
			for (Q=(*pL).Last+1;Q>=P;Q--)
				(*pL).Elements[Q]=(*pL).Elements[Q-1];
			(*pL).Elements[P-1]=x;
			(*pL).Last++;
		}
}
ElementType retrive(Position P,List L){
	return L.Elements[P-1];
}
void printList(List L){
	if (L.Last==0)	
		printf("Danh sach rong");
	else{
		Position P=1;
		while (P<=L.Last){
			printf("%d ",L.Elements[P-1]);
			P++;
		}
	}
	printf("\n");
}
void inList(int n,List *pL){
	int a,i=0;
	while(i<n){
		scanf("%d",&a);
		(*pL).Elements[i]=a;
		i++;
	}
	(*pL).Last=n;
}
void lietkesole(List L){
	int i;
	for (i=first(L);i<=endList(L);i++)
		if (retrive(i,L)%2!=0)	printf("%d ",retrive(i,L));	
}
void chepsochan(List L,List *pL2){
	Position i,i2=1;
	for (i=first(L);i<=endList(L);i++)
		if (retrive(i,L)%2==0){
			insertList(retrive(i,L),i2,pL2);
			i2++;
		}
	(*pL2).Last=i2-2;
}
int main(){
	int n;
	scanf("%d",&n);
	List L,L2;
	makenullList(&L);
	makenullList(&L2);
	inList(n,&L);
	printList(L);
	lietkesole(L);
	chepsochan(L,&L2);printf("\n");
	printList(L2);
}

//////////////////////////////////

//Bang cách su dung nhung phép toán  trên danh sách, hãy viet chuong trình cho phép tìm tap hop giao cuaa 2 danh sách bieu dien tap hop

#include<stdio.h>
#define Maxlenght 1000
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
} List;
void makenullList(List *pL){
	(*pL).Last=0;
}
Position first(List L) {
	return 1;
}
Position endList(List L) {
	return L.Last+1;
}
void insertList(ElementType x, Position P, List *pL) {
	if ((*pL).Last==Maxlenght)
		printf("Danh sach day\n");
	else if (0>P||P>(*pL).Last+1)
			printf("Vi tri khong hop le\n");
		else {
			Position Q;
			for (Q=(*pL).Last+1;Q>=P;Q--)
				(*pL).Elements[Q]=(*pL).Elements[Q-1];
			(*pL).Elements[P-1]=x;
			(*pL).Last++;
		}
}
void deleteList(Position P,List *pL){
	if (P<1||P>(*pL).Last)
		printf("Vi tri khong hop le\n");
	else if ((*pL).Last==0)	
			printf("Danh sach rong\n");
		 else {
		 	Position Q;
		 	for (Q=P;Q<=(*pL).Last;Q++)
		 		(*pL).Elements[Q-1]=(*pL).Elements[Q];
		 	(*pL).Last--;
		 }
}
ElementType retrive(Position P,List L){
	return L.Elements[P-1];
}
void xoaphantutrung(List *pL){
	Position i,j;
	for (i=0;i<=(*pL).Last;i++){
		if (i==0)
			for (j=1;j<=(*pL).Last;j++)
				if ((*pL).Elements[i]==(*pL).Elements[j]){
					deleteList(j+1,pL);
					j--;
				}
		if (i>0&&i<(*pL).Last){
				for (j=0;j<i;j++)
					if ((*pL).Elements[i]==(*pL).Elements[j]){
						deleteList(j+1,pL);
						j--;
				}
				for (j=i+1;j<=(*pL).Last;j++)
					if ((*pL).Elements[i]==(*pL).Elements[j]){			
							deleteList(j+1,pL);
							j--;
						}
				}
		if (i==(*pL).Last)
			for (j=0;j<(*pL).Last;j++)
				if ((*pL).Elements[i]==(*pL).Elements[j]){	
					deleteList(j+1,pL);		
					j--;
				}
	}
}
void printList(List L){
	if (L.Last==0)	;
		//printf("Danh sach rong");
	else{
		Position P=1;
		while (P<=L.Last){
			printf("%d ",L.Elements[P-1]);
			P++;
		}
	}
	printf("\n");
}
void inList(int n,List *pL){
	int a,i=0;
	while(i<n){
		scanf("%d",&a);
			(*pL).Elements[i]=a;
		i++;
	}
	(*pL).Last=i;
}
void Hieu2danhsach(List L1,List L2,List *pL3){
	Position i,j,n=1;
	for (i=first(L1);i<=endList(L1);i++)
		for (j=first(L2);j<=endList(L2);j++)
			if (retrive(i,L1)==retrive(j,L2)){
				insertList(retrive(i,L1),n,pL3);
				n++;
			}
	(*pL3).Last=n-2;
}
int main(){
	List L1,L2,L3;
	makenullList(&L1);
	makenullList(&L2);
	makenullList(&L3);
	int m,n;
	scanf("%d",&m);
	inList(m,&L1);xoaphantutrung(&L1);
	scanf("%d",&n);
	inList(n,&L2);xoaphantutrung(&L2);
	printList(L1);
	printList(L2);
	Hieu2danhsach(L1,L2,&L3);
	printList(L3);
}

///////////////////////////////////////////////////

//Bang cách su dung nhung phép toán  trên danh sách, hãy viet chuong trình cho phép tính trung bình cong các phan tu trong danh sách


#include<stdio.h>
#define Maxlenght 1000
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
} List;
void makenullList(List *pL){
	(*pL).Last=0;
}
void printList(List L){
	if (L.Last==0)	
		printf("Danh sach rong");
	else{
		Position P=1;
		while (P<=L.Last){
			printf("%d ",L.Elements[P-1]);
			P++;
		}
	}
	printf("\n");
}
void inList(int n,List *pL){
	int a,i=0;
	while(i<n){
		scanf("%d",&a);
		(*pL).Elements[i]=a;
		i++;
	}
	(*pL).Last=n;
}
float trungbinhcong(List L){
	Position i;
	float s=0;
	for (i=0;i<=L.Last;i++)
		s=s+L.Elements[i];
	return s/L.Last;
}
int main(){
	List L;
	makenullList(&L);
	int n;
	scanf("%d",&n);
	inList(n,&L);
	printList(L);
	printf("%.03f",trungbinhcong(L));
}

///////////////////////////////////////////////////////////////

//Hãy viet hàm ElementType minList(List L) 
ElementType minList(List list)
{
    ElementType min = list.Elements[0];
    for (int i = 0; i < list.Last; i++)
        if (min > list.Elements[i])
            min = list.Elements[i];
    return min;
}

//////////////////////////////////////////////////////////

// hãy viet chuong trình cho phép xóa tat ca các phan tu x trong danh sách

#include<stdio.h>
#define Maxlenght 50
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
} List;
void makenullList(List *pL){
	(*pL).Last=0;
}
void deleteList(Position P,List *pL){
	if (P<1||P>(*pL).Last)
		printf("Vi tri khong hop le\n");
else if ((*pL).Last==0)	
			printf("Danh sach rong\n");
		 else {
		 	Position Q;
		 	for (Q=P;Q<=(*pL).Last;Q++)
		 		(*pL).Elements[Q-1]=(*pL).Elements[Q];
		 	(*pL).Last--;
		 }
}
void printList(List L){
	if (L.Last==0)	
		;
	else{
		Position P=1;
		while (P<=L.Last){
			printf("%d ",L.Elements[P-1]);
			P++;
		}
	}
	printf("\n");
}
void inList(int n,List *pL){
	int a,i=0;
	while(i<n){
		scanf("%d",&a);
		(*pL).Elements[i]=a;
		i++;
	}
	(*pL).Last=n;
}
void xoatatcaphantuX(ElementType x,List *pL){
	Position i;
	for (i=0;i<=(*pL).Last;i++){
		if (x==(*pL).Elements[i]){
			deleteList(i+1,pL);
			i--;
		}
	}
}
int main(){
	List L;
	makenullList(&L);
	int n,x;
	scanf("%d",&n);
	inList(n,&L);
	scanf("%d",&x);
	printList(L);
	xoatatcaphantuX(x,&L);
	printList(L);
	return 0;
}

//////////////////////////////////////////////////////////

// hãy viet chuong trình cho phép tìm tap hop hop cua 2 danh sách bieu dien tap hop

#include<stdio.h>
#define Maxlenght 1000
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
} List;
void makenullList(List *pL){
	(*pL).Last=0;
}
Position first(List L) {
	return 1;
}
Position endList(List L) {
	return L.Last+1;
}
void insertSet(int x,List *pL){
    pL->Elements[(*pL).Last]=x;
    (*pL).Last++;
}
ElementType retrive(Position P,List L){
	return L.Elements[P-1];
}
Position locate(ElementType x,List L){
	Position P=1;
	while (P!=L.Last+1){
		if (x==L.Elements[P-1])	return P;
		else
			P++;
	}
	return P;
}
void deleteList(Position P,List *pL){
	if (P<1||P>(*pL).Last+1)
		printf("Vi tri khong hop le\n");
	else if ((*pL).Last==0)	
			printf("Danh sach rong\n");
		 else {
		 	Position Q;
		 	for (Q=P;Q<=(*pL).Last;Q++)
		 		(*pL).Elements[Q-1]=(*pL).Elements[Q];
		 	(*pL).Last--;
		 }
}
int member(ElementType x,List L){
    int i;
    for (i=0;i<=L.Last;i++)
        if (x==L.Elements[i])   return 1;
    return 0;
}
void xoaphantutrung(List *pL){
	Position i,j;
	for (i=0;i<=(*pL).Last;i++){
		if (i==0)
			for (j=1;j<=(*pL).Last;j++)
				if ((*pL).Elements[i]==(*pL).Elements[j]){
					deleteList(j+1,pL);
					j--;
				}
		if (i>0&&i<(*pL).Last){
				for (j=0;j<i;j++)
					if ((*pL).Elements[i]==(*pL).Elements[j]){
						deleteList(j+1,pL);
						j--;
				}
				for (j=i+1;j<=(*pL).Last;j++)
					if ((*pL).Elements[i]==(*pL).Elements[j]){			
							deleteList(j+1,pL);
							j--;
						}
				}
		if (i==(*pL).Last)
			for (j=0;j<(*pL).Last;j++)
				if ((*pL).Elements[i]==(*pL).Elements[j]){	
					deleteList(j+1,pL);		
					j--;
				}
	}
}
void printList(List L){
	if (L.Last==0)	
		printf("Danh sach rong");
	else{
		Position P=1;
		while (P<=L.Last){
			printf("%d ",L.Elements[P-1]);
			P++;
		}
	}
	printf("\n");
}
void inList(int n,List *pL){
	int a,i=0;
	while(i<n){
		scanf("%d",&a);
			(*pL).Elements[i]=a;
		i++;
	}
	(*pL).Last=i;
}
void unionSet(List L1,List L2,List *pL){
    makenullList(pL);
    int i;
    for (i=0;i<L1.Last;i++)				
	insertSet(L1.Elements[i],pL);
    for (i=0;i<L2.Last;i++)
        if (!member(L2.Elements[i],L1)) 
            insertSet(L2.Elements[i],pL);
}
int main(){
	List L1,L2,L3;
	makenullList(&L1);
	makenullList(&L2);
	makenullList(&L3);
	int m,n;
	scanf("%d",&m);
	inList(m,&L1);
	scanf("%d",&n);
	inList(n,&L2);
	xoaphantutrung(&L1);
	xoaphantutrung(&L2);
	printList(L1);
	printList(L2);
	unionSet(L1,L2,&L3);
	printList(L3);	
}				

//hãy viet chuong trình cho phép tìm HIEU cua 2 danh sách bieu dien tap hop	

#include<stdio.h>
#define Maxlenght 1000
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
}List;

void deleteList(Position p, List *pL)
{
    if (p < 1 || p >= pL->Last)
    {
        
    }

    for (Position i = p; i < pL->Last; i++)
        pL->Elements[i - 1] = pL->Elements[i];

    pL->Last--;
}

Position endList(List L)
{
    return L.Last + 1;
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
                deleteList(j + 1, pList);	
                j--;
            }
}

void readSet(List *pList)
{
    readList(pList);	
    normalize(pList);
}

ElementType retrieve(Position i, List L)
{
        return L.Elements[i - 1];
}

void printList(List L)
{	Position p;
    for ( p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L)); 

    printf("\n");
}
int member(ElementType x, List L)
{	int i;
    for ( i = 1; i <= L.Last; i++)
        if (x == retrieve(i, L))
            return 1;
    return 0;
}

void insertSet(ElementType x, List *pL)
{
    pL->Elements[pL->Last] = x;
    pL->Last++;
}
void makenullList(List *pL)
{
    pL->Last = 0;
}

void difference(List L1, List L2, List *pL)
{	int i;
    makenullList(pL);
    for ( i = 0; i < L1.Last; i++)
        if (!member(L1.Elements[i], L2))
            insertSet(L1.Elements[i], pL);
}


int main()
{
    List L1,L2,L3;

    readSet(&L1);
    readSet(&L2);

    difference(L1, L2, &L3);

    printList(L1);
    printList(L2);
    printList(L3);

    return 0;
}		

//				
				
				
				
				
				
				
				
				
				
				
