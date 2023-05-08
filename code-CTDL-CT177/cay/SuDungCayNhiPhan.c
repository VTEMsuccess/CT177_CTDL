//Su dung cay nhi phan

///bai tap dung cay nhi phan Tien Tu_(N L R) va Trung Tu_(L N R)  

int CURRENT_INDEX = 0;

Tree createTree(char *pre, char *in, int start, int end)
{
    if (start > end)
        return NULL;
    Tree T = (Tree)malloc(sizeof(struct Node));
    if (start == end)
    {
        T->Data = pre[CURRENT_INDEX];
        T->Left = NULL;
        T->Right = NULL;
        CURRENT_INDEX++;
        return T;
    }
    T->Data = pre[CURRENT_INDEX];
    int i = findIndex(pre[CURRENT_INDEX], in, start, end);
    CURRENT_INDEX++;
    T->Left = createTree(pre, in, start, i - 1);
    T->Right = createTree(pre, in, i + 1, end);
    return T;
}

//ham findMin tim gia tri nho nhat cua cay nhi phan
int findMin(Tree T)
{
    if (T==NULL)
        return 0;
    if (isLeaf(T))
        return T->Data;
    int minLeft = findMin(T->Left);
    int minRight = findMin(T->Right);
    return minLeft < minRight ? minLeft : minRight;
}



//Ham findMax tim gia tri lon nhat cay nhi phan

int findMax(Tree T)
{
    if (T==NULL)
        return 0;
    if (isLeaf(T))
        return T->Data;
    int maxLeft = findMax(T->Left);
    int maxRight = findMax(T->Right);
    return maxLeft > maxRight ? maxLeft : maxRight;
}

/* ham findElement 
	xac dinh xem x co la gia tri cua nut trong cay nhi phan hay khoong */

Tree findElement(DataType x, Tree T)
{
    if (T == NULL || T->Data == x)
        return T;

    Tree lef = findElement(x, T->Left);
    Tree rig = findElement(x, T->Right);
    if (lef == NULL)
        return rig;
    return lef;
}

//ham getDiameter tinh ban kinh cua mot cay nhi phan
	// viet them ham tinh chieu cao neu de chua cho
int getHeight(Tree T)
{
    if (T == NULL || (T->Left == NULL && T->Right == NULL))
        return 0;
    int lh = getHeight(T->Left);
    int rh = getHeight(T->Right);

    return 1 + (lh > rh ? lh : rh);
}

//ham tinh duong kinh cua mot cay

void getDiameter(Tree T, int *r)
{
    if (T == NULL)
        return;

    *r = getHeight(T->Left) + getHeight(T->Right) + 3;	
}

// ham getFullNodes dem so nut co du hai con
	// viet them ham isLeaf kiem tra xem mot nut co phai nut la khong
int getFullNodes(Tree T)
{
    if (T == NULL || isLeaf(T))
        return 0;

    if (T->Left != NULL && T->Right != NULL)
        return 1 + getFullNodes(T->Left) + getFullNodes(T->Right);

    return getFullNodes(T->Left) + getFullNodes(T->Right);
}

// ham convertTree de chuyen doi mot cay nhi phan sang cay phan chieu cua no
Tree convertTree(Tree T)
{
    if (T == NULL)
        return NULL;

    Tree t = (Tree)malloc(sizeof(struct Node));
    t->Data = T->Data;
    t->Left = convertTree(T->Right);
    t->Right = convertTree(T->Left);

    return t;
}

// ham isMirrors kiem tra xem 2 cay co la phan chieu cua nhau khong
int isMirrors(Tree t1, Tree t2)
{
    if (t1 == NULL)
    {
        if (t2 == NULL)
            return 1;
        return 0;
    }
    if (t2 == NULL)
        return 0;
    if (t2->Data != t1->Data)
        return 0;
    return isMirrors(t1->Left, t2->Right) && isMirrors(t1->Right, t2->Left);
}

// viet them ham printArray in nd mang path co do dai len neu de chua cho
	
void printArray(int path[], int len){
 int i;
 for(i=0;i<len;i++)
    printf("%d",path[i]);
    printf("\n");
}

// ham printAllPaths hien thi tat ca cac duong di (tu nut goc den nut la)
	// co do dai duong di thoa dk cho truoc
void printAllPaths(Tree T, int path[], int len, int pathlen)
{
    if (T == NULL || len > pathlen + 1)
        return;
    path[len] = T->Data;
    len++;

    if (len == pathlen + 1 && isLeaf(T))
        printArray(path, len);

    printAllPaths(T->Left, path, len, pathlen);
    printAllPaths(T->Right, path, len, pathlen);
}







































