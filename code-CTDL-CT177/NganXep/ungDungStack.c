/*ung dung ngan xep*/


/*viet them ham hienthi(NganXep *pS)
viet them ham khoitao
viet them ham them*/	//neu de chua cho truoc

//ham chuyen so nguyen duong n ve nhi phan
void hienthi(NganXep *pS)
{
    for (int i = pS->Dinh; i < SoPhanTu; i++)
        printf("%d ", pS->DuLieu[i]);
}

void doiNhiPhan(int n, NganXep *pS)
{
    khoitao(pS);
    while (n != 0)
    {
        them(n % 2, pS);
        n /= 2;
    }
}

//ham readStack(Stack *pS)

void readStack(Stack *pS)
{
    makenullStack(pS);
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x, pS);
    }
}

//ham printStack(Stack *pS)

void printStack(Stack *pS)
{
    while (!emptyStack(*pS))
    {
        printf("%d ", top(*pS));
        pop(pS);
    }
    printf("\n");
}

//cho truoc cac ham phia duoi
/*	void makenullStack(Stack *pS)
	int emptyStack(Stack S)	
	ElementType top(Stack S) 
	void pop(Stack *pS) 
	void push(ElementType x, Stack *pS)*/

//ham ktChuoi()

int ktChuoi()
{
    char chuoi[100];
    fgets(chuoi, 100, stdin);
    fflush(stdin);
    chuoi[strlen(chuoi) - 1] = '\0';
    Stack S;
    makenullStack(&S);
    int length = strlen(chuoi);
    for (int i = 0; i < length; i++)
    {
        if (chuoi[i] == '(')
            push('(', &S);
        else if (chuoi[i] == ')')
        {
            if (emptyStack(S))
                return 0;
            pop(&S);
        }
    }
    return emptyStack(S);
}

/*	cho truoc cac ham
		void makenullStack(Stack *pS)
		int emptyStack(Stack S)	
		ElementType top(Stack S) 
		void pop(Stack *pS) 
		void push(ElementType x, Stack *pS) */
	
// viet ham tinhGiatri(char *chuoi)

float tinhGiatri(char *chuoi)
{
    Stack S;
    makenullStack(&S);
    int length = strlen(chuoi);

    for (int i = 0; i < length; i++)
    {
        if (chuoi[i] >= 48 && chuoi[i] <= 57)
            push((int)(chuoi[i] - 48), &S);
        else if (chuoi[i] == '+')
        {
            float a = top(S);
            pop(&S);
            float b = top(S);
            pop(&S);
            push(a + b, &S);
        }
        else if (chuoi[i] == '-')
        {
            float a = top(S);
            pop(&S);
            float b = top(S);
            pop(&S);
            push(b - a, &S);
        }
        else if (chuoi[i] == '*')
        {
            float a = top(S);
            pop(&S);
            float b = top(S);
            pop(&S);
            push(a * b, &S);
        }
        else if (chuoi[i] == '/')
        {
            float a = top(S);
            pop(&S);
            float b = top(S);
            pop(&S);
            push(b / a, &S);
        }
    }
    return top(S);
}
//cho truoc ham
/*	makenullStack
	push
	emptyStack
	pop
	top	*/
//viet ham inThaplucphan(int n)

void inThaplucphan(int n)
{
    char Hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    Stack S;
    makenullStack(&S);
    while (n != 0)
    {
        push(Hex[n % 16], &S);
        n /= 16;
    }
    while (!emptyStack(S))
    {
        printf("%c", top(S));
        pop(&S);
    }
}


//ham chuyenHauto(char *trungto, char *hauto)

//ham xac dinh muc uu tien cua cac toan tu 	+	 -	 *	 /
int mucUutien(char op){
   if (op=='+' || op=='-')
       return 1;
   else if (op=='*' || op=='/')
       return 2;
}

	///ham isNumber
	//ham isAb					de chua cho thi viet them cac ham nay
	//ham pushChar
	//ham isOP 

int isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

int isAb(char c)
{
    return (c >= 'a' && c <= 'z');
}

void pushChar(char c, char *s)
{

    s[strlen(s) + 1] = '\0';
    s[strlen(s)] = c;
}

int isOP(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


void chuyenHauto(char *trungto, char *hauto)
{
    hauto[0] = '\0';
    Stack S;
    makenullStack(&S);
    for (int i = 0; i < strlen(trungto); i++)
    {
        if (trungto[i] == ' ')
        {
        }
        else if (isNumber(trungto[i]) || isAb(trungto[i]))
            pushChar(trungto[i], hauto);
        else if (trungto[i] == '(')
            push('(', &S);
        else if (trungto[i] == ')')
        {
            while (top(S) != '(')
            {
                pushChar(top(S), hauto);
                pop(&S);
            }
            pop(&S);
        }
        else if (isOP(trungto[i]))
        {
            while (!emptyStack(S) && top(S) != '(' && mucUutien(trungto[i]) <= mucUutien(top(S)))
            {
                pushChar(top(S), hauto);
                pop(&S);
            }
            push(trungto[i], &S);
        }
    }
    while (!emptyStack(S))
    {
        pushChar(top(S), hauto);
        pop(&S);
    }
}


























