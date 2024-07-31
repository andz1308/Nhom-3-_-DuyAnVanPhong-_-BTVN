#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#define Max 100

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// 1. Hàm liệt kê các số nguyên tố nhỏ hơn n
void lietKeSoNguyenTo(int a[], int n) {
	bool coNguyenTo = false;
	printf("Cac so nguyen to nho hon n: ");
	for (int i = 0; i < n; i++) {
		if (laSoNguyenTo(a[i])) {
			printf("%d ", a[i]);
			coNguyenTo = true;
		}
	}
	if (!coNguyenTo) {
		printf("Khong co so nguyen to nao nho hon n.\n");
	}
	else {
		printf("\n");
	}
}

// Hàm lấy chữ số đầu tiên của một số nguyên
int chuSoDau(int n) {
	n = abs(n);
	while (n >= 10) {
		n /= 10;
	}
	return n;
}

// 2. Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongChuSoDauLe(int a[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		int chuSo = chuSoDau(a[i]);
		if (chuSo % 2 != 0) {
			tong += a[i];
		}
	}
	return tong;
}

// 3. Hàm liệt kê số lần xuất hiện của các phần tử trong mảng
void lietKeSoLanXuatHien(int a[], int n) {
	int dem[Max];
	for (int i = 0; i < n; i++) {
		dem[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				dem[i]++;
				for (int k = j; k < n - 1; k++) {
					a[k] = a[k + 1];
				}
				n--;
				j--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("Phan tu %d xuat hien %d lan\n", a[i], dem[i]);
	}
}

// 4. Hàm sắp xếp mảng: số chẵn tăng dần, số lẻ giảm dần
void sapXepChanTangLeGiam(int a[], int n) {
	int chan[Max], le[Max];
	int mChan = 0, mLe = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[mChan++] = a[i];
		}
		else {
			le[mLe++] = a[i];
		}
	}

	for (int i = 0; i < mChan - 1; i++) {
		for (int j = i + 1; j < mChan; j++) {
			if (chan[i] > chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	for (int i = 0; i < mLe - 1; i++) {
		for (int j = i + 1; j < mLe; j++) {
			if (le[i] < le[j]) {
				int temp = le[i];
				le[i] = le[j];
				le[j] = temp;
			}
		}
	}

	int idx = 0;
	for (int i = 0; i < mChan; i++) {
		a[idx++] = chan[i];
	}
	for (int i = 0; i < mLe; i++) {
		a[idx++] = le[i];
	}
}

// 5. Hàm tìm dãy con giảm dài nhất
int dayConGiamDaiNhat(int a[], int n) {
	int maxLen = 1, len = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			len++;
		}
		else {
			if (len > maxLen) {
				maxLen = len;
			}
			len = 1;
		}
	}
	return (len > maxLen) ? len : maxLen;
}

// 6. Hàm tìm số nhỏ thứ 2 trong mảng
int timSoNhoThu2(int a[], int n) {
	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] < min1) {
			min2 = min1;
			min1 = a[i];
		}
		else if (a[i] < min2 && a[i] != min1) {
			min2 = a[i];
		}
	}
	return (min2 == INT_MAX) ? -1 : min2;
}

// Hàm kiểm tra một số có chứa các chữ số của số x
bool chuaChuSo(int a, int x) {
	char strA[20], strX[3];
	sprintf_s(strA, "%d", abs(a));
	sprintf_s(strX, "%d", abs(x));

	bool found = false;
	for (int i = 0; strX[i] != '\0'; i++) {
		found = false;
		for (int j = 0; strA[j] != '\0'; j++) {
			if (strX[i] == strA[j]) {
				found = true;
				break;
			}
		}
		if (!found) return false;
	}
	return true;
}

// 7. Hàm tìm các phần tử chứa các chữ số của x
void timPhanTuChuaChuSo(int a[], int n, int x) {
	bool coSo = false;
	for (int i = 0; i < n; i++) {
		if (chuaChuSo(a[i], x)) {
			printf("%d ", a[i]);
			coSo = true;
		}
	}
	if (!coSo) {
		printf("Khong co phan tu nao chua cac chu so cua x.\n");
	}
	else {
		printf("\n");
	}
}

// 8. Hàm sắp xếp mảng: các phần tử chẵn tăng dần, các phần tử lẻ giữ nguyên vị trí
void sapXepChanTangLeGiuNguyen(int a[], int n) {
	int chan[Max], mChan = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[mChan++] = a[i];
		}
	}

	for (int i = 0; i < mChan - 1; i++) {
		for (int j = i + 1; j < mChan; j++) {
			if (chan[i] > chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] = chan[idx++];
		}
	}
}

// 9. Hàm sắp xếp mảng: số lẻ ở đầu mảng, số chẵn ở cuối mảng
void sapXepLeDauChanCuoi(int a[], int n) {
	int le[Max], chan[Max];
	int mLe = 0, mChan = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[mChan++] = a[i];
		}
		else {
			le[mLe++] = a[i];
		}
	}

	int idx = 0;
	for (int i = 0; i < mLe; i++) {
		a[idx++] = le[i];
	}
	for (int i = 0; i < mChan; i++) {
		a[idx++] = chan[i];
	}
}

// Hàm nhập mảng
void nhapMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("Nhap phan tu thu %d: ", i + 1);
		scanf_s("%d", &a[i]);
	}
}

// Hàm in mảng
void inMang(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

// Hàm chính
int main() {
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf_s("%d", &n);

	int a[Max];
	nhapMang(a, n);

	int choice, x;
	do {
		printf("\n--- MENU ---\n");
		printf("1. Liet ke cac so nguyen to nho hon n\n");
		printf("2. Tinh tong cac phan tu co chu so dau la chu so le\n");
		printf("3. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
		printf("4. Sap xep mang so chan tang dan, so le giam dan\n");
		printf("5. Tim day con giam dai nhat trong mang\n");
		printf("6. Tim so nho thu 2 trong mang\n");
		printf("7. Tim cac phan tu chua cac chu so cua x\n");
		printf("8. Sap xep mang: cac phan tu chan tang dan, cac phan tu le giu nguyen vi tri\n");
		printf("9. Sap xep mang: so le o dau mang, so chan o cuoi mang\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			lietKeSoNguyenTo(a, n);
			break;
		case 2:
			printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tongChuSoDauLe(a, n));
			break;
		case 3:
			lietKeSoLanXuatHien(a, n);
			break;
		case 4:
			sapXepChanTangLeGiam(a, n);
			printf("Mang sau khi sap xep chan tang le giam: ");
			inMang(a, n);
			break;
		case 5:
			printf("Do dai day con giam dai nhat: %d\n", dayConGiamDaiNhat(a, n));
			break;
		case 6:
			x = timSoNhoThu2(a, n);
			if (x == -1) {
				printf("Khong co so nho thu 2 trong mang.\n");
			}
			else {
				printf("So nho thu 2 trong mang: %d\n", x);
			}
			break;
		case 7:
			printf("Nhap so x (co 2 chu so): ");
			scanf_s("%d", &x);
			timPhanTuChuaChuSo(a, n, x);
			break;
		case 8:
			sapXepChanTangLeGiuNguyen(a, n);
			printf("Mang sau khi sap xep chan tang le giu nguyen: ");
			inMang(a, n);
			break;
		case 9:
			sapXepLeDauChanCuoi(a, n);
			printf("Mang sau khi sap xep le dau chan cuoi: ");
			inMang(a, n);
			break;
		case 0:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le. Vui long chon lai.\n");
			break;
		}
	} while (choice != 0);

	return 0;
}
