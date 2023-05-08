
//bài 1 Minh Minh
//Tính so don vi thoi gian can thiet cua Minh Minh de hoàn thành n công viec duoc giao
#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef struct{
	Position Front, Rear;
} Queue;
void makenullQueue(Queue *pQ){
	Position Header;
	Header=(struct Node*)malloc(sizeof(struct Node));
	Header->Next=NULL;
	pQ->Front=Header;
	pQ->Rear=Header;
}
int emptyQueue(Queue Q){
	return (Q.Front==Q.Rear);
}
void enQueue(ElementType x,Queue *pQ){
	pQ->Rear->Next = (struct Node*)malloc(sizeof(struct Node));
	pQ->Rear=pQ->Rear->Next;
	pQ->Rear->Element=x;
	pQ->Rear->Next = NULL;
}
void deQueue(Queue *pQ){
	if (!emptyQueue(*pQ)){
		Position Tempt;
		Tempt = pQ->Front;
		pQ->Front=pQ->Front->Next;
		free(Tempt);
	}
	else
		printf("Loi!, hang doi rong.");
}
ElementType front (Queue Q){
	if (emptyQueue(Q))
		return -999;
	else
		return (Q.Front->Next->Element);
}
int solan(){
	int dem = 0;
	Queue P,Q;
	makenullQueue(&P);
	makenullQueue(&Q);
	int n,t;
	scanf("%d",&n);
	int i;
	for (i=0;i<n;i++){
		scanf("%d",&t);
		enQueue(t,&P);
	}
	for (i=0;i<n;i++){
		scanf("%d",&t);
		enQueue(t,&Q);
	}
	while (!emptyQueue(Q)){
		if (front(P)==front(Q)){
			dem++;
			deQueue(&P);
			deQueue(&Q);
		}
		else{
			t = front(P);
			deQueue(&P);
			enQueue(t,&P);
			dem++;
		}
	}
	return dem;
}
int main(){
    printf("%d",solan());
}

/////////////////////////////////////////////////////////

//bai 2 Minh Minh có mot hàng doi Q và cô ay muon thuc hien N thao tác, moi thao tác là mot trong 2 dang sau:

#include<stdio.h>
#include<string.h>
#define MaxLength 50
typedef int ElementType;
typedef struct{
	ElementType Elements[MaxLength];	
	int Front;
	int Rear;
} Queue;
void makenullQueue(Queue *pQ){
	pQ->Front=-1;
	pQ->Rear =-1;
}
int emptyQueue(Queue Q){
	return (Q.Front==-1);
}
int fullQueue(Queue Q){
	return (Q.Rear-Q.Front+1==MaxLength);
}
ElementType front (Queue Q){
	if (emptyQueue(Q))
		return -999;
	else
		return (Q.Elements[Q.Front]);
}
int deQueue(Queue *pQ ){
	if (emptyQueue(*pQ))
		return 0;
	else{
		pQ->Front++;
		if (pQ->Front>pQ->Rear)
			makenullQueue(pQ);
		return 1;
		}
}
void enQueue(ElementType x, Queue *pQ){
	if (!fullQueue(*pQ)){
		if (emptyQueue(*pQ))	pQ->Front=0;
		if (pQ->Rear==MaxLength-1){
			int i;
			for (i=pQ->Front;i<=pQ->Rear;i++)
				pQ->Elements[i-pQ->Front]=pQ->Elements[i];
			pQ->Rear = MaxLength -1 - pQ->Front;
			pQ->Front=0;
		}
		pQ->Rear++;
		pQ->Elements[pQ->Rear]=x;
	}
	else
		printf("Loi, Hang day! ");
}
int soluongphantu(Queue Q){
	if (emptyQueue(Q))
		return 0;
	else
		return (Q.Rear-Q.Front)+1;
}
void thaotac1(int a,Queue *pQ){
		enQueue(a,pQ);
		printf("%d\n",soluongphantu(*pQ));
}
void thaotac2(Queue *pQ){
		ElementType a = pQ->Elements[pQ->Front];
		if (!deQueue(pQ))
			printf("-1 %d\n",soluongphantu(*pQ));
		else
			printf("%d %d\n",a,soluongphantu(*pQ));
}
int charToInt(char s[]){
	int t=0,i=2;
	while (s[i]!='\n'){ 
		t = t*10 + ((int)s[i]-48);
		i++;
	}
	return t;
}	
int main(){
	Queue Q;
	makenullQueue(&Q);
	int n;
	scanf("%d",&n);
	int i;
	for (i=1;i<=n;i++){
		char s[6];
		scanf(" ");
		fgets(s,7,stdin);
		if (s[0]-48=='E'-48)
			thaotac1(charToInt(s),&Q);
		if (s[0]-48=='D'-48)
			thaotac2(&Q);
	}
	return 0;
}

































