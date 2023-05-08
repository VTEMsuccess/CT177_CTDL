#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int KeyType;
struct Node{
	KeyType Key;
	int Height;
	struct Node *Left,*Right;
};
typedef struct Node* AVLTree;

//ham in cac khoa cua nhung nut co cung chieu cao height
void printHeight(int height, AVLTree T){
    if (T!=NULL)
	{
	    if (T->Height==height) 
		printf("%d ",T->Key);
	    printHeight(height,T->Left);
	    printHeight(height,T->Right);
    }
}

//viet ham in ket qua duyet tien tu cay AVL
void printLRN(AVLTree T){
    if(T==NULL)
        return ;
    printLRN(T->Left);
    printLRN(T->Right);
    printf("(%d - %d); ", T->Key, getHeight(T));
}

// ham in khoa cua nhung nut la trong cay AVL
void printLeaves(AVLTree T){
    if (T!=NULL){
	    if (isLeaf(T))	printf("%d ",T->Key);
	    printLeaves(T->Left);
	    printLeaves(T->Right);
    }
}

//ham duyet tien tu cay AVL
void printNLR(AVLTree root)
{
    if (root == NULL)
        return;

    printf("(%d - %d); ", root->Key, getHeight(root));
    printNLR(root->Left);
    printNLR(root->Right);
}

//ham tim va tra ve nut co khoa Key trong cay AVL giong cay BST
AVLTree search(KeyType x, AVLTree T)
{
    if (T == NULL)
        return NULL;
    if (T->Key == x)
        return T;
    if ( x < T->Key )
       return search(x, T->Left);
    return search(x, T->Right);
     
}

//ham xac dinh nut la
int isLeaf(AVLTree T){	
	if (T!=NULL)
		return (T->Left==NULL&&T->Right==NULL);
	else
		return 0;
}

int getBalance(AVLTree root){
    if (root==NULL) return 0;
    else
        return getHeight(root->Left) - getHeight(root->Right);
}

/*
	int getHeight(AVLTree T){
	if (T==NULL)
		return -1;
	 else return T->Height;
}	

*/

// cai dat getHeight cach 2
 int getHeight(AVLTree T){
 	return T==NULL ? -1 : T->Height;
 }

//Set lai và tra ve chieu cao cho toàn bo cây có nút goc root
AVLTree setAllHeight(AVLTree root)
{
    if (root == NULL)
        return NULL;
    root->Left = setAllHeight(root->Left);
    root->Right = setAllHeight(root->Right);
    root->Height = 1 + max(getHeight(root->Left), getHeight(root->Right));
    return root;
}
 //cach2 viet ham rightRotate 
 AVLTree rightRotate(AVLTree T)
{
    if (T == NULL)
        return NULL;
    AVLTree leftChild = T->Left;
    AVLTree rightLeftChild = leftChild->Right;
    leftChild->Right = T;
    T->Left = rightLeftChild;

    return setAllHeight(leftChild);
}
 // cach 1 viet ham rightRotate
AVLTree rightRotate(AVLTree T){
	AVLTree temp = T->Left; // AVLTree kieu struct Node*
	T->Left = temp->Right;
	temp->Right = T;
	T->Height= 1+ max(getHeight(T->Left),getHeight(T->Right));
	temp->Height= 1+ max(getHeight(temp->Left),getHeight(temp->Right));
	return temp;
}



AVLTree leftRotate(AVLTree T){
	struct Node* temp = T->Right;
	T->Right = temp->Left;
	temp->Left = T;
	T->Height= 1+ max(getHeight(T->Left),getHeight(T->Right));
	temp->Height= 1+ max(getHeight(temp->Left),getHeight(temp->Right));
	return temp;
}

//ham xuw ly truong hop can bang ben phai cua con trai (R - L)

AVLTree leftrightRotate(AVLTree T){
	T->Left = leftRotate(T->Left);
	return rightRotate(T);
}

//ham xuw ly truong hop can bang ben trai cua con phai (L - R)

AVLTree rightleftRotate(AVLTree T){
	T->Right = rightRotate(T->Right);
	return leftRotate(T);
}

//ham xem nut co khoa Key vao cay AVL
AVLTree insertNode(KeyType Key, AVLTree T){
	if(T == NULL){
    	T = (struct Node*)malloc(sizeof(struct Node));
	    T->Key = Key;
	    T->Height = 0;
    	T->Left = NULL;
    	T->Right = NULL;
    }
	else if (Key < T->Key)
		T->Left = insertNode(Key,T->Left);
		else if (Key > T->Key) 
			T->Right = insertNode(Key,T->Right);
	T->Height = max(getHeight(T->Left),getHeight(T->Right))+1;
	int balance = getBalance(T);
	if (balance > 1 && Key < T->Left->Key)
		return rightRotate(T);
	if (balance > 1 && Key > T->Left->Key)
		return leftrightRotate(T);
	if (balance < -1 && Key > T->Right->Key)
		return leftRotate(T);
	if (balance < -1 && Key < T->Right->Key)	
		return rightleftRotate(T);
	return T;
}

//viet ham isAVL kiem tra xem co la cay AVL hay khoong
int isAVL(AVLTree T){
	if(T==NULL)
	    return 1; // true
    if(getBalance(T)>1 || getBalance(T)<-1)
	    return 0; // false
	else
		return isAVL(T->Left) && isAVL(T->Right);
}
