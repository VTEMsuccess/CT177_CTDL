#include <stdio.h>
#define MaxLength 300 // So phan tu toi da
typedef int ElementType; // Kieu du lieu cua phan tu
typedef int Position; // Position = index + 1

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;
ElementType retrieve(Position p, List list)
{
    if (!(p > list.Last))
        return list.Elements[p - 1];
    return 0;
}
int member(ElementType x, List list)
{	int i;
    for ( i = 1; i <= list.Last; i++)
        if (x == retrieve(i, list))
            return 1;
       
    return 0;
}
int main(){
	List L;
	int i;
	L.Last=0;
	for(i=0;i<5;i++)
	    L.Elements[i] = 2*i;
	L.Last=5;
	if(member(0,L))
	    printf("0 in L");
	else printf("0 not in L");

}
