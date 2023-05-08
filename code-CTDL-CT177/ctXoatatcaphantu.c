#include <stdio.h>
#include "ThuVienDsdac.c"

void readList(List *pL)
{	int i;
    makenullList(pL);
    int n, e;
    scanf("%d", &n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &e);
        insertList(e, pL->Last + 1, pL);
    }
}
void printList(List L)
{	Position p;
    for ( p = 1; p <= L.Last; p++)
        printf("%d ", retrieve(p, L)); // viet them ham retrieve neu chua co

    printf("\n");
}
int member(ElementType x, List list)
{	int i;
    for ( i = 1; i <= list.Last; i++)
        if (x == retrieve(i, list))
            return 1;
    return 0;
}
void removeAll(ElementType x, List *pL)
{
    while (member(x, *pL))
        deleteList(locate(x, *pL), pL);
}

int main()
{
    List list;
    readList(&list);
    printList(list);

    ElementType x;
    scanf("%d", &x);
    removeAll(x, &list);
    printList(list);

    return 0;
}
