//khai bao kdl danh sach sinh vien
typedef struct
{
    char ID[10], Name[50];
    float R1, R2, R3;
} Student;

struct Node
{
    Student Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef struct Node *List;

//chen them 1 Sinh Vien vao cuoi phan tu
int append(Student s, List *pL)
{
    List P = *pL;
    while (P->Next != NULL)
    {
        if (strcmp(s.ID, P->Next->Element.ID) == 0)
            return 0;
        P = P->Next;
    }
    P->Next = (List)malloc(sizeof(struct Node));
    strcpy(P->Next->Element.ID, s.ID);
    strcpy(P->Next->Element.Name, s.Name);
    P->Next->Element.R1 = s.R1;
    P->Next->Element.R1 = s.R2;
    P->Next->Element.R1 = s.R3;
    return 1;
}
//tao 1 danh sach sinh vien rong
List getList()
{
    List L;
    L = (List)malloc(sizeof(struct Node));
    return L;
}
//ham tra ve danh sach sinh vien chua dat
List getFailedList(List L)
{
	 List S = L,
         FL = getList();
    int a;
    while (S->Next != NULL)
    {
        if ((S->Next->Element.R1 + S->Next->Element.R2 + S->Next->Element.R3) / 3 < 4)
            a = append(S->Next->Element, &FL);
        S = S->Next;
    }
    a++;
    return FL;
}       

//ham tra ve vi tri dau tien cua Sinh vien co ID la ID
List locate(char ID[], List L)
{
    List P = L;
    while (P->Next != NULL)
    {
        if (strcmp(ID, P->Next->Element.ID) == 0)
            return P;
        P = P->Next;
    }
    return P;
}
//ham in danh sach sinh vien
void printList(List L)
{
    List P = L;
    int i = 1;
    while (P->Next != NULL)
    {
        printf("%2d -", i);
        printf("%11s -", P->Next->Element.ID);
        printf("%51s - ", P->Next->Element.Name);
        printf("%.3f - ", P->Next->Element.R1);
        printf("%.3f - ", P->Next->Element.R2);
        printf("%.3f - ", P->Next->Element.R3);
        printf("%.3f\n", (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
        P = P->Next;
        i++;
    }
}
//Ham hien thi danh sach cac sinh vien dat
void showPassedList(List L)
{
    List P = L;
    int i = 1;
    while (P->Next != NULL)
    {
        if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 >= 4)
        {
            printf("%2d -", i);
            printf("%11s -", P->Next->Element.ID);
            printf("%51s - ", P->Next->Element.Name);
            printf("%.3f - ", P->Next->Element.R1);
            printf("%.3f - ", P->Next->Element.R2);
            printf("%.3f - ", P->Next->Element.R3);
            printf("%.3f\n", (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
            i++;
        }
        P = P->Next;
    }
    printf("%d students in total", i - 1);
}
/////////////////////////////////////////////////////////
#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*Khai báo danh sách sinh viên và mot so hàm cho truoc*/
//ham getList
//ham append
//ham readList
//ham printList

typedef struct
{
    char ID[10], Name[50];
    float R1, R2, R3;
} Student;

struct Node
{
    Student Element;
    struct Node *Next;
};

typedef struct Node *Position;
typedef struct Node *List;

void makenullList(List *pL)
{
    *pL = (List)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

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

List getFailedList(List L)
{
	 List S = L,
         FL = getList();
    int a;
    while (S->Next != NULL)
    {
        if ((S->Next->Element.R1 + S->Next->Element.R2 + S->Next->Element.R3) / 3 < 4)
            a = append(S->Next->Element, &FL);
        S = S->Next;
    }
    a++;
    return FL;
}
	
int main()
{
	List L1, L2;
        L1=readList();
	printList(L1);	
         L2=getFailedList(L1);
         printList(L2);
         return 0;
}

/////////////////////////////////
// chuong trình cho phép hien thi danh sách sinh viên ÐaT (tuc diem trung bình >= 4)





#include<stdio.h>
#include<malloc.h>
#include<string.h>

/*Khai báo danh sách sinh viên và mot so hàm cho truoc*/
//ham getList
//ham append
//ham readList
//ham printList

void showPassedList(List L)
{
	void showPassedList(List L)
{
    List P = L;
    int i = 1;
    while (P->Next != NULL)
    {
        if ((P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3 >= 4)
        {
            printf("%2d -", i);
            printf("%11s -", P->Next->Element.ID);
            printf("%51s - ", P->Next->Element.Name);
            printf("%.3f - ", P->Next->Element.R1);
            printf("%.3f - ", P->Next->Element.R2);
            printf("%.3f - ", P->Next->Element.R3);
            printf("%.3f\n", (P->Next->Element.R1 + P->Next->Element.R2 + P->Next->Element.R3) / 3);
            i++;
        }
        P = P->Next;
    }
    printf("%d students in total", i - 1);
}
	//Duy?t qua danh sách L và hi?n th? nh?ng SV d?t (di?m tb >=4)
	/*Khi hi?n th? thì tính luôn di?m t?ng h?p v?i di?m t?ng h?p là trung bình c?ng c?a R1, R2, R3*/
	
}
	
int main()
{
	List L=readList();
	printList(L);       
         showPassedList(L);
        return 0;
}


























