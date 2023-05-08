//khai bao hang doi bang DSLK

#include <stdlib.h>

typedef int ElementType;	//ElementType là kieu so nguyen

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;

typedef struct
{
    Position Front, Rear;
} Queue;
 /* mot so phep toan */
 
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

//xoa pt o dau hang

void deQueue(Queue *pQ)
{
    pQ->Front = pQ->Front->Next;
}

//them pt x vao cuoi hang

void enQueue(ElementType x, Queue *pQ)
{
    pQ->Rear->Next = (Position)malloc(sizeof(struct Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next = NULL;
}

//dem so luong pt trong hang

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

//DE CHO TRUOC CAC HAM PHIA DUOI
/*	
	void makenullQueue(Queue *pQ)
	int emptyQueue(Queue Q)
	ElementType front(Queue Q)
	void deQueue(Queue *pQ)
	void enQueue(ElementType x, Queue *pQ)  //ElementType là kieu so thuc
*/

// hãy viet chuong trình giai mã mot thông diep bang khóa lap lai

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "PQueue.c"

//khai bao hang doi bang DSLK

#include <stdlib.h>

typedef float ElementType;		//ElementType là kieu so thuc

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;

typedef struct
{
    Position Front, Rear;
} Queue;


int main()
{
    char hash[512];
    char key[100];

    fgets(hash, 511, stdin);
    fflush(stdin);
    fgets(key, 99, stdin);
    fflush(stdin);

    hash[strlen(hash) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    Queue Q;
    makenullQueue(&Q);
    for (int i = 0; i < strlen(key); i++)
        enQueue(key[i] - 48, &Q);

    for (int i = 0; i < strlen(hash); i++)
    {
        printf("%c", hash[i] - front(Q));
        enQueue(front(Q), &Q);
        deQueue(&Q);
    }

    return 0;
}


//	CAC HAM DE CHO TRUOC O PHIA DUOI

/*
	void makenullStack(Stack *pS)
	int emptyStack(Stack S)
	ElementType top(Stack S)
	void pop(Stack *pS)
	void push(ElementType x, Stack *pS)
	
	void makenullQueue(Queue *pQ)
	int emptyQueue(Queue Q)
	ElementType front(Queue Q)
	void deQueue(Queue *pQ)
	void enQueue(ElementType x, Queue *pQ) //ElementType là kieu ký tu

*/

//viet chuong trình kiem tra mot chuoi ký tu có doc xuôi và doc nguoc nhu nhau hay không (kiem tra chuoi palindrome).

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "AStack.c"
#include "CAQueue.c"


typedef char ElementType;	//ElementType là kieu ky tu

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;

typedef struct
{
    Position Front, Rear;
} Queue;


int isAb(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    char s[256];
    fgets(s, 255, stdin);
    s[strlen(s) - 1] = '\0';

    Stack S;
    makenullStack(&S);

    Queue Q;
    makenullQueue(&Q);

    // Dua vo ngan xep va hang doi
    for (int i = 0; i < strlen(s); i++)
        if (isAb(s[i]))
        {
            push(tolower(s[i]), &S);
            enQueue(tolower(s[i]), &Q);
        }

    // Kiem tra
    while (!emptyQueue(Q))
    {
        if (top(S) != front(Q))
        {
            printf("\"%s\" doc xuoi khac doc nguoc\n", s);
            return 0;
        }
        deQueue(&Q);
        pop(&S);
    }

    printf("\"%s\" doc xuoi va doc nguoc nhu nhau\n", s);

    return 0;
}














