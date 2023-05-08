



// chuong trình kiem tra mot chuoi ký tu có doc xuôi và doc nguoc nhu nhau hay không (kiem tra chuoi palindrome).
	
//	DE CHO TRUOC CAC HAM PHIA DUOI

/*
	void makenullStack(Stack *pS)
	int emptyStack(Stack S)
	ElementType top(Stack S)
	void pop(Stack *pS)
	void push(ElementType x, Stack *pS)			
	
	void makenullQueue(Queue *pQ)
	int emptyQueue(Queue Q)
	ElementType front(Queue Q)
	void deQueue(Queue *pQ)
	void enQueue(ElementType x, Queue *pQ) //ElementType là kieu ký tu		*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "AStack.c"
#include "CAQueue.c"

int isAb(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    char s[256];
    fgets(s, 255, stdin);
    s[strlen(s) - 1] = '\0';

    Stack S;
    makenullStack(&S);

    Queue Q;
    makenullQueue(&Q);

    // Dua vo ngan xep va hang doi
    for (int i = 0; i < strlen(s); i++)
        if (isAb(s[i]))
        {
            push(tolower(s[i]), &S);
            enQueue(tolower(s[i]), &Q);
        }

    // Kiem tra
    while (!emptyQueue(Q))
    {
        if (top(S) != front(Q))
        {
            printf("\"%s\" doc xuoi khac doc nguoc\n", s);
            return 0;
        }
        deQueue(&Q);
        pop(&S);
    }

    printf("\"%s\" doc xuoi va doc nguoc nhu nhau\n", s);

    return 0;
}

//vi?t chuong trình mã hóa mot thông diep bang khóa lap lai.

//de cho truoc cac ham phia duoi

/*		VI DU "Hoc CTDL rat vui!".

	void makenullQueue(Queue *pQ)
	int emptyQueue(Queue Q)
	ElementType front(Queue Q)
	void deQueue(Queue *pQ)
	void enQueue(ElementType x, Queue *pQ)  //ElementType là kiEu sO thUc	*/
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PQueue.c"

int main()
{
    char pass[512];
    char key[100];

    fgets(pass, 511, stdin);
    fflush(stdin);
    fgets(key, 99, stdin);
    fflush(stdin);

    pass[strlen(pass) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    Queue Q;
    makenullQueue(&Q);
    for (int i = 0; i < strlen(key); i++)
        enQueue(key[i] - 48, &Q);

    for (int i = 0; i < strlen(pass); i++)
    {
        printf("%c", pass[i] + front(Q));
        enQueue(front(Q), &Q);
        deQueue(&Q);
    }

    return 0;
}

//vi?t chuong trình giai mã mot thông diep bang khóa lap lai.


//de cho truoc cac ham phia duoi

/*		Ví d? chuoi "Jxd#JVMM#yc}!y|k*".

	void makenullQueue(Queue *pQ)
	int emptyQueue(Queue Q)
	ElementType front(Queue Q)
	void deQueue(Queue *pQ)
	void enQueue(ElementType x, Queue *pQ)  //ElementType là kiEu sO thUc	*/
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PQueue.c"

int main()
{
    char hash[512];
    char key[100];

    fgets(hash, 511, stdin);
    fflush(stdin);
    fgets(key, 99, stdin);
    fflush(stdin);

    hash[strlen(hash) - 1] = '\0';
    key[strlen(key) - 1] = '\0';

    Queue Q;
    makenullQueue(&Q);
    for (int i = 0; i < strlen(key); i++)
        enQueue(key[i] - 48, &Q);

    for (int i = 0; i < strlen(hash); i++)
    {
        printf("%c", hash[i] - front(Q));
        enQueue(front(Q), &Q);
        deQueue(&Q);
    }

    return 0;
}

//viet chuong trình tính so quay thu ngân can phai mo tai siêu thi Coopmart Can Tho vào mot thoi diem cu the

// DE CHO TRUOC CAC HAM PHIA DUOI

	/*
		void makenullQueue(Queue *pQ)
		int emptyQueue(Queue Q)
		ElementType front(Queue Q)
		void deQueue(Queue*pQ)
		void enQueue(ElementType x, Queue *pQ)  //ElementType là kieu so nguyên
	*/

#include <stdio.h>
#include <stdlib.h>
#include "PIQueue.c"

// **** Dua thoi gian den cua khach vao hang ****
void lineUp(int letTime, int client, Queue *pQ)
{
    makenullQueue(pQ);
    for (int i = 1; i <= client; i++)
        enQueue(i * letTime, pQ);
}

// **** Dat lai thoi gian cho tung quay ****
void reset(int A[], int n)
{
    for (int i = 0; i < n; i++)
        A[i] = 0;
}

// **** Tinh tong thoi gian cho cua khach ****
int getTotalTime(int tranferTime, Queue *line, int cashiers[], int open)
{
    int totalTime = 0;
    while (!emptyQueue(*line))
    {
        for (int i = 0; i < open; i++)
        {
            if (emptyQueue(*line))
                break;
            if (cashiers[i] < front(*line))
                cashiers[i] = front(*line);
            totalTime += cashiers[i] - front(*line) + tranferTime;
            cashiers[i] += tranferTime;
            deQueue(line);
        }
    }
    return totalTime;
}

int main()
{
    // message template
    char info[] = "So quay: %d; Thoi gian cho trung binh: %.1f\n";
    char success[] = "=> Sieu thi se mo %d quay\n";
    char failed[] = "Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.\n";

    int client;      // so khach hang
    int maxCashier;  // so quay toi da
    int tranferTime; // thoi gian giao dich
    int letTime;     // thoi gian khach den
    int maxWaitTime; // thoi gian cho toi da

    scanf(
        "%d%d%d%d%d",
        &client,
        &maxCashier,
        &tranferTime,
        &letTime,
        &maxWaitTime);

    Queue line;
    int cashiers[maxCashier];
    int totalTime;

    for (int open = 1; open <= maxCashier; open++)
    {
        lineUp(letTime, client, &line);
        reset(cashiers, open);

        totalTime = getTotalTime(tranferTime, &line, cashiers, open);

        // **** In thong tin voi tung so luong quay ****
        printf(info, open, (float)(totalTime / client));

        // **** Ket luan neu so quay toi da dap ung yeu cau ****
        if (totalTime / client <= maxWaitTime)
        {
            printf(success, open);
            return 0;
        }
    }

    // **** Ket luan neu failed ****
    printf(failed, maxCashier, (float)(totalTime / client));

    return 0;
}
















































































