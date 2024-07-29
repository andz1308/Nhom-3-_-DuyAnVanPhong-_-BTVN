#include <stdio.h>

// Ham tinh tong, hieu, tich va thuong
void tinh_toan(int a, int b, int* tong, int* hieu, int* tich, float* thuong) {
    *tong = a + b;
    *hieu = a - b;
    *tich = a * b;
    *thuong = (b != 0) ? (float)a / b : 0.0; // Kiem tra chia cho 0
}

int main() {
    int a, b;
    int tong, hieu, tich;
    float thuong;

    // Nhap gia tri cho a va b
    printf("Nhap so a: ");
    scanf_s("%d", &a);
    printf("Nhap so b: ");
    scanf_s("%d", &b);

    // Tinh toan cac gia tri
    tinh_toan(a, b, &tong, &hieu, &tich, &thuong);

    // Xuat ket qua va dia chi cac o nho
    printf("Tong: %d, Dia chi: %p\n", tong, (void*)&tong);
    printf("Hieu: %d, Dia chi: %p\n", hieu, (void*)&hieu);
    printf("Tich: %d, Dia chi: %p\n", tich, (void*)&tich);
    printf("Thuong: %.2f, Dia chi: %p\n", thuong, (void*)&thuong);

    return 0;
}
