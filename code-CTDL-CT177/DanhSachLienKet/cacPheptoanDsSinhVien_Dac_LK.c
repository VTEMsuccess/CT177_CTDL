

//KHAI BAO DA THUC CHACH 2
typedef struct
{
    double he_so;
    int bac;
} DonThuc;
struct Node
{
    DonThuc e;
    struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;

//IN DA THUC
void inDaThuc(DaThuc d)
{
    DaThuc P = d;
    while (P->Next != NULL)
    {
        printf("%.3fX^%d", P->Next->e.he_so, P->Next->e.bac);
        if (P->Next->Next != NULL)
            printf(" + ");
        P = P->Next;
    }
    printf("\n");
}

//CHEN DON THUC
void chenDonThuc(DonThuc x, DaThuc *pD)
{
    Position P = *pD;
    while (P->Next != NULL)
    {
        if (P->Next->e.bac == x.bac)
        {
            P->Next->e.he_so = P->Next->e.he_so + x.he_so;
            return;
        }
        if (P->Next->e.bac < x.bac)
        {
            Position T = (Position)malloc(sizeof(struct Node));
            T->e = x;
            T->Next = P->Next;
            P->Next = T;
            return;
        }
        P = P->Next;
    }
    Position T = (Position)malloc(sizeof(struct Node));
    T->e = x;
    P->Next = T;
}

//CONG DA THUC
DaThuc congDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc D = khoitao();
    Position P = D1;
    while (P->Next != NULL)
    {
        chenDonThuc(P->Next->e, &D);
        P = P->Next;
    }
    P = D2;
    while (P->Next != NULL)
    {
        chenDonThuc(P->Next->e, &D);
        P = P->Next;
    }
    return D;
}

//DAO HAM
void daoHam(DonThuc *d)
{
    d->he_so = d->he_so * d->bac;
    d->bac--;
}



//HAM KHOI TAO KIEU TRA VE LA DA THUC
DaThuc khoitao()
{
    DaThuc D = (DaThuc)malloc(sizeof(DaThuc));
    D->Next = NULL;
    return D;
}

//HAM NHAN DA THUC
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2)
{
    DaThuc P = D1, Q;
    DaThuc Result = khoitao();
    DonThuc E;
    while (P->Next != NULL)
    {
        Q = D2;
        while (Q->Next != NULL)
        {
            E.he_so = P->Next->e.he_so * Q->Next->e.he_so;
            E.bac = P->Next->e.bac + Q->Next->e.bac;
            chenDonThuc(E, &Result);
            Q = Q->Next;
        }
        P = P->Next;
    }
    return Result;
}

//HAM NHAP DA THUC
DaThuc nhapDaThuc()
{
    int n;
    double hs;
    int bac;
    DonThuc d;
    DaThuc D = khoitao();
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %d", &hs, &bac);
        d.he_so = hs;
        d.bac = bac;
        chenDonThuc(d, &D);
    }
    return D;
}

//TINH DAO HAM
DaThuc tinhDaoHam(DaThuc D)
{
    DaThuc P = D;
    while (P->Next != NULL)
    {
        daoHam(&P->Next->e);
        P = P->Next;
    }
    return D;
}
/////////////////////////////////////////////////////////////////////////////////////


//DA THUC LA DANH SACH cua don thuc
struct DonThuc
{
    double he_so;
    int bac;
} ;

struct DaThuc
{
    DonThuc A[100];
    int so_luong;
};
//CHUOI LA DANH SACH CAC KY TU
typedef struct
{
    char c[80];
    int p;
} Line;

//DANH SACH CAC SO THUC FLOAT
typedef struct
{
    float c[100];
    int p;
} List;

// danh sach sinh vien
typedef struct
{
    char MSSV[10], hoVaTen[50];
    float LT, TH1, TH2;
} SinhVien;

typedef struct
{
    SinhVien A[40];
    int n;
} DanhSach;

//CAU TRUC Polygon
typedef struct
{
    int x, y;
} Point;

typedef struct
{
    Point c[100];
    int p;
} Polygon;

//ham danh sach rong
ifDanhSach dsRong()
{
    DanhSach D;
    D.n = 0;
    return D;
}
//ham kiem tra rong
int ktRong(DanhSach L){
    if (L.n==0)
        return 1;
    return 0;
}
//ham chen
void chenCuoi(struct SinhVien S, DanhSach *L)
{
    L->A[L->n] = S;
    L->n++;
}

//ham tim
int tim(char MSSV[10], DanhSach L)
{
    for (int i = 0; i < L.n; i++)
        if (strcmp(MSSV, L.A[i].MSSV) == 0)
            return i + 1;
    return L.n + 1;
}
//ham xoa tai
void xoaTai(int p, DanhSach *L)
{
    for (int i = p; i < L->n; i++)
        L->A[i - 1] = L->A[i];
    L->n--;
}
//ham hien thi
void hienthi(DanhSach danhSach)
{
    for (int i = 0; i < danhSach.n; i++)
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", danhSach.A[i].MSSV, danhSach.A[i].HoTen, danhSach.A[i].DiemLT, danhSach.A[i].DiemTH1, danhSach.A[i].DiemTH2, danhSach.A[i].DiemLT + danhSach.A[i].DiemTH1 + danhSach.A[i].DiemTH2);
}
//ham nhap
int length(char *string)
{
    int i = 0;
    while (string[i])
        i++;
    return i;
}

struct SinhVien nhapSV()
{
    struct SinhVien sinhVien;

    getchar();
    fgets(sinhVien.MSSV, 10, stdin);
    sinhVien.MSSV[length(sinhVien.MSSV) - 1] = '\0';
    fflush(stdin);

    fgets(sinhVien.HoTen, 50, stdin);
    sinhVien.HoTen[length(sinhVien.HoTen) - 1] = '\0';
    fflush(stdin);

    scanf("%f", &sinhVien.DiemLT);
    scanf("%f", &sinhVien.DiemTH1);
    scanf("%f", &sinhVien.DiemTH2);

    return sinhVien;
}

DanhSach nhap()
{
    DanhSach danhSach = dsRong();
    struct SinhVien sinhVien;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        sinhVien = nhapSV();
        if (tim(sinhVien.MSSV, danhSach) < 1 || tim(sinhVien.MSSV, danhSach) >= danhSach.n)
        {
            chenCuoi(sinhVien, &danhSach);
        }
    }
    return danhSach;
}

//ham chepkhongdat
float tongDiem(struct SinhVien S)
{
    return S.DiemLT + S.DiemTH1 + S.DiemTH2;
}

DanhSach chepKhongDat(DanhSach L)
{
    DanhSach _L = dsRong();
    for (int i = 0; i < L.n; i++)
        if (tongDiem(L.A[i]) < 4)
            chenCuoi(L.A[i], &_L);
    return _L;
}

//ham xoa sinh vien
void xoaSinhVien(char MSSV[10], DanhSach *pL)
{
    while (tim(MSSV, *pL) <= pL->n)
        xoaTai(tim(MSSV, *pL), pL);
}



