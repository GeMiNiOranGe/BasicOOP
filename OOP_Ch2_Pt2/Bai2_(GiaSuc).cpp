/*Một nông trại chăn nuôi 3 loại gia súc: bò, cừu và dê. Mỗi loại gia súc đều có thể
sinh con, cho sữa và phát ra tiếng kêu riêng của chúng. Khi đói, các gia súc sẽ phát 
ra tiếng kêu để đòi ăn. Sau một thời gian chăn nuôi, người ta muốn thống kê số lượng
gia súc mỗi loại và tổng số lít sữa mà chúng cho.
Hãy xây dựng chương trình để quản lý nông trại có các chức năng sau:
	- Khởi tạo số lượng gia súc các loại ban đầu cho nông trại;
	- Thống kê số lượng gia súc sau một lượt sinh, biết rằng:
		o Tất cả gia súc mỗi loại đều sinh cùng lúc.
		o Số lượng sinh của mỗi gia súc là khác nhau (từ 1 đến 5 con/ lượt)
	- Thống kê số lượng sữa cho được sau mỗi lần lấy sữa, biết rằng:
		o Tất cả gia súc mỗi loại đều cho sữa cùng lúc.
		o Số lượng sữa của mỗi loại là khác nhau:
			+ Bò: từ 0 đến 20 lít/ lần;
			+ Cừu: từ 0 đến 5 lít/ lần;
			+ Dê: từ 0 đến 10 lít/ lần;*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class giaSuc {
private:
	int soLuong, luongSua;
public:
	giaSuc();
	giaSuc(int);
	giaSuc(int, int);
	friend istream& operator>>(istream&, giaSuc&);
	friend ostream& operator<<(ostream&, giaSuc);
	int soLuongSinhSauMotLuot();
	int soLuongSuaSauMotLuot(int);
	void soLuongDauRa(int, int);
};

int main() {
	srand((unsigned int)time(NULL));
	giaSuc bo, cuu, de;
	int soLan;
	cout << "bo" << endl; cin >> bo;
	cout << "cuu" << endl; cin >> cuu;
	cout << "de" << endl; cin >> de;
	cout << endl;
	cout << "so lan: "; cin >> soLan;
	cout << "bo" << endl; bo.soLuongDauRa(soLan, 20);
	cout << "cuu" << endl; cuu.soLuongDauRa(soLan, 5);
	cout << "de" << endl; de.soLuongDauRa(soLan, 10);
	cout << endl;
	cout << "bo" << endl << bo;
	cout << "cuu" << endl << cuu;
	cout << "de" << endl << de;
	return 0;
}

giaSuc::giaSuc() {
	this->soLuong = 0;
	this->luongSua = 0;
}
giaSuc::giaSuc(int soLuong) {
	this->soLuong = soLuong;
	this->luongSua = 0;
}
giaSuc::giaSuc(int soLuong, int luongSua) {
	this->soLuong = soLuong;
	this->luongSua = luongSua;
}

istream& operator>>(istream& is, giaSuc& gs) {
	cout << "so luong gia suc ban dau: ";
	is >> gs.soLuong;
	cout << "so luong sua ban dau: ";
	is >> gs.luongSua;
	return is;
}
ostream& operator<<(ostream& os, giaSuc gs) {
	os << "so luong gia suc la: " << gs.soLuong << endl;
	os << "so luong sua la: " << gs.luongSua << endl;
	return os;
}

int giaSuc::soLuongSinhSauMotLuot() {
	int soLuongSinhNgauNhien = rand() % 5 + 1;
	if (this->soLuong > 1) {
		if (soLuongSinhNgauNhien == 1) {
			this->soLuong *= 2;
		}
		else if (soLuongSinhNgauNhien > 1) {
			this->soLuong *= soLuongSinhNgauNhien;
		}
		else {
		}
	}
	else if (this->soLuong == 1) {
		this->soLuong += soLuongSinhNgauNhien;
	}
	else {
	}
	return this->soLuong;
}
int giaSuc::soLuongSuaSauMotLuot(int soLuongSuaChoDuocCuaMoiLoai) {
	int soLuongSuaNgauNhien = rand() % (soLuongSuaChoDuocCuaMoiLoai + 1);
	if (this->luongSua > 1) {
		if (soLuongSuaNgauNhien == 1) {
			this->luongSua *= 2;
		}
		else if (soLuongSuaNgauNhien > 1) {
			this->luongSua *= soLuongSuaNgauNhien;
		}
		else {
		}
	}
	else if (this->luongSua == 1) {
		this->luongSua += soLuongSuaNgauNhien;
	}
	else {
	}
	return this->luongSua;
}
void giaSuc::soLuongDauRa(int soLan, int luongSuaTuyLoai) {
	for (int i = 1; i <= soLan; i++) {
		cout << "lan " << i << ": " << endl;
		cout << "    sinh: " << soLuongSinhSauMotLuot() << endl << "    sua: " << soLuongSuaSauMotLuot(luongSuaTuyLoai) << endl;
	}
}
