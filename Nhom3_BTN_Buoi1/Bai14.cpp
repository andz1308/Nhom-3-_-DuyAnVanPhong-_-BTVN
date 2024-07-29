#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Hàm tính thời gian nghỉ hưu
void tinhThoiGianNghiHuu(int namHienTai, int tuoiHuuNam, int tuoiHuuNu,
    int ngay, int thang, int nam, const char* gioiTinh) {

    int tuoi = namHienTai - nam;

    // Kiểm tra giới tính và tuổi để tính thời gian nghỉ hưu
    if (strcmp(gioiTinh, "nam") == 0) {
        if (tuoi >= tuoiHuuNam) {
            int namNghiHuu = nam;
            int thangNghiHuu = thang;

            // Tính thời gian nghỉ hưu theo năm hiện tại
            if (namHienTai >= 2025) {
                namNghiHuu += tuoiHuuNam;
                thangNghiHuu += 3;
            }
            else if (namHienTai >= 2024) {
                namNghiHuu += tuoiHuuNam;
                thangNghiHuu += 6;
            }
            else if (namHienTai >= 2023) {
                namNghiHuu += tuoiHuuNam;
                thangNghiHuu += 9;
            }
            else if (namHienTai >= 2022) {
                namNghiHuu += tuoiHuuNam;
                thangNghiHuu += 4;
            }
            else if (namHienTai >= 2021) {
                namNghiHuu += tuoiHuuNam;
                thangNghiHuu += 3;
            }

            // Điều chỉnh năm và tháng nếu tháng vượt quá 12
            while (thangNghiHuu > 12) {
                thangNghiHuu -= 12;
                namNghiHuu++;
            }

            printf("Thoi gian ban duoc nghi huu thang %02d/%d.\n", thangNghiHuu, namNghiHuu);
        }
        else {
            printf("Tuoi hien tai khong du de nghi huu.\n");
        }
    }
    else if (strcmp(gioiTinh, "nu") == 0) {
        if (tuoi >= tuoiHuuNu) {
            int namNghiHuu = nam;
            int thangNghiHuu = thang;

            // Tính thời gian nghỉ hưu theo năm hiện tại
            if (namHienTai >= 2025) {
                namNghiHuu += tuoiHuuNu;
                thangNghiHuu += 8;
            }
            else if (namHienTai >= 2024) {
                namNghiHuu += tuoiHuuNu;
                thangNghiHuu += 4;
            }
            else if (namHienTai >= 2023) {
                namNghiHuu += tuoiHuuNu;
                thangNghiHuu += 9;
            }
            else if (namHienTai >= 2022) {
                namNghiHuu += tuoiHuuNu;
                thangNghiHuu += 8;
            }
            else if (namHienTai >= 2021) {
                namNghiHuu += tuoiHuuNu;
                thangNghiHuu += 4;
            }

            // Điều chỉnh năm và tháng nếu tháng vượt quá 12
            while (thangNghiHuu > 12) {
                thangNghiHuu -= 12;
                namNghiHuu++;
            }

            printf("Thoi gian ban duoc nghi huu thang %02d/%d.\n", thangNghiHuu, namNghiHuu);
        }
        else {
            printf("Tuoi hien tai khong du de nghi huu.\n");
        }
    }
    else {
        printf("Gioi tinh khong hop le. Vui long nhap 'nam' hoac 'nu'.\n");
    }
}

int main() {
    char hoTen[MAX_NAME_LENGTH];
    char gioiTinh[5];
    int ngay, thang, nam;
    int namHienTai = 2024; // Giả sử năm hiện tại là 2024

    // Nhập thông tin từ người dùng
    printf("Nhap ho ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    // Xóa ký tự newline thừa nếu có
    size_t len = strlen(hoTen);
    if (len > 0 && hoTen[len - 1] == '\n') {
        hoTen[len - 1] = '\0';
    }

    printf("Nhap gioi tinh (nam/nu): ");
    fgets(gioiTinh, sizeof(gioiTinh), stdin);
    // Xóa ký tự newline thừa nếu có
    len = strlen(gioiTinh);
    if (len > 0 && gioiTinh[len - 1] == '\n') {
        gioiTinh[len - 1] = '\0';
    }

    // Kiểm tra và đảm bảo rằng giới tính nhập vào hợp lệ
    if (strcmp(gioiTinh, "nam") != 0 && strcmp(gioiTinh, "nu") != 0) {
        printf("Gioi tinh khong hop le. Vui long nhap 'nam' hoac 'nu'.\n");
        return 1;
    }

    printf("Nhap ngay sinh (ngay/thang/nam): ");
    if (scanf_s("%d/%d/%d", &ngay, &thang, &nam) != 3) {
        printf("Nhap ngay sinh khong hop le.\n");
        return 1;
    }

    // Xử lý tính thời gian nghỉ hưu
    tinhThoiGianNghiHuu(namHienTai, 62, 60, ngay, thang, nam, gioiTinh);

    return 0;
}
