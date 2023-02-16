#include <iostream>
#include <cmath>

using namespace std;

class check {
private:

public:
	bool primeNumber(int n);
	bool perfectNumber(int n);
	bool palindromeNumber(int n);
	bool squareNumber(int n);

};

void ketQua(bool n);

int main() {
	check soCanKiemTra;
	int n;
	cin >> n;
	cout << "1) La so nguyen to phai khong ?" << endl;
	ketQua(soCanKiemTra.primeNumber(n));
	cout << endl;
	cout << "2) La so hoan hao phai khong ?" << endl;
	ketQua(soCanKiemTra.perfectNumber(n));
	cout << endl;
	cout << "3) La so doi xung (so doc xuoi nguoc deu duoc) phai khong ?" << endl;
	ketQua(soCanKiemTra.palindromeNumber(n));
	cout << endl;
	cout << "4) La so chinh phuong phai khong ?" << endl;
	ketQua(soCanKiemTra.squareNumber(n));
	cout << endl;
	system("pause");
	return 0;
}

//kiem tra so nguyen to
bool check::primeNumber(int n) {
	if (n < 2) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	for (int i = 3; i < n - 1; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

//kiem tra so hoan hao
bool check::perfectNumber(int n) {
	int sum = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (i * i != n)
				sum = sum + i + n / i;
			else
				sum = sum + i;
		}
	}
	if (sum == n && n != 1) {
		return true;
	}
	return false;
}

//kiem tra doi xung (so doc xuoi nguoc deu duoc)
bool check::palindromeNumber(int n) {
	int reverseNumber = 0, originalNumber = n;
	for (; n > 0; ) {
		reverseNumber = reverseNumber * 10 + n % 10;
		n /= 10;
	}
	if (reverseNumber == originalNumber) {
		return true;
	}
	else {
		return false;
	}
}

//kiem tra chinh phuong
bool check::squareNumber(int n) {
	int tam = sqrt(n);
	if (tam * tam == n) {
		return true;
	}
	return false;
}

void ketQua(bool n) {
	if (n) {
		cout << "True" << endl;
	}
	else {
		cout << "False" << endl;
	}
}
