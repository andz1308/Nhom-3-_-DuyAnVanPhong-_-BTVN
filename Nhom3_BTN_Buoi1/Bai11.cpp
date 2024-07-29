#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void nhapM1C_SoNguyen(int** a, int* n);
void xuatM1C_SoNguyen(int* a, int n);
void timPhanTuLonNhat(int* a, int n, int* giaTriMax, int** diaChiMax);
void timDiaChiPhanTu(int* a, int n, int* diaChiChanMax, int* diaChiLeMin);
void xoaPhanTu(int** a, int* n, int viTriXoa);
void themPhanTu(int** a, int* n, int x);
int laSoChinhPhuong(int x);
int tinhTongSoChinhPhuong(int* a, int n);
void xuatSoCucDai(int* a, int n);

// Các hàm mới
void xuatSoCucTieu(int* a, int n);
void xoaPhanTuTaiViTriK(int** a, int* n, int k);
void themPhanTuTaiViTriK(int** a, int* n, int x, int k);
void chuyenSoChanLenDau(int** a, int* n);
int kiemTraChanLeXenKe(int* a, int n);

int main()
{
    int* arr;
    int size;
    nhapM1C_SoNguyen(&arr, &size);

    if (size > 0) {
        // Xuất các số cực tiểu trong mảng
        printf("Cac so cuc tieu trong mang la:\n");
        xuatSoCucTieu(arr, size);

        // Xóa phần tử tại vị trí k
        int k;
        printf("Nhap vi tri k de xoa: ");
        scanf_s("%d", &k);
        xoaPhanTuTaiViTriK(&arr, &size, k);
        printf("Mang sau khi xoa phan tu tai vi tri %d:\n", k);
        xuatM1C_SoNguyen(arr, size);

        // Thêm phần tử x tại vị trí k
        int x;
        printf("Nhap phan tu x de them: ");
        scanf_s("%d", &x);
        printf("Nhap vi tri k de them phan tu x: ");
        scanf_s("%d", &k);
        themPhanTuTaiViTriK(&arr, &size, x, k);
        printf("Mang sau khi them phan tu %d tai vi tri %d:\n", x, k);
        xuatM1C_SoNguyen(arr, size);

        // Chuyển số chẵn lên đầu mảng, số lẻ xuống cuối mảng
        chuyenSoChanLenDau(&arr, &size);
        printf("Mang sau khi chuyen so chan len dau, so le xuong cuoi:\n");
        xuatM1C_SoNguyen(arr, size);

        // Kiểm tra mảng có chứa chẵn lẻ xen kẽ không
        if (kiemTraChanLeXenKe(arr, size)) {
            printf("Mang co chua chan le xen ke.\n");
        }
        else {
            printf("Mang khong chua chan le xen ke.\n");
        }
    }
    else {
        printf("Mang khong co phan tu.\n");
    }

    free(arr);

    return 0;
}

void nhapM1C_SoNguyen(int** a, int* n) {
    *n = 10;
    *a = (int*)malloc(*n * sizeof(int));

    if (*a != NULL) {
        srand(time(NULL));
        for (int i = 0; i < *n; i++) {
            (*a)[i] = rand() % 100;
        }
    }
    else {
        printf("Loi: Khong the cap phat bo nho.\n");
        *n = 0;
    }
}

void xuatM1C_SoNguyen(int* a, int n) {
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d co gia tri %d va dia chi o nho la %p\n", i, a[i], (void*)&a[i]);
    }
}

void timPhanTuLonNhat(int* a, int n, int* giaTriMax, int** diaChiMax) {
    if (n <= 0) {
        printf("Loi: Mang khong co phan tu.\n");
        return;
    }

    *giaTriMax = a[0];
    *diaChiMax = &a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > *giaTriMax) {
            *giaTriMax = a[i];
            *diaChiMax = &a[i];
        }
    }
}

