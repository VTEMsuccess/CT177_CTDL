
// khai bao ngan xep

#define MaxLength <n>
typedef <kdl> ElementType;
typedef struct{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;


// ham kiem tra Ngan Xep co rong ktRong(NganXep S)

int ktRong(NganXep S)
{
    return S.Dinh == SoPhanTu;
}

//ham kiem tra Stack day ktDay(NganXep S)

int ktDay(NganXep S)
{
    return S.Dinh == 0;
}

// ham hien thi Stack  hienthi(NganXep *pS)

void hienthi(NganXep *pS)
{
    for (int i = pS->Dinh; i < SoPhanTu; i++)
        printf("%d ", pS->DuLieu[i]);
}

//ham gia tri dinh	giatriDinh(NganXep S)

int giatriDinh(NganXep S)
{
    return S.DuLieu[S.Dinh];
}

//Ham xoa phan tu tai vi tri dinh cua ngan Xep xoa(NganXep *pS)

void xoa(NganXep *pS)
{
    if (pS->Dinh == SoPhanTu)
        return;
    pS->Dinh++;
}

//khoi tao ngan xep rong khoitao(NganXep *pS)
void khoitao(NganXep *pS)
{
    pS->Dinh = SoPhanTu;
}

//them pt x vao vi tri dinh cua ngan xep boi con tro pS them(int x, NganXep *pS)

void them(int x, NganXep *pS)
{
    if (pS->Dinh == 0)
        return;
    pS->Dinh--;
    pS->DuLieu[pS->Dinh] = x;
}

// khoi tao mot Stack rong makenullStack(Stack *pS)

void makenullStack(Stack *pS)
{
    pS->Top_idx = MaxLength;
}

//kiem tra Stack rong emptyStack(Stack S)

int emptyStack(Stack S)
{
    return S.Top_idx == MaxLength;
}

//kiem tra Stack day fullStack(Stack S)

int fullStack(Stack S)
{
    return S.Top_idx == 0;
}

//tra ve gia tri dinh top(Stack S)

ElementType top(Stack S)
{
    return S.Elements[S.Top_idx];
}

//Xoa pt o dau pop(Stack S)

void pop(Stack *pS)
{
    pS->Top_idx++;
}

//chen them pt vao dinh push(ElementType x, Stack *pS)

void push(ElementType x, Stack *pS)
{
    pS->Top_idx--;
    pS->Elements[pS->Top_idx] = x;
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





































