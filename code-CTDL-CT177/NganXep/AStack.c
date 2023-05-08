// khai bao ngan xep

#define MaxLength <n>
typedef <kdl> ElementType;
typedef struct{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;

/*	 mot so phep toan Stack	*/

//khoi tao mot Stack rong

void makenullStack(Stack *pS)
{
    pS->Top_idx = MaxLength;
}

//ham kiem tra Stack co rong hay khong

int emptyStack(Stack S)
{
    return S.Top_idx == MaxLength;
}

//ham tra ve gia tri dinh Stack

ElementType top(Stack S)
{
    return S.Elements[S.Top_idx];
}

//ham xoa pt o dau Stack

void pop(Stack *pS)
{
    pS->Top_idx++;
}

//ham them pt vao dinh Stack

void push(ElementType x, Stack *pS)
{
    pS->Top_idx--;
    pS->Elements[pS->Top_idx] = x;
}

//kiem tra Stack day hay khong

int fullStack(Stack S)
{
    return S.Top_idx == 0;
}


//ham in Stack ra man hinh

void printStack(Stack *pS)
{
    while (!emptyStack(*pS))
    {
        printf("%d ", top(*pS));
        pop(pS);
    }
    printf("\n"); 
}