void timDiaChiPhanTu(int* a, int n, int* diaChiChanMax, int* diaChiLeMin) {
    *diaChiChanMax = -1;
    *diaChiLeMin = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            if (*diaChiChanMax == -1 || a[i] > a[*diaChiChanMax]) {
                *diaChiChanMax = i;
            }
        }
        else {
            if (*diaChiLeMin == -1 || a[i] < a[*diaChiLeMin]) {
                *diaChiLeMin = i;
            }
        }
    }

    if (*diaChiChanMax == -1) {
        printf("Khong co phan tu chan trong mang.\n");
    }
    if (*diaChiLeMin == -1) {
        printf("Khong co phan tu le trong mang.\n");
    }
}

void xoaPhanTu(int** a, int* n, int viTriXoa) {
    if (viTriXoa < 0 || viTriXoa >= *n) {
        printf("Loi: Vi tri xoa khong hop le.\n");
        return;
    }

    for (int i = viTriXoa; i < *n - 1; i++) {
        (*a)[i] = (*a)[i + 1];
    }

    *n = *n - 1;
    *a = (int*)realloc(*a, *n * sizeof(int));
}

void themPhanTu(int** a, int* n, int x) {
    *n = *n + 1;
    *a = (int*)realloc(*a, *n * sizeof(int));

    for (int i = *n - 1; i > 0; i--) {
        (*a)[i] = (*a)[i - 1];
    }

    (*a)[0] = x;
}

int laSoChinhPhuong(int x) {
    int squareRoot = (int)sqrt(x);
    return squareRoot * squareRoot == x;
}

int tinhTongSoChinhPhuong(int* a, int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (laSoChinhPhuong(a[i])) {
            sum += a[i];
        }
    }

    return sum;
}

void xuatSoCucDai(int* a, int n) {
    for (int i = 1; i < n - 1; i++) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            printf("Phan tu %d la so cuc dai.\n", a[i]);
        }
    }

    if (n > 1 && a[0] > a[1]) {
        printf("Phan tu %d la so cuc dai.\n", a[0]);
    }
    if (n > 1 && a[n - 1] > a[n - 2]) {
        printf("Phan tu %d la so cuc dai.\n", a[n - 1]);
    }
}

// Các hàm mới
void xuatSoCucTieu(int* a, int n) {
    for (int i = 0; i < n; i++) {
        if ((i == 0 && n > 1 && a[i] < a[i + 1]) ||
            (i == n - 1 && n > 1 && a[i] < a[i - 1]) ||
            (i > 0 && i < n - 1 && a[i] < a[i - 1] && a[i] < a[i + 1])) {
            printf("Phan tu %d la so cuc tieu.\n", a[i]);
        }
    }
}

void xoaPhanTuTaiViTriK(int** a, int* n, int k) {
    if (k < 0 || k >= *n) {
        printf("Loi: Vi tri xoa khong hop le.\n");
        return;
    }

    xoaPhanTu(a, n, k);
}

void themPhanTuTaiViTriK(int** a, int* n, int x, int k) {
    if (k < 0 || k > *n) {
        printf("Loi: Vi tri them khong hop le.\n");
        return;
    }

    *n = *n + 1;
    *a = (int*)realloc(*a, *n * sizeof(int));

    for (int i = *n - 1; i > k; i--) {
        (*a)[i] = (*a)[i - 1];
    }

    (*a)[k] = x;
}

void chuyenSoChanLenDau(int** a, int* n) {
    int* temp = (int*)malloc(*n * sizeof(int));
    if (temp == NULL) {
        printf("Loi: Khong the cap phat bo nho.\n");
        return;
    }

    int chanIndex = 0;
    int leIndex = *n - 1;

    for (int i = 0; i < *n; i++) {
        if ((*a)[i] % 2 == 0) {
            temp[chanIndex++] = (*a)[i];
        }
    }

    for (int i = 0; i < *n; i++) {
        if ((*a)[i] % 2 != 0) {
            temp[leIndex--] = (*a)[i];
        }
    }

    free(*a);
    *a = temp;
}

int kiemTraChanLeXenKe(int* a, int n) {
    if (n < 2) return 0;

    int chan = (a[0] % 2 == 0);
    for (int i = 1; i < n; i++) {
        if ((a[i] % 2 == 0) == chan) {
            return 0;
        }
        chan = !chan;
    }

    return 1;
}
