// khai bao cay nhi phan

typedef <kieuDuLieu> DataType;
struct Node{
	DataType Data;
	struct Node *Left, * Right;
};
typedef struct Node* Tree;

//ham tra ve mot cay rong
Tree initTree(){
    return NULL;
}

//ham kiem tra cay co goc la T co rong hay khong
int isEmpty(Tree T){
	return T==NUL
}

//ham duyet Tien Tu
void preOrder(Tree T)
{
    if (T == NULL)
        return;					// cho Data thay bang kdl de bai yeu cau
    printf("%.. ", T->Data);	// thay %d - %c - %s theo yeu cau de bai
    preOrder(T->Left);			
    preOrder(T->Right);
}

//ham duyet Trung Tu
void inOrder(Tree T)
{
    if (T == NULL)
        return;
    inOrder(T->Left);			// cho Data thay bang kdl de bai yeu cau
    printf("%.. ", T->Data);		// thay %d - %c - %s theo yeu cau de bai
    inOrder(T->Right);
}

//ham duyet Hau Tu
void postOrder(Tree T)
{
    if (T == NULL)
        return;
    postOrder(T->Left);
    postOrder(T->Right);			// cho Data thay bang kdl de bai yeu cau
    printf("%d ", T->Data);		// thay %d - %c - %s theo yeu cau de bai
}

//ham tao cay nhi phan tu gia tri x va hai cay con co san l,r
Tree createTree(int x, Tree l, Tree r)
{
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = l;
    T->Right = r;
    return T;
}

//ham tinh chieu cao cay nhi phan
int getHeight(Tree T)
{
    if (T == NULL)
        return -1;
    int lh = getHeight(T->Left);
    int rh = getHeight(T->Right);

    return 1 + (lh > rh ? lh : rh);
}

//ham dem so nut la cua cay nhi phan T
int getLeaves(Tree T)
{
    if (T == NULL)
        return 0;
    if (T->Left == NULL && T->Right == NULL)
        return 1;
    return getLeaves(T->Left) + getLeaves(T->Right);
}





































