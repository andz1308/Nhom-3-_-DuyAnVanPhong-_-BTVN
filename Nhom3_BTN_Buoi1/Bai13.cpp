#include <stdio.h>

#define MAX_SIZE 100 // Định nghĩa kích thước tối đa cho mảng

void nhapMang(int a[], int b[], int n);
void xuatMang(int a[], int b[], int n);
void chiaMang(int a[], int b[], int n);

int main() {
    int n;
    printf("Nhap so luong phan tu trong mang (toi da %d): ", MAX_SIZE);
    scanf_s("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("So luong phan tu phai trong khoang 1 den %d.\n", MAX_SIZE);
        return 1;
    }

    int a[MAX_SIZE];
    int b[MAX_SIZE];

    nhapMang(a, b, n);
    printf("Mang a va b:\n");
    xuatMang(a, b, n);

    printf("Ket qua phep chia:\n");
    chiaMang(a, b, n);

    return 0;
}

void nhapMang(int a[], int b[], int n) {
    printf("Nhap cac phan tu mang a:\n");
    for (int i = 0; i < n; i++) {
        printf("a[%d]: ", i);
        scanf_s("%d", &a[i]);
    }

    printf("Nhap cac phan tu mang b:\n");
    for (int i = 0; i < n; i++) {
        printf("b[%d]: ", i);
        scanf_s("%d", &b[i]);
    }
}

void xuatMang(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        printf("a[%d] = %d, b[%d] = %d\n", i, a[i], i, b[i]);
    }
}

void chiaMang(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (b[i] == 0) {
            printf("Phep chia a[%d] / b[%d] bi loi: chia cho 0.\n", i, i);
        }
        else {
            double ketQua = (double)a[i] / b[i];
            printf("a[%d] / b[%d] = %.2f\n", i, i, ketQua);
        }
    }
}
