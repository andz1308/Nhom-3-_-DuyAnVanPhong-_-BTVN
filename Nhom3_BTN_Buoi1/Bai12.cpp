#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc phân số
typedef struct {
    int tu;   // Tử số
    int mau;  // Mẫu số
} PhanSo;

// Hàm tính giá trị phân số dưới dạng số thực để so sánh
float giaTri(PhanSo ps) {
    return (float)ps.tu / ps.mau;
}

// Hàm tìm phân số lớn nhất và nhỏ nhất
void timLonNhatNhoNhat(PhanSo* mang, int n, PhanSo* lonNhat, PhanSo* nhoNhat) {
    if (n <= 0) {
        printf("Danh sach phan so rong.\n");
        return;
    }

    *lonNhat = *nhoNhat = mang[0];

    for (int i = 1; i < n; i++) {
        if (giaTri(mang[i]) > giaTri(*lonNhat)) {
            *lonNhat = mang[i];
        }
        if (giaTri(mang[i]) < giaTri(*nhoNhat)) {
            *nhoNhat = mang[i];
        }
    }
}

// Hàm xóa phần tử tại vị trí k
void xoaPhanTu(PhanSo* mang, int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    for (int i = k; i < *n - 1; i++) {
        mang[i] = mang[i + 1];
    }
    (*n)--;
}

// Hàm thêm phần tử x tại vị trí k
void themPhanTu(PhanSo* mang, int* n, int k, PhanSo x) {
    if (k < 0 || k > *n) {
        printf("Vi tri k khong hop le.\n");
        return;
    }
    for (int i = *n; i > k; i--) {
        mang[i] = mang[i - 1];
    }
    mang[k] = x;
    (*n)++;
}

// Các hàm đã định nghĩa trước đó
void nhapPhanSo(PhanSo* ps);
void xuatPhanSo(PhanSo ps);
void nhapMangPhanSo(PhanSo* mang, int n);
void xuatMangPhanSo(PhanSo* mang, int n);
void xuatPhanSoMauLonHonTu(PhanSo* mang, int n);
int demPhanSoChan(PhanSo* mang, int n);
void rutGonPhanSo(PhanSo* ps);
PhanSo tinhTichMangPhanSo(PhanSo* mang, int n);
PhanSo timPhanTuLonNhat(PhanSo* mang, int n);

int main()
{
    int n;
    printf("Nhap so luong phan so: ");
    scanf_s("%d", &n);

    PhanSo* mang = (PhanSo*)malloc(n * sizeof(PhanSo));

    nhapMangPhanSo(mang, n);

    printf("\nMang cac phan so vua nhap:\n");
    xuatMangPhanSo(mang, n);

    xuatPhanSoMauLonHonTu(mang, n);

    int demChan = demPhanSoChan(mang, n);
    printf("So phan so co ca tu va mau deu chan: %d\n", demChan);

    for (int i = 0; i < n; i++) {
        rutGonPhanSo(&mang[i]);
    }

    printf("\nMang cac phan so sau khi rut gon:\n");
    xuatMangPhanSo(mang, n);

    PhanSo tich = tinhTichMangPhanSo(mang, n);
    printf("\nTich cac phan so trong mang sau khi rut gon: ");
    xuatPhanSo(tich);

    PhanSo lonNhat, nhoNhat;
    timLonNhatNhoNhat(mang, n, &lonNhat, &nhoNhat);
    printf("\nPhan so lon nhat trong mang: ");
    xuatPhanSo(lonNhat);
    printf("Phan so nho nhat trong mang: ");
    xuatPhanSo(nhoNhat);

    // Xóa phần tử tại vị trí k
    int k;
    printf("Nhap vi tri k de xoa: ");
    scanf_s("%d", &k);
    xoaPhanTu(mang, &n, k);
    printf("Danh sach phan so sau khi xoa:\n");
    xuatMangPhanSo(mang, n);

    // Thêm phần tử x tại vị trí k
    PhanSo x;
    printf("Nhap vi tri k de them: ");
    scanf_s("%d", &k);
    printf("Nhap phan so (tu so va mau so) de them: ");
    nhapPhanSo(&x);
    themPhanTu(mang, &n, k, x);
    printf("Danh sach phan so sau khi them:\n");
    xuatMangPhanSo(mang, n);

    free(mang);

    return 0;
}

// Các hàm đã định nghĩa trước đó (cần sửa lại và thêm vào để hoàn chỉnh)
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf_s("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf_s("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. Vui long nhap lai.\n");
        }
    } while (ps->mau == 0);
}

void xuatPhanSo(PhanSo ps) {
    printf("%d/%d\n", ps.tu, ps.mau);
}

void nhapMangPhanSo(PhanSo* mang, int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        nhapPhanSo(&mang[i]);
    }
}

void xuatMangPhanSo(PhanSo* mang, int n) {
    for (int i = 0; i < n; i++) {
        printf("Phan so thu %d: ", i + 1);
        xuatPhanSo(mang[i]);
    }
}

void xuatPhanSoMauLonHonTu(PhanSo* mang, int n) {
    printf("Cac phan so co mau lon hon tu so:\n");
    for (int i = 0; i < n; i++) {
        if (mang[i].mau > mang[i].tu) {
            xuatPhanSo(mang[i]);
        }
    }
}

int demPhanSoChan(PhanSo* mang, int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (mang[i].tu % 2 == 0 && mang[i].mau % 2 == 0) {
            dem++;
        }
    }
    return dem;
}

int timUCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void rutGonPhanSo(PhanSo* ps) {
    int ucln = timUCLN(ps->tu, ps->mau);
    ps->tu /= ucln;
    ps->mau /= ucln;
}

PhanSo tinhTichMangPhanSo(PhanSo* mang, int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu *= mang[i].tu;
        tich.mau *= mang[i].mau;
    }
    rutGonPhanSo(&tich);
    return tich;
}

PhanSo timPhanTuLonNhat(PhanSo* mang, int n) {
    PhanSo lonNhat = mang[0];
    for (int i = 1; i < n; i++) {
        if (mang[i].tu * lonNhat.mau > lonNhat.tu * mang[i].mau) {
            lonNhat = mang[i];
        }
    }
    return lonNhat;
}
