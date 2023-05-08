




// hãy vi?t chuong trình cho phép tìm tap hop hop cua 2 danh sách bieu dien tap hop

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


//vi?t chuong trình cho phép liet kê các so chan và tính trung bình cong các phan tu là so chan trong danh sách
#include "PListLib.c"
void readList(List *pL)
{
    makenullList(pL);
    int n;
    Position P = *pL,N;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        P->Next = N;
        P = P->Next;
    }
}
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
void append(ElementType x, List *pL)
{
    Position P = endList(*pL);
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}
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
int main()
{
    List L;
    readList(&L);
    printList(L);
    copyEvenNumbers(L, &L);
    printList(L);
    printf("%.3f", getAvg(L));
    return 0;
}

//vi?t chuong trình cho phép tính trung bình cong các phan tu trong danh sách
#include <stdio.h>
#include "PListLib.c"
typedef int ElementType; // kieu cua phan tu du lieu

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position; // kieu vi tri
typedef Position List;

void readList(List *pL)
{
    makenullList(pL);
    int n;
    Position P = *pL,N;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        P->Next = N;
        P = P->Next;
    }
}
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
int main()
{
    List L;
    readList(&L);
    printList(L);
    printf("%.3f", getAvg(L));
    return 0;

}

//vi?t chuong trình cho phép xóa phan tu x xuat hien dau tiên trong danh sách
#include "PListLib.c"
void readList(List *pL)
{
    makenullList(pL);
    int n;
    Position P = *pL,N;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        P->Next = N;
        P = P->Next;
    }
}
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
void erase(ElementType x, List *pL)
{
    if (locate(x, *pL)->Next != NULL)
        deleteList(locate(x, *pL), pL);
}

int main()
{
    List L;
    readList(&L);
    printList(L);
    ElementType x;
    scanf("%d", &x);
    erase(x, &L);
    printList(L);
    return 0;
}

//vi?t chuong trình cho phép nhap và hien thi mot danh sách so nguyên tu bàn phím
#include "PListLib.c"

void readList(List *pL)
{
    makenullList(pL);
    int n;
    Position P = *pL,N;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        P->Next = N;
        P = P->Next;
    }
}
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
int main()
{
    List L;
    readList(&L);
    printList(L);
    return 0;
}

/////////////////////////////////////////////////////////////////



// hãy viet chuong trình cho phép liet kê các so le, so chan trong danh sách

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



//hãy viet chuong trình cho phép tìm tap hop giao cua 2 danh sách bieu dien tap hop

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

//chuong trinh cho phep xoa tat ca phan tu x trong danh sach
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






























