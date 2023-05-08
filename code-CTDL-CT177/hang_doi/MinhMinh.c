#include "PIQueue.c"
#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d", &n);

    char action;
    int param;

    Queue list;
    makenullQueue(&list);

    // danh sach tham so;
    Queue params;
    makenullQueue(&params);

    // danh sach so luong;
    Queue lengths;
    makenullQueue(&lengths);

    for ( i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &action);
        switch (action)
        {
        case 'D':
            if (emptyQueue(list))
            {
                enQueue(-1, &params);
                enQueue(0, &lengths);
            }
            else
            {
                enQueue(front(list), &params);
                deQueue(&list);
                enQueue(count(list), &lengths);
            }
            break;
        case 'E':
            scanf("%d", &param);
            enQueue(param, &list);
            enQueue(101, &params);
            enQueue(count(list), &lengths);
            break;
        }
    }
    while (!(emptyQueue(params) && emptyQueue(lengths)))
    {
        if (front(params) == 101)
            printf("%d\n", front(lengths));
        else
            printf("%d %d\n", front(params), front(lengths));
        deQueue(&params);
        deQueue(&lengths);
    }
    return 0;
}
