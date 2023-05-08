#include<stdio.h>
#define Maxlenght 1000
typedef int ElementType;
typedef int Position;
typedef struct {
	ElementType Elements[Maxlenght];
	Position Last;
} List;

void printList(List L){
	if (L.Last==0)
		return ;	
		
	else{
		Position P=1;
		while (P<=L.Last){
			printf("%d ",L.Elements[P-1]);
			P++;
		}
	}
	printf("\n");
}
int main(){
	List L;
	printList(L);
	return 0;
}
