#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Ham chuyen doi chuoi thanh chu hoa
void chuyen_hoa(char* st) {
    while (*st) {
        *st = toupper((unsigned char)*st);
        st++;
    }
}

// Ham chuyen ky tu dau moi tu thanh chu hoa
void chuyen_hoa_dau_tu(char* st) {
    int dau_tu = 1;
    while (*st) {
        if (isspace((unsigned char)*st)) {
            dau_tu = 1;
        }
        else if (dau_tu) {
            *st = toupper((unsigned char)*st);
            dau_tu = 0;
        }
        st++;
    }
}

int main() {
    char st[100];

    // Nhap chuoi
    printf("Nhap chuoi: ");
    fgets(st, sizeof(st), stdin);

    // Xuat gia tri tung ky tu cua st thong qua con tro
    char* ptr = st;
    printf("Gia tri tung ky tu cua chuoi:\n");
    while (*ptr) {
        printf("%c\n", *ptr);
        ptr++;
    }

    // Chuyen cac ky tu cua chuoi ve dang chu hoa
    chuyen_hoa(st);
    printf("Chuoi sau khi chuyen thanh chu hoa: %s", st);

    // Chuyen ky tu dau moi tu ve dang chu hoa
    // Reset lai chuoi ve ban dau de thuc hien yeu cau nay
    fgets(st, sizeof(st), stdin);
    chuyen_hoa_dau_tu(st);
    printf("Chuoi sau khi chuyen ky tu dau moi tu thanh chu hoa: %s", st);

    return 0;
}
