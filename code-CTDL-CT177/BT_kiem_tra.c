// ham calculateExpr
float calculateExpr(Tree T){
    if(T!=NULL){
        if(T->Data>='0' && T->Data<='9') return (float)(T->Data-'0');
            
        float a = calculateExpr(T->Left);
        float b = calculateExpr(T->Right);
        switch(T->Data){
            case'-': return a-b;
            case'+': return a+b;
            case'*':return a*b;
            case'/': return a/b;
            case'%': return (a)/b-1.5;
           
        } return (float)a/b;
        
    }
    return 0;
}
//
#include "AListLib.c"
int main(){
    List *pL;
    int n;
    Position p, q;
    ElementType x, temp;
    scanf("%d", &n);
    pL->Last = n;
    for(p = 1; p <= n; p++){
        scanf("%d", &x);
		pL->Element[p-1] = x;
    }
    for(p = 1; p <= n; p++){
        printf("%d ", pL->Elements[p-1]);
    }
    for(p = 1; p <= n; p++){
        for(q= p + 1; q <= n; q++){
            if(pL->Elements[p] > pL->Elements[q]){
                temp = pL->Elements[p];
                pL->Elements[p] = pL->Elements[q];
                pL->Elements[q] = temp;
            }
        }
    }
    for(p = 1; p <= n; p++){
        printf("%d ", pL->Elements[p-1]);
    }    
    return 0;
}

//
void printNodes(Tree T,int h){
	if(T!=NULL){
		if(getHeight(T) == h)
			printf("%c ",T->Data);
		printNodes(T->Left,h);
		printNodes(T->Right,h);
	}
}

// khai bao
struct Node{
    int Khoa, Cao;
    struct Node* Trai;
    struct Node* Phai;
};
typedef struct Node* Tree;

//ham updateBalance
int max(int a,int b){
	return a > b ? a : b;
}
int getHeight(Tree T){	
	if (T==NULL)
		return -1;
	else
	    return 1 + max(getHeight(T->Left),getHeight(T->Right));
}
void updateBalance(Tree *pT){
	if ((*pT)!=NULL){
		updateBalance(&((*pT)->Left));
		updateBalance(&((*pT)->Right));
		(*pT)->Balance = getHeight((*pT)->Left) - getHeight((*pT)->Right);
	}
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

//ham countNodes
int getBalance(AVLTree root){
    if (root==NULL) return 0;
    else
        return getHeight(root->Left) - getHeight(root->Right);
}

int count = 0;
int countNodes(AVLTree T){
	if(T!=NULL){
		if(getBalance(T) > 1  || getBalance(T) < -1){
			printf("%d ",T->Key);
			count++;
		}
		countNodes(T->Left);
		countNodes(T->Right);
	}
}
//
Tree findLMOperand (Tree T) {
    if (T==NULL)
        return NULL;
    if (T->Data >= '0' && T->Data <= '9')
        return T;
    
    findLMOperand(T->Right);
    if (findLMOperand(T->Left) != NULL) {
        return findLMOperand(T->Left);
    } else {
        return findLMOperand(T->Left);
    }
}


//

int count = 0;
int findLevel(KeyType x,Tree Root){
	if(Root == NULL) return 0;
	else if(Root->Key == x) return count;
	else if(x<Root->Key) {
		count++;
		return findLevel(x,Root->Left);
	}
	else {
		count++;
		return findLevel(x,Root->Right);	
	}
}
//
Tree findRMOperand (Tree T) {
    if (T==NULL)
        return NULL;
    if (T->Data >= '0' && T->Data <= '9')
        return T;
    
    findRMOperand(T->Right);
    if (findRMOperand(T->Right) != NULL) {
        return findRMOperand(T->Right);
    } else {
        return findRMOperand(T->Left);
    }
}
//
void updateLevel(Tree *pT, Tree T) {
    if(!emptyTree(*pT))
    {
        (*pT)->Level = countNodes((*pT)->Key, T) - 1;
        updateLevel(&((*pT)->Left), T);
        updateLevel(&((*pT)->Right), T);
    }
}
//
int isExprTree(Tree T) {
    if(emptyTree(T))
        return 0;
    else
    {
        if(isLeaf(T))
            return isLeaf(T) && isOperand(T->Data);
        else
        {
            return isOperator(T->Data) && isExprTree(leftChild(T)) && isExprTree(rightChild(T));
        }
    }
}
