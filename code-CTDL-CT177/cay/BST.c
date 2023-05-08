
/*cac ham duyet Tien-Trung-Hau Tu cua BST giong voi cay nhi phan*/

//ham duyet Hau Tu
void postOrder(Tree T)
{
    if (T == NULL)
        return;
    postOrder(T->Left);
    postOrder(T->Right);			// cho Data thay bang kdl de bai yeu cau
    printf("%.. ", T->Data);		// thay %d - %c - %s theo yeu cau de bai
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
//ham duyet tien tu
void preOrder(Tree T)
{
    if (T == NULL)
        return;
    printf("%.. ", T->Data);	// thay %d - %c - %s theo yeu cau de bai
    preOrder(T->Left);
    preOrder(T->Right);			// cho Data thay bang kdl de bai yeu cau
  		
}


//khai bao cay tim kiem nhi phan
typedef <kdl> KeyType;
struct Node{
	KeyType key;
	struct Node* Left, *Right;
};	
typedef struct Node* Tree;
	
//ham tim kiem nut CHA cua nut co khoa x trong cay tim kiem nhi phan
Tree getParent(int x, Tree root)
{
    if (root == NULL)
        return NULL;

    if (x < root->Key)
    {
        if (root->Left == NULL)
            return NULL;
        if (root->Left->Key == x)
            return root;
        return getParent(x, root->Left);
    }

    if (root->Right == NULL)
        return NULL;
    if (root->Right->Key == x)
        return root;
    return getParent(x, root->Right);
}

//ham tra ve con tro dung truoc nut co khoa X trong phep duyet Trung Tu
	//gia su x chac chan co cay T
	
Tree leftest(Tree T)	//cay con trai nhat
{
    if (T == NULL)
        return NULL;
    if (T->Left == NULL)
        return T;
    return leftest(T->Left);
}
Tree rightest(Tree T)	//cay con phai nhat
{
    if (T == NULL)
        return NULL;

    if (T->Right == NULL)
        return T;
    return rightest(T->Right);
}
Tree getPrevious(int x, Tree T){
     if (T == NULL)
        return NULL;
    if (T->Key == x)
        if (T->Left != NULL)
            return rightest(T->Left); //viet them ham rightest neu chua co

    Tree lrest = leftest(T->Right); // viet them ham leftest neu chua co

    if (lrest != NULL)
        if (lrest->Key == x)
            return T;

    if (x < T->Key)
        return getPrevious(x, T->Left);
    return getPrevious(x, T->Right);
}

//ham tinh chieu cao  cay tim kiem nhi phan giong voi cay nhi phan
int getHeight(Tree T)
{
    if (T == NULL)
        return -1;
    int lh = getHeight(T->Left);
    int rh = getHeight(T->Right);

    return 1 + (lh > rh ? lh : rh);
}

int hNode(int x, Tree T)
{
    if (T == NULL)
        return getHeight(T);

    if (T->Key == x)
        return getHeight(T);

    if (x < T->Key)
        return hNode(x, T->Left);
    return hNode(x, T->Right);
}


//ham kiem tra cay BST co goc T co rong hay khong. Giong voi ham cay nhi phan
int isEmpty(Tree T){
    return T==NULL;
}

//ham tra ve 1 cay rong
Tree inittree(){
	return NULL;
}
//Xóa mot nút có khóa là x trong cây tìm kiem nhi phân
int deleteMax(Tree *pT)
{
    if ((*pT)->Right == NULL)
    {
        int key = (*pT)->Key;
        (*pT) = (*pT)->Left;
        return key;
    }
    return deleteMax(&((*pT)->Right));
}

//ham xoa mot nut co khoa x trong cay BST
void deleteNode(int x, Tree *pT)
{
    if (*pT == NULL)
        return;
    if ((*pT)->Key != x)
    {
        if ((*pT)->Key > x)
            return deleteNode(x, &((*pT)->Left));
        return deleteNode(x, &((*pT)->Right));
    }
    if ((*pT)->Left == NULL || (*pT)->Right == NULL)
    {
        *pT = NULL;
        return;
    }

    if ((*pT)->Left == NULL)
    {
        *pT = (*pT)->Right;
        return;
    }

    if ((*pT)->Left == NULL)
    {
        *pT = (*pT)->Left;
        return;
    }

    (*pT)->Key = deleteMax(&((*pT)->Left));
}

//tim kiem nut anh em ruot phai cua nut co khoa x trong cay BST
//neu muon tim ham leftSibling thi chi sua lai ty
Tree rightSibling(int x, Tree root)
{
    if (root == NULL || root->Left == NULL)
        return NULL;

    if (root->Left->Key == x)
        return root->Right;

    if (x < root->Key)
        return rightSibling(x, root->Left);
    return rightSibling(x, root->Right);
}

//Thêm khóa X vào cây tìm kiem nhi phân chi boi con tro pT
void insertNode(int x, Tree *pRoot)
{
    if (*pRoot == NULL)
    {
        (*pRoot) = (Tree)malloc(sizeof(struct Node));
        (*pRoot)->Left = NULL;
        (*pRoot)->Right = NULL;
        (*pRoot)->Key = x;
        return;
    }
    if (x == (*pRoot)->Key)
        return;
    if (x < (*pRoot)->Key)
        return insertNode(x, &((*pRoot)->Left));

    return insertNode(x, &((*pRoot)->Right));
}

//ham tim kiem khoa x trong cay tim kiem nhi phan
Tree searchNode(int x, Tree root)
{
    if (root == NULL)
        return NULL;
    else if (x < root->Key)
        return searchNode(x, root->Left);
    else if (x > root->Key)
        return searchNode(x, root->Right);
    else
        return root;
}
//liet ke cac gia tri khoa tren duong di, tim kiem 1 khoa x trong cay BST
void printPath(int x, Tree T){
    if (T==NULL)
    {
        printf("-> Khong thay");
        return ;
    }
    printf("%d ", T->Key);
    if (T->Key==x)
    {
        printf("-> Tim thay");
        return ;
    }
    if (x < T->Key)
        return printPath(x, T->Left);
    return printPath(x, T->Right);
}

























 







